#include <stdlib.h>

#define _UNICONN_INTERNAL
#include <unipkt.h>

unipkt_packet_t *unipkt_create(unipkt_sequence_t sequence,
                               const char *function, bool needret)
{
  // allocate buffer
  _unipkt_packet_t *packet = malloc(sizeof(_unipkt_packet_t));
  if (!packet) return NULL;

  // clear with zero
  memset(packet, 0x00, sizeof(_unipkt_packet_t));

  // setup information
  packet->flag = needret;
  packet->version = version_1;
  strcpy_s(packet->name, sizeof(packet->name), function);

  return (unipkt_packet_t)packet;
}

unipkt_packet_t *unipkt_create_from(uint8_t *buffer)
{
}

size_t unipkt_packup(unipkt_packet_t *packet, uint8_t *buffer, size_t buflen)
{
  size_t length = 0;

  if (buffer) memset(buffer, 0x00, buflen);

  // |Len        |
  // +--+--+--+--+
  // |01|00|00|00|
  // +--+--+--+--+
  // 0     2     4
  length += 0x04; // packet total length

  // write metadata
  length += _unipkt_write_metadata(buffer, length,
                                   _handle(packet)->version,
                                   _handle(packet)->sequence,
                                   _handle(packet)->flag,
                                   _handle(packet)->argcount);
  // write function name
  length += _unipkt_write_funcname(buffer, length,
                                   _handle(packet)->name);

  if (_handle(packet)->arguments)
  {
    // write arguments
    unipkt_argument_t *chain = _handle(packet)->arguments;
    {
      while (chain != NULL)
      {
        length += _unipkt_write_argument(buffer, length, chain);
        chain = chain->next;
      }
    }
  }

  // write packet length
  _unipkt_write_packetlen(buffer, length);

  // write checksum
  length += _unipkt_write_checksum(buffer, length);

  return length;
}

void unipkt_destroy(unipkt_packet_t *packet)
{
}

unipkt_packet_t *unipkt_put_ex(unipkt_packet_t *packet, const char *name,
                               uint8_t *payload, uint32_t length)
{
  // for first argument
  if (!_handle(packet)->arguments)
  {
    // update chain
    _handle(packet)->arguments = _unipkt_new_argument(name, payload, length);
    _handle(packet)->final = _handle(packet)->arguments;

    _handle(packet)->argcount++;
    return packet;
  }

  // create next argument chain
  _handle(packet)->final->next = _unipkt_new_argument(name, payload, length);
  _handle(packet)->final = _handle(packet)->final->next;

  _handle(packet)->argcount++;
  return packet;
}

unipkt_packet_t *unipkt_put_number(unipkt_packet_t *packet, const char *name,
                                   unipkt_type_t type, uint64_t payload)
{
  return unipkt_put_ex(packet, name, (uint8_t *)&payload, _typelen(type));
}

unipkt_packet_t *unipkt_put_singlefl(unipkt_packet_t *packet,
                                     const char *name, float payload)
{
  return unipkt_put_ex(packet, name, (uint8_t *)&payload, _typelen(singlefl));
}

unipkt_packet_t *unipkt_put_doublefl(unipkt_packet_t *packet,
                                     const char *name, double payload)
{
  return unipkt_put_ex(packet, name, (uint8_t *)&payload, _typelen(doublefl));
}

unipkt_argument_t *_unipkt_new_argument(const char *name,
                                        uint8_t *payload, uint32_t length)
{
  // allocate space for argument
  unipkt_argument_t *argument = malloc(sizeof(unipkt_argument_t));
  if (!argument) return NULL;

  memset(argument, 0x00, sizeof(unipkt_argument_t));
  argument->value = malloc(length);
  {
    // copy argument name
    strcpy_s(argument->key,
             sizeof(argument->key), name);

    // copy payload data
    argument->length = length;
    memcpy_s(argument->value, length, payload, length);
  }

  return argument;
}

size_t _unipkt_write_metadata(uint8_t *buffer, size_t offset, unipkt_version_t version,
                              uint16_t sequence, unipkt_flag_t flag, uint16_t argcount)
{
  // |Ver  |Seq  |Flg  |Arg  |X    |X    |
  // +--+--+--+--+--+--+--+--+--+--+--+--+
  // |01|00|E9|00|00|00|01|00|--|--|--|--|
  // +--+--+--+--+--+--+--+--+--+--+--+--+
  // 0     2     4     6     8     A     C
  if (!buffer) return 0x0C;

  uint64_t data = 0;
  data = (data << 16) | argcount;
  data = (data << 16) | flag;
  data = (data << 16) | sequence;
  data = (data << 16) | version;

  *((uint64_t *)(buffer + offset)) = data;

  return 0x0C;
}

size_t _unipkt_write_funcname(uint8_t *buffer,
                              size_t offset, const char *name)
{
  // |L.|Name    |
  // +--+--+--+--+
  // |03|46|6F|6F|
  // +--+--+--+--+
  // 0     2     4
  size_t namelen = strlen(name);
  size_t length = 0x01 + namelen;
  if (!buffer) return length;

  *((uint8_t *)(buffer + offset)) = namelen;
  memcpy(buffer + offset + 1, name, namelen);

  return length;
}

size_t _unipkt_write_argument(uint8_t *buffer,
                              size_t offset, unipkt_argument_t *argument)
{
  // |L.|Key     |Len        |Val     |
  // +--+--+--+--+--+--+--+--+--+--+--+
  // |03|46|6F|6F|03|00|00|00|42|61|72|
  // +--+--+--+--+--+--+--+--+--+--+--+
  // 0     2     4     6     8        B
  size_t keylen = strlen(argument->key);
  size_t length = 0x01 + keylen +
                  0x04 + argument->length;
  if (!buffer) return length;

  // argument name length
  buffer[offset++] = 0x01;
  memcpy(buffer + offset, argument->key, keylen);
  offset += keylen;

  // argument value length
  *((uint32_t *)(buffer + offset)) = argument->length;
  memcpy(buffer + offset + 4, argument->value, argument->length);

  return length;
}

size_t _unipkt_write_checksum(uint8_t *buffer, size_t offset)
{
  // |S.|
  // +--+
  // |FE|
  // +--+
  // 0  1

  if (!buffer) return 0x01;

  uint64_t checksum = 0x00;
  for (size_t i = 0; i < offset; ++i)
    checksum += buffer[i];

  // grab low byte
  buffer[offset] = checksum & 0xFF;

  return 0x01;
}

void _unipkt_write_packetlen(uint8_t* buffer, size_t length) {
  if (!buffer) return;

  *((uint32_t*)buffer) = length + 0x04;
}

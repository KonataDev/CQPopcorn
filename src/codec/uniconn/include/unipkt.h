#ifndef _UNICONN_H_
#define _UNICONN_H_

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef uint16_t unipkt_sequence_t;

typedef enum unipkt_flag
{
  need_result = 1
} unipkt_flag_t;

typedef enum unipkt_version
{
  version_1 = 1
} unipkt_version_t;

#define _mktype(group, len) (group << 5) | len
#define _typelen(type) type & 0xF
typedef enum unipkt_type
{
  unipkt_int8 = _mktype(1, 1),
  unipkt_int16 = _mktype(1, 2),
  unipkt_int32 = _mktype(1, 3),
  unipkt_int64 = _mktype(1, 4),
  unipkt_uint8 = _mktype(2, 1),
  unipkt_uint16 = _mktype(2, 2),
  unipkt_uint32 = _mktype(2, 3),
  unipkt_uint64 = _mktype(2, 4),
  unipkt_singlefl = _mktype(3, 4),
  unipkt_doublefl = _mktype(3, 8),
  unipkt_boolean = _mktype(3, 1),
  unipkt_charseq = _mktype(3, 2),
  unipkt_byteseq = _mktype(3, 3)
} unipkt_type_t;

typedef struct unipkt_argument
{
  void *next;
  char key[255];
  uint8_t *value;
  uint32_t length;
} unipkt_argument_t;

typedef struct _unipkt_packet
{
  char name[255];
  unipkt_sequence_t sequence;
  unipkt_flag_t flag;
  unipkt_argument_t *arguments;
  unipkt_argument_t *final;
  uint16_t argcount;
  size_t version;
} _unipkt_packet_t;

typedef void *unipkt_packet_t;

/**
 * @brief create an uniconn packet
 * 
 * @param sequence 
 * @param function 
 * @param needret  
 * @return new packet instance
 */
unipkt_packet_t *unipkt_create(unipkt_sequence_t sequence, const char *function, bool needret);

/**
 * @brief create an uniconn packet from bytes
 * 
 * @param buffer buffer input
 * @return unipkt_packet_t* 
 */
unipkt_packet_t *unipkt_create_from(uint8_t *buffer);

/**
 * @brief put a new argument to a packet
 * 
 * @param packet packet instance
 * @param name function name
 * @param payload value
 * @param length length
 * @return unipkt_packet_t* 
 */
unipkt_packet_t *unipkt_put_ex(unipkt_packet_t *packet, const char *name,
                               uint8_t *payload, uint32_t length);

#define unipkt_put_charseq(packet, name, payload) unipkt_put_ex(packet, name, payload, (uint32_t)strlen(payload))
#define unipkt_put_byteseq(packet, name, payload, length) unipkt_put_ex(packet, name, payload, length)

/**
 * @brief put a new argument to a packet
 * 
 * @param packet packet instance
 * @param name function name
 * @param type value type
 * @param payload value
 * @return unipkt_packet_t* 
 */
unipkt_packet_t *unipkt_put_number(unipkt_packet_t *packet, const char *name,
                                   unipkt_type_t type, uint64_t payload);

#define unipkt_put_int8(packet, name, payload) unipkt_put_number(packet, name, unipkt_int8, payload)
#define unipkt_put_int16(packet, name, payload) unipkt_put_number(packet, name, unipkt_int16, payload)
#define unipkt_put_int32(packet, name, payload) unipkt_put_number(packet, name, unipkt_int32, payload)
#define unipkt_put_int64(packet, name, payload) unipkt_put_number(packet, name, unipkt_int64, payload)
#define unipkt_put_uint8(packet, name, payload) unipkt_put_number(packet, name, unipkt_uint8, payload)
#define unipkt_put_uint16(packet, name, payload) unipkt_put_number(packet, name, unipkt_uint16, payload)
#define unipkt_put_uint32(packet, name, payload) unipkt_put_number(packet, name, unipkt_uint32, payload)
#define unipkt_put_uint64(packet, name, payload) unipkt_put_number(packet, name, unipkt_uint64, payload)

/**
 * @brief put a new argument to a packet
 * 
 * @param packet packet instance
 * @param name function name
 * @param payload value
 * @return unipkt_packet_t* 
 */
unipkt_packet_t *unipkt_put_singlefl(unipkt_packet_t *packet, const char *name, float payload);

/**
 * @brief put a new argument to a packet
 * 
 * @param packet packet instance
 * @param name function name
 * @param payload value
 * @return unipkt_packet_t* 
 */
unipkt_packet_t *unipkt_put_doublefl(unipkt_packet_t *packet, const char *name, double payload);

/**
 * @brief serialize a packet to buffer stream
 * 
 * @param packet packet input.
 * @param buffer the buffer writes to. for calculating the length please keep the buffer to null.
 * @param buffer length.
 * @return actually length
 */
size_t unipkt_packup(unipkt_packet_t *packet, uint8_t *buffer, size_t buflen);

/**
 * @brief free a packet
 * 
 * @param packet packet input.
 */
void unipkt_destroy(unipkt_packet_t *packet);

#ifdef _UNICONN_INTERNAL
#define _handle(x) ((_unipkt_packet_t *)x)

unipkt_argument_t *_unipkt_new_argument(const char *name,
                                        uint8_t *payload, uint32_t length);

size_t _unipkt_write_checksum(uint8_t *buffer, size_t offset);
size_t _unipkt_write_argument(uint8_t *buffer,
                              size_t offset, unipkt_argument_t *argument);
size_t _unipkt_write_funcname(uint8_t *buffer,
                              size_t offset, const char *name);
size_t _unipkt_write_metadata(uint8_t *buffer, size_t offset, unipkt_version_t version,
                              uint16_t sequence, unipkt_flag_t flag, uint16_t argcount);
void _unipkt_write_packetlen(uint8_t* buffer, size_t length);
#endif

#endif /* _UNICONN_H_ */

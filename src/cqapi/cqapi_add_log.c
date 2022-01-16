#include <cqapi.h>
#include <unipkt.h>

int32_t _onebot_add_log(int32_t authcode, uint32_t loglevel,
                        char *logtype, char *content)
{
}

int32_t _uniconn_add_log(int32_t authcode, uint32_t loglevel,
                         char *logtype, char *content)
{
  int sequence = stream_getseq();

  // create new packet
  unipkt_packet_t packet = unipkt_create(sequence, "AddLog", true);
  if(!packet) return -1000;

  unipkt_put_int32(packet, "authcode", authcode);
  unipkt_put_uint32(packet, "loglevel", loglevel);
  unipkt_put_charseq(packet, "logtype", logtype);
  unipkt_put_charseq(packet, "content", content);

  // send unipkt to upstream
  unipkt_packet_t receive = stream_send(packet, sequence);
  int32_t result = unipkt_get_int32(receive, 0);

  // destroy packets
  unipkt_destroy(packet);
  unipkt_destroy(receive);

  return result;
}

#include <stdio.h>
#include <stdlib.h>
#include <unipkt.h>

int main()
{
  // allocate a packet
  unipkt_packet_t packet = unipkt_create(0x00, "Test4Fun", true);
  {
    // put arguments
    unipkt_put_int8(packet, "arg1", 0xE9);
    unipkt_put_charseq(packet, "arg2", "Hello from uniconn!");
    unipkt_put_byteseq(packet, "arg3", "\x12\x34\x56\x78", 4);
    unipkt_put_doublefl(packet, "arg4", 1.0f);
  }

  // calculate packet length
  size_t length = unipkt_packup(packet, NULL, NULL);
  uint8_t *buffer = malloc(length);

  // write to buffer
  if (unipkt_packup(packet, buffer, length) < 0) return 1;

  // print buffer
  for (size_t i = 0; i < length; ++i)
    printf("%02X ", *(buffer+i));
}

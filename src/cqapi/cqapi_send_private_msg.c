#include <cqapi.h>
#include <stdio.h>

__cqapi(int32_t) cqapi_send_private_msg(int32_t authcode,
  uint64_t account, const char* message) {
  printf(message);
}

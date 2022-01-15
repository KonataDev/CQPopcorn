#include <stdio.h>
#include <cqext.h>
#include <cqapi.h>

int main(int argc, char** argv) {

  if (argc < 2) return 1;

  // Load cq extension dll
  cq_ext_instance_t instance = cqext_load(argv[1]);
  if (instance == NULL) return 2;

  cq_ret_t result;

  // Initilize cq extension
  result = cqext_bootstrap(instance, 0x00);
  if (result != 0) return 3;

  // Enable extension
  result = cqext_event_enable(instance);
  if (result != 0) return 4;

  getchar();
}

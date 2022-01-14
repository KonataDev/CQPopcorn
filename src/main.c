#include <stdio.h>
#include <Windows.h>

#include <cqext.h>
#include <cqapi.h>

int main(int argc, char** argv) {

  if (argc < 1) return 1;

  // Load cq extension dll
  cq_ext_instance_t instance = cqext_load(argv[0]);
  if (instance == NULL) return 2;

  cq_ret_t result;

  // Initilize cq extension
  result = cqext_bootstrap(instance, 0x00);
  if (result != 0) return 3;

  // Go enable
  result = cqext_event_enable(instance);
  if (result != 0) return 4;

  getchar();
}

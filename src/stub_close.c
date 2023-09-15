#include <stdint.h>
#include <calypsi/stubs.h>
#include "lib.h"

typedef void (*__close)(uint8_t);

int _Stub_close(int fd) {
  __fd_resources &= ~(1 << (fd - 3));
  ((__close)0xffc3)(fd);
  return 0;
}

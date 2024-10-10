#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <calypsi/intrinsics6502.h>
#include "lib.h"

#define CHROUT(c) ( (void (*)(char) ) 0xffd2) (c)
#define CLRCHN() ( (void (*)() ) 0xffcc)()

size_t _Stub_write (int fd, const void *buf, size_t count) {
  const char *p = buf;
  size_t n = 0;

  switch (fd) {
  default:
    if (((1 << (fd - 3)) & __fd_resources) == 0) {
      goto bad;
    }
    // prepare for output
    if (__kernel_call_failed(__chkout(fd))) {
      return EOF;
    }
    // fall through
  case 2:
  case 1: {
    char c;
    while (count) {
      CHROUT(*p);
      n += 1;
      p += 1;
      count -= 1;
    }
    break;
    }
    case 0:
    bad:
      __set_errno(EBADF);
      return (size_t) -1;
  }
  if (__read_status()) {
    CLRCHN();
    return EOF;
  } else {
    CLRCHN();
    return n;
  }
}

#include <errno.h>
#include <stddef.h>

#define CHROUT(c) ( (void (*)(char) ) 0xffd2) (c)

size_t _Stub_write (int fd, const void *buf, size_t count) {
  const char *p = buf;
  size_t n = 0;

  switch (fd) {
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
  default:
    __set_errno(EBADF);
    return (size_t) -1;
  }
  return n;
}

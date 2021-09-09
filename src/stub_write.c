#include <errno.h>
#include <sys/types.h>

#define CHROUT(c) ( (void (*)(char) ) 0xffd2) (c)

ssize_t _Stub_write (int fd, const void *buf, size_t count) {
  const char *p = buf;
  ssize_t n = 0;

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
    return (ssize_t) -1;
  }
  return n;
}

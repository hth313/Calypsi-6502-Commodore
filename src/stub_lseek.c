#include <stdio.h>
#include <errno.h>

long _Stub_lseek (int fd, long offset, int whence) {
  return -EPERM;
}

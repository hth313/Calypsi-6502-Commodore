#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <calypsi/stubs.h>
#include "lib.h"

uint8_t __fd_resources;

typedef void (*__open)(void);
typedef uint8_t (*__read_status)(void);

int _Stub_open(const char *path, int oflag, ...) {
  if (__fd_resources == 255) {
    // All resource busy

    return EOF;
  }
  char x1 = path[0];
  uint8_t device = 8;
  if (x1) {
    if ('0' <= x1 && x1 <= '9') {
      char x2 = path[1];
      if (x2 == ':') {
        device = x1 - '0';
        path += 2;
      } else if ('0' <= x2 && x2 <= '9' && path[2] == ':') {
        device *= 10;
        device += x2 - '0';
        path += 3;
      }
    }
    if (device == 0 || device == 3) {
      // Do not allow opening keyboard or screen, they are
      // already stdin and stdout.

      return EOF;
    }

    // Allocate a file descriptor
    uint8_t fd = 3;
    uint8_t r = 1;
    while ((__fd_resources & r)) {
      fd++;
      r <<= 1;
    }
    __fd_resources |= r;
    __set_logical_file(fd, device, 255);
    __set_filename(path, strlen(path));
    ((__open)0xffc0)();
    if (((__read_status)0xffb7)()) {
      // Open failed
      _Stub_close(fd);
      return EOF;
    }
    if ((oflag & O_WROK)) {
      __chkout(fd);
    }
    if ((oflag & O_RDOK)) {
      __chkin(fd);
    }
    return fd;
  } else {
    // no filename given
    return EOF;
  }
}

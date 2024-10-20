#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <calypsi/stubs.h>
#include <calypsi/intrinsics6502.h>
#include <errno.h>
#include "lib.h"

uint8_t __fd_resources;

int _Stub_open(const char *path, int oflag, ...) {
  if (__fd_resources == 255) {
    return -ENOSR;
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

      return -EINVAL;
    }

    // Allocate a file descriptor
    uint8_t fd = 3;
    uint8_t r = 1;
    while ((__fd_resources & r) && (fd < 15)) {
      fd++;
      r <<= 1;
    }
    if (fd == 15) {
      return -ENOSR;
    }

    __fd_resources |= r;
    __set_logical_file(fd, device, fd);
    __set_filename(path, strlen(path));
    if (__kernel_call_failed(__open())) {
      return -EIO;
    }

    // Finally check if something might have gone wrong
    if (__read_status() == 0) {
      return fd;
    } else {
      // Some problem, close the file.
      _Stub_close(fd);
    }
  }
  return -EIO;
}

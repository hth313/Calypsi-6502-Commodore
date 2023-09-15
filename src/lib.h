#ifndef __COMMODORE_LIB_H__
#define __COMMODORE_LIB_H__

#include <stdint.h>

extern uint8_t __fd_resources;

extern void __set_filename(const char *, uint8_t len);
extern uint8_t __set_logical_file(uint8_t fd, uint8_t device,
                                  uint8_t secondary);
extern void __chkin(uint8_t fd);
extern void __chkout(uint8_t fd);

#endif // __COMMODORE_LIB_H__

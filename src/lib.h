#ifndef __COMMODORE_LIB_H__
#define __COMMODORE_LIB_H__

#include <stdbool.h>
#include <stdint.h>

typedef bool (*__open_t)(void);
typedef uint8_t (*__read_status_t)(void);

#define __read_status  ((__read_status_t)0xffb7)
#define __open  ((__open_t)0xffc0)

extern uint8_t __fd_resources;

extern void __set_filename(const char *, uint8_t len);
extern uint8_t __set_logical_file(uint8_t fd, uint8_t device,
                                  uint8_t secondary);
extern bool __chkin(uint8_t fd);
extern bool __chkout(uint8_t fd);

#endif // __COMMODORE_LIB_H__

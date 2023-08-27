#ifndef __VIC_II_H__
#define __VIC_II_H__

#include <stdint.h>

typedef struct _VIC_II _VIC_II_t;

struct _VIC_II {
  uint8_t s0x;
  uint8_t s0y;
  uint8_t s1x;
  uint8_t s1y;
  uint8_t s2x;
  uint8_t s2y;
  uint8_t s3x;
  uint8_t s3y;
  uint8_t s4x;
  uint8_t s4y;
  uint8_t s5x;
  uint8_t s5y;
  uint8_t s6x;
  uint8_t s6y;
  uint8_t s7x;
  uint8_t s7y;
  uint8_t sxmsb;
  union {
    uint8_t yscl : 3;
    uint8_t rsel : 1;
    uint8_t blnk : 1;
    uint8_t bmm : 1;
    uint8_t ecm : 1;
    uint8_t rc8 : 1;
  };
  uint8_t rc;
  uint8_t lpx;
  uint8_t lpy;
  uint8_t se;
  union {
    uint8_t xscl : 3;
    uint8_t csel : 1;
    uint8_t mcm : 1;
    uint8_t rst : 1;
  };
  uint8_t sexy;
  union {
    uint8_t : 0;
    uint8_t cb : 3;
    uint8_t vs : 4;
  };
  union {
    uint8_t rirq : 1;
    uint8_t isbc : 1;
    uint8_t issc : 1;
    uint8_t ilp : 1;
  };
  union {
    uint8_t mrirq : 1;
    uint8_t misbc : 1;
    uint8_t missc : 1;
  };
  uint8_t bsp;
  uint8_t scm;
  uint8_t sexx;
  uint8_t ssc;
  uint8_t sbc;
  uint8_t bordercol;
  uint8_t screencol;
  uint8_t mc1;
  uint8_t mc2;
  uint8_t mc3;
  uint8_t sprmc0;
  uint8_t sprmc1;
  uint8_t spr0col;
  uint8_t spr1col;
  uint8_t spr2col;
  uint8_t spr3col;
  uint8_t spr4col;
  uint8_t spr5col;
  uint8_t spr6col;
  uint8_t spr7col;
  union {
    uint8_t c128_fast : 1;
  };
};

// VIC symbol
#define VIC  (* (volatile _VIC_II_t *)  0xd000)

#endif // __VIC_II_H__

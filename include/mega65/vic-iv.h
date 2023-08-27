#ifndef __VIC_IV_H__
#define __VIC_IV_H__

#include <clang/AST/NestedNameSpecifier.h>
#include <cstdint>
#include <stdint.h>

typedef struct _VIC_IV _VIC_IV_t;

struct _VIC_IV {
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
  uint8_t _gap[8];
  uint8_t key;
  uint8_t tbdrpos_0;
  union {
    uint8_t tbdrpos_1 : 4;
    uint8_t sprbpmem_0 : 4;
  };
  uint8_t bbdrpos_0;
  union {
    uint8_t bbdrpos_1 : 4;
    uint8_t sprbpmem_1 : 4;
  };
  uint8_t textxpos_0;
  union {
    uint8_t textxpos_1 : 4;
    uint8_t sprtilen_0 : 4;
  };
  uint8_t textypos_0;
  union {
    uint8_t textypos_1 : 4;
    uint8_t sprtilen_1 : 4;
  };
  uint8_t xposlsb;
  union {
    uint8_t xposmsb : 6;
    uint8_t dblrr : 1;
    uint8_t norrdel : 1;
  };
  uint8_t fnrasterlsb;
  union {
    uint8_t fnrastermsb : 3;
    uint8_t : 1;
    uint8_t reserved : 1;
    uint8_t upscale : 1;
    uint8_t shdemu : 1;
    uint8_t fnrst : 1;
  };
  union {
    uint8_t chr16 : 1;
    uint8_t fclrlo : 1;
    uint8_t fclrhi : 1;
    uint8_t smth : 1;
    uint8_t sprh640 :1;
    uint8_t palemu : 1;
    uint8_t vfast : 1;
    uint8_t alphen : 1;
  };
  uint8_t sprhgten;
  uint8_t sprhght;
  uint8_t sprx64en;
  uint8_t linesteplsb;
  uint8_t linestepmsb;
  uint8_t chrxscl;
  uint8_t chryscl;
  uint8_t sdbdrwdlsb;
  union {
    uint8_t sdbdrwdmsb : 6;
    uint8_t rstdelen : 1;
    uint8_t hotreg : 1;
  };
  uint8_t chrcount;
  uint8_t sprxsmsbs;
  uint8_t scrnptrlsb;
  uint8_t scrnptrmsb;
  uint8_t scrnptrbnk;
  union {
    uint8_t scrnptrmb : 4;
    uint8_t chrcount_hi : 2;
    uint8_t fcolmcl : 1;
    uint8_t exglyph : 1;
  };
  uint8_t colptrlsb;
  uint8_t colptrmsb;
  uint8_t charptrlsb;
  uint8_t charptrmsb;
  uint8_t charptrbnk;
  uint8_t spr16en;
  uint8_t sprptradrlsb;
  uint8_t sprptradrmsb;
  union {
    uint8_t sprptrbnk : 7;
    uint8_t sprptr16 : 1;
  };
  union {
    uint8_t rasline0 : 6;
    uint8_t vgahdtv : 1;
    uint8_t palntsc : 1;
  };
  union {
    uint8_t abtpalsel : 2;
    uint8_t sprpalsel : 2;
    uint8_t btpalsel : 2;
    uint8_t mapedpal : 2;
  };
  uint8_t bp16ens;
  uint8_t spryadj;
  union {
    uint8_t alphadelay : 4;
    uint8_t rasterheight : 4;
  };
  uint8_t sprenalpha;
  uint8_t spralphaval;
  uint8_t sprenv400;
  uint8_t sprymsbs;
  uint8_t sprysmsbs;
  uint8_t rascmp;
  union {
    uint8_t rascmpmsb : 3;
    uint8_t sptrcont : 1;
    uint8_t chary16 : 1;
    uint8_t nobugcompat : 1;
    uint8_t extirqs : 1;
    uint8_t fnrstcmp : 1;
  };
  uint8_t disprows;
  union {
    uint8_t bitpbank : 3;
    uint8_t resv : 1
    uint8_t hsyncp : 1;
    uint8_t vsyncp : 1;
    uint8_t debugc : 2;
  };
};

// VIC symbol
#define VIC  (* (volatile _VIC_IV_t *)  0xd000)

#endif // __VIC_II_H__

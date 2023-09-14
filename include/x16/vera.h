#ifndef __VERA_H__
#define __VERA_H__

#include <stdint.h>

typedef struct _VERA _VERA_t;

struct _VERA_layer {
  uint8_t config;
  uint8_t mapbase;
  uint8_t tilebase;
  uint8_t hscroll_l;
  uint8_t hscroll_h;
  uint8_t vhscroll_l;
  uint8_t vscroll_h;
};

struct _VERA {
  uint8_t address_low;
  uint8_t address_mid;
  union {
    struct {
      uint8_t address_high : 1;
      uint8_t nibble_address : 1;
      uint8_t nibble_inc : 1;
      uint8_t decr : 1;
      uint8_t address_inc : 4;
    };
    uint8_t address_upper;
#define NIBBLE_ADDRESS(x) (((x) & 1) << 1)
#define NIBBLE_INC(x)     (((x) & 1) << 2)
#define DECR(x)           (((x) & 1) << 3)
#define ADDRESS_INC(x)    (((x) & 15) << 4)
  };
  uint8_t data0;
  uint8_t data1;
  union {
    struct {
      uint8_t addrsel : 1;
      uint8_t dcsel : 6;
      uint8_t reset : 1;
    };
    uint8_t ctrl;
#define ADDRSEL(x)       ((x) & 1)
#define DCSEL(x)         (((x) & 63) << 1)
#define RESET            0x80
  };
  uint8_t ien;
#define VSYNC   0x01
#define LINE    0x02
#define SPRCOL  0x04
#define AFLOW   0x08
  uint8_t isr;
#define SPRITE_COLLISIONS(x)   (((x) & 15) << 4)
  union {
    uint8_t irq_line;     // write
    uint8_t scan_line;    // read
  };
  union {
    struct {
      uint8_t output_mode : 2;
      uint8_t ntsc_chroma_disable_rgb_hv_sync : 1;
      uint8_t ntsc_rgb_240P : 1;
      uint8_t layer0_enable : 1;
      uint8_t layer1_enable : 1;
      uint8_t sprites_enable : 1;
      uint8_t current_field : 1;
    };
    uint8_t dc_video;                      // DCSEL = 0
#define OUTPUT_MODE(x)     (((x) & 3))
#define NTSC_CHROMA_DISABLE_RGB_HV_SYNC 0x04
#define NTSC_RGB_240P 0x08
#define LAYER0_ENABLE 0x10
#define LAYER1_ENABLE 0x20
#define SPRITES_ENABLE 0x40
#define CURRENT_FIELD  0x80
    uint8_t h_start;                       // DCSEL = 1
    uint8_t fx_ctrl;                       // DCSEL = 2
    uint8_t fx_x_incr_l;                   // DCSEL = 3   (write only)
    uint8_t fx_x_pos_l;                    // DCSEL = 4   (write only)
    uint8_t fx_x_pos_s;                    // DCSEL = 5   (write only)
    uint8_t fx_cache_l;                    // DCSEL = 6   (write only)
    uint8_t fx_accum_reset;                // DCSEL = 6   (read only)
    uint8_t dc_ver0;                       // DCSEL = 63  (read only)
  };
  union {
    uint8_t h_scale;                       // DCSEL = 0
    uint8_t h_stop;                        // DCSEL = 1
    uint8_t fx_tilebase;                   // DCSEL = 2   (write only)
    uint8_t fx_x_incr_h;                   // DCSEL = 3   (write only)
    uint8_t fx_x_pos_h;                    // DCSEL = 4   (write only)
    uint8_t fx_y_pos_s;                    // DCSEL = 5   (write only)
    uint8_t fx_cache_m;                    // DCSEL = 6   (write only)
    uint8_t fx_accum;                      // DCSEL = 6   (read only)
    uint8_t dc_ver1;                       // DCSEL = 63  (read only)
  };
  union {
    uint8_t v_scale;                       // DCSEL = 0
    uint8_t v_start;                       // DCSEL = 1
    uint8_t fx_mapbase;                    // DCSEL = 2   (write only)
    uint8_t fx_y_incr_l;                   // DCSEL = 3   (write only)
    uint8_t fx_y_pos_l;                    // DCSEL = 4   (write only)
    uint8_t fx_x_poly_fill_l;              // DCSEL = 5   (read only)
    uint8_t fx_cache_h;                    // DCSEL = 6   (write only)
    uint8_t dc_ver2;                       // DCSEL = 63  (read only)
  };
  union {
    uint8_t border_color;                  // DCSEL = 0
    uint8_t v_stop;                        // DCSEL = 1
    uint8_t fx_mult;                       // DCSEL = 2   (write only)
    uint8_t fx_y_incr_h;                   // DCSEL = 3   (write only)
    uint8_t fx_y_pos_h;                    // DCSEL = 4   (write only)
    uint8_t fx_x_poly_fill_h;              // DCSEL = 5   (read only)
    uint8_t fx_cache_u;                    // DCSEL = 6   (write only)
    uint8_t dc_ver3;                       // DCSEL = 63  (read only)
  };
  struct _VERA_layer layer[2];
  uint8_t audio_ctrl;
  uint8_t audio_rate;
  uint8_t audio_data;
  uint8_t spi_data;
  uint8_t spi_ctrl;
};

// VERA symbol
#define VERA  (* (volatile _VERA_t *)  0x9f20)

#endif // __VERA_H__

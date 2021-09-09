              .extern _Zp

CHROUT:       .equlab 0xffd2

              .section code
              .public _Stub_putchar
_Stub_putchar:
#ifdef __NUTSTUDIO_CORE_65C02__
              stz     zp:_Zp+1      ; zero extended char, we always succeed
#else
              lda     #0
              sta     zp:_Zp+1
#endif
              lda     zp:_Zp+0
              jmp     CHROUT

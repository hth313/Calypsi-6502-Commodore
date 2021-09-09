              .extern _Zp

CHRIN:       .equlab 0xffcf

              .section code
              .public _Stub_read
_Stub_read:                         ; TODO: handle file descriptor
              lda     #0            ; set file counter = 0
              sta     zp:_Zp+0
              sta     zp:_Zp+1
              ldx     zp:_Zp+5      ; 256 or more?
              beq     20$           ; no
              ldy     #0
10$:          jsr     CHRIN
              sta     (_Zp+2),y
              iny
              bne     10$
              inc     zp:_Zp+3      ; step 256
              inc     zp:_Zp+1
              dec     zp:_Zp+5      ; yes, decrement 256 counter
              bne     10$

20$:          ldy     #0
25$:          cpy     zp:_Zp+4
              beq     30$
              jsr     CHRIN
              sta     (_Zp+2),y
              inc     zp:_Zp+0
              iny
              bne     25$
30$:          rts

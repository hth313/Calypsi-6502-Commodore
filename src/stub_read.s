              .extern _Zp

CHKIN:	      .equlab 0xffc6
CHRIN:	      .equlab 0xffcf
READST:	      .equlab 0xffb7

              .section code
              .public _Stub_read
_Stub_read:   ldx     zp:_Zp+0
	      beq     start$	    ; stdin
	      cpx     #3	    ; test for stdout/stderr
	      bcs     eof$
	      jsr     CHKIN	    ; ensure channel is prepared to read
start$:	      lda     #0	    ; set file counter = 0
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
30$:	      jsr     READST	    ; check for error
	      tax
	      beq     done$
eof$:	      lda     #-1
	      sta     zp:_Zp+0
	      sta     zp:_Zp+1
done$:	      rts

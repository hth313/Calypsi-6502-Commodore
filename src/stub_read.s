            .extern _Zp

CHKIN:      .equlab 0xffc6
CHRIN:      .equlab 0xffcf
READST:     .equlab 0xffb7
CLRCHN:     .equlab 0xffcc

            .section code
            .public _Stub_read
_Stub_read: ldx     zp:_Zp+0
            beq     start$        ; stdin
            cpx     #3            ; test for stdout/stderr
            bcc     eof$
            jsr     CHKIN         ; ensure channel is prepared to read
start$:     lda     #0            ; set file counter = 0
            sta     zp:_Zp+0
            sta     zp:_Zp+1
            lda     zp:_Zp+4
            ora     zp:_Zp+5
            beq     30$
            jsr     CHRIN         ; get first byte
            tax
            jsr     READST
            and     #0x02
            bne     eof$
            txa
            ldy     #0
            ldx     zp:_Zp+5      ; 256 or more?
            beq     20$           ; no
            bne     15$
10$:        jsr     CHRIN
15$:        sta     (_Zp+2),y
            inc     zp:_Zp+0
            jsr     READST
            tax
            bne     30$
            iny
            bne     10$
            inc     zp:_Zp+3      ; step 256
            inc     zp:_Zp+1
            dec     zp:_Zp+5      ; yes, decrement 256 counter
            bne     10$

25$:        cpy     zp:_Zp+4
            beq     30$
            jsr     CHRIN
20$:        sta     (_Zp+2),y
            inc     zp:_Zp+0
            jsr     READST
            tax
            bne     30$
            iny
            bne     25$
30$:        jsr     CLRCHN
            rts     
eof$:       jsr     CLRCHN
            lda     #0
            sta     zp:_Zp+0
            sta     zp:_Zp+1
            rts

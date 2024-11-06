	      .extern _Zp
	      .section code
	      .pubweak __chkin
__chkin:      tax
	      jmp     0xffc6

	      .section code
	      .pubweak __chkout
__chkout:     tax
	      jmp     0xffc9

	      .section code
	      .pubweak __set_filename
__set_filename:
	      ldx     zp:_Zp+0
	      ldy     zp:_Zp+1
	      jmp     0xffbd

	      .section code
	      .pubweak __set_logical_file
__set_logical_file:
	      ldx     zp:_Zp+0
	      ldy     zp:_Zp+1
	      jmp     0xffba

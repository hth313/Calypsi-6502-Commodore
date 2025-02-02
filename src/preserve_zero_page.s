              .rtmodel version, "1"
              .rtmodel core, "*"

              ;; External declarations
              .section registers    ; pseudo registers in zero page

              .section zpsave, noinit
              .pubweak __preserve_zp
__preserve_zp:                      ; This symbol meant to be required
	      .space  56	    ; This is the current size (for MEGA65)
	      .require __preserve_zp_needed
              .require __restore_zp_needed

              ;; Variant, change attribute value if you make your own.
              ;; Here we define one out of variants as this C startup is
              ;; shared by multiple target systems.
#if defined(__CALYPSI_TARGET_SYSTEM_C64__)
              .rtmodel cstartup,"c64"
#elif defined(__CALYPSI_TARGET_SYSTEM_MEGA65__)
              .rtmodel cstartup,"mega65"
#elif defined(__CALYPSI_TARGET_SYSTEM_CX16__)
              .rtmodel cstartup,"cx16"
#else
#pragma GCC error "--target system not one of C64, MEGA65 or X16"
#endif

              .rtmodel version, "1"
              .rtmodel core, "*"

              ;; External declarations
              .section cstack
              .section heap
              .section data_init_table
	      .section registers    ; pseudo registers in zero page
	      .section zpsave	    ; this is where pseudo registers are saved

              .extern main, exit
              .extern _Zp, _Vsp, _Vfp

              .pubweak __program_root_section, __program_start

#if defined(__CALYPSI_CODE_MODEL_BANKED__)
              .extern _JmpInline24
call:         .macro  dest
              jsr     _JmpInline24
              .word   .mmuslot5 \dest
              .byte   .mmubank \dest
              .endm
#else
call:         .macro  dest
              jsr     \dest
              .endm
#endif

              .section programStart, root ; to be at address 0x801 for Commodore 64
__program_root_section:
              .word   nextLine
              .word   10            ; line number
#if defined(__CALYPSI_TARGET_SYSTEM_MEGA65__)
              .byte   0x9e, " 8206", 0 ; SYS 806
#else
              .byte   0x9e, " 2062", 0 ; SYS 2062
#endif
nextLine:     .word   0             ; end of program

              .section startup, root, noreorder
__program_start:

              .section startup, noreorder
              .pubweak __preserve_zp_needed
__preserve_zp_needed:
              ldx     #.sectionSize registers - 1
-             lda     zp:.sectionStart registers,x
              sta     .sectionStart zpsave,x
              dex
              bpl     -

              .section startup, root, noreorder
              lda     #.byte0(.sectionEnd cstack)
              sta     zp:_Vsp
              lda     #.byte1(.sectionEnd cstack)
              sta     zp:_Vsp+1
              jsr     __low_level_init

;;; Initialize data sections if needed.
              .section startup, noroot, noreorder
              .pubweak __data_initialization_needed
              .extern __initialize_sections
__data_initialization_needed:
              lda     #.byte0 (.sectionStart data_init_table)
              sta     zp:_Zp
              lda     #.byte1 (.sectionStart data_init_table)
              sta     zp:_Zp+1
              lda     #.byte0 (.sectionEnd data_init_table)
              sta     zp:_Zp+2
              lda     #.byte1 (.sectionEnd data_init_table)
              sta     zp:_Zp+3
              call    __initialize_sections

              .section startup, noroot, noreorder
              .pubweak __call_initialize_global_streams
              .extern __initialize_global_streams
__call_initialize_global_streams:
              call    __initialize_global_streams

;;; **** Initialize heap if needed.
              .section startup, noroot, noreorder
              .pubweak __call_heap_initialize
              .extern __heap_initialize, __default_heap
__call_heap_initialize:
              lda     #.byte0 __default_heap
              sta     zp:_Zp+0
              lda     #.byte1 __default_heap
              sta     zp:_Zp+1
              lda     #.byte0 (.sectionStart heap)
              sta     zp:_Zp+2
              lda     #.byte1 (.sectionStart heap)
              sta     zp:_Zp+3
              lda     #.byte0 (.sectionSize heap)
              sta     zp:_Zp+4
              lda     #.byte1 (.sectionSize heap)
              sta     zp:_Zp+5
              call    __heap_initialize

              .section startup, root, noreorder
              tsx
              stx     _InitialStack ; for exit()
              lda     #0            ; argc = 0
              sta     zp:_Zp
              sta     zp:_Zp+1
#ifdef __CALYPSI_CODE_MODEL_BANKED__
              call    main
              call    exit
              rts
#else
              jsr     main
              jmp     exit
#endif

;;; ***************************************************************************
;;;
;;; __low_level_init - custom low level initialization
;;;
;;; This default routine just returns doing nothing. You can provide your own
;;; routine, either in C or assembly for doing custom low leve initialization.
;;;
;;; ***************************************************************************

              .section code
              .pubweak __low_level_init
__low_level_init:
              rts

;;; ***************************************************************************
;;;
;;; Keep track of the initial stack pointer so that it can be restores to make
;;; a return back on exit().
;;;
;;; ***************************************************************************

              .section zdata, bss
              .pubweak _InitialStack
_InitialStack:
              .space  1

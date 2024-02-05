#if defined(__CALYPSI_TARGET_SYSTEM_C64__)
              .rtmodel cstartup,"c64"
#elif defined(__CALYPSI_TARGET_SYSTEM_MEGA65__)
              .rtmodel cstartup,"mega65"
#elif defined(__CALYPSI_TARGET_SYSTEM_CX16__)
              .rtmodel cstartup,"cx16"
#else
#pragma GCC error "--target system not one of C64, MEGA65 or X16"
#endif

	      .section code
              .pubweak _Stub_exit
              .extern _Zp, _InitialStack
_Stub_exit:   ldx     _InitialStack
              txs
              rts

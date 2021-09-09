              .section code
              .public _Stub_exit
              .extern _Zp, _InitialStack
_Stub_exit:   ldx     _InitialStack
              txs
              rts

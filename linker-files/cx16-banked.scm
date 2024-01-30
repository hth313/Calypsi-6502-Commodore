(define memories
  '((memory program
            (address (#x801 . #x9fff)) (type any)
            (section (programStart #x801) (startup #x80e)))
    (memory zeroPage (address (#x2 . #x7f)) (type ram) (qualifier zpage)
	    (section (registers #x2)))
    (memory stackPage (address (#x100 . #x1ff)) (type ram))
    (memory VRAM (address (#x00000 . #x1ffff))
	    (section zvram vram))
    (memory bankSlotRAM
	    (address (#xa000 . #xbfff))
	    (scatter-to RAM-banks)
	    :generate-instances
	    (section bankedcode))
    (memory bankedRAM (address (#x2000 . #x1fffff))
	    (section RAM-banks))
    ))

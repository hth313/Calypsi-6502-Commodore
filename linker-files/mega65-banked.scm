(define memories
  '((memory program
            (address (#x2001 . #x9fff)) (type any)
            (section (programStart #x2001) (startup #x200e)))
    (memory zeroPage (address (#x2 . #x7f)) (type ram) (qualifier zpage)
	    (section (registers #x2)))
    (memory stackPage (address (#x100 . #x1ff)) (type ram))
    (memory bank1  (address (#x10000 . #x1ffff)) (type data) (qualifier far))
    (memory bank45 (address (#x40000 . #x5ffff)) (type data) (qualifier far))
    ))

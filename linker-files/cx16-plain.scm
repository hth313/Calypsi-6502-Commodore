(define memories
  '((memory program
            (address (#x801 . #x9fff)) (type any)
            (section (programStart #x801) (startup #x80e)))
    (memory zeroPage (address (#x2 . #x7f)) (type ram) (qualifier zpage)
	    (section (registers #x2)))
    (memory stackPage (address (#x100 . #x1ff)) (type ram))
    ))

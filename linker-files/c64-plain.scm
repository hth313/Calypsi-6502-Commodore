(define memories
  '((memory program
            (address (#x801 . #x9fff)) (type any)
            (section (programStart #x801) (startup #x80e)))
    (memory zeroPage (address (#x2 . #xff)) (type ram) (qualifier zpage))
    (memory upperdata
            (address (#xc000 . #xcfff))
            (section cstack zdata heap))
    ))

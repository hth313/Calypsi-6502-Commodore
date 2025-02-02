(define memories
  '((memory program
            (address (#x801 . #x9fff)) (type any)
            (section (programStart #x801) (startup #x80e)))
    (memory zeroPage (address (#x2 . #xff)) (type ram) (qualifier zpage))
    (memory stackPage (address (#x100 . #x1ff)) (type ram))
    (memory freeSpace (address (#x02a7 . #x02ff)) (section zpsave))
    (memory upperdata
            (address (#xc000 . #xcfff))
            (section cstack zdata heap))
    ))

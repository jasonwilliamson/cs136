#lang racket

;; this is a simple testing module for name-game.rkt

(require "name-game.rkt")

;; Each of the following should produce #t
(equal? (name-game "Katie")
        (list "katie, katie, bo-batie" "banana-fana fo-fatie" "fee-fi-mo-matie" "katie"))

(equal? (name-game "billy")
        (list "billy, billy, bo-illy" "banana-fana fo-filly" "fee-fi-mo-milly" "billy"))

(equal? (name-game "fred")
        (list "fred, fred, bo-bred" "banana-fana fo-red" "fee-fi-mo-mred" "fred"))
(equal? (name-game "Marsha")
        (list "marsha, marsha, bo-barsha" "banana-fana fo-farsha" "fee-fi-mo-arsha" "marsha"))
(equal? (name-game "stella")
        (list "stella, stella, bo-bella" "banana-fana fo-fella" "fee-fi-mo-mella" "stella"))
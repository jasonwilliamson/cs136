#lang racket

;; this is a simple testing module for intersect.rkt

(require "intersect.rkt")

;; Each of the following should produce #t


(equal? (intersect '(1 2 3) '(2 3)) '(2 3))
(equal? (intersect '(1 2 3 4 5) '(2 3 5 7 8)) '(2 3 5))
(equal? (intersect '(1 2 3) '()) '())
(equal? (intersect '() '(2 3)) '())
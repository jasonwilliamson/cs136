#lang racket

;; this is a simple testing module for difference.rkt

(require "difference.rkt")

;; Each of the following should produce #t
(equal? (difference '(1 2 3) '(2 3)) '(1))

(equal? (difference '(1 2 3) '(1 2 3 4)) '(4))

(equal? (difference '(1 2 3) '(2 3 4)) '(1 4))
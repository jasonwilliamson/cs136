#lang racket

;; this is a simple testing module for range-missing.rkt

(require "range-missing.rkt")

;; Each of the following should produce #t

(equal? (range-missing '(1 2 4) 2 5) '(3 5))
(equal? (range-missing '(1 2 4 7) 0 5) '(0 3 5))
#lang racket

;;  
;; ****************************************  
;;      Jason Williamson (20552360)  
;;     CS 135 Winter 2015  
;;     Assignment 01, Problem 2 (range-missing.rkt)  
;; ****************************************  


;; A module for producing the list of all integers missing in a range

(provide range-missing)

;; (range-missing lon a b) consumes lon, a (listof Int), a and b, both Ints 
;; where a <= b, producing a (listof Int) of all the integers missing in 
;; the range from [a, b] (inclusive)
;; range-missing (listof Int) Int Int -> (listof Int)
;; requires: a <= b


;;;;;;;;;;;;;;;;;;;;; IPLEMENTATION ;;;;;;;;;;;;;;;;;;;;;;;;

;; (list-range a b) consumes a, an Int, and b, and Int 
;; such that a <= b and producing a list of all integers 
;; from a...b (inclusive)
;; list-range Int Int -> (listof Int)
;; requires: a <= b
(define (list-range a b)
  (cond [(> a b) empty]
        [else (cons a (list-range (add1 a) b))]))

;; see interface above
(define (range-missing lon a b)
  (define lor (list-range a b))
  (define (not-member? v)(false? (member v lon)))
  (filter not-member? lor))
    

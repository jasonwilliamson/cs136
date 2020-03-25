#lang racket

;;  
;; ****************************************  
;;      Jason Williamson (20552360)  
;;     CS 135 Winter 2015  
;;     Assignment 01, Problem 3 (intersect.rkt)  
;; ****************************************  

;; A module for producing elements of an intersection of two lists

(provide intersect)

;; (intersect lst1 lst2) consumes lst1, and lst2, both a 
;; (listof 'Any) and produces a list that contains all of the elements
;; that appear in both lst1 and lst2.
;; intersect (listof 'Any) (listof 'Any) -> (listof 'Any)

;;;;;;;;;;;;;;;;;;;;; IPLEMENTATION ;;;;;;;;;;;;;;;;;;;;;;;;

;; see interface above
(define (intersect lst1 lst2)
  (define (member? x)(not (false? (member x lst2))))
  
  (filter member? lst1))


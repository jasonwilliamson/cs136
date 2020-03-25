#lang racket

;;  
;; ****************************************  
;;      Jason Williamson (20552360)  
;;     CS 135 Winter 2015  
;;     Assignment 01, Problem 4 (difference.rkt)  
;; **************************************** 

;; A module for producing the difference of two lists 

(provide difference)

;; (difference lst1 lst2) consumes lst1 and lst2, both (listof 'Any) 
;; and producing a list that contains the elements of lst1 that are not
;; in lst2, and the elements of lst2 that are not in lst1, whith the elements
;; in the new list keeping there respective order that they appeared in each list
;; ( first lst1's elements then lst2's )
;; difference (listof Any) (listof Any) -> (listof Any)


;;;;;;;;;;;;;;; IMPLEMENTATION ;;;;;;;;;;;;;;;;;;;;;;;

;; see interface above 
(define (difference lst1 lst2)
  (define (not-member-lst2? x)(false? (member x lst2)))
  (define (not-member-lst1? x)(false? (member x lst1)))
  (append (filter not-member-lst2? lst1) (filter not-member-lst1? lst2)))





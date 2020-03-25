#lang racket

;;  
;; ****************************************  
;;      Jason Williamson (20552360)  
;;     CS 135 Winter 2015  
;;     Assignment 01, Problem 1 (name-game.rkt)  
;; ****************************************  


;; A module for formatting strings for the name game

(provide name-game)

;; (name-game name) consumes name, a Str and produces
;; a list of strings, where each string in the list
;; represents a new line in the name game for the specially 
;; formatted for the consumed name (all in lower case)
;; name-game Str -> (listof Str)

;;;;;;;;;;;;;;;;;;;;; IPLEMENTATION ;;;;;;;;;;;;;;;;;;;;;;;;



;; (member? v lst) consumes v, Any and lst, a (listof 'Any) 
;; producing true if v exists within lst, otherwise produces
;; false
;; member? 'Any (listof 'Any) -> Bool
(define (member? v lst)(not (false? (member v lst))))

;;(name-type loc) consumes loc, a (listof Char) and produces a
;; symbol denoting the type of name based on the criteria for the
;; name game. If name begins with either #\b, #\f, #\m then function 
;; returns the value 'b, 'f, 'm respectively. Otherwise function 
;; returns 'norm
;; name-type (listof Char) -> Sym
;; requires: (listof Char) must be all lowercase values
(define (name-type loc)
  (define special-chars (list #\b #\f #\m))
  (cond [(member? (first loc) special-chars)
         (cond [(char=? (first loc) #\b) 'b]
               [(char=? (first loc) #\f) 'f]
               [(char=? (first loc) #\m) 'm])]
        [else 'norm]))


;; (remove-first-consonant loc) consumes loc, a (listof Char)
;; and produces a new (listof Char) with the first consonant
;; sound removed
;; remove-first-consonant (listof Char) -> (listof Char)
(define (remove-first-consonant loc)
  (define vowels (list #\a #\e #\i #\o #\u))
  (define consonents (list #\c #\s #\t #\z))
  (cond [(member? (first loc) vowels) loc]
        [(or (and (member? (first loc) consonents) (char=? #\h (second loc)))
             (and (member? (first loc) (list #\s)) (char=? #\t (second loc))))
         (rest (rest loc))] 
        [else (rest loc)]))


;; (string-by-case line type) consumes line, a Nat and type, a Sym
;; producing a single line string based on the criteria of the name game
;; string-by-case Nat Sym -> Str
;; require: line must be either 1, 2, or 3
(define (string-by-case line type)
  (cond [(= 1 line)
         (cond [(symbol=? type 'b) "bo-"]
               [else "bo-b"])]
        [(= 2 line)
         (cond [(symbol=? type 'f) "fo-"]
               [else "fo-f"])]
        [(= 3 line)
         (cond [(symbol=? type 'm) "mo-"]
               [else "mo-m"])]))


;; see interface above
(define (name-game name)
  ;; convert name to lowercase list of Chars
  (define lowercase-name-lst (map char-downcase (string->list name)))
  ;; case-type will be either 'b 'f 'm 'norm
  (define case-type (name-type lowercase-name-lst))
  ;; string with first consent removed
  (define y-name (list->string (remove-first-consonant lowercase-name-lst)))
  (define x-name (list->string lowercase-name-lst))
  
  (list (string-append x-name ", " x-name ", " (string-by-case 1 case-type) y-name)
        (string-append "banana-fana " (string-by-case 2 case-type) y-name)
        (string-append "fee-fi-" (string-by-case 3 case-type) y-name)
        x-name))
  

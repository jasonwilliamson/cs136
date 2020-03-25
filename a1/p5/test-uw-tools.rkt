#lang racket

;; this is simple testing module for uw-tools.rkt

(require "uw-tools.rkt")

;; Each of the following should produce #t

;; course-desc Str Nat -> Str
(equal? (substring (course-desc "cs" 136) 0 18) "This course builds")
(equal? (substring (course-desc "CS" 136) 0 18) "This course builds")
(equal? (substring (course-desc "Cs" 136) 0 18) "This course builds")

;; online? Str Nat -> Bool
(equal? (online? "cs" 136) #f)
(equal? (online? "math" 135) #t)

;; course-sections Nat Str Nat -> (listof Str)
(equal? (course-sections 1155 "cs" 136) '("LEC 001"
                                          "LEC 002"
                                          "LEC 003"
                                          "TUT 101"
                                          "TUT 102"
                                          "TUT 103"
                                          "TUT 104"
                                          "TST 201"))

;; course-capacity Nat Str Nat -> (listof (list Str Nat Nat))
(equal? (course-capacity 1155 "cs" 136) '(("LEC 001" 75 73) ("LEC 002" 75 75) ("LEC 003" 70 73)))
(course-capacity 1155 "cs" 136)

;; section-info Nat Str Nat Str -> Str
(equal? (section-info 1155 "CS" 136 "LEC 003") "CS 136 LEC 003 13:00-14:20 TTh MC 4045 Holtby,Daniel James")               
;(section-info 1155 "CS" 136 "LEC 002")                 
;(section-info 1155 "CS" 136 "LEC 003")
(section-info 1155 "CS" 136 "LEC 003")

;; next-holiday Str -> Str
(equal? (next-holiday "2014-01-10") "2014-02-17 Family Day")

;; room-status Str Nat Str Str -> Str
(equal? (room-status "MC" 2054 "T" "11:20") "CS 136 Elementary Algorithm Design and Data Abstraction")
(equal? (room-status "MC" 2054 "Th" "11:21") "FREE")
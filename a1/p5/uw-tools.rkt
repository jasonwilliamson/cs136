#lang racket

;;  
;; ****************************************  
;;     Jason Williamson (20552360)  
;;     CS 135 Winter 2015  
;;     Assignment 01, Problem 5 (uw-tools.rkt)  
;; ****************************************  


;; A module that provides more "user friendly" function using
;; the uw-api

(require "uw-api.rkt")

(provide course-desc 
         online? 
         course-sections 
         course-capacity
         section-info
         next-holiday
         room-status)

;; (course-desc subject catalog) consumes subject, a Str that represents
;; the course subject name, and catalog, a Nat, that represents the catalog
;; number of the course. Producing a string with the calendar "description"
;; of the course.
;; course-desc Str Nat -> Str
;; requires: subject must be a valid uWaterloo subject name
;;           catalog must be a valid uWaterloo course number
;; Example:
;; (course-desc "CS" 136) -> "This course builds ..."


;; (online? subject catalog) consumes subject, a Str that represents
;; the course subject name, and catalog, a Nat, that represents the catalog
;; number of the course. Producing true if the course is available online,
;; false otherwise.
;; online? Str Nat -> Bool
;; requires: subject must be a valid uWaterloo subject name
;;           catalog must be a valid uWaterloo course number
;; Example:
;; (online? "CS" 136) -> #f


;; (course-sections term subject catalog) consumes term, a Nat that
;; uses a four digit representation for each term value; subject, a Str that represents
;; the course subject name; catalog, a Nat, that represents the catalog
;; number of the course. Producing a (listof Str) that correspond to the section names
;; for the course.
;; course-sections Nat Str Nat -> (listof Str)
;; requires: term must be valid four digit uWaterloo term representation.
;;           subject must be a valid uWaterloo subject name
;;           catalog must be a valid uWaterloo course number
;; Example:
;; (course-sections 1155 "CS" 136) -> '("LEC 001" "LEC 002" ... "TST 201")


;; (course-capacity term subject catalog) consumes term, a Nat that
;; uses a four digit representation for each term value; subject, a Str that represents
;; the course subject name; catalog, a Nat, that represents the catalog
;; number of the course. Producing a list of lists illustrating how "full" a course is.
;; For each "LEC" section, it must produce a list with 3 items: the section, 
;; the enrollment_capicity and the enrollment_total (number of students in the class).
;; course-capacity Nat Str Nat -> (listof (list Str Nat Nat))
;; requires: term must be valid four digit uWaterloo term representation.
;;           subject must be a valid uWaterloo subject name
;;           catalog must be a valid uWaterloo course number
;; Example:
;; (course-capacity 1155 "CS" 136) -> '(("LEC 001" 75 75) ... ("LEC 003" 71 71))


;; (section-info term subject catalog section) consumes term, a Nat that
;; uses a four digit representation for each term value; subject, a Str that represents
;; the course subject name; catalog, a Nat, that represents the catalog
;; number of the course; section, a Str that represents the section
;; i.e. "LEC 003". Producing a single string with information about a particular
;; section.
;; section-info Nat Str Nat Str -> Str
;; requires: term must be valid four digit uWaterloo term representation.
;;           subject must be a valid uWaterloo subject name
;;           catalog must be a valid uWaterloo course number
;;           section must be a valid uWaterloo section in the form
;;                   i.e. "LEC 003"
;; Example:
;; (section-info 1155 "CS" 136 "LEC 003") -> 
;;   "CS 136 LEC 003 13:00-14:20 TTh MC 4045 Holtby,Daniel James"


;; (next-holiday date) consumes date, a Str and produces a string with the next
;; holiday on or after the date provided. The produced string will contain the 
;; date of the holiday followed by a space and the name of the holiday.
;; next-holiday Str -> Str
;; required: date must be string of the format i.e. "2014-01-10"
;; Example:
;; (next-holiday "2014-01-10") -> "2014-02-16 Family Day"


;; (room-status building room day time) consumes building, a Str, representing a
;; valid uwaterloo building code, i.e. "MC"; room, a Nat, representing a room 
;; number; day, a str representing a day of the week, i.e. "T" for tuesday; time
;; a Str, representing the desired time. Producing a string that displays the
;; course in the room at the day and time, or "FREE" if the room is not in 
;; use. 
;; room-status Str Nat Str Str -> Str
;; require: day must be one of: 
;; Example:
;; (room-status "MC" 2054 "T" "11:20") -> "CS 136 Elementary Algorithm Design and Data Abstraction"
;; (room-status "MC" 2054 "Th" "11:21") -> "FREE"


;;;;;;;;;;;;;;;;;;;;; IPLEMENTATION ;;;;;;;;;;;;;;;;;;;;;;;;

;; (string->upcase str) consumes str, a Str and produces that same string
;; only all characters are uppercase values.
;; string->upcase Str -> Str
(define (string->upcase str)
  (define char-lst (string->list str))
  (define upper-char-lst (foldr (lambda (x y) (cons (char-upcase x) y)) 
                                empty char-lst))
  (list->string upper-char-lst))


;; (al-value-by-key key lst) consumes str, a Str that represents a key in an 
;; AL list, and lst, an association list (AL). Producing the associated value
;; of the provided key.
;; al-value-by-key Str AL -> Any
;; requires: key must be Str,
;;           lst must be of the type 
;;              Lst (AL) is one of:
;;              ⋆ empty
;;              ⋆ (cons (list Str Any) AL)
(define (al-value-by-key key lst)
  (foldr (lambda (x y)
           (cond [(string=? key (first x)) (second x)]
                 [else y])) empty lst))


;; (course-info subject catalog) consumes subject, a Str that represents
;; the course subject name, and catalog, a Nat, that represents the catalog
;; number of the course. Producing a list containing all of the information 
;; for the provided course (an association list). In case of an invalid selection
;; function produces #f
;; course-info Str Nat -> (listof (list Str Any))
;; requires: subject must be a valid uWaterloo subject name
;;           catalog must be a valid uWaterloo course number
(define (course-info subject catalog)
  (uw-api (string-append "/courses/" subject "/" (number->string catalog))))


;; (course-term-info term subject catalog) consumes term, a Nat that
;; uses a four digit representation for each term value; subject, a Str that represents
;; the course subject name; catalog, a Nat, that represents the catalog
;; number of the course. Producing a list containing all of the information for the 
;; class schedule for the given course of a given term (listof (an association list)).
;; In case of an invalid selction function produces #f
;; course-term-info Nat Str Nat -> (listof (listof (list Str Any)))
;; requires: term must be valid four digit uWaterloo term representation.
;;           subject must be a valid uWaterloo subject name
;;           catalog must be a valid uWaterloo course number
(define (course-term-info term subject catalog)
  (uw-api (string-append "/terms/" (number->string term) "/"
                         subject "/" (number->string catalog) "/schedule")))


;; (course-lecture-info term subject catalog) consumes term, a Nat that
;; uses a four digit representation for each term value; subject, a Str that represents
;; the course subject name; catalog, a Nat, that represents the catalog
;; number of the course. Producing a list containing only the section information
;; of that equal to "LEC ###"
;; course-lecture-info Nat Str Nat -> (listof (list Str Any))
;; requires: term must be valid four digit uWaterloo term representation.
;;           subject must be a valid uWaterloo subject name
;;           catalog must be a valid uWaterloo course number
(define (course-lecture-info term subject catalog)
  (define info (course-term-info term subject catalog))
  
  (foldr (lambda (x y) 
           (foldr (lambda (j k)
                    (cond [(and (string=? "section" (first j))
                                (string=? "LEC" (substring (second j) 0 3)))
                           (cons x y)]
                          [else k])) empty x)) empty info))


;; (time-str->number str) consumes str, a Str that represents the time
;; in the format "[hour]:[minute]", based on military time. The function
;; produces the number value with the char #\: being removed.
;; time-str->number Str -> Nat
(define (time-str->number str)
  (define char-lst (string->list str))
  (string->number (list->string 
   (foldr (lambda (x y) 
           (cond [(char=? #\: x) y]
                 [else (cons x y)])) empty char-lst))))


;; (member? v lst) consumes v, of type Any and lst, a (listof Any) and
;; returns true if the element v is contained in lst, otherwise function 
;; returns false.
;; member? Any (listof Any) -> Bool
(define (member? v lst)
  (not (false? (member v lst))))


;; (weekdays->list str) consumes str, a Str containing a the days of the week
;; i.e. "MTWThF". Producing a list containing each individual day in the string
;; as an element i.e. '( "M" "T" "W" "Th" "F" ).
;; weekdays->list Str -> (listof Str)
;; example: (weekdays->list "MTWThF") -> '( "M" "T" "W" "Th" "F" )
(define (weekdays->list str)
  (define mwf-lst (list #\M #\W #\F))
  (define char-lst (string->list str))
    
  (define (format-weekdays lst)
    (cond 
      [(empty? lst) empty]
      [(member? (first lst) mwf-lst) 
       (cons (list->string (list (first lst)))
             (format-weekdays (rest lst)))]
      [(and (and (char=? #\T (first lst))
                 (cons? (rest lst)))
            (char=? #\h (second lst)))
       (cons "Th" (format-weekdays (rest (rest lst))))]
      [else (cons "T" (format-weekdays (rest lst)))]))
    
    (format-weekdays char-lst))


;; see interface above
(define (course-desc subject catalog)
  (define info (course-info subject catalog))
  
  (foldr (lambda (x y) 
           (cond [(string=? "description" (first x)) (second x)]
                 [else y])) empty info))


;; see interface above
(define (online? subject catalog)
  (define info (course-info subject catalog))
  
  (define offerings (foldr (lambda (x y) 
                             (cond [(string=? "offerings" (first x)) (second x)]
                                   [else y])) empty info))
  
  (foldr (lambda (x y) 
           (cond [(string=? "online" (first x)) (second x)]
                 [else y])) empty offerings))


;; see interface above
(define (course-sections term subject catalog)
  (define info (course-term-info term subject catalog))
 
  (foldr (lambda (x y)
           (cons (foldr (lambda (j k)
                          (cond [(string=? "section" (first j))(second j)]
                                [else k])) empty x) y)) empty info))


;; see interface above
(define (course-capacity term subject catalog)
  (define info (course-lecture-info term subject catalog))
  
  (foldr (lambda (x y) 
           (foldr (lambda (j k)
              (cond [(string=? "section" (first j))
                 (cons (list (second j)
                             (foldr (lambda (m n)
                                (cond [(string=? "enrollment_capacity" (first m))
                                       (second m)]
                                      [else n])) empty x)
                             (foldr (lambda (a b)
                                (cond [(string=? "enrollment_total" (first a)) 
                                       (second a)]
                                      [else b])) empty x)) y)]
                    [else k])) empty x)) empty info))
                   

;; see interface above
(define (section-info term subject catalog section)
  ;; convert to uppercase 
  (define section-upper (string->upcase section))
  ;; list of section LEC's only
  (define info (course-lecture-info term subject catalog))
  
  ; single section list
  (define section-list 
    (first (filter cons? 
      (foldr (lambda (x y)
        (cons (foldr (lambda (j k)
             (cond [(and (string=? "section" (first j))
                        (string=? section-upper (second j))) x]
                   [else k])) empty x) y)) empty info)))) 
  
  ;; classes list from specific section
  (define classes-info (foldr (lambda (x y) 
                             (cond [(string=? "classes" (first x))
                                    (first (second x))]
                                   [else y])) empty section-list))
   
  ;; date info from classes 
  (define date-info (al-value-by-key "date" classes-info))
  ;; catalog as string
  (define catalog-str (number->string catalog))
  ;; other information under date info
  (define start-time (al-value-by-key "start_time" date-info))
  (define end-time (al-value-by-key "end_time" date-info))
  (define weekdays (al-value-by-key "weekdays" date-info))
  ;; building-information
  (define building-info (al-value-by-key "location" classes-info))
  (define building (al-value-by-key "building" building-info))
  (define room (al-value-by-key "room" building-info))
  ; instructor-information
  (define instructor (first (al-value-by-key "instructors" classes-info)))
  ; format output
  (string-append (string->upcase subject) " " catalog-str " " 
                 (string->upcase section) " " start-time "-"
                 end-time " " weekdays " " building " " room " " instructor))
  

;; see interface above
(define (next-holiday date)
  (define holiday-list (uw-api "/events/holidays"))
  (define provided-year (string->number (substring date 0 4)))
  (define provided-month (string->number (substring date 5 7)))
  (define provided-day (string->number (substring date 8 10)))
  
  (foldr (lambda (x y)
           (define d (second (first x)))
           (define year (string->number (substring d 0 4)))
           (define month (string->number (substring d 5 7)))
           (define day (string->number (substring d 8 10)))
           (cond [(and (= provided-year year)
                       (and (<= provided-month month)
                            (<= provided-day day))) 
                  (string-append d " " (second (second x)))]
                 [else y])) empty holiday-list))
                       
  
;; see above interface
(define (room-status building room day time)
  (define rooom-str (number->string room))
  (define time-num (time-str->number time))
  (define building-info (uw-api (string-append "/buildings/" 
                                               building "/"
                                               rooom-str
                                               "/courses" )))
  ;; narrowing down possible conflicts
  ;; by date here..
  (define con-lst
    (foldr (lambda (x y)
             (cons 
              (cond [(member? day
                     (weekdays->list (al-value-by-key "weekdays" x))) x]
                    [else empty]) y)) empty building-info))
  ;; and removing empty lists
  (define possible-conflict-lst (filter (lambda (x)
                                        (not (empty? x))) con-lst))
  
  ;; status will either be empty or the class description
  (define status
  (foldr (lambda (x y)
         (define start (time-str->number (al-value-by-key "start_time" x)))
         (define end (time-str->number (al-value-by-key "end_time" x)))
         (cond [(and (>= time-num start)
                     (<= time-num end)) 
                (string-append
                (al-value-by-key "subject" x)
                " "
                (al-value-by-key "catalog_number" x)
                " "
                (al-value-by-key "title" x))]
               [else y])) empty possible-conflict-lst))
  
  (cond [(empty? status) "FREE"]
        [else status])) 






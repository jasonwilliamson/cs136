// =======================================
// = CS136, S15: Assignment 5, Problem 6 =
// = =================================== =
// = Author: Salmon [12345678]           =
// =======================================

// Interface for a C module that provides functions to work with various times.

#include <stdbool.h>

// A valid time is when:
// - 0 <= hour < 24,
// - 0 <= minute < 60, and
// - 0 <= second < 60.
// You can assume that time_equal, time_tick, time_twelve, and time_print are
// passed valid struct times.
struct time {
    int hour,
    minute,
    second;
};

// T(hour, minute, second) constructs a valid time for the 24-hour clock.
//       if given an invalid time in the 24-hour clock then return 00:00:00 (midnight).
struct time T(int hour, int minute, int second);

// time_equal(t1, t2) determines if *t1 and *t2 are the same time.
// requires:  t1 and t2 are not NULL
bool time_equal(struct time *t1, struct time *t2);

// time_tick(t) ticks the time t by one second.
// requires:  t is not NULL
// effects: increases the time t by one second. If that is not a valid time, resets
//       the seconds and increases the minutes. If that is not a valid time, resets
//       the minutes and increases the hours. If that is not a valid time then
//       it sets t to be 00:00:00 (midnight).
void time_tick(struct time *t);

// time_twelve(&t) outputs t converted to the 12-hour clock.
// requires:  t is not NULL
// effects: prints the time t converted to the 12-hour clock.
void time_twelve(struct time *t);

// time_print(t) outputs t as a 24-hour clock.
// requires:  t is not NULL
// effects: prints the time t as a 24-hour clock.
void time_print(struct time *t);


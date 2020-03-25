// =======================================
// = CS136, W14: Assignment 6, Problem 1 =
// = =================================== =
// = Author: The Manufacturer [12345678] =
// =======================================

// Interface for the reservation C module. Provides functions to interact with
// aircraft manifests.

#include <stdbool.h>

// An aircraft manifest contains the number of first class and economy class seats.
// The seats are ordered by first class seats followed by the economy class seats.
// If a seat is available its value is false, otherwise if a seat is
// already taken (booked) its value is true.
//
// Example:
// If seats[4] = { false, true, false, false }, num_fc = 1 and num_ec = 3 then
// seats[0] is first class and seats[1] through seats[3] are economy class.
//
// For the following functions, you can assume:
// * that there will be at most 100 seats
// * the manifest is valid:
//   num_fc >= 0, num_ec >= 0, num_fc + num_ec <= 100
struct manifest {
    bool seats[100];
    int num_fc;       // number of first class seats
    int num_ec;       // number of economy class seats
};

// M(num_fc, num_ec) Returns a new manifest with num_fc First Class seats and
// num_ec Economy Class seats.
// requires:  num_fc >= 0, num_ec >= 0, num_fc + num_ec <= 100
struct manifest M(int num_fc, int num_ec);

// get_available_seats_fc(&man) Returns the number of available First Class
// seats from the manifest.
// requires:  man is not NULL and a valid manifest (see above)
int get_available_seats_fc(struct manifest *man);

// get_available_seats_ec(&man) Returns the number of available Economy
// Class seats from the manifest.
// requires: man is not NULL and a valid manifest (see above)
int get_available_seats_ec(struct manifest *man);

// book_seat_fc(&man) Attempts to book the first available First Class seat.
//   If the attempt is successful returns the seatnumber booked, otherwise
//   returns -1 if the booking was unsuccessful.
// requires: man is not NULL and a valid manifest (see above)
// effects: sets the seat at the returned index to true, to indicate it is booked.
int book_seat_fc(struct manifest *man);

// book_seat_ec(&man) Attempts to book the first available Economy Class seat.
//   If the attempt is successful returns the seatnumber booked, otherwise
//   returns -1 if the booking was unsuccessful.
// requires: man is not NULL and a valid manifest (see above)
// effects: sets the seat at the returned index to true, to indicate it is booked.
int book_seat_ec(struct manifest *man);

// reset_manifest(&man) Clears the aircraft manifest.
// requires: man is not NULL and a valid manifest (see above)
// effects: sets all of the elements of man->seats to be false (available).
void reset_manifest(struct manifest *man);


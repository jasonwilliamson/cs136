// module that provides the function strappend

// strappend(s1,s2) returns a NEW string that contains all of
//   the characters from s1, followed by all of the characters from s2
// requires: s1, s2 are null terminated strings
// effects: returns a new dynamically allocated string.
//          caller must eventually free returned string.
// time: O(n+m), where n is strlen(s1) and m is strlen(s2)
char *strappend(const char *s1, const char *s2);

// NOTE: you are NOT allowed to use string.h


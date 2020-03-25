#include <assert.h>
#include "count.h"

int main(void) {
    Count c = create_Count();
    next(c,1);
    next(c,2);
    next(c,1);
    next(c,3);
    next(c,7);
    next(c,1);
    next(c,2);
    next(c,3);
    next(c,1);
    next(c,1);
    assert(total(c) == 10);
    assert(unique(c) == 4);
    assert(count(c,1) == 5);
    assert(count(c,6) == 0);
    assert(count(c,7) == 1);
    assert(mostfreq(c) == 1);
    stats(c);
    destroy_Count(c);
    
    
    Count c2 = create_Count();
    next(c2, 5);
    next(c2, 3);
    next(c2, 8);
    next(c2, 1);
    next(c2, 2);
    next(c2, 8);
    next(c2, 6);
    next(c2, 2);
    next(c2, 13);
    assert(total(c2) == 9);
    assert(unique(c2) == 7);
    assert(count(c2,1) == 1);
    assert(count(c2,11) == 0);
    assert(count(c2,2) == 2);
    assert(mostfreq(c2) == 8);
    stats(c2);
    destroy_Count(c2);

    
}


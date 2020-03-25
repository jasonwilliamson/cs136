#include <assert.h>
#include "count.h"
#include <stdio.h>

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
    printf("total == %d\n", total(c));
    assert(total(c) == 10);
    printf("unique == %d\n",unique(c));
    assert(unique(c) == 4);
    assert(count(c,1) == 5);
    assert(count(c,6) == 0);
    assert(count(c,7) == 1);
    assert(mostfreq(c) == 1);
    stats(c);
    destroy_Count(c);
}


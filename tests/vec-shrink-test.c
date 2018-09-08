#include "suite.h"
#include "vec.h"

void vec_shrink_test(CuTest * tc)
{
    struct vec v = vec_new(sizeof(int));
    int val = 123;
    v.push_back(&v, &val);
    CuAssertIntEquals(tc, 1, v._capacity);
    CuAssertIntEquals(tc, 1, v._size);

    v.reserve(&v, 16);
    CuAssertIntEquals(tc, 16, v._capacity);
    CuAssertIntEquals(tc, 1, v._size);
    
    v.shrink(&v);
    CuAssertIntEquals(tc, 1, v._capacity);
    CuAssertIntEquals(tc, 1, v._size);

    vec_delete(&v);
}


int main(void) { return execute(vec_shrink_test);}
#include "suite.h"
#include "vec.h"

void vec_reserve_test(CuTest * tc)
{
    struct vec v = vec_new(sizeof(int));
    CuAssertIntEquals(tc, 1, v._capacity);
    CuAssertIntEquals(tc, 0, v._size);
    CuAssertIntEquals(tc, sizeof(int), v._elemsize);
    v.reserve(&v, 16);
    CuAssertIntEquals(tc, 16, v._capacity);
    CuAssertIntEquals(tc, 0, v._size);

    vec_delete(&v);
}


int main(void) { return execute(vec_reserve_test);}
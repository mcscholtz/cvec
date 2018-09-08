#include "suite.h"
#include "vec.h"

void vec_frontback_test(CuTest * tc)
{
    struct vec v = vec_new(sizeof(int));
    int val = 1;
    int ret;
    v.push_back(&v,&val);
    v.back(&v, &ret);
    CuAssertIntEquals(tc, 1, ret);
    v.front(&v, &ret);
    CuAssertIntEquals(tc, 1, ret);
    
    val = 2;
    v.push_back(&v,&val);
    v.back(&v, &ret);
    CuAssertIntEquals(tc, 2, ret);
    
    val = 3;
    v.push_back(&v,&val);
    v.back(&v, &ret);
    CuAssertIntEquals(tc, 3, ret);

    val = 4;
    v.push_back(&v,&val);
    v.back(&v, &ret);
    CuAssertIntEquals(tc, 4, ret);

    v.erase(&v,0);
    v.front(&v, &ret);
    CuAssertIntEquals(tc, 2, ret);

    v.erase(&v,0);
    v.front(&v, &ret);
    CuAssertIntEquals(tc, 3, ret);

    v.erase(&v,0);
    v.front(&v, &ret);
    CuAssertIntEquals(tc, 4, ret);

    CuAssertIntEquals(tc, 4, v._capacity);
    CuAssertIntEquals(tc, 1, v._size);

    vec_delete(&v);
}


int main(void) { return execute(vec_frontback_test);}
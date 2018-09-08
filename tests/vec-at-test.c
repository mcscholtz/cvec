#include "suite.h"
#include "vec.h"

void vec_at_test(CuTest * tc)
{
    struct vec v = vec_new(sizeof(int));
    int val = 1;
    v.push_back(&v,&val);
    CuAssertIntEquals(tc, 1, v._size);
    CuAssertIntEquals(tc, 1, v._capacity);
    
    val = 2;
    v.push_back(&v,&val);
    CuAssertIntEquals(tc, 2, v._size);
    CuAssertIntEquals(tc, 2, v._capacity);
    
    val = 3;
    v.push_back(&v,&val);
    CuAssertIntEquals(tc, 3, v._size);
    CuAssertIntEquals(tc, 4, v._capacity);

    val = 4;
    v.push_back(&v,&val);
    CuAssertIntEquals(tc, 4, v._size);
    CuAssertIntEquals(tc, 4, v._capacity);

    int ret;
    v.at(&v, 0, &ret);
    CuAssertIntEquals(tc, 1, ret);
    CuAssertIntEquals(tc, 4, v._size);
    CuAssertIntEquals(tc, 4, v._capacity);


    vec_delete(&v);
}


int main(void) { return execute(vec_at_test);}
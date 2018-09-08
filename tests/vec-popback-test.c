#include "suite.h"
#include "vec.h"

void vec_popback_test(CuTest * tc)
{
    struct vec v = vec_new(sizeof(int));
    for(int i = 0; i<8;i++) {
        v.push_back(&v,&i);
    }
    CuAssertIntEquals(tc, 8, v._size);
    CuAssertIntEquals(tc, 8, v._capacity);

    int res;
    for(int i = 0; i<8;i++) {
        v.pop_back(&v,&res);
        CuAssertIntEquals(tc, 7-i, v._size);
        CuAssertIntEquals(tc, 8, v._capacity);
        CuAssertIntEquals(tc, 7-i, res);
    }
    
    vec_delete(&v);
}


int main(void) { return execute(vec_popback_test);}
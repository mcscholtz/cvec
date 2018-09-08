#include "suite.h"
#include "vec.h"
#include <stdio.h>

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

    for(int i = 0; i < 4; i++){
        int ret;
        v.at(&v,i,&ret);
        printf("[%d]:%d\n",i,ret);
    }

    v.erase(&v, 0);
    CuAssertIntEquals(tc, 3, v._size);
    CuAssertIntEquals(tc, 4, v._capacity);
    v.erase(&v, 2);
    CuAssertIntEquals(tc, 2, v._size);
    CuAssertIntEquals(tc, 4, v._capacity);
    v.erase(&v, 1);
    CuAssertIntEquals(tc, 1, v._size);
    CuAssertIntEquals(tc, 4, v._capacity);


    for(int i = 0; i < v._size; i++){
        int ret;
        v.at(&v,i,&ret);
        printf("[%d]:%d\n",i,ret);
    }

    int ret;
    v.at(&v, 0, &ret);
    CuAssertIntEquals(tc, 2, ret);
    CuAssertIntEquals(tc, 1, v._size);
    CuAssertIntEquals(tc, 4, v._capacity);


    vec_delete(&v);
}


int main(void) { return execute(vec_at_test);}
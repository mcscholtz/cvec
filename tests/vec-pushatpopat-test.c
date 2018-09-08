#include "suite.h"
#include "vec.h"

void vec_pushatpopat_test(CuTest * tc)
{
    struct vec v = vec_new(sizeof(int));
    int val = 1;
    v.push_at(&v, 0,&val); //first item in vec
    CuAssertIntEquals(tc,1,v._size);
    CuAssertIntEquals(tc,1,v._capacity);

    val = 2;
    v.push_at(&v, 1,&val); //at back of vec
    CuAssertIntEquals(tc,2,v._size);
    CuAssertIntEquals(tc,2,v._capacity);

    val = 3;
    v.push_at(&v, 0,&val); //front item
    CuAssertIntEquals(tc,3,v._size);
    CuAssertIntEquals(tc,4,v._capacity);

    val = 4;
    v.push_at(&v, 1,&val); //in middle of vec
    CuAssertIntEquals(tc,4,v._size);
    CuAssertIntEquals(tc,4,v._capacity);

    int ret;
    v.at(&v,0, &ret);
    CuAssertIntEquals(tc,3,ret);
    v.at(&v,1, &ret);
    CuAssertIntEquals(tc,4,ret);
    v.at(&v,2, &ret);
    CuAssertIntEquals(tc,1,ret);
    v.at(&v,3, &ret);
    CuAssertIntEquals(tc,2,ret);

    v.pop_at(&v,0, &ret); //first item
    CuAssertIntEquals(tc,3,ret);
    CuAssertIntEquals(tc,3,v._size);
    v.pop_at(&v,1, &ret); //middle item
    CuAssertIntEquals(tc,1,ret);
    CuAssertIntEquals(tc,2,v._size);
    v.pop_at(&v,1, &ret); //last item
    CuAssertIntEquals(tc,2,ret);
    CuAssertIntEquals(tc,1,v._size);
    v.pop_at(&v,0, &ret); //last item in vec
    CuAssertIntEquals(tc,4,ret);
    CuAssertIntEquals(tc,0,v._size);


    vec_delete(&v);
}


int main(void) { return execute(vec_pushatpopat_test);}
#include "suite.h"
#include "source.h"

void hello_test(CuTest * tc)
{
    int h = hello();
    CuAssertIntEquals(tc, 1, h);
}


int main(void) { return execute(hello_test);}
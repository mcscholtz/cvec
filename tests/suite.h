#ifndef __SUITE_H
#define __SUITE_H
#include "cutest.h"
#include <stdlib.h>

int execute(void(*test)(CuTest *tc));

#endif
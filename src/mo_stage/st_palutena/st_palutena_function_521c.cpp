#include <types.h>
#pragma force_active on

extern "C" void fn_67_521C(void *self, unsigned int value)
{
    unsigned int *field = (unsigned int *)((char *)self + 8);
    *field = __rlwimi(*field, value, 28, 0, 3);
}

#include <types.h>
#pragma force_active on

extern "C" {

unsigned fn_27_198ED4(const void *arg)
{
    const unsigned *p = (const unsigned *)((const char *)arg + 8);
    unsigned word = *p;
    return (word >> 25) & 0x1;
}

}

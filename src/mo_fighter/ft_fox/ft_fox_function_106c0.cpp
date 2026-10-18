#include <stddef.h>
#pragma force_active on

extern "C" {

void __dl__FPv(void*);

void* fn_97_106C0(void* ptr, short count)
{
    void* result = ptr;
    if (ptr != 0 && count > 0) {
        __dl__FPv(ptr);
    }
    return result;
}

}

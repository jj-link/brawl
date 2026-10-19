#include <types.h>
#pragma force_active on

void operator delete(void* p);

extern "C" void* fn_27_30C3EC(void* p, s32 n) {
    if (p != nullptr && n > 0) {
        operator delete(p);
    }
    return p;
}

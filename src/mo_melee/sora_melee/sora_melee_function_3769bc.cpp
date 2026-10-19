#include <types.h>
#pragma force_active on

extern "C" void* fn_27_3769BC(void* p, s32 size) {
    if (p != nullptr && size > 0) {
        operator delete(p);
    }
    return p;
}

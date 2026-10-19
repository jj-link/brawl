#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_2B1468(void* p, s32 size) {
    if (p != nullptr && size > 0) {
        ::operator delete(p);
    }
    return p;
}
}

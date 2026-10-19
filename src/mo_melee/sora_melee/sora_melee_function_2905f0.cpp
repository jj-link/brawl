#include <types.h>
#pragma force_active on

extern "C" void* fn_27_2905F0(void* p, s32 size) {
    if (p != nullptr) {
        if (size > 0) {
            ::operator delete(p);
        }
    }
    return p;
}

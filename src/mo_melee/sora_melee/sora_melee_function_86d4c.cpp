#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_86D4C(void* p, s32 n) {
    if (p != nullptr && n > 0) {
        ::operator delete(p);
    }
    return p;
}
}

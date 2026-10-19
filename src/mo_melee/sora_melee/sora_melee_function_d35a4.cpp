#include <types.h>
#pragma force_active on

void operator delete(void* p);

extern "C" void* fn_27_D35A4(void* p, s32 n) {
    if (p != nullptr) {
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

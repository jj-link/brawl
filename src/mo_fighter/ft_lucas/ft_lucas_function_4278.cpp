#include <types.h>
#pragma force_active on

void operator delete(void* p);

extern "C" void* fn_114_4278(void* p, s16 flag) {
    if (p != 0 && flag > 0) {
        operator delete(p);
    }
    return p;
}

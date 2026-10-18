#include <types.h>
#pragma force_active on

extern "C" void* fn_114_5B8C(void* p, s16 flag) {
    if (p != 0 && flag > 0) {
        ::operator delete(p);
    }
    return p;
}

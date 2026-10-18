#include <types.h>
#pragma force_active on

extern "C" void* fn_41_2890(void* p, s16 flag) {
    if (p != nullptr && flag > 0) {
        ::operator delete(p);
    }
    return p;
}

#include <types.h>
#pragma force_active on

extern "C" void* fn_41_FC08(void* p, s16 n) {
    if (p != nullptr && n > 0) {
        operator delete(p);
    }
    return p;
}

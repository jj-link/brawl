#include <types.h>

#pragma force_active on

extern "C" void fn_802AA2A4(u32* arg0) {
    register u32 t;
    asm {
        mftb t
    }
    arg0[1] = t;
}

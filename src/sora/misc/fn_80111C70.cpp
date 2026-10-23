#include <types.h>
#pragma force_active on

union C {
    u32 w;
    u16 h[2];
};

extern "C" C fn_80111C70(const s32* arg0, s32 arg1) {
    C c;
    c.w = 0xFFFFu;
    c.h[0] = *(const u16*)arg0;
    c.h[1] = (u16)(((u32)arg1 - (u32)arg0[5]) / 18u);
    return c;
}

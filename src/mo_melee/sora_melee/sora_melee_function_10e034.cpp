#include <types.h>
#pragma force_active on

struct UnkReset {
    u8 pad0[4];
    s32 m4;
    s16 m8;
    s16 mA;
};

extern "C" {
void fn_27_10E034(UnkReset* p) {
    p->m4 = -1;
    p->m8 = 0;
    p->mA = -1;
}
}

#include <types.h>
#pragma force_active on

struct FnStruct27 {
    u8 pad[4];
    s32 m4;
    s16 m8;
    s16 mA;
};

extern "C" {
void fn_27_EF0E4(FnStruct27* p) {
    p->m4 = -1;
    p->m8 = 0;
    p->mA = -1;
}
}

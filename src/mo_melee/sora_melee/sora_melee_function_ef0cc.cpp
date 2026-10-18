#include <types.h>
#pragma force_active on

struct fn_27_EF0CC_Obj {
    u8 pad[4];
    s32 m4;
    s16 m8;
    s16 ma;
};

extern "C" void fn_27_EF0CC(fn_27_EF0CC_Obj* p) {
    p->m4 = -1;
    p->m8 = 0;
    p->ma = -1;
}

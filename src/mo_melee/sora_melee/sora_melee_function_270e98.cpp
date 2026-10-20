#include <types.h>
#pragma force_active on

struct fn_27_270E98_Obj {
    u32 unk0;
    s32 unk4;
};

extern "C" bool fn_27_270E98(fn_27_270E98_Obj* p) {
    return p->unk4 == 2;
}

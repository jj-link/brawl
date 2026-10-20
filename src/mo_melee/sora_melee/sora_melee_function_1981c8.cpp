#include <types.h>
#pragma force_active on

struct Fn27Obj {
    u32 unk0;
    u32 unk4;
    s32 pad8 : 4;
    s32 val : 4;
};

extern "C" s32 fn_27_1981C8(Fn27Obj* p) {
    return p->val;
}

#include <types.h>
#pragma force_active on

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC;
};

extern "C" s32 fn_80166E18(void* a, s32 b, s32 c, u8 d, s32 e);

extern "C" void fn_80166DD0(void* a, Obj* obj) {
    obj->unk0 += fn_80166E18(a, obj->unk4, obj->unk8, obj->unkC, 0);
}

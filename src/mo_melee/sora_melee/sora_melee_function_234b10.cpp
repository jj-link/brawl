#include <types.h>
#pragma force_active on

struct fn_27_234B10_Obj {
    u32 unk0;
    u32 unk4;
    u8* unk8;
    u8 unkC;
};

extern "C" void fn_27_234B10(fn_27_234B10_Obj* obj) {
    if (obj->unkC == 0) {
        obj->unk8[0] = 0;
    }
}

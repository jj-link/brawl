#include <types.h>
#pragma force_active on

struct fn_27_D9188_Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" {
void* fn_27_D9188(fn_27_D9188_Obj* p, s32 idx)
{
    s32 i = (p->unk8 >> 27) + idx;
    if (i >= 9) {
        i -= 9;
    }
    return (char*)p + 0xc + i * 0x30;
}
}

#include <types.h>
#pragma force_active on

extern "C" u8 lbl_27_data_35338[];

struct fn27Obj {
    void *unk0;
    void *unk4;
    u32 unk8;
};

extern "C" void fn_27_1A4D6C(fn27Obj *p)
{
    u32 v = p->unk8;
    p->unk0 = lbl_27_data_35338;
    p->unk4 = lbl_27_data_35338 + 0x48;
    p->unk8 = v & 0xFFFF;
}

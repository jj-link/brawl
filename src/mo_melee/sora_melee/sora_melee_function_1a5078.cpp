#include <types.h>
#pragma force_active on

struct fn_27_1A5078_obj {
    void *unk0;
    void *unk4;
    u32 unk8;
};

extern "C" {
extern u8 lbl_27_data_35068[];

void fn_27_1A5078(fn_27_1A5078_obj *p)
{
    p->unk0 = lbl_27_data_35068;
    p->unk4 = lbl_27_data_35068 + 0x48;
    p->unk8 = p->unk8 & 0xFFFF;
}
}

#pragma force_active on
typedef unsigned int u32;

struct fn_27_D2F78_obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
void fn_27_D2F78(fn_27_D2F78_obj *p)
{
    p->unk8 &= ~0x00400000;
}
}

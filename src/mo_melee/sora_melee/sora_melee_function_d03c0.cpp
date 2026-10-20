#pragma force_active on
typedef unsigned int u32;

struct fn_27_D03C0_obj {
    u32 unk0;
    u32 unk4;
    u32 hi : 14;
    u32 field : 7;
    u32 lo : 11;
};

extern "C" {
void fn_27_D03C0(fn_27_D03C0_obj* p, u32 v)
{
    p->field = v;
}
}

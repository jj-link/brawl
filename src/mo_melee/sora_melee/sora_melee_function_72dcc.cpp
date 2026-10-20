#pragma force_active on
typedef unsigned int u32;

struct fn_27_72DCC_Bits {
    u32 unk0;
    u32 unk4;
    u32 top : 6;
    u32 rest : 26;
};

extern "C" void fn_27_72DCC(fn_27_72DCC_Bits* p, u32 v)
{
    p->top = v;
}

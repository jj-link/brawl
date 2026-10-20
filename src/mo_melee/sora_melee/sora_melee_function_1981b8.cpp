#pragma force_active on
typedef unsigned int u32;

struct BitsHolder {
    u32 unk0;
    u32 unk4;
    u32 top : 4;
    u32 rest : 28;
};

extern "C" void fn_27_1981B8(BitsHolder *p, u32 v)
{
    p->top = v;
}

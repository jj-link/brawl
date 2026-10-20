#pragma force_active on
typedef unsigned int u32;

struct FnObj27 {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_1D5ADC(FnObj27* p)
{
    p->flags &= ~0x00010000;
}

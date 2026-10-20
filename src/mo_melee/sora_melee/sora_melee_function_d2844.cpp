#pragma force_active on
typedef unsigned int u32;

struct FnObj27 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
void fn_27_D2844(FnObj27 *p)
{
    p->unk8 |= 0x10000;
}
}

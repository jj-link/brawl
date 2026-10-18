#include <types.h>
#pragma force_active on

struct FnZeroBlock {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
};

extern "C" void fn_27_7B3AC(FnZeroBlock* p)
{
    p->unk8 = 0;
    p->unkC = 0;
    p->unk10 = 0;
    p->unk14 = 0;
}

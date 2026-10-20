#include <types.h>
#pragma force_active on

struct FnBits {
    u32 unk0;
    u32 unk4;
    u32 hi : 3;
    u32 mid : 3;
    u32 lo : 26;
};

extern "C" void fn_27_198D24(FnBits* p, u32 v)
{
    p->mid = v;
}

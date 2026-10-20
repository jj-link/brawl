#include <types.h>
#pragma force_active on

struct FlagsBF {
    u32 a : 3;
    u32 f : 3;
    u32 rest : 26;
};

extern "C" void fn_27_C9C40(u8* p, u32 v) {
    FlagsBF* w = (FlagsBF*)(p + 8);
    w->f = v;
}

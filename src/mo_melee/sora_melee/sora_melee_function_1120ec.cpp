#include <types.h>
#pragma force_active on

struct FnInner {
    char pad[0x20];
    u8 a : 1;
    u8 flag : 1;
    u8 rest : 6;
};

struct FnOuter {
    FnInner *inner;
};

extern "C" {
bool fn_27_1120EC(FnOuter *p)
{
    return p->inner->flag;
}
}

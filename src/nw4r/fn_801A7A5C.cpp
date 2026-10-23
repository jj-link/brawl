#include <types.h>
#pragma force_active on

struct Fn801A7A5CInner {
    u8 pad[0x70];
    u32 flags;
    u8 pad2[0x34];
    u32 unkA8;
    u8 pad3[0x8];
    float unkB4;
    float unkB8;
    float unkBC;
    float unkC0;
    float unkC4;
    float unkC8;
};

struct Fn801A7A5COuter {
    Fn801A7A5CInner* inner;
};

extern "C" void fn_801A7A5C(Fn801A7A5COuter* p, float f1, float f2, float f3, float f4, float f5, float f6) {
    Fn801A7A5CInner* inner = p->inner;
    if (inner == 0) {
        return;
    }
    inner->unkA8 = 1;
    inner->unkBC = f1;
    inner->unkC0 = f2;
    inner->unkC4 = f3;
    inner->unkC8 = f4;
    inner->unkB4 = f5;
    inner->unkB8 = f6;
    inner->flags = (inner->flags & 0xFFFFFF0F) | 0x40;
}

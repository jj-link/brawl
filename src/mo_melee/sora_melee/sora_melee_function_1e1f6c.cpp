#include <types.h>
#pragma force_active on

struct FnTriple {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
};

extern "C" void fn_27_1E1F6C(FnTriple* p, u32 v) {
    p->unk10 = v;
    p->unkC = v;
    p->unk8 = v;
}

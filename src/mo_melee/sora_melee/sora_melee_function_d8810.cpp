#include <types.h>
#pragma force_active on

struct FnOut {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    s16 unkC;
    s16 unkE;
};

extern "C" void fn_27_D8810(FnOut* out, const u32* in, u32 c, const s16* p, s16 e) {
    out->unk0 = in[0];
    out->unk4 = in[1];
    out->unk8 = c;
    out->unkC = *p;
    out->unkE = e;
}

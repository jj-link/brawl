#include <types.h>
#pragma force_active on

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8_hi : 5;
    u32 unk8_mid : 5;
    u32 unk8_lo : 22;
} FnState;

extern "C" void fn_27_1CFBF4(FnState* p, u32 v) {
    p->unk8_mid = v;
}

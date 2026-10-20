#include <types.h>
#pragma force_active on

struct Sora27_19BC68 {
    u32 unk0;
    u32 unk4;
    unsigned : 15;
    unsigned value : 1;
};

extern "C" {
u16 fn_27_19BC68(const Sora27_19BC68* p) {
    return p->value;
}
}

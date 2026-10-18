#include <types.h>
#pragma force_active on

struct PeachArrayQuad {
    u32 c;
    u32 a;
    u32 b;
    u32 arr[4];
};

extern "C" {
u32* fn_103_F720(PeachArrayQuad* quad, s32 index) {
    return &quad->arr[index];
}
}

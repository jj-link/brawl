#include <types.h>
#pragma force_active on

extern "C" {
u32 fn_27_1D09DC(u32* self) {
    u32 val = self[2];
    return (val >> 19) & 1;
}
}

#include <types.h>
#pragma force_active on

extern "C" {
u32 fn_27_3241FC(u32* p, u32, u32 idx) {
    return p[(idx - p[6]) + 11];
}
}

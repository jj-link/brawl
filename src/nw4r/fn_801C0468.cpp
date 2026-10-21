#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_80202614(s32);
}

extern "C" s32 fn_801C0468(s32 arg0) {
    return (fn_80202614(arg0 + 0x30) + 0x87) & 0xFFFFFFE0;
}

#include <types.h>
#pragma force_active on

extern "C" {
extern int lbl_80408488[];

u32 fn_800C9B14(u32 idx) {
    u8* p = (u8*)lbl_80408488 + idx * 8;
    u32 b = (p[4] >> 7) & 1;
    return (-b | b) >> 31;
}
}

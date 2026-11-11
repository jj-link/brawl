#include <types.h>
#pragma force_active on
extern "C" u8 lbl_80409798[];
extern "C" s32 fn_8015B3CC(char* base, s32 idx)
{
    u8 val;
    s32 count = 0;
    if (idx < 0 || idx > 0x2B) val = 0x23;
    else val = lbl_80409798[idx];
    s32* p = (s32*)(base + val * 0x280);
    for (int i = 0; i < 40; i++) {
        if (p[1] == -1) break;
        count++;
        p += 4;
    }
    return count;
}
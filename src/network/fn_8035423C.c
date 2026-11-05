#include <types.h>
#include <string.h>
#pragma force_active on

extern char lbl_8048DC08[];

s32 fn_8035423C(void* arg0, void* arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6) {
    s32 i;
    s32 count;

    *(u32*)(lbl_8048DC08 + 0xC) = 0;
    if (strlen((char*)arg0) >= 0x20) {
        return 0;
    }
    if (strlen((char*)arg1) != 0x14) {
        return 0;
    }
    if ((arg2 - 5) & 7) {
        return 0;
    }
    if (!(arg3 & 1)) {
        return 0;
    }
    count = 0;
    for (i = 0; i < 32; i++) {
        if (((arg4 >> i) & 1) == 1) {
            count++;
        }
    }
    if (count != 1) {
        return 0;
    }
    memcpy(lbl_8048DC08 + 0x10, arg0, 0x20);
    memcpy(lbl_8048DC08 + 0x30, arg1, 0x14);
    *(s32*)(lbl_8048DC08 + 0x44) = arg2;
    *(s32*)(lbl_8048DC08 + 0x48) = arg3;
    *(u32*)(lbl_8048DC08 + 0x4C) = arg4;
    *(s32*)(lbl_8048DC08 + 0x50) = arg5;
    *(u32*)(lbl_8048DC08 + 0xC) = 1;
    return 1;
}

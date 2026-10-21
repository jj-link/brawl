#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern char lbl_80529CF8[];

s32 fn_8023F454(u32 arg0) {
    char *p;
    s32 i;
    s32 idx;

    p = lbl_80529CF8;
    for (i = 0, idx = 0; i < 2; i++) {
        if (*(u32 *)(p + 0x192C) == arg0) {
            *(u32 *)(lbl_80529CF8 + idx * 4 + 0x192C) = 0;
            return 1;
        }
        p += 4;
        idx++;
    }
    return 0;
}

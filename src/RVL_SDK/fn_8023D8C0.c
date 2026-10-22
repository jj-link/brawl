#pragma force_active on
typedef signed int s32;
typedef unsigned char u8;

extern char lbl_80529CF8[];

s32 fn_8023D8C0(s32 arg0, u8 *arg1, s32 arg2) {
    s32 i;
    char *p;

    if (arg0 & 4) {
        u8 t = *arg1;
        if (t >= 2) {
            return 5;
        }
        *(u8 *)(lbl_80529CF8 + (t << 3) + 0x558) = 0;
        return 0;
    }

    p = lbl_80529CF8;
    for (i = 0; i < 2; p += 8, i++) {
        if (*(u8 *)(p + 0x558) == 0) {
            if (arg0 & 2) {
                if (arg2 == 0) {
                    return 5;
                }
                *(s32 *)(lbl_80529CF8 + (i << 3) + 0x554) = arg2;
            }
            *(u8 *)(lbl_80529CF8 + (i << 3) + 0x558) = arg0;
            *arg1 = i;
            return 0;
        }
    }
    return 3;
}

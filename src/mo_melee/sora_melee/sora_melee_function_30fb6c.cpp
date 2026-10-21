#include <types.h>
#pragma force_active on

extern u8 lbl_27_bss_7790[];

extern "C" s32 fn_27_30FB6C(s32 unused, s32 a, s32 key, s32 b, s32 flag) {
    s32* node;
    s32* p;

    if (a <= -1 || a >= 4) {
        node = 0;
    } else if (b <= -1 || b >= 0x37) {
        node = 0;
    } else {
        s32* row = (s32*)(lbl_27_bss_7790 + a * 0xdc);
        node = (s32*)row[b];
    }

    if (node == 0) {
        return key;
    }

    for (p = node; *p != 0; p += 2) {
        if (flag == 0) {
            if (*p == key) {
                return p[1];
            }
        } else {
            if (p[1] == key) {
                return *p;
            }
        }
    }
    return key;
}

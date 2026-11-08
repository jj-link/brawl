#include <types.h>
#pragma force_active on

extern char lbl_805644C0[];

s32 fn_803D68CC(char** arg0, u32 arg1) {
    char* p;
    s32 count;

    if (arg1 == 1) {
        p = arg0[0];
    } else {
        p = arg0[1];
    }

    if ((u32)arg0[3] == 1) {
        count = 0;
        while ((s8)*p != 0) {
            if ((*(int (**)(int, int))(lbl_805644C0 + 0x54))((s8)*p, 1)) {
                p++;
            }
            p++;
            count++;
        }
    } else {
        count = 0;
        while ((s8)*p != 0 || (s8)p[1] != 0) {
            p += (*(int (**)(char*))(lbl_805644C0 + 0x58))(p);
            count++;
        }
    }
    return count;
}

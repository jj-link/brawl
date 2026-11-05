#include <types.h>
#pragma force_active on

extern char lbl_8053B248[];

s32 fn_803A9C74(char** arg0, u32 arg1) {
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
            if ((*(int (**)(int, int))(lbl_8053B248 + 0x30))((s8)*p, 1)) {
                p++;
            }
            p++;
            count++;
        }
    } else {
        count = 0;
        while ((s8)*p != 0 || (s8)p[1] != 0) {
            p += (*(int (**)(char*))(lbl_8053B248 + 0x34))(p);
            count++;
        }
    }
    return count;
}

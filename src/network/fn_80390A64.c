#include <revolution/OS/OSError.h>
#pragma force_active on

extern void fn_801D8690(const char *, int, const char *, ...);
extern int fn_801E0714(void);
extern char lbl_8059FC50[6];

static inline void NHTTPi_CheckCurrentThread(int arg0, int arg1) {
    int temp_r3;
    unsigned int temp_r0;

    temp_r3 = fn_801E0714();
    temp_r0 = arg0 + 0x30;
    if (temp_r3 != 0) {
        if ((arg1 == 0 && (unsigned int)temp_r3 != temp_r0) ||
            (arg1 != 0 && (unsigned int)temp_r3 == temp_r0)) {
            OSReport("%s:illegal thread\n", __func__);
            fn_801D8690("NHTTP_os_RVL.c", 0xDF, lbl_8059FC50);
        }
    }
}

void fn_80390A64(int arg0, int arg1) {
    NHTTPi_CheckCurrentThread(arg0, arg1);
}

#include <types.h>
#pragma force_active on

extern s32 fn_8035C660(s32, s32*, s32*, s32*);
extern void fn_8036AAF0(void**, s32, s32);
extern char lbl_8048FB70[];
extern char* strncpy(char*, const char*, s32);

s32 fn_80372FC0(void** arg0, s32 fd, s32* arg2) {
    s32 writable = 0;
    s32 error = 0;
    s32 result = fn_8035C660(fd, 0, &writable, &error);

    if (result == -1) {
        char* p = (char*)*arg0;
        strncpy(p, lbl_8048FB70, 0x100);
        p[0xFF] = 0;
        *(s32*)(p + 0x434) = 5;
        fn_8036AAF0(arg0, 3, 1);
        return 3;
    }
    if (result > 0) {
        if (error != 0) {
            *arg2 = 4;
            return 0;
        }
        if (writable != 0) {
            *arg2 = 3;
            return 0;
        }
    }
    *arg2 = 0;
    return 0;
}
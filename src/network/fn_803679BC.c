#include <types.h>
#pragma force_active on

extern s32 fn_803678E0(s32, s32, char**, s32*);
extern char* strncpy(char*, const char*, s32);

s32 fn_803679BC(s32 p0, s32 p1, char* dst, s32 len) {
    char* spC = 0;
    s32 sp8 = 0;

    if (fn_803678E0(p0, p1, &spC, &sp8) == 0) {
        *dst = 0;
        return 0;
    }
    strncpy(dst, spC, len < sp8 ? len : sp8);
    dst[len - 1 < sp8 ? len - 1 : sp8] = 0;
    return 1;
}

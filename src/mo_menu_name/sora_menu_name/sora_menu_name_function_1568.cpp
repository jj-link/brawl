#include <types.h>
#pragma force_active on

extern "C" {
extern s32 lbl_16_rodata_0;
extern s32 lbl_16_bss_8[];
s32 fn_8006CEEC(s32, s32);
void fn_8006BAB0(char*, s32, s32, s32);
int strcmp(const char*, const char*);
}

extern "C" s32 fn_16_1568(void* unused, char* out, const char* name) {
    char buf[16];
    s32* p;
    s32 count = lbl_16_rodata_0;
    s32 i;
    s32 j;
    s32 n;
    s32 id;
    s32 found = 0;

    for (i = 0, p = lbl_16_bss_8; i < count; p++, i++) {
        id = *p;
        n = fn_8006CEEC(id, 0x7fff);
        for (j = 0; j < n; j++) {
            buf[0] = 0;
            fn_8006BAB0(buf, id, j, 1);
            if (strcmp(buf, name) == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    if (!found) {
        return 0;
    }
    j++;
    if (j >= n) {
        j = 0;
    }
    out[0] = 0;
    fn_8006BAB0(out, id, j, 1);
    return 1;
}

#include <types.h>
#include <string.h>
#pragma force_active on

extern char lbl_80474DA8[];
extern s32 fn_8020BA48(char *, void *, s32);
extern u32 fn_8020AA78(void *, void *, u32);
extern s32 fn_8020BC3C(void *);

s32 fn_801E369C(void *out) {
    u8 file[0x90];
    u32 buffer[64] __attribute__((aligned(32)));
    u32 header[8] __attribute__((aligned(32)));
    u32 i;
    u32 sum;
    int j;
    memset(out, 0, 0x20);
    if (fn_8020BA48(lbl_80474DA8, file, 1) != 0) return 0;
    if (fn_8020AA78(file, header, 0x20) != 0x20) {
        fn_8020BC3C(file);
        return 0;
    }
    sum = 0; { u32 *p = header + 1; for (j = 0; j < 7; j++) sum += *p++; }
    for (i = 0; i < 16; i++) {
        if ((s32)fn_8020AA78(file, buffer, 0x100) != 0x100) {
            fn_8020BC3C(file);
            return 0;
        }
        { u32 *p = buffer; for (j = 0; j < 64; j++) sum += *p++; }
    }
    if (fn_8020BC3C(file) != 0) return 0;
    if (header[0] == sum) {
        memcpy(out, header, 0x20);
        return 1;
    }
    return 0;
}
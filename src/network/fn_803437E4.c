#include <types.h>
#include <string.h>
#pragma force_active on
extern void fn_8034F028(void *, const void *, unsigned int);
extern void fn_80335638(int, const char *, ...);
extern void *fn_803788C8(int, int, char *);
extern int fn_80389760(void *, unsigned int, unsigned int, const void *, int);
extern char lbl_8048BA90[];
extern char lbl_8059F134;
extern void *lbl_805A0FA8;
void fn_803437E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char sp8[0x14];
    char sp1C[0x84];
    u16 temp_r8;
    u32 temp_r9;
    u32 temp_r0;
    u32 temp_r8_2;
    s32 var_r31;
    u8 *base;
    u8 *obj;
    int result;
    var_r31 = arg4;
    if (arg3 != 0 && arg4 != 0) {
        fn_8034F028(sp1C, (const void *)arg3, arg4 * 4);
    } else {
        var_r31 = 0;
    }
    strcpy(sp8, &lbl_8059F134);
    *(u32 *)(sp8 + 4) = 0x0B000000;
    sp8[8] = arg0;
    sp8[9] = (u8)(var_r31 * 4);
    base = (u8 *)lbl_805A0FA8;
    temp_r8 = *(u16 *)(base + 0x2E);
    *(s16 *)(sp8 + 10) = (s16)((((s32)temp_r8 >> 8) & ~0xFFFF00) | ((temp_r8 << 8) & 0xFFFF00));
    *(s32 *)(sp8 + 12) = *(s32 *)(base + 0x30);
    temp_r9 = *(u32 *)(base + 0x218);
    temp_r8_2 = ((temp_r9 >> 8) & 0xFF0000) | ((temp_r9 >> 8) & 0xFF);
    temp_r0 = temp_r8_2 | (((temp_r9 << 8) & 0xFF000000) | ((temp_r9 << 8) & 0xFF00));
    *(s32 *)(sp8 + 16) = (s32)((temp_r0 << 0x10) | (temp_r0 >> 0x10));
    fn_80335638(0x40, lbl_8048BA90, arg0, arg1, arg2, temp_r8_2, temp_r9);
    obj = (u8 *)lbl_805A0FA8;
    result = fn_80389760(*(void **)(obj + 0xF8), (unsigned int)fn_803788C8(arg1, 0, 0), arg2, sp8, ((unsigned char *)sp8)[9] + 0x14);
    if (result == 0 || result == 2) return;
}
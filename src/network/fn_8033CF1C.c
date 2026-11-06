#include <types.h>
#include <string.h>
#include <stdio.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on
extern int lbl_805A0FA8;
extern char *lbl_805A0F90;
extern int lbl_8059F0B0;
extern char lbl_8048AA60[];
extern char lbl_8059F0C4[3], lbl_8059F0C8[4], lbl_8059F0CC[4];
extern char lbl_8059F0D0[4], lbl_8059F0D4[2], lbl_8059F0D8[2];
extern char lbl_8059F0DC[4], lbl_8059F0E0[4], lbl_8059F0E8[8], lbl_8059F0F0[8];
extern void fn_80335450(int, void *, int);
extern void *fn_80335390(int, int);
extern void fn_8033524C(int, int);
extern void fn_80374BD4(int);
extern int fn_803362EC(const char *, const char *, char *, signed char);
extern int fn_80336344(const char *, const char *, char *, signed char);
extern void fn_80337350(int, char *, int);
extern int fn_80337248(int);
extern void fn_80342A90(void);
extern void fn_8034F028(void *, const void *, int);
extern void fn_8034296C(int, int, int, int);
extern void fn_8034AA48(void);
extern int fn_803894EC(int, int, int, int, int, int, int, void *, int);
extern int fn_80349F28(int);
extern int fn_8034DCF0(void);
extern int fn_8033CD90(int);
extern s64 fn_803F1470(s64, s64);
static inline int get_level(int elapsed) {
    int level = lbl_8059F0B0;
    if (level != -1) return level;
    level = (elapsed + 4999) / 5000;
    if (level > 10) level = 10;
    return level;
}
void fn_8033CF1C(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, void *arg9, int arg10) {
    char query[256];
    char buf1[40];
    char buf2[40];
    char num1[12];
    char num2[12];
    int size, p, elapsed, level, v, flag1, flag2;
    s64 t;
    char *base = lbl_8048AA60;
    if (lbl_805A0F90) {
        fn_80335450(4, lbl_805A0F90, 0);
        lbl_805A0F90 = 0;
    }
    if (arg1) {
        size = snprintf(query, 256, base + 0x108, base + 0x160, 11, lbl_8059F0E8, -1, 32, 32, base + 0x16c, 3, base + 0x178, lbl_8059F0E8);
        size = 256 - size - strlen(lbl_8059F0F0);
        lbl_805A0F90 = fn_80335390(4, size);
        if (!lbl_805A0F90) {
            if (lbl_805A0FA8) {
                *(unsigned char *)(lbl_805A0FA8 + 0x1bc) = 2;
                fn_80374BD4(**(int **)(lbl_805A0FA8 + 4));
                *(unsigned char *)(lbl_805A0FA8 + 0x1bc) = 0;
                fn_8033524C(9, 0xfffec77f);
                snprintf(num1, 12, lbl_8059F0C4, *(unsigned char *)(lbl_805A0FA8 + 0x19) + 1);
                fn_803362EC(lbl_8059F0C8, num1, buf1, 0x2f);
                snprintf(num1, 12, lbl_8059F0C4, *(unsigned char *)(lbl_805A0FA8 + 0xd) + 1);
                fn_80336344(lbl_8059F0CC, num1, buf1, 0x2f);
                fn_80336344(lbl_8059F0D0, *(unsigned char *)(lbl_805A0FA8 + 0x1ba) ? lbl_8059F0D4 : lbl_8059F0D8, buf1, 0x2f);
                snprintf(num1, 12, lbl_8059F0C4, 11);
                fn_80336344(lbl_8059F0DC, num1, buf1, 0x2f);
                elapsed = (int)fn_803F1470(*(s64 *)(lbl_805A0FA8 + 0x4c0), (u32)(OS_TIME_SPEED / 1000));
                level = get_level(elapsed);
                snprintf(num1, 12, lbl_8059F0C4, level);
                fn_80336344(lbl_8059F0E0, num1, buf1, 0x2f);
                fn_80337350(1, buf1, 0);
                arg2 = lbl_805A0FA8;
                v = *(int *)(arg2 + 0x224);
                arg0 = *(unsigned char *)(arg2 + 0x15) == 2;
                arg1 = v == 0;
                v = fn_80337248(v);
                (*(void (**)(int, int, int, int, int, int))(arg2 + 0x480))(9, 0, arg1, arg0, v, *(int *)(arg2 + 0x484));
                fn_80342A90();
            }
            return;
        }
        fn_8034F028(lbl_805A0F90, (void *)arg1, size);
        *(size + lbl_805A0F90 - 1) = 0;
    }
    fn_8034296C(0, arg0, arg2, arg3);
    *(int *)(lbl_805A0FA8 + 0x488) = arg4;
    *(int *)(lbl_805A0FA8 + 0x48c) = arg5;
    *(int *)(lbl_805A0FA8 + 0x490) = arg6;
    *(int *)(lbl_805A0FA8 + 0x494) = arg7;
    *(int *)(lbl_805A0FA8 + 0x4c8) = arg8;
    if (arg9) memcpy((void *)(lbl_805A0FA8 + 0x4cc), arg9, 4);
    else memset((void *)(lbl_805A0FA8 + 0x4cc), 0, 4);
    *(int *)(lbl_805A0FA8 + 0x554) = arg10;
    p = lbl_805A0FA8;
    if (*(int *)(p + 0xf8) == 0) {
        int tmp = *(int *)(p + 0x30c);
        *(int *)(p + 0xf8) = fn_803894EC(tmp, tmp, *(int *)(p + 0x310), 0, 0x14, 1, 0, (void *)fn_8034AA48, 0);
    }
    if (*(int *)(lbl_805A0FA8 + 0xf8) == 0 && fn_80349F28(5) != 0) return;
    snprintf(num2, 12, lbl_8059F0C4, *(unsigned char *)(lbl_805A0FA8 + 0x19) + 1);
    fn_803362EC(lbl_8059F0C8, num2, buf2, 0x2f);
    snprintf(num2, 12, lbl_8059F0C4, *(unsigned char *)(lbl_805A0FA8 + 0xd) + 1);
    fn_80336344(lbl_8059F0CC, num2, buf2, 0x2f);
    fn_80336344(lbl_8059F0D0, *(unsigned char *)(lbl_805A0FA8 + 0x1ba) ? lbl_8059F0D4 : lbl_8059F0D8, buf2, 0x2f);
    snprintf(num2, 12, lbl_8059F0C4, 11);
    fn_80336344(lbl_8059F0DC, num2, buf2, 0x2f);
    elapsed = (int)fn_803F1470(*(s64 *)(lbl_805A0FA8 + 0x4c0), (u32)(OS_TIME_SPEED / 1000));
    level = get_level(elapsed);
    snprintf(num2, 12, lbl_8059F0C4, level);
    fn_80336344(lbl_8059F0E0, num2, buf2, 0x2f);
    fn_80337350(3, buf2, 0);
    if (*(int *)(lbl_805A0FA8 + 0x30) != 0 && *(unsigned short *)(lbl_805A0FA8 + 0x2e) != 0) {
        if (fn_8034DCF0() == 0) return;
    } else {
        *(int *)(lbl_805A0FA8 + 0x1b4) = 14;
        t = OSGetTime();
        p = lbl_805A0FA8;
        *(u32 *)(p + 0x214) = (u32)t;
        *(u32 *)(p + 0x210) = (u32)(t >> 32);
    }
    if (*(int *)(lbl_805A0FA8 + 0x10) == 0) fn_8033CD90(*(int *)(lbl_805A0FA8 + 0x218));
}
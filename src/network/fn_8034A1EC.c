#include <types.h>
#include <stdio.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

typedef void (*CbFn)(int, int, int, int, int, int);

extern char lbl_8048C848[];
extern int lbl_805A0FA8;
extern int lbl_8059F0B0;
extern char lbl_8059F0C4[3];
extern char lbl_8059F0C8[4];
extern char lbl_8059F0CC[4];
extern char lbl_8059F0D0[4];
extern char lbl_8059F0D4[2];
extern char lbl_8059F0D8[2];
extern char lbl_8059F0DC[4];
extern char lbl_8059F0E0[4];

extern s32 DWC_GetState(void);
extern void fn_80335638(int, const char *, ...);
extern void fn_80336F14();
extern void fn_80338938(int, int);
extern void fn_8033524C();
extern int fn_803362EC(const char *, const char *, char *, signed char);
extern int fn_80336344(const char *, const char *, char *, signed char);
extern void fn_80337350(int, char *, int);
extern s32 fn_80337248(s32);
extern void fn_80342A90();
extern void fn_80374BD4(s32);
extern s64 fn_803F1470(s64, s64);
extern int __cntlzw(unsigned int);

static inline int get_level(int elapsed) {
    int level = lbl_8059F0B0;
    if (level != -1) {
        return level;
    }
    level = (elapsed + 4999) / 5000;
    if (level > 10) {
        level = 10;
    }
    return level;
}

s32 fn_8034A1EC(s32 arg0) {
    char num[12];
    char buf[44];
    s32 var_r31;
    s32 elapsed;
    s32 level;
    s32 f1;
    s32 f2;
    s32 idx;
    CbFn cb;
    s32 q;
    s32 var_r27;

    if (arg0 == 0) {
        return 0;
    }
    fn_80335638(2, lbl_8048C848, arg0);
    switch (arg0) {
    case 1:
        var_r31 = 6;
        var_r27 = -0x32;
        break;
    case 2:
        var_r31 = 6;
        var_r27 = -0x3C;
        break;
    case 3:
        var_r31 = 6;
        var_r27 = -0x1E;
        break;
    case 4:
        var_r31 = 6;
        var_r27 = -0x50;
        break;
    case 5:
        var_r31 = 6;
        var_r27 = -0x14;
        break;
    }
    switch (DWC_GetState()) {
    case 2:
        fn_80338938(var_r31, var_r27 - 0xFA00);
        break;
    case 4:
        fn_80336F14(var_r31, var_r27 - 0x12110);
        break;
    case 5:
        if (lbl_805A0FA8 != 0 && var_r31 != 0) {
            *(u8 *)(lbl_805A0FA8 + 0x1BC) = 2;
            fn_80374BD4(*(s32 *)(*(s32 *)(lbl_805A0FA8 + 4)));
            q = lbl_805A0FA8;
            *(u8 *)(q + 0x1BC) = 0;
            fn_8033524C(var_r31, var_r27 - 0x14820, q);
            snprintf(num, 12, lbl_8059F0C4, *(u8 *)(lbl_805A0FA8 + 0x19) + 1);
            fn_803362EC(lbl_8059F0C8, num, buf, 0x2F);
            snprintf(num, 12, lbl_8059F0C4, *(u8 *)(lbl_805A0FA8 + 0xD) + 1);
            fn_80336344(lbl_8059F0CC, num, buf, 0x2F);
            fn_80336344(lbl_8059F0D0, *(u8 *)(lbl_805A0FA8 + 0x1BA) ? lbl_8059F0D4 : lbl_8059F0D8, buf, 0x2F);
            snprintf(num, 12, lbl_8059F0C4, 11);
            fn_80336344(lbl_8059F0DC, num, buf, 0x2F);
            elapsed = (s32)fn_803F1470(*(s64 *)(lbl_805A0FA8 + 0x4C0), (u32)(OS_TIME_SPEED / 1000));
            level = get_level(elapsed);
            snprintf(num, 12, lbl_8059F0C4, level);
            fn_80336344(lbl_8059F0E0, num, buf, 0x2F);
            fn_80337350(1, buf, 0);
            var_r27 = lbl_805A0FA8;
            f1 = (unsigned)__cntlzw((u32)(*(u8 *)(var_r27 + 0x15) - 2)) >> 5;
            f2 = (unsigned)__cntlzw((u32)(*(s32 *)(var_r27 + 0x224))) >> 5;
            idx = fn_80337248(*(s32 *)(var_r27 + 0x224));
            cb = *(CbFn *)(var_r27 + 0x480);
            cb(var_r31, 0, f2, f1, idx, *(s32 *)(var_r27 + 0x484));
            fn_80342A90();
        }
        break;
    default:
        fn_8033524C(var_r31, var_r27 - 0x16F30);
        break;
    }
    return arg0;
}
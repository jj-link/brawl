#include <types.h>
#include <stdio.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

extern int lbl_805A0FA8;
extern int lbl_8059F0B0;
extern char lbl_8048C860[];
extern char lbl_8059F0C4[3], lbl_8059F0C8[4], lbl_8059F0CC[4];
extern char lbl_8059F0D0[4], lbl_8059F0D4[2], lbl_8059F0D8[2];
extern char lbl_8059F0DC[4], lbl_8059F0E0[4];
extern int fn_80335638(int, const char *, ...);
extern void fn_8033524C(int, int);
extern void fn_80374BD4(int);
extern int fn_803362EC(const char *, const char *, char *, signed char);
extern int fn_80336344(const char *, const char *, char *, signed char);
extern void fn_80337350(int, char *, int);
extern int fn_80337248(int);
extern void fn_80342A90(void);
extern s64 fn_803F1470(s64, s64);

static inline int get_level(int elapsed) {
    int level = lbl_8059F0B0;
    if (level != -1) return level;
    level = (elapsed + 4999) / 5000;
    if (level > 10) level = 10;
    return level;
}

static inline void do_callback(int code) {
    int p = lbl_805A0FA8;
    int v = *(int *)(p + 0x224);
    int flag1;
    int flag2 = *(unsigned char *)(p + 0x15) == 2;
    flag1 = v == 0;
    v = fn_80337248(v);
    (*(void (**)(int, int, int, int, int, int))(p + 0x480))(code, 0, flag1, flag2, v, *(int *)(p + 0x484));
}

int fn_8034A500(int arg0) {
    char buf1[44];
    char num1[12];
    int elapsed, level;
    int var_r31;
    int var_r27;

    if (arg0 == 0) {
        return 0;
    }
    fn_80335638(2, lbl_8048C860, arg0);
    switch (arg0) {
    case 1:
        var_r31 = 9;
        var_r27 = -1;
        break;
    case 2:
        var_r31 = 6;
        var_r27 = -50;
        break;
    case 3:
        var_r31 = 6;
        var_r27 = -30;
        break;
    }
    if (lbl_805A0FA8 != 0 && var_r31 != 0) {
        *(unsigned char *)(lbl_805A0FA8 + 0x1bc) = 2;
        fn_80374BD4(**(int **)(lbl_805A0FA8 + 4));
        *(unsigned char *)(lbl_805A0FA8 + 0x1bc) = 0;
        fn_8033524C(var_r31, var_r27 - 0x14FF0);
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
        do_callback(var_r31);
        fn_80342A90();
    }
    return arg0;
}

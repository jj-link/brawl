#include <types.h>
#include <stdio.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

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
extern void fn_80374BD4(int);
extern void fn_8033524C(int, int);
extern int fn_803362EC(const char *, const char *, char *, signed char);
extern int fn_80336344(const char *, const char *, char *, signed char);
extern s64 fn_803F1470(s64, s64);
extern void fn_80337350(int, char *, int);
extern int fn_80337248(int);
extern void fn_80342A90(void);

static inline int get_level(int elapsed)
{
    int level = lbl_8059F0B0;
    if (level != -1) return level;
    level = (elapsed + 4999) / 5000;
    if (level > 10) level = 10;
    return level;
}

static inline unsigned int cb_shift(unsigned int value)
{
    return (unsigned int)__cntlzw(value) >> 5;
}

void fn_80341220(int arg0, int arg1)
{
    char num[12];
    char buf[44];
    int p;
    int elapsed;
    int level;

    if (lbl_805A0FA8 == 0 || arg0 == 0) {
        return;
    }

    *(unsigned char *)(lbl_805A0FA8 + 0x1bc) = 2;
    fn_80374BD4(**(int **)(lbl_805A0FA8 + 4));
    *(unsigned char *)(lbl_805A0FA8 + 0x1bc) = 0;
    fn_8033524C(arg0, arg1);

    snprintf(num, 12, lbl_8059F0C4,
             *(unsigned char *)(lbl_805A0FA8 + 0x19) + 1);
    fn_803362EC(lbl_8059F0C8, num, buf, 0x2f);
    snprintf(num, 12, lbl_8059F0C4,
             *(unsigned char *)(lbl_805A0FA8 + 0xd) + 1);
    fn_80336344(lbl_8059F0CC, num, buf, 0x2f);
    fn_80336344(lbl_8059F0D0,
                *(unsigned char *)(lbl_805A0FA8 + 0x1ba)
                    ? lbl_8059F0D4 : lbl_8059F0D8,
                buf, 0x2f);
    snprintf(num, 12, lbl_8059F0C4, 11);
    fn_80336344(lbl_8059F0DC, num, buf, 0x2f);

    elapsed = (int)fn_803F1470(
        *(s64 *)(lbl_805A0FA8 + 0x4c0),
        (u32)(OS_TIME_SPEED / 1000));
    level = get_level(elapsed);
    snprintf(num, 12, lbl_8059F0C4, level);
    fn_80336344(lbl_8059F0E0, num, buf, 0x2f);
    fn_80337350(1, buf, 0);

    p = lbl_805A0FA8;
    {
        int value;
        int flag1;
        int flag2;

        flag2 = (int)cb_shift(
            (u32)(*(unsigned char *)(p + 0x15) - 2));
        value = *(int *)(p + 0x224);
        flag1 = (int)cb_shift((u32)value);
        value = fn_80337248(value);
        (*(void (**)(int, int, int, int, int, int))(p + 0x480))(
            arg0, 0, flag1, flag2, value, *(int *)(p + 0x484));
    }
    fn_80342A90();
}

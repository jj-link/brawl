#include <types.h>
#include <stdio.h>

#pragma force_active on

extern int lbl_805A0FA8;
extern int lbl_8059F0B0;
extern char lbl_8048ABE8[];
extern char lbl_8059F0C4[3];
extern char lbl_8059F0C8[4];
extern char lbl_8059F0CC[4];
extern char lbl_8059F0D0[4];
extern char lbl_8059F0D4[2];
extern char lbl_8059F0D8[2];
extern char lbl_8059F0DC[4];
extern char lbl_8059F0E0[4];

extern int fn_8033652C(int);
extern void fn_80335638(int, const char *, ...);
extern int fn_803362EC(const char *, const char *, char *, signed char);
extern void fn_80336344(const char *, const char *, const char *, signed char);
extern void fn_80337350(int, char *, int);
extern void fn_80349C88(void);
extern s64 fn_803F1470(s32, s32, s32, s32);

static inline int get_level(int elapsed) {
    int level = lbl_8059F0B0;
    if (level != -1) return level;
    level = (elapsed + 4999) / 5000;
    if (level > 10) level = 10;
    return level;
}

void fn_8034D6F0(int arg0)
{
    char num[12];
    char buf[44];
    int level;
    int elapsed;
    int p;
    unsigned char c;

    if (arg0 != 0) {
        *(int *)(lbl_805A0FA8 + 0x108) =
            *(int *)(lbl_805A0FA8 + 0x218);
        *(int *)(lbl_805A0FA8 + 0x308) = 1;
        *(unsigned char *)(lbl_805A0FA8 + 0x0E) = 0;

        p = lbl_805A0FA8;
        p = *(int *)(p + 0x218) + fn_8033652C(0x989680) + 0x5F5E100;
        fn_80335638(0x200001, lbl_8048ABE8, p);
        *(int *)(lbl_805A0FA8 + 0x4A0) = p;
    }

    *(unsigned char *)(lbl_805A0FA8 + 0x15) = 2;
    *(int *)(lbl_805A0FA8 + 0x1B4) = 0xF;
    *(unsigned char *)(lbl_805A0FA8 + 0x17) = 2;
    *(int *)(lbl_805A0FA8 + 0x34) = 0;
    *(unsigned char *)(lbl_805A0FA8 + 0x1A) = 0;

    p = *(unsigned char *)(lbl_805A0FA8 + 0x16) == 1 ? 4 : 6;

    c = *(unsigned char *)(lbl_805A0FA8 + 0x19);
    snprintf(num, 12, lbl_8059F0C4, c + 1);
    fn_803362EC(lbl_8059F0C8, num, buf, 0x2F);

    snprintf(num, 12, lbl_8059F0C4,
             *(unsigned char *)(lbl_805A0FA8 + 0x0D) + 1);
    fn_80336344(lbl_8059F0CC, num, buf, 0x2F);

    fn_80336344(lbl_8059F0D0,
                *(unsigned char *)(lbl_805A0FA8 + 0x1BA)
                    ? lbl_8059F0D4
                    : lbl_8059F0D8,
                buf, 0x2F);

    snprintf(num, 12, lbl_8059F0C4, 11);
    fn_80336344(lbl_8059F0DC, num, buf, 0x2F);

    elapsed = (int)fn_803F1470(
        *(s32 *)(lbl_805A0FA8 + 0x4C0),
        *(s32 *)(lbl_805A0FA8 + 0x4C4),
        0,
        (*(u32 *)0x800000F8 >> 2) / 1000);

    level = get_level(elapsed);

    snprintf(num, 12, lbl_8059F0C4, level);
    fn_80336344(lbl_8059F0E0, num, buf, 0x2F);

    fn_80337350(p, buf, 0);
    fn_80349C88();
    *(int *)(lbl_805A0FA8 + 0x21C) = 0;
}

#include <types.h>
#include <stdio.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

extern int lbl_805A0FA8;
extern int lbl_8059F0B0;
extern char lbl_8059F0C4[3], lbl_8059F0C8[4], lbl_8059F0CC[4];
extern char lbl_8059F0D0[4], lbl_8059F0D4[2], lbl_8059F0D8[2];
extern char lbl_8059F0DC[4], lbl_8059F0E0[4];
extern int fn_803362EC(const char *, const char *, char *, signed char);
extern int fn_80336344(const char *, const char *, char *, signed char);
extern void fn_80337350(int, char *, int);
extern s64 fn_803F1470(s64, s64);

static inline int get_level(int elapsed) {
    int level = lbl_8059F0B0;
    if (level != -1) return level;
    level = (elapsed + 4999) / 5000;
    if (level > 10) level = 10;
    return level;
}

void fn_80342328(int arg0) {
    char num[12];
    char buf[44];
    int elapsed, level;

    snprintf(num, 12, lbl_8059F0C4, *(unsigned char *)(lbl_805A0FA8 + 0x19) + 1);
    fn_803362EC(lbl_8059F0C8, num, buf, 0x2f);
    snprintf(num, 12, lbl_8059F0C4, *(unsigned char *)(lbl_805A0FA8 + 0xd) + 1);
    fn_80336344(lbl_8059F0CC, num, buf, 0x2f);
    fn_80336344(lbl_8059F0D0, *(unsigned char *)(lbl_805A0FA8 + 0x1ba) ? lbl_8059F0D4 : lbl_8059F0D8, buf, 0x2f);
    snprintf(num, 12, lbl_8059F0C4, 11);
    fn_80336344(lbl_8059F0DC, num, buf, 0x2f);
    elapsed = (int)fn_803F1470(*(s64 *)(lbl_805A0FA8 + 0x4c0), (u32)(OS_TIME_SPEED / 1000));
    level = get_level(elapsed);
    snprintf(num, 12, lbl_8059F0C4, level);
    fn_80336344(lbl_8059F0E0, num, buf, 0x2f);
    fn_80337350(arg0, buf, 0);
}

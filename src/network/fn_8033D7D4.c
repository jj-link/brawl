#include <types.h>
#include <string.h>
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
extern void fn_8034296C(int, int, int, int);
extern void fn_8034AA48(void);
extern int fn_803894EC(int, int, int, int, int, int, int, void *, int);
extern int fn_80349F28();
extern int fn_803362EC(const char *, const char *, char *, signed char);
extern int fn_80336344(const char *, const char *, char *, signed char);
extern void fn_80337350(int, char *, int);
extern int fn_80349C88(void);
extern int fn_8033CD90(int);
extern int fn_8034DCF0(void);
extern void fn_80379148(int);
extern int fn_803685D0(int, int);
extern int fn_80346B10(int, int);
extern int fn_80342BA8(int);
extern s64 fn_803F1470(s64, s64);

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

void fn_8033D7D4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, void *arg6, int arg7) {
    char buf[48];
    char num[12];
    unsigned int copy;
    int p;
    int level;
    int elapsed;
    int result;
    s64 t;

    memcpy(&copy, arg6, 4);
    fn_8034296C(3, 0, arg1, arg2);
    *(int *)(lbl_805A0FA8 + 0x488) = arg3;
    *(int *)(lbl_805A0FA8 + 0x48C) = arg4;
    *(int *)(lbl_805A0FA8 + 0x4C8) = arg5;
    memcpy((void *)(lbl_805A0FA8 + 0x4CC), &copy, 4);
    *(int *)(lbl_805A0FA8 + 0x554) = arg7;
    *(unsigned char *)(lbl_805A0FA8 + 0x1A) = 1;
    *(int *)(lbl_805A0FA8 + 0x34) = *(int *)(lbl_805A0FA8 + 0x218);
    *(unsigned char *)(lbl_805A0FA8 + 0x17) = 1;
    *(int *)(lbl_805A0FA8 + 0x108) = arg0;
    *(int *)(lbl_805A0FA8 + 0x1B4) = 3;
    p = lbl_805A0FA8;
    if (*(int *)(p + 0xF8) == 0) {
        int tmp = *(int *)(p + 0x30C);
        *(int *)(p + 0xF8) = fn_803894EC(tmp, tmp, *(int *)(p + 0x310), 0, 0x14, 1, 0, (void *)fn_8034AA48, 0);
    }
    if (*(int *)(lbl_805A0FA8 + 0xF8) == 0 && fn_80349F28(5) != 0) {
        return;
    }
    snprintf(num, 12, lbl_8059F0C4, *(unsigned char *)(lbl_805A0FA8 + 0x19) + 1);
    fn_803362EC(lbl_8059F0C8, num, buf, 0x2F);
    snprintf(num, 12, lbl_8059F0C4, *(unsigned char *)(lbl_805A0FA8 + 0xD) + 1);
    fn_80336344(lbl_8059F0CC, num, buf, 0x2F);
    fn_80336344(lbl_8059F0D0, *(unsigned char *)(lbl_805A0FA8 + 0x1BA) ? lbl_8059F0D4 : lbl_8059F0D8, buf, 0x2F);
    snprintf(num, 12, lbl_8059F0C4, 11);
    fn_80336344(lbl_8059F0DC, num, buf, 0x2F);
    elapsed = (int)fn_803F1470(*(s64 *)(lbl_805A0FA8 + 0x4C0), (u32)(OS_TIME_SPEED / 1000));
    level = get_level(elapsed);
    snprintf(num, 12, lbl_8059F0C4, level);
    fn_80336344(lbl_8059F0E0, num, buf, 0x2F);
    fn_80337350(5, buf, 0);
    if (fn_80349C88() != 0) {
        return;
    }
    if (*(int *)(lbl_805A0FA8 + 0x10) == 0 && fn_8033CD90(*(int *)(lbl_805A0FA8 + 0x218)) != 0) {
        return;
    }
    if (*(unsigned char *)(lbl_805A0FA8 + 0x4A5) == 0) {
        if (*(int *)(lbl_805A0FA8 + 0x30) != 0 && *(unsigned short *)(lbl_805A0FA8 + 0x2E) != 0) {
            if (fn_8034DCF0() != 0) {
                return;
            }
            return;
        } else {
            *(int *)(lbl_805A0FA8 + 0x1B4) = 14;
            t = OSGetTime();
            p = lbl_805A0FA8;
            *(u32 *)(p + 0x214) = (u32)t;
            *(u32 *)(p + 0x210) = (u32)(t >> 32);
        }
    } else {
        fn_80379148(*(int *)(lbl_805A0FA8 + 0x10));
        if (fn_803685D0(*(int *)lbl_805A0FA8, *(int *)(lbl_805A0FA8 + 0x108)) != 0) {
            *(int *)(lbl_805A0FA8 + 0x1B4) = 3;
            result = fn_80346B10(*(int *)(lbl_805A0FA8 + 0x108), 0);
            if (*(unsigned char *)(lbl_805A0FA8 + 0x16) == 0) {
                result = fn_80349F28(result);
            } else {
                result = fn_80349C88();
            }
            if (result != 0) {
                return;
            }
        } else {
            *(int *)(lbl_805A0FA8 + 0x1B4) = 13;
            result = fn_80342BA8(*(int *)(lbl_805A0FA8 + 0x108));
            if (fn_80349F28(result) != 0) {
                return;
            }
        }
    }
}

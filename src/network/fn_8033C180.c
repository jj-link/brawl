#include <types.h>
#include <stdio.h>
#include <string.h>
#include <revolution/OS/OSTime.h>

#pragma force_active on

typedef struct Entry {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    void *unk4;
    void *unk8;
} Entry;

extern Entry lbl_805338B0[];
extern int lbl_805A0FA8;
extern int lbl_8059F0B0;
extern char lbl_8048AAB8[];
extern char lbl_8059F0C4[3], lbl_8059F0C8[4], lbl_8059F0CC[4];
extern char lbl_8059F0D0[4], lbl_8059F0D4[2], lbl_8059F0D8[2];
extern char lbl_8059F0DC[4], lbl_8059F0E0[4];

extern void fn_80335450(int, void *, int);
extern void *fn_80335390(int, int);
extern void fn_8033524C(int, int);
extern void fn_80374BD4(int);
extern int fn_803362EC(const char *, const char *, char *, signed char);
extern int fn_80336344(const char *, const char *, char *, signed char);
extern void fn_80337350(int, char *, int);
extern int fn_80337248(int);
extern void fn_80342A90(void);
extern void fn_8037B354(int, void *);
extern int fn_80335638(int, const char *, ...);
extern s64 fn_803F1470(s64, s64);

static inline int get_level(int elapsed)
{
    int level = lbl_8059F0B0;

    if (level != -1)
        return level;
    level = (elapsed + 4999) / 5000;
    if (level > 10)
        level = 10;
    return level;
}

static inline void do_callback(int code)
{
    int p = lbl_805A0FA8;
    int v = *(int *)(p + 0x224);
    int flag1;
    int flag2 = *(unsigned char *)(p + 0x15) == 2;

    flag1 = v == 0;
    v = fn_80337248(v);
    (*(void (**)(int, int, int, int, int, int))(p + 0x480))(
        code, 0, flag1, flag2, v, *(int *)(p + 0x484));
}

static inline u8 find_free(void)
{
    u8 i;

    for (i = 0; i < 154; i++) {
        if (lbl_805338B0[i].unk0 == 0)
            return i + 100;
    }
    return 0;
}

u8 fn_8033C180(u8 id, char *arg1, int *arg2)
{
    char buf1[44];
    char num1[12];
    int elapsed, level;

    if (arg1 == 0 || arg2 == 0)
        return 0;

    if (id >= 100 && lbl_805338B0[id - 100].unk0 != 0) {
        if (lbl_805338B0[id - 100].unk4 != 0 &&
            strcmp((const char *)lbl_805338B0[id - 100].unk4, arg1) != 0)
            return 0;
    } else {
        id = find_free();
        if (id == 0)
            return 0;
    }

    lbl_805338B0[id - 100].unk0 = id;
    lbl_805338B0[id - 100].unk1 = 0;
    lbl_805338B0[id - 100].unk2 = 0;
    if (lbl_805338B0[id - 100].unk4 != 0)
        fn_80335450(4, lbl_805338B0[id - 100].unk4, 0);

    lbl_805338B0[id - 100].unk4 = fn_80335390(4, strlen(arg1) + 1);
    if (lbl_805338B0[id - 100].unk4 == 0) {
        if (lbl_805A0FA8 != 0) {
            *(unsigned char *)(lbl_805A0FA8 + 0x1bc) = 2;
            fn_80374BD4(**(int **)(lbl_805A0FA8 + 4));
            *(unsigned char *)(lbl_805A0FA8 + 0x1bc) = 0;
            fn_8033524C(9, 0xfffec77f);
            snprintf(num1, 12, lbl_8059F0C4,
                     *(unsigned char *)(lbl_805A0FA8 + 0x19) + 1);
            fn_803362EC(lbl_8059F0C8, num1, buf1, 0x2f);
            snprintf(num1, 12, lbl_8059F0C4,
                     *(unsigned char *)(lbl_805A0FA8 + 0xd) + 1);
            fn_80336344(lbl_8059F0CC, num1, buf1, 0x2f);
            fn_80336344(lbl_8059F0D0,
                        *(unsigned char *)(lbl_805A0FA8 + 0x1ba)
                            ? lbl_8059F0D4
                            : lbl_8059F0D8,
                        buf1, 0x2f);
            snprintf(num1, 12, lbl_8059F0C4, 11);
            fn_80336344(lbl_8059F0DC, num1, buf1, 0x2f);
            elapsed = (int)fn_803F1470(
                *(s64 *)(lbl_805A0FA8 + 0x4c0),
                (u32)(OS_TIME_SPEED / 1000));
            level = get_level(elapsed);
            snprintf(num1, 12, lbl_8059F0C4, level);
            fn_80336344(lbl_8059F0E0, num1, buf1, 0x2f);
            fn_80337350(1, buf1, 0);
            do_callback(9);
            fn_80342A90();
        }
        return 0;
    }

    strcpy((char *)lbl_805338B0[id - 100].unk4, arg1);
    fn_80335638(4, lbl_8048AAB8, arg1, *arg2);
    lbl_805338B0[id - 100].unk8 = arg2;
    fn_8037B354(id, lbl_805338B0[id - 100].unk4);
    return id;
}

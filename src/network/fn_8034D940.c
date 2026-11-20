#include <types.h>
#include <stdio.h>
#include <revolution/OS/OSTime.h>

#pragma force_active on

extern int lbl_805A0FA8;
extern int lbl_8059F0B0;
extern char lbl_8048CEB8[];
extern char lbl_8059F0C4[3], lbl_8059F0C8[4], lbl_8059F0CC[4];
extern char lbl_8059F0D0[4], lbl_8059F0D4[2], lbl_8059F0D8[2];
extern char lbl_8059F0DC[4], lbl_8059F0E0[4];

extern void fn_80335638(int, const char *, ...);
extern int fn_803362EC(const char *, const char *, char *, signed char);
extern int fn_80336344(const char *, const char *, char *, signed char);
extern void fn_80337350(int, char *, int);
extern int fn_8033AA6C(int);
extern u8 fn_8033A77C(void);
extern int fn_803437E4(int, int, unsigned short, void *, int);
extern int fn_80349F28(int);
extern int fn_80349C88(void);
extern s64 fn_803F1470(s64, s64);

static inline int get_level(int elapsed) {
    int level = lbl_8059F0B0;

    if (level != -1)
        return level;

    level = (elapsed + 4999) / 5000;
    if (level > 10)
        level = 10;

    return level;
}

#define SWAP_HALF(x) \
    (((((u32)(x) >> 8) & 0x00ff0000 & ~0xff) | \
      (((u32)(x) >> 8) & 0xff)) | \
     (((((u32)(x) << 8) & 0xff000000 & ~0xff00)) | \
      (((u32)(x) << 8) & 0xff00)))
#define SWAP(x) ((SWAP_HALF(x) << 16) | (SWAP_HALF(x) >> 16))

static inline u8 get_aid(int p, int current) {
    int count = *(u8 *)(p + 0xd);
    unsigned int q = p;
    int i;

    for (i = 0; i <= count; i++) {
        if (current == *(int *)(q + 0x108))
            return *(u8 *)(p + 0x2e8 + i);
        q += 4;
    }

    return 0xff;
}

int fn_8034D940(u32 aid, int suspend, int send) {
    char buf[32];
    u32 packet[4];
    char num[12];
    int i;
    u8 local;
    int result;
    int elapsed;
    int level;
    int p;
    u32 old_susp;
    u32 new_susp;

    p = lbl_805A0FA8;
    local = get_aid(p, *(int *)(p + 0x218));

    old_susp = *(u32 *)(p + 0x1c);
    if (suspend)
        *(u32 *)(p + 0x1c) = old_susp | (1u << aid);
    else
        *(u32 *)(p + 0x1c) = old_susp & ~(1u << aid);
    new_susp = *(u32 *)(lbl_805A0FA8 + 0x1c);
    if (old_susp != new_susp) {
        if (aid == local)
            fn_80335638(0x210000, lbl_8048CEB8, aid, suspend, old_susp, new_susp);

        snprintf(num, 12, lbl_8059F0C4,
                 *(u8 *)(lbl_805A0FA8 + 0x19) + 1);
        fn_803362EC(lbl_8059F0C8, num, buf, 0x2f);

        snprintf(num, 12, lbl_8059F0C4,
                 *(u8 *)(lbl_805A0FA8 + 0xd) + 1);
        fn_80336344(lbl_8059F0CC, num, buf, 0x2f);

        fn_80336344(lbl_8059F0D0,
                    *(u8 *)(lbl_805A0FA8 + 0x1ba)
                        ? lbl_8059F0D4
                        : lbl_8059F0D8,
                    buf, 0x2f);

        snprintf(num, 12, lbl_8059F0C4, 11);
        fn_80336344(lbl_8059F0DC, num, buf, 0x2f);

        elapsed = (int)fn_803F1470(
            *(s64 *)(lbl_805A0FA8 + 0x4c0),
            (u32)(OS_TIME_SPEED / 1000));
        level = get_level(elapsed);

        snprintf(num, 12, lbl_8059F0C4, level);
        fn_80336344(lbl_8059F0E0, num, buf, 0x2f);
        fn_80337350(-1, buf, 0);
    }

    if (!send)
        return 1;

    send = *(u32 *)(lbl_805A0FA8 + 0x1c);
    {
        int ok;

        if (fn_8033AA6C(lbl_805A0FA8)) {
            if (*(int *)(lbl_805A0FA8 + 0x1b4) == 15)
                ok = 1;
            else
                ok = 0;
        } else {
            ok = 1;
        }

        if (ok == 0)
            send &= ~(1 << fn_8033A77C());
    }

    packet[0] = SWAP(*(u32 *)(lbl_805A0FA8 + 0x218));
    packet[1] = 0x01000000;
    packet[2] = SWAP(suspend);
    packet[3] = SWAP(send);

    for (i = 1; i < *(u8 *)(lbl_805A0FA8 + 0xd) + 1; i++) {
        if (aid == *(u8 *)(lbl_805A0FA8 + 0x2e8 + i)) {
            result = fn_803437E4(
                0x82,
                *(int *)(lbl_805A0FA8 + 0x38 + i * 4),
                *(u16 *)(lbl_805A0FA8 + 0xb8 + i * 2),
                packet, 4);

            if (*(u8 *)(lbl_805A0FA8 + 0x16) == 0)
                result = fn_80349F28(result);
            else
                result = fn_80349C88();

            if (result)
                return 0;
        }
    }

    return 1;
}

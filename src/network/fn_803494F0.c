#include <types.h>
#include <revolution/DWC/dwc_main.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

typedef struct MatchState {
    unsigned char pad00[0x0d];
    unsigned char count;
    unsigned char pad0e[8];
    unsigned char mode;
    unsigned char pad17[0xf1];
    int players[32];
    unsigned char pad188[0x2c];
    int state;
    unsigned char pad1b8[4];
    unsigned char flag;
    unsigned char pad1bd[7];
    unsigned short delay;
    unsigned char pad1c6[0x26];
    unsigned int mask;
    unsigned char pad1f0[0x10];
    unsigned long long time;
    unsigned char pad208[0x1c];
    int value;
    unsigned char pad228[0xc0];
    unsigned char indices[32];
    unsigned int available;
} MatchState;

extern MatchState *lbl_805A0FA8;
extern char lbl_8048AA60[];

extern void fn_80335638(int, const char *, ...);
extern void **fn_8033AD60(int, int);
extern void fn_80374BC0(void *);
extern int fn_80341E20(int, int);
extern int fn_80343500(int, int, int, int, int *, int);
extern int fn_80349F28(int);
extern int fn_80349C88(int);
extern void fn_80348ACC(int);

static inline unsigned char get_player_index(MatchState *match, int player)
{
    int i;

    for (i = 1; i <= match->count; i++) {
        if (player == match->players[i])
            return match->indices[i];
    }
    return 0xff;
}

static inline const char *log_cancel_sync(int command, int sender)
{
    const char *base = lbl_8048AA60;

    fn_80335638(0x80, base + 0x1d44, command - 13, sender);
    return base;
}

int fn_803494F0(int arg0, int arg1, int arg2)
{
    const char *base = log_cancel_sync(arg1, arg0);
    void **entry;
    MatchState *p;
    unsigned long long elapsed;
    unsigned char index;
    unsigned int peers;
    int i;
    int result;
    int value;
    struct {
        int sp8;
        int spc;
        int sp10;
    } scratch;

    if (DWC_GetState() != 6) {
        fn_80335638(0x80, base + 0x1d70);
        return 1;
    }

    switch (arg1) {
    case 13:
        if (lbl_805A0FA8->state != 7) {
            lbl_805A0FA8->state = 7;
            lbl_805A0FA8->value = arg2;
            entry = fn_8033AD60(arg2, lbl_805A0FA8->count + 1);
            if (entry != 0) {
                lbl_805A0FA8->flag = 2;
                fn_80374BC0(*entry);
                lbl_805A0FA8->flag = 0;
            } else {
                char *cursor = (char *)lbl_805A0FA8;
                value = ((MatchState *)cursor)->count + 1;
                if (cursor != 0) {
                    for (i = 0; i < value; cursor += 4, i++) {
                        if (arg2 == *(int *)(cursor + 0x108)) {
                            fn_80341E20(i, value);
                            break;
                        }
                    }
                }
            }
        }
        fn_80335638(0x80, base + 0x1ac8, 1, arg0);
        result = fn_80343500(14, arg0, 0, 0, &scratch.sp10, 0);
        if (lbl_805A0FA8->mode == 0)
            result = fn_80349F28(result);
        else
            result = fn_80349C88(result);
        if (result != 0) {
            result = 0;
        } else {
            lbl_805A0FA8->time = OSGetTime();
            result = 1;
        }
        if (result == 0)
            return 0;
        break;

    case 14:
        if (lbl_805A0FA8->state == 19) {
            elapsed = OSGetTime();
            p = lbl_805A0FA8;
            elapsed = (elapsed - p->time) /
                      (OS_BUS_CLOCK_SPEED / 4 / 1000) / 2;
            if (elapsed > 300) {
                unsigned long long delay = elapsed - 300;
                if (delay > p->delay)
                    p->delay = delay;
            }

            p = lbl_805A0FA8;
            index = get_player_index(p, arg0);
            if (index != 0xff)
                p->mask |= 1 << index;

            p = lbl_805A0FA8;
            peers = p->available & ~(1U << p->indices[0]);
            if (peers == p->mask) {
                for (i = 1; i <= lbl_805A0FA8->count; i++) {
                    arg0 = lbl_805A0FA8->players[i];
                    fn_80335638(0x80, base + 0x1ac8, 2, arg0);
                    result = fn_80343500(15, arg0, 0, 0, &scratch.spc, 0);
                    if (lbl_805A0FA8->mode == 0)
                        result = fn_80349F28(result);
                    else
                        result = fn_80349C88(result);
                    if (result != 0) {
                        result = 0;
                    } else {
                        lbl_805A0FA8->time = OSGetTime();
                        result = 1;
                    }
                    if (result == 0)
                        return 0;
                }
                lbl_805A0FA8->state = 20;
                fn_80335638(0x80, base + 0xc20, lbl_805A0FA8->delay);
            }
        } else {
            fn_80335638(0x80, base + 0x1ac8, 2, arg0);
            result = fn_80343500(15, arg0, 0, 0, &scratch.sp8, 0);
            if (lbl_805A0FA8->mode == 0)
                result = fn_80349F28(result);
            else
                result = fn_80349C88(result);
            if (result != 0) {
                result = 0;
            } else {
                lbl_805A0FA8->time = OSGetTime();
                result = 1;
            }
            if (result == 0)
                return 0;
        }
        break;

    case 15:
        if (lbl_805A0FA8->state == 7)
            fn_80348ACC(2);
        break;
    }

    return 1;
}

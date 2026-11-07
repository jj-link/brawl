#include <revolution/OS/OSTime.h>
#include <revolution/NHTTP/d_nhttp.h>
#pragma force_active on

extern char lbl_8048D400[];
extern char *lbl_805A0FD4;
extern unsigned int lbl_805A0FD8;
extern void *lbl_8059F1C8;
extern int lbl_80534030[];

extern void fn_80352C20(int);
extern void fn_803540BC(void);
extern int fn_8020BB4C(void *, void *, int, void (*)(int), void *);
extern int fn_8020AAE0(void *, void *, int, void (*)(int), void *);
extern int fn_8020ABC0(void *, void *, int, void (*)(int), void *);
extern int fn_8020BCA8(void *, void (*)(int), void *);
extern int fn_8020A9B8(void *, void (*)(int), void *);
extern int fn_8020A7F8(void *, int, int, void (*)(int), void *);
extern void fn_80354114(int, int, int, int);
extern void fn_80335638(int, const char *, ...);
extern void fn_80352C38(int, void *, void *, long long);
extern void fn_803967D0(int);
extern void fn_803962D4(void (*)(void));
extern s64 fn_803F1470(s64, s64);

#define FIELD(offset) (*(int *)(lbl_805A0FD4 + (offset)))
#define TIME_FIELD (*(s64 *)(lbl_805A0FD4 + 0x5b38))
#define GLOBAL_TIME (*(s64 *)((char *)lbl_80534030 + 0x1b0))

void fn_80352418(void)
{
    char *base = lbl_8048D400;

    switch (lbl_805A0FD8) {
    case 1:
        if (FIELD(0x59e4) == 3) {
            lbl_805A0FD8 = 0x13;
        } else {
            fn_8020BB4C(lbl_8059F1C8, lbl_805A0FD4 + 0x5aa4, 1,
                        fn_80352C20, lbl_805A0FD4 + 0x59e8);
            lbl_805A0FD8 = 2;
        }
        break;

    case 2:
        if (FIELD(0x59d8) != 0)
            fn_80354114(3, 1, 9, 7);
        break;

    case 3:
        fn_8020AAE0(lbl_805A0FD4 + 0x5aa4, lbl_805A0FD4, 0x20,
                    fn_80352C20, lbl_805A0FD4 + 0x59e8);
        lbl_805A0FD8 = 4;
        break;

    case 4:
        if (FIELD(0x59d8) != 0) {
            if ((unsigned int)FIELD(0x59dc) == 0x20U) {
                GLOBAL_TIME = *(s64 *)lbl_805A0FD4;
                fn_80335638(0x1000000, base + 0x198, GLOBAL_TIME);
                FIELD(0x59dc) = 0;
            } else if (FIELD(0x59dc) >= 0) {
                fn_80335638(0x1000000, base + 0x1b0, FIELD(0x59dc));
                FIELD(0x59dc) = -1;
            }
            fn_80354114(0x11, 3, 0x1b, 5);
        }
        break;

    case 5:
        fn_8020BCA8(lbl_805A0FD4 + 0x5aa4, fn_80352C20,
                    lbl_805A0FD4 + 0x59e8);
        lbl_805A0FD8 = 6;
        break;

    case 6:
        if (FIELD(0x59d8) != 0)
            fn_80354114(7, 5, 0x1b, 0x1b);
        break;

    case 7:
        fn_8020A9B8(lbl_8059F1C8, fn_80352C20,
                    lbl_805A0FD4 + 0x59e8);
        lbl_805A0FD8 = 8;
        break;

    case 8:
        if (FIELD(0x59d8) != 0) {
            if (FIELD(0x59dc) == 0)
                fn_80335638(0x1000000, base + 0x1d0);
            fn_80354114(9, 7, 9, 0x1b);
        }
        break;

    case 9:
        fn_80352C38(0, 0, 0, 0);
        TIME_FIELD = OSGetTime();
        lbl_805A0FD8 = 10;
        break;

    case 10:
        if (lbl_80534030[0] == 1) {
            lbl_805A0FD8 = 11;
        } else if (lbl_80534030[0] >= -0x5207 &&
                   lbl_80534030[0] <= -0x4e86) {
            lbl_805A0FD8 = 0x17;
        } else if (lbl_80534030[0] < 0) {
            FIELD(0x59d4)++;
            if (FIELD(0x59d4) < 3)
                lbl_805A0FD8 = 9;
            else
                lbl_805A0FD8 = 0x17;
        } else if (fn_803F1470(OSGetTime() - TIME_FIELD, OS_TIME_SPEED / 1000) > 30000) {
            fn_80335638(0x1000000, base + 0x1ec);
            lbl_805A0FD8 = 0x15;
        }
        break;

    case 11:
        fn_8020A7F8(lbl_8059F1C8, 0x3f, 0, fn_80352C20,
                    lbl_805A0FD4 + 0x59e8);
        lbl_805A0FD8 = 12;
        break;

    case 12:
        if (FIELD(0x59d8) != 0)
            fn_80354114(13, 11, 0x1b, 0x1b);
        break;

    case 13:
        fn_8020BB4C(lbl_8059F1C8, lbl_805A0FD4 + 0x5aa4, 2,
                    fn_80352C20, lbl_805A0FD4 + 0x59e8);
        lbl_805A0FD8 = 14;
        break;

    case 14:
        if (FIELD(0x59d8) != 0)
            fn_80354114(15, 13, 0x1b, 0x1b);
        break;

    case 15:
        *(s64 *)lbl_805A0FD4 = GLOBAL_TIME;
        fn_8020ABC0(lbl_805A0FD4 + 0x5aa4, lbl_805A0FD4, 0x20,
                    fn_80352C20, lbl_805A0FD4 + 0x59e8);
        lbl_805A0FD8 = 16;
        break;

    case 16:
        if (FIELD(0x59d8) != 0) {
            if ((unsigned int)FIELD(0x59dc) == 0x20U) {
                FIELD(0x59dc) = 0;
            } else {
                fn_80335638(0x1000000, base + 0x204, FIELD(0x59dc));
                FIELD(0x59dc) = -1;
            }
            fn_80354114(17, 15, 0x1b, 0x1b);
        }
        break;

    case 17:
        fn_8020BCA8(lbl_805A0FD4 + 0x5aa4, fn_80352C20,
                    lbl_805A0FD4 + 0x59e8);
        lbl_805A0FD8 = 18;
        break;

    case 18:
        if (FIELD(0x59d8) != 0)
            fn_80354114(19, 17, 0x1b, 0x1b);
        break;

    case 19:
        fn_80352C38(FIELD(0x59e4), lbl_805A0FD4 + 0x417e,
                    lbl_805A0FD4 + 0x41b2, GLOBAL_TIME);
        TIME_FIELD = OSGetTime();
        lbl_805A0FD8 = 20;
        break;

    case 20:
        if (lbl_80534030[0] == 1) {
            lbl_805A0FD8 = 0x17;
        } else if (lbl_80534030[0] >= -0x5207 &&
                   lbl_80534030[0] <= -0x4e86) {
            lbl_805A0FD8 = 0x17;
        } else if (lbl_80534030[0] < 0) {
            FIELD(0x59d4)++;
            if (FIELD(0x59d4) < 3)
                lbl_805A0FD8 = 19;
            else
                lbl_805A0FD8 = 0x17;
        } else if (fn_803F1470(OSGetTime() - TIME_FIELD, OS_TIME_SPEED / 1000) > 30000) {
            fn_80335638(0x1000000, base + 0x228);
            lbl_805A0FD8 = 0x15;
        }
        break;

    case 21:
        lbl_805A0FD8 = 22;
        fn_803967D0(FIELD(0x59e0));
        break;

    case 22:
        if (lbl_80534030[0] != 0) {
            lbl_80534030[0] = -0x4e84;
            lbl_805A0FD8 = 23;
        }
        break;

    case 23:
        lbl_805A0FD8 = 24;
        if (lbl_80534030[0x1c8 / 4] != 0) {
            fn_80335638(0x1000000, base + 0x180);
            NHTTPDestroyResponse(
                (NHTTPResponseHandle)lbl_80534030[0x1c8 / 4]);
            lbl_80534030[0x1c8 / 4] = 0;
        }
        fn_803962D4(fn_803540BC);
        break;

    case 26:
        break;
    }
}

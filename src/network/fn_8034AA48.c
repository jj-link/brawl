#include <types.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

extern char lbl_8048AA60[];
extern char lbl_8059F0E8[8];
extern int lbl_805A0F98;
extern int lbl_805A0FA8;

extern void fn_80335638(int, const char *, ...);
extern void fn_8034B17C(int);
extern void *fn_80389934(int, int);
extern int fn_80388794(void *, const char *, int);
extern void fn_80389838(int, void *);
extern int fn_8038993C(int);
extern int fn_8034B494(int);
extern void fn_8034B67C(void);
extern int fn_803894EC(int, int, int, int, int, int, int, void *, int);
extern int fn_80349F28(int);
extern int fn_80349C88(void);
extern int fn_80346B10(int, int);
extern int fn_80346D80(int, int, int);
extern int fn_80343500(int, int, int, int, int, int);
extern void fn_80343118(int, int, void *);
extern void fn_8034A500(void);
extern void fn_80342BA8(int);
extern void fn_8033D7D4(int, int, int, int, int, int, void *, int);
extern int fn_80388958(void);
extern unsigned short fn_80388960(void *);
extern void fn_80374BD4(int);

static inline unsigned long long add_time(unsigned long long a,
                                          unsigned long long b) {
    return a + b;
}

static inline int process_peers(char *base) {
    int off4;
    int off2;
    int k;
    int result;

    for (k = 1, off2 = 2, off4 = 4;
         k <= *(unsigned char *)(lbl_805A0FA8 + 0xD);
         off2 += 2, off4 += 4, k++) {
        int t5 = lbl_805A0FA8 + off4;
        int t9 = lbl_805A0FA8 + off2;

        result = fn_80343500(
            10,
            *(int *)(t5 + 0x108),
            *(int *)(t5 + 0x38),
            *(unsigned short *)(t9 + 0xB8),
            lbl_805A0FA8 + 0x360,
            *(int *)(lbl_805A0FA8 + 0x360) + 1
        );
        if (result != 0) {
            return result;
        }
    }

    *(unsigned char *)(lbl_805A0FA8 + 0x1A) = 0;
    *(int *)(lbl_805A0FA8 + 0x34) = 0;
    *(unsigned char *)(lbl_805A0FA8 + 0x1BC) = 1;
    fn_80374BD4(**(int **)(lbl_805A0FA8 + 4));
    *(unsigned char *)(lbl_805A0FA8 + 0x1BC) = 0;
    fn_80335638(0x40, base + 0x1280, *(int *)(lbl_805A0FA8 + 0x21C));
    return 0;
}

void fn_8034AA48(int arg0, int arg1, int arg2) {
    int i;
    int r;
    int tmp;
    int p;
    unsigned long long t;
    unsigned int q;
    char *base = lbl_8048AA60;

    fn_80335638(0x40, base + 0x1E60, arg1,
                *(int *)(lbl_805A0FA8 + 0x1B4));
    lbl_805A0F98 += 1;

    if ((unsigned int)(arg1 - 4) <= 1) {
        *(unsigned long long *)(lbl_805A0FA8 + 0x188) = 0;
        fn_80335638(4, base + 0xBC, base + 0x1E50);
    } else {
        t = OSGetTime();
        q = (*(unsigned int *)0x800000F8 >> 2) / 1000;
        t = add_time((unsigned long long)q * 30000, t);
        *(unsigned long long *)(lbl_805A0FA8 + 0x188) = t;
        fn_80335638(4, base + 0x1E88, base + 0x1E50);
    }

    switch (arg1) {
    case 5:
    default:
        goto switch_done;

    case 0:
        fn_8034B17C(arg2);
        break;

    case 4:
        *(unsigned long long *)(lbl_805A0FA8 + 0x188) = 0;
        i = 0;
        while (i < fn_8038993C(arg0)) {
            arg2 = (int)fn_80389934(arg0, i);
            if (fn_80388794((void *)arg2, base + 0x1EB8, -1) == -1) {
                r = 0;
            } else if (fn_80388794((void *)arg2, base + 0x1EC4, -1) == -1) {
                r = 0;
            } else if (fn_80388794((void *)arg2, base + 0x16C, -1) == -1) {
                r = 0;
            } else if (fn_80388794((void *)arg2, base + 0x178, -1) == -1 &&
                       fn_80388794((void *)arg2, base + 0x178, 0) == 0) {
                r = 0;
            } else if (fn_80388794((void *)arg2, base + 0x160, -1) == -1) {
                r = 0;
            } else {
                r = fn_80388794((void *)arg2, lbl_8059F0E8, 0);
            }

            if (r == 0) {
                fn_80389838(arg0, (void *)arg2);
                fn_80335638(0x400, base + 0x1ED0, i);
                i -= 1;
            }
            i += 1;
        }

        switch (*(int *)(lbl_805A0FA8 + 0x1B4)) {
        case 2:
            fn_8034B494(1);
            fn_8034B67C();
            if (fn_8038993C(arg0) != 0) {
                p = (int)fn_80389934(arg0, 0);
                r = fn_80388794((void *)p, lbl_8059F0E8, 0);
                *(unsigned char *)(lbl_805A0FA8 + 0x15) = 3;
                *(int *)(lbl_805A0FA8 + 0x108) = r;

                p = lbl_805A0FA8;
                if (*(int *)(p + 0xF8) == 0) {
                    tmp = *(int *)(p + 0x30C);
                    *(int *)(p + 0xF8) = fn_803894EC(
                        tmp, tmp, *(int *)(p + 0x310), 0, 0x14, 1, 0,
                        (void *)fn_8034AA48, 0
                    );
                }

                if (*(int *)(lbl_805A0FA8 + 0xF8) != 0 ||
                    fn_80349F28(5) == 0) {
                    *(int *)(lbl_805A0FA8 + 0x1B4) = 3;
                    r = fn_80346B10(*(int *)(lbl_805A0FA8 + 0x108), 0);
                    if (*(unsigned char *)(lbl_805A0FA8 + 0x16) == 0) {
                        fn_80349F28(r);
                    } else {
                        fn_80349C88();
                    }
                }
            } else {
                *(int *)(lbl_805A0FA8 + 0xFC) = 2;
                t = OSGetTime();
                *(unsigned long long *)(lbl_805A0FA8 + 0x100) = t;
            }
            break;

        case 4: {
            unsigned int w = *(unsigned int *)(lbl_805A0FA8 + 0x1C8);
            fn_80335638(
                4, base + 0x1EE8, (int)(w >> 24),
                (int)((w >> 16) & 0xFF), (int)((w >> 8) & 0xFF),
                (int)(w & 0xFF),
                (int)*(unsigned short *)(lbl_805A0FA8 + 0x1C6)
            );

            while (fn_8038993C(arg0) != 0) {
                int state;
                p = (int)fn_80389934(arg0, 0);
                state = lbl_805A0FA8;
                r = fn_80388958();
                if ((unsigned int)r == *(unsigned int *)(state + 0x1C8)) {
                    state = lbl_805A0FA8;
                    r = fn_80388960((void *)p);
                    if ((unsigned int)r ==
                        (unsigned int)*(unsigned short *)(state + 0x1C6)) {
                        break;
                    }
                }
                fn_80389838(arg0, (void *)p);
            }

            if (fn_8038993C(arg0) != 0) {
                p = (int)fn_80389934(arg0, 0);
                r = fn_80388794((void *)p, lbl_8059F0E8, 0);
                if (*(unsigned char *)(lbl_805A0FA8 + 0x16) == 1 &&
                    r == *(int *)(lbl_805A0FA8 + 0x108)) {
                    if (fn_8034B494(0) != 0) {
                        if (*(unsigned char *)(lbl_805A0FA8 + 0xD) != 0) {
                            int rr = process_peers(base);
                            if (*(unsigned char *)(lbl_805A0FA8 + 0x16) == 0) {
                                r = fn_80349F28(rr);
                            } else {
                                r = fn_80349C88();
                            }
                            if (r != 0) {
                                break;
                            }
                        }
                        goto start_connection;
                    } else {
                        r = fn_80343500(
                            5,
                            *(int *)(lbl_805A0FA8 + 0x108),
                            *(int *)(lbl_805A0FA8 + 0x38),
                            *(unsigned short *)(lbl_805A0FA8 + 0xB8),
                            0, 0
                        );
                        *(int *)(lbl_805A0FA8 + 0x21C) = 0;
                        if (*(unsigned char *)(lbl_805A0FA8 + 0x16) == 0) {
                            r = fn_80349F28(r);
                        } else {
                            r = fn_80349C88();
                        }
                        if (r == 0) {
                            *(int *)(lbl_805A0FA8 + 0x1B4) = 3;
                            r = fn_80346D80(
                                0, 0, *(int *)(lbl_805A0FA8 + 0x108)
                            );
                            if (*(unsigned char *)(lbl_805A0FA8 + 0x16) == 0) {
                                fn_80349F28(r);
                            } else {
                                fn_80349C88();
                            }
                        }
                    }
                    break;
                }

            start_connection:
                *(int *)(lbl_805A0FA8 + 0x1B4) = 5;
                fn_80343118(0, 0, fn_80389934(arg0, 0));
                fn_8034A500();
            } else {
                *(int *)(lbl_805A0FA8 + 0xFC) = 2;
                t = OSGetTime();
                *(unsigned long long *)(lbl_805A0FA8 + 0x100) = t;
            }
            break;
        }

        case 12:
            r = fn_8038993C(arg0);
            if (r != 0) {
                fn_80335638(0x200400, base + 0x1F10, r);
                p = lbl_805A0FA8;
                r = fn_80388794(fn_80389934(arg0, 0), lbl_8059F0E8, 0);
                fn_8033D7D4(
                    r,
                    *(int *)(p + 0x480),
                    *(int *)(p + 0x484),
                    *(int *)(p + 0x488),
                    *(int *)(p + 0x48C),
                    *(int *)(p + 0x4C8),
                    (void *)(p + 0x4CC),
                    *(int *)(p + 0x554)
                );
            } else {
                *(int *)(lbl_805A0FA8 + 0xFC) = 2;
                t = OSGetTime();
                *(unsigned long long *)(lbl_805A0FA8 + 0x100) = t;
                fn_80335638(0x200400, base + 0x1F34);
            }
            break;

        case 13:
            if (fn_8038993C(*(int *)(lbl_805A0FA8 + 0xF8))) {
                r = fn_80346B10(*(int *)(lbl_805A0FA8 + 0x108), 0);
                if (*(unsigned char *)(lbl_805A0FA8 + 0x16) == 0) {
                    r = fn_80349F28(r);
                } else {
                    r = fn_80349C88();
                }
                if (r != 0) {
                    return;
                }
                *(int *)(lbl_805A0FA8 + 0x1B4) = 3;
            } else {
                fn_80342BA8(*(int *)(lbl_805A0FA8 + 0x108));
            }
            break;

        default:
            break;
        }
        break;
    }

switch_done:
    lbl_805A0F98 -= 1;
}

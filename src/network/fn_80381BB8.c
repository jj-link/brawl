#include <types.h>
#pragma force_active on

typedef struct { unsigned char reserved[8]; const unsigned short *classes; } CTypeMap;
typedef struct { unsigned char reserved[0x38]; CTypeMap *ctype; } Locale;
extern Locale lbl_804942B8;

typedef struct { char c[11]; } Str11;
extern Str11 lbl_80415D70;

extern char lbl_804908D0[];
extern char lbl_8059FAD0[3];
extern char lbl_8059FAE4[3];
extern char lbl_8059FAE8[5];

extern void *fn_8035DFE8(int);
extern void fn_8035E00C(void *);
extern int fn_8037BFCC(void *, void *, int *);
extern int fn_8037B644(void *, void *, int);
extern int fn_8037BE7C(void *);
extern void fn_8037BBB8(void *);
extern void fn_8037BDD4(void *, int, int);
extern void fn_8038194C(void *, void *, int);
extern void fn_803F602C(void *, void *, int);
extern int fn_8035C658(int);
extern char *fn_8035D654(char *);
extern int sprintf(char *, const char *, ...);
extern int strlen(const char *);
extern int strncmp(const char *, const char *, unsigned int);
extern char *strstr(const char *, const char *);
extern int atoi(const char *);

#define F(off, type) (*(type *)((char *)(arg0) + (off)))

static inline int IsSpace(int c) {
    return (c < 0 || c >= 256) ? 0 : lbl_804942B8.ctype->classes[c] & 0x100;
}

void fn_80381BB8(void *arg0) {
    char *tbl = lbl_804908D0;
    char *r31;
    char *hdr;
    void *buffer;
    char *r28;
    char *r27;
    int cnt;
    char *s;
    char *e;
    char *r25;
    char *r24;
    char *p;
    int nl;
    char *base;
    int r22;
    int sp8;
    int retcode;
    Str11 spC;
    int r3;
    int r5;

    r22 = 1;
    buffer = fn_8035DFE8(0x1000);
    if (buffer == 0) {
        F(0x120, int) = 1;
        F(0x3c, int) = 1;
        return;
    }
    sp8 = 0x1000;
    retcode = fn_8037BFCC(arg0, buffer, &sp8);
    if (retcode != 3 && retcode != 1) {
        if (retcode == 0) {
            if (F(0x194, int) != 0) {
                if (fn_8037B644((char *)arg0 + 0xC0, buffer, sp8) == 0) {
                    goto tail;
                }
                if (fn_8037BE7C(arg0) == 0) {
                    F(0x120, int) = 1;
                    F(0x3c, int) = 0x11;
                    goto tail;
                }
            } else {
                if (fn_8037B644((char *)arg0 + 0x9C, buffer, sp8) == 0) {
                    goto tail;
                }
            }
        }
        r28 = F(0xa0, char *) + F(0x11c, int);
        if (F(0x114, int) / 100 == 1 &&
            (strncmp(r28, lbl_8059FAD0, 2) == 0 || strncmp(r28, lbl_8059FAE4, 2) == 0)) {
            p = r28;
            r22 = 0;
        } else {
            p = strstr(r28, lbl_8059FAE8);
        }
        if (p == 0) {
            p = strstr(r28, lbl_8059FAE4);
        }
        if (p != 0) {
            if (r22 == 1) {
                p += 2;
            }
            *p = 0;
            r27 = p + 2;
            base = F(0xa0, char *);
            cnt = F(0xa8, int) - (int)(r27 - base);
            nl = (int)(p - base) + 1;
            F(0xa8, int) = nl;
            F(0xac, int) = nl;
            if (F(0x114, int) / 100 == 1) {
                if (cnt != 0) {
                    fn_803F602C(base, r27, cnt + 1);
                    F(0xa8, int) = cnt;
                } else {
                    fn_8037BBB8((char *)arg0 + 0x9C);
                }
                if (F(0x17c, int) != 0) {
                    F(0x17c, int) = 0;
                    F(0x10, int) = 6;
                    fn_8037BDD4(arg0, 0, 0);
                }
                F(0x10, int) = 8;
                fn_8037BDD4(arg0, 0, 0);
            } else if (F(0x114, int) / 100 == 3) {
                if (F(0x130, int) > 0xA) {
                    F(0x120, int) = 1;
                    F(0x3c, int) = 0xB;
                } else {
                    hdr = strstr(r28, tbl + 0x80);
                    if (hdr != 0) {
                        s = hdr + 9;
                        while (IsSpace(*s)) {
                            s++;
                        }
                        e = s;
                        while (*e != 0 && !IsSpace(*e)) {
                            e++;
                        }
                        *e = 0;
                        if (*s == '/') {
                            F(0x12c, char *) = fn_8035DFE8(strlen(F(0x18, char *)) + strlen(s) + 0xE);
                            if (F(0x12c, char *) == 0) {
                                F(0x120, int) = 1;
                                F(0x3c, int) = 1;
                            }
                            sprintf(F(0x12c, char *), tbl + 0x8C, F(0x18, char *),
                                    F(0x20, unsigned short), s);
                        } else {
                            F(0x12c, char *) = fn_8035D654(s);
                            if (F(0x12c, char *) == 0) {
                                F(0x120, int) = 1;
                                F(0x3c, int) = 1;
                            }
                        }
                        goto tail;
                    }
                    goto blk56;
                }
            } else {
            blk56:
                r31 = strstr(r28, tbl + 0xA0);
                if (r31 != 0) {
                    spC = lbl_80415D70;
                    r25 = r31 + 0x10;
                    r24 = r25;
                    r3 = strlen(spC.c);
                    while (r24 != 0 && *r24 != 0 && *r24 != '\n' && *r24 != '\r' && *r24 != ' ') {
                        r24++;
                    }
                    r5 = (int)(r24 - r25);
                    if (r5 > r3) {
                        F(0x120, int) = 1;
                        F(0x3c, int) = 0x10;
                        goto tail;
                    }
                    if (r3 == r5 && strncmp(r25, spC.c, r5) >= 0) {
                        F(0x120, int) = 1;
                        F(0x3c, int) = 0x10;
                        goto tail;
                    }
                    F(0x128, int) = atoi(r25);
                }
                r3 = (int)strstr(r28, tbl + 0xB0);
                F(0x134, unsigned int) = ((unsigned int)(-r3 | r3)) >> 31;
                if (F(0x134, int) != 0) {
                    F(0x138, unsigned char) = 0;
                    F(0x144, int) = 0;
                    F(0x148, int) = 0;
                    F(0x14c, int) = 0;
                }
                if ((unsigned int)(F(0xc, int) - 3) <= 1U) {
                    F(0x120, int) = 1;
                } else {
                    F(0x10, int) = 0xA;
                    if (r31 != 0 && F(0x128, int) == 0) {
                        F(0x120, int) = 1;
                    } else if (cnt > 0) {
                        fn_8038194C(arg0, r27, cnt);
                    }
                }
            }
        } else if (retcode == 2) {
            F(0x120, int) = 1;
            F(0x3c, int) = 7;
            F(0x50, int) = fn_8035C658(F(0x4c, int));
        }
    }
tail:
    fn_8035E00C(buffer);
}

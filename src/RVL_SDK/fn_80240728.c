#pragma force_active on
#include <internal/mem.h>

extern char lbl_80529CF8[];
extern char lbl_80481A9C[];
extern char *fn_8023A0F0(void *);
extern void fn_80231A14(int, void *, int, int);
extern unsigned char fn_80241D40(void *);
extern unsigned char fn_80244B64(unsigned short, int);

typedef void (*NameCallback)(void *, char *, char *);
typedef void (*InfoCallback)(char *, char *, char *, char *, int);
typedef void (*DoneCallback)(char *, void *, int);

void fn_80240728(void *arg0, void *arg1, int arg2)
{
    char *p;
    char *q;
    int i;
    int j;

    if (arg0 != 0) {
        p = fn_8023A0F0(arg0);
    } else {
        p = lbl_80529CF8 + 0x1F30;
        for (j = 0; j < 16; j++, p += 0x88) {
            if ((*(unsigned char *)(p + 0x76) & 0x80) &&
                *(unsigned char *)(p + 0x7F) == 3)
                break;
        }
        if (j == 16)
            p = 0;
    }
    if (*(unsigned char *)(lbl_80529CF8 + 0x27C0) >= 4) {
        fn_80231A14(0xD0003, lbl_80481A9C, arg2,
                    p ? *(unsigned char *)(p + 0x7F) : 0);
    }
    if (p != 0) {
        if (arg2 == 0) {
            int k;
            memcpy(p + 0x35, arg1, 0x40);
            *(unsigned char *)(p + 0x76) |= 8;
            q = lbl_80529CF8;
            for (k = 0; k < 2; k++) {
                NameCallback f = *(NameCallback *)(q + 0x192C);
                if (f)
                    f(arg0, p + 0x22, p + 0x35);
                q += 4;
            }
        }
        if (*(unsigned char *)(p + 0x82) != 0) {
            InfoCallback f;
            if ((*(unsigned char *)(p + 0x81) & 0x40) &&
                *(unsigned char *)(p + 0x85) == 0)
                return;
            *(unsigned char *)(p + 0x82) = 0;
            f = *(InfoCallback *)(lbl_80529CF8 + 0x1914);
            if (f)
                f(p + 0x1C, p + 0x22, p + 0x35, p + 0x25,
                  *(unsigned char *)(p + 0x83));
            q = lbl_80529CF8;
            for (i = 0; i < 2; i++) {
                f = *(InfoCallback *)(q + 0x1924);
                if (f)
                    f(p + 0x1C, p + 0x22, p + 0x35, p + 0x25,
                      *(unsigned char *)(p + 0x83));
                q += 4;
            }
        }
        if ((*(unsigned char *)(p + 0x81) & 0x40) &&
            (*(unsigned char *)(p + 0x76) & 2)) {
            *(unsigned char *)(p + 0x81) &= ~0x50;
            fn_80244B64(*(unsigned short *)(p + 0x18), 0x13);
            return;
        }
        if (*(unsigned char *)(p + 0x7F) == 3) {
            *(unsigned char *)(p + 0x7F) = 0;
            if (arg2 != 0) {
                DoneCallback f = *(DoneCallback *)(p + 4);
                if (f) {
                    f(p + 0x1C, *(void **)(p + 8), 0xA);
                    *(DoneCallback *)(p + 4) = 0;
                }
            } else {
                unsigned char result = fn_80241D40(p);
                if (result != 1) {
                    DoneCallback f = *(DoneCallback *)(p + 4);
                    if (f) {
                        f(p + 0x1C, *(void **)(p + 8), result);
                        *(DoneCallback *)(p + 4) = 0;
                    }
                }
            }
        }
    }
}

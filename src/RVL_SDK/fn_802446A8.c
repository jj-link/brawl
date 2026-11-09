#include <types.h>
#pragma force_active on
extern unsigned char lbl_8052C4C0[];
extern char lbl_80482278[];
extern void fn_80231A14(unsigned int, const char *, int, int);
extern void *fn_8023C8BC(void);
extern unsigned char fn_8023C69C(void *, void (*)(unsigned char *));
extern void fn_80244490(unsigned char *);

void fn_802446A8(unsigned char *arg) {
    unsigned char *base = lbl_8052C4C0;
    unsigned short *result = (unsigned short *)(base + 0x34);
    unsigned short value;
    void *p;
    if (base[0x7e]) {
        if (base[0x28] >= 4) {
            fn_80231A14(0xe0003, lbl_80482278, arg[0], arg[1]);
        }
        if (arg[0] == 0) {
            *result = 0x111;
            p = fn_8023C8BC();
            *(void **)(base + 0x30) = p;
            if (p != 0) {
                if (fn_8023C69C((unsigned char *)p + 2, fn_80244490) == 1)
                    return;
                switch (arg[0]) {
                case 0: value = 0; break;
                case 1: value = 0x10b; break;
                case 2: value = 0x103; break;
                case 4: case 5: value = 0x109; break;
                case 6: value = 0x10c; break;
                case 7: value = 0x10d; break;
                case 8: value = 0x115; break;
                default: value = 0x114; break;
                }
                *result = value;
            } else {
                *result = 0x102;
            }
        } else {
            switch (arg[0]) {
            case 0: value = 0; break;
            case 1: value = 0x10b; break;
            case 2: value = 0x103; break;
            case 4: case 5: value = 0x109; break;
            case 6: value = 0x10c; break;
            case 7: value = 0x10d; break;
            case 8: value = 0x115; break;
            default: value = 0x114; break;
            }
            *result = value;
        }
        if (*(void (**)(int, void *))(base + 0x2c)) {
            (*(void (**)(int, void *))(base + 0x2c))(5, result);
        }
        base[0x7e] = 0;
        *(void (**)(int, void *))(base + 0x2c) = 0;
    }
}
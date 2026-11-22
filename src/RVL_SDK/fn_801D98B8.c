#include <types.h>
#pragma force_active on

extern void fn_801D7184(int);
extern void fn_801D716C(int);
extern unsigned int fn_801D718C(int, int);
extern int fn_80211080(void);
extern int fn_8021111C(long long, unsigned int);
extern int fn_802112C8(long long, unsigned int, int *);

void fn_801D98B8(void)
{
    unsigned int sp8;
    int r;
    unsigned int buf;

    sp8 = 1;
    fn_801D7184(0x81280000);
    fn_801D716C(0x812F0000);

    if (fn_80211080() == 0) {
        r = fn_802112C8(0x100000002LL, 0, (int *)&sp8);
        if (sp8 == 1) {
            switch (r) {
            case 0:
                buf = fn_801D718C((sp8 * 0xD8 + 0x1F) & ~0x1F, 0x20);
                if (fn_802112C8(0x100000002LL, buf, (int *)&sp8) == 0) {
                    if (fn_8021111C(0x100000002LL, buf) == 0) {
                        for (;;) {
                        }
                    }
                }
                break;
            default:
                break;
            }
        }
    }
}
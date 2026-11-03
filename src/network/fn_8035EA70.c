#include <string.h>
#pragma force_active on
extern unsigned int fn_8035D728(void);
extern void fn_8035DA18(int);
extern int fn_8035DA30(int, int);
extern int fn_803607C4(int *, void *, void *, int *);
extern int fn_803612EC(int *);
int fn_8035EA70(void *arg0, void *arg1, unsigned int arg2, void *arg3) {
    int size;
    unsigned char buf[0x104];
    unsigned int i;
    unsigned char *p = buf;
    unsigned int n;
    if (arg2 > 0x75) return -1;
    p[0] = 0;
    p[1] = 2;
    fn_8035DA18(fn_8035D728());
    n = 0x7d - arg2;
    for (i = 0; i < n; i++) {
        p[i + 2] = fn_8035DA30(0, 0xff) + 1;
    }
    (p + n)[2] = 0;
    memcpy(p + (0x7e - arg2) + 2, arg1, arg2);
    size = 0x20;
    if (!fn_803612EC(&size) || !fn_803607C4(&size, (char *)arg0 + 0x104, arg0, &size) || !fn_803612EC(&size)) return -1;
    memcpy(arg3, buf, 0x80);
    return 0;
}
#include <types.h>
#pragma force_active on

extern unsigned int SOHtoNl(unsigned int);
extern void *memcpy(void *, const void *, unsigned long);
extern int fn_8038CFA4(void *self, unsigned int a, unsigned short b, const void *data, int length);

void fn_8038D0A8(void *arg0, unsigned int arg1, unsigned short arg2, unsigned int arg3) {
    int val;
    unsigned char buf[10];

    val = arg3;
    buf[0] = 0xFD;
    buf[1] = 0xFC;
    buf[2] = 0x1E;
    buf[3] = 0x66;
    buf[4] = 0x6A;
    buf[5] = 0xB2;
    val = SOHtoNl(arg3);
    memcpy(buf + 6, &val, 4);
    fn_8038CFA4(arg0, arg1, arg2, buf, 10);
}

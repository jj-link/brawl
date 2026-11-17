#include <string.h>
#pragma force_active on

extern void fn_80242908(void *p);

void fn_8024629C(void *arg0, char *arg1) {
    unsigned char *base;
    int len;
    int r8;
    int r5;
    unsigned char *dst;
    int i;
    unsigned int ctr;
    const unsigned char *s;

    base = (unsigned char *)arg0;
    len = (unsigned short)(strlen(arg1) + 1);
    *(unsigned short *)(base + 2) = 0xFB;
    *(unsigned short *)(base + 4) = 0;
    base[8] = 0x13;
    base[9] = 0x0C;
    base[10] = 0xF8;
    dst = base + 0xB;
    for (i = 0; i < len; i++) {
        *dst++ = arg1[i];
    }
    fn_80242908(base);
}
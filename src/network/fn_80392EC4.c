#include <string.h>
#pragma force_active on

extern char lbl_80491668[];

unsigned long fn_80392EC4(char *arg0, const char *arg1)
{
    char *table = lbl_80491668;
    char *dst = arg0;
    int len = strlen(arg1);
    int i = 0;
    for (; i < len; i += 3) {
        dst[0] = table[arg1[0] >> 2];
        dst[1] = table[((arg1[0] << 4) & 0x30) + (arg1[1] >> 4)];
        dst[2] = table[((arg1[1] << 2) & 0x3c) + (arg1[2] >> 6)];
        dst[3] = table[arg1[2] & 0x3f];
        arg1 += 3;
        dst += 4;
    }

    if (i == len + 1) {
        dst[-1] = '=';
    } else if (i == len + 2) {
        dst[-2] = '=';
        dst[-1] = '=';
    }

    *dst = 0;
    return strlen(arg0);
}

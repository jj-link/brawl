#include <types.h>
#pragma force_active on

int fn_80362510(unsigned int arg0, unsigned char *arg1) {
    if (arg0 <= 0x7F) {
        arg1[0] = (unsigned char)arg0;
        return 1;
    }
    if (arg0 <= 0x7FF) {
        arg1[0] = ((arg0 >> 6) & 0x3FF) | 0xC0;
        arg1[1] = (arg0 & 0x3F) | 0x80;
        return 2;
    }
    arg1[0] = ((arg0 >> 12) & 0x0F) | 0xE0;
    arg1[1] = ((arg0 >> 6) & 0x3F) | 0x80;
    arg1[2] = (arg0 & 0x3F) | 0x80;
    return 3;
}
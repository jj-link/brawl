#include <string.h>
#include <revolution/NET/crc.h>
#pragma force_active on

extern char lbl_8059C570[6];

extern "C" void fn_8001B9EC(char* dest, const char* src) {
    char* out = dest + 5;
    strcpy(dest, lbl_8059C570);
    int crc = NETCalcCRC16(src, strlen(src));
    for (int i = 0; i < 4; i++) {
        int digit = (crc >> ((3 - i) * 4)) & 15;
        if (digit < 10)
            out[i] = digit + '0';
        else
            out[i] = digit + 'a' - 10;
    }
    out[4] = 0;
}

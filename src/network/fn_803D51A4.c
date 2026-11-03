#include <types.h>
#pragma force_active on

extern int fn_803D4CB8(unsigned int);

u16 fn_803D51A4(void) {
    u16 count = 0;
    unsigned int i = 0;
    do {
        int result;
        if ((u16)i >= 100U) {
            result = 0;
        } else {
            result = fn_803D4CB8((u16)i) != 0;
        }
        if (result != 0) {
            count++;
        }
        i++;
    } while (i < 100U);
    return count;
}
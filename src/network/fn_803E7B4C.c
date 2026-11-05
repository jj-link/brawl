#include <types.h>
#pragma force_active on

s32 fn_803E7B4C(s8* buf) {
    s32 i = 0;
    s32 count = 0;
    
    while (buf[i] != 0) {
        if (i == 8) {
            if (buf[i] != 0x20 || buf[i+1] != 0x20 || buf[i+2] != 0x20) {
                count++;
            }
        }
        
        if (buf[i] != 0x20) {
            count++;
        }
        
        i++;
    }
    return count;
}
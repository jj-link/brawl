#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_8018F0A4(void** arg0) {
    char* p = (char*)*arg0;
    s32 off = *(s32*)(p + 0x1c);
    char* q;
    if (off != 0) {
        q = p + off;
    } else {
        q = 0;
    }
    if (q != 0) {
        return *(s32*)(q + 0x4);
    }
    return 0;
}
}

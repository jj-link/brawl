#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_800BA178(s32 arg0) {
    s32 r;
    if (arg0 & 8) {
        if (arg0 & 2) {
            r = 1;
        } else if (arg0 & 1) {
            r = 7;
        } else {
            r = 0;
        }
    } else if (arg0 & 4) {
        if (arg0 & 2) {
            r = 3;
        } else if (arg0 & 1) {
            r = 5;
        } else {
            r = 4;
        }
    } else if (arg0 & 2) {
        r = 2;
    } else if (arg0 & 1) {
        r = 6;
    } else {
        r = 8;
    }
    return r;
}
}

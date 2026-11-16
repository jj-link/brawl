#include <types.h>
#pragma force_active on

s32 fn_803EB3BC(const s8 *arg0) {
    s32 mode;
    s32 i;

    if (arg0 == 0) return 10;
    i = 1;
    switch (arg0[0]) {
    case 'r': mode = 2; break;
    case 'w': mode = 1; break;
    case 'a': mode = 4; break;
    default: return 0;
    }
    if (arg0[1] == 'b') i = 2;
    switch (arg0[i++]) {
    case 0: return mode;
    case 't':
    default: return 0;
    case '+':
        switch (arg0[i]) {
        case 0: return mode | 8;
        default: return 0;
        }
    }
}
#include <types.h>
#pragma force_active on

extern "C" void fn_801A7A9C(s32** arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32* temp = *arg0;
    if (temp != NULL) {
        temp[0xf4 / 4] = arg1;
        temp[0xf8 / 4] = arg2;
        temp[0xfc / 4] = arg3;
        temp[0x100 / 4] = arg4;
    }
}

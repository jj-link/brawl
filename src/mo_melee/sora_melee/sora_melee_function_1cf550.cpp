#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1CF550(void* obj) {
    s32 val = *(s32*)((char*)obj + 8);
    return val >> 29;
}

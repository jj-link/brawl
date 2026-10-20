#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_CE6EC(void* obj) {
    s32 v = *(s32*)((char*)obj + 8);
    return (v >> 4) & 1;
}

#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_FEE5C(void* p) {
    s32 val = *(s32*)((char*)p + 8);
    return val >> 27;
}

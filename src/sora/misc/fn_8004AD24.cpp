#include <types.h>
#pragma force_active on

extern "C" s32 fn_8004B738(s32);

extern "C" s32 fn_8004AD24(void* p) {
    s32 r = 0;
    s32 t = *(s32*)((char*)p + 0x18);
    if (t != 0) {
        r = fn_8004B738(t);
    }
    return r;
}

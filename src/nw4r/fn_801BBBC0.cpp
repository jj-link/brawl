#include <types.h>
#pragma force_active on

extern "C" {

s32 fn_802049BC(s32, s32, s32);

s32 fn_801BBBC0(void* self, s32 arg1, s32 arg2) {
    s32 result = fn_802049BC(arg1, arg2, 0);
    ((s32*)self)[1] = result;
    return (result != 0);
}

}

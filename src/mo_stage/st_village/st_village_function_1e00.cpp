#include <types.h>
#pragma force_active on

extern "C" const f32 lbl_70_rodata_0;

extern "C" s32 fn_70_1E00(void* self, f32* out) {
    s32 result = 0;
    const f32* value = (const f32*)((const char*)&lbl_70_rodata_0 + result);
    out[0] = *value;
    out[1] = *value;
    out[2] = *value;
    return result;
}

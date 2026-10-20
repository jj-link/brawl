#include <types.h>
#pragma force_active on

extern const float lbl_41_rodata_18;

extern "C" {
float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* acc, u32 id, u32 index);
void* getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(void* acc, u32 id, u32 index);

struct Self {
    u8 pad[0xdc];
    unsigned char acc;
};

float fn_41_38B8(Self* self) {
    float mul = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(&self->acc, 0x1100000C, 0);
    float* p = (float*)getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(&self->acc, 0xA815, 0);
    float val1 = p[0];
    float val2 = p[1];
    if (lbl_41_rodata_18 != val2) {
        val1 = val1 + val2 * mul;
    }
    return val1;
}
}

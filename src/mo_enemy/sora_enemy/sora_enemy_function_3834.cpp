#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

extern const float lbl_41_rodata_18;

struct Self {
    u8 pad0[0xdc];
    soModuleAccesser acc;
};

extern "C" float fn_41_3834(Self* self) {
    float f31 = soValueAccesser::getValueFloat(&self->acc, 0x1100000C, 0);
    void* p = soValueAccesser::getConstantIndefinite(&self->acc, 0x10000 - 0x57EC, 0);
    float f1 = *(float*)p;
    float f2 = *(float*)((u8*)p + 4);
    if (lbl_41_rodata_18 != f2) {
        f1 += f2 * f31;
    }
    return f1;
}

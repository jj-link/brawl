#include <so/so_value_accesser.h>
#pragma force_active on

struct FnObj {
    char pad0[0x24];
    float f24;
    float f28;
    char pad2[0x68 - 0x2C];
    float f68;
};

extern "C" float fn_41_1B044(float a, float b, float c, float d);

extern "C" void fn_41_1F348(FnObj* self, soModuleAccesser* acc, float p) {
    float v = soValueAccesser::getValueFloat(acc, 0x1100000C, 0);
    self->f24 = fn_41_1B044(p, self->f28, self->f68, v);
}

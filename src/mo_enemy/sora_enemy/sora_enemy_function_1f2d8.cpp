#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" float fn_41_1B044(float a, float b, float c, float d);

extern "C" void fn_41_1F2D8(u8* self, soModuleAccesser* acc, float f) {
    float v = soValueAccesser::getValueFloat(acc, 0x1100000C, 0);
    float r = fn_41_1B044(f, *(float*)(self + 0x20), *(float*)(self + 0x68), v);
    *(float*)(self + 0x1c) = r;
}

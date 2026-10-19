#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" float fn_41_393C(void* self);

extern "C" float fn_41_502F4(char* self) {
    float f31 = fn_41_393C(self);
    float f1 = soValueAccesser::getValueFloat((soModuleAccesser*)(self + 0xdc), 0x11000008, 0);
    return f31 * f1;
}

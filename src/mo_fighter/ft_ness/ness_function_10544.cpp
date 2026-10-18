#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_27_160770(int kind, const Vec2f* vector, void* state, soModuleAccesser* accesser);

extern "C" void fn_101_10544(void* object, int kind, const Vec2f* vector, soModuleAccesser* accesser) {
    fn_27_160770(kind, vector, static_cast<unsigned char*>(object) + 4, accesser);
}

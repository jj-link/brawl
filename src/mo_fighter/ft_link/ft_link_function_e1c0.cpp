#include <mt/mt_vector.h>
#pragma force_active on

class soModuleAccesser;

extern "C" {
extern void fn_27_1603F4(const Vec2f* vector, void* state, soModuleAccesser* accesser);

void fn_93_E1C0(void* object, const Vec2f* vector, soModuleAccesser* accesser);
}

extern "C" void fn_93_E1C0(void* object, const Vec2f* vector, soModuleAccesser* accesser) {
    fn_27_1603F4(vector, static_cast<u8*>(object) + 4, accesser);
}

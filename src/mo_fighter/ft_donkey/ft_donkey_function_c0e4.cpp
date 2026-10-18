#include <mt/mt_vector.h>
#pragma force_active on

class soModuleAccesser;
extern "C" void fn_27_1603F4(const Vec2f* vector, void* state, soModuleAccesser* accesser);

extern "C" void fn_92_C0E4(void* object, const Vec2f* vector, soModuleAccesser* accesser) {
    fn_27_1603F4(vector, static_cast<u8*>(object) + 4, accesser);
}

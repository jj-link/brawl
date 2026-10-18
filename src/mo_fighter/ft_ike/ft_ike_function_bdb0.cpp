#include <mt/mt_vector.h>
#pragma force_active on

class soModuleAccesser;
extern "C" void fn_27_160770(int kind, const Vec2f* vector, void* state, soModuleAccesser* accesser);

extern "C" void fn_119_BDB0(void* object, int kind, const Vec2f* vector, soModuleAccesser* accesser) {
    fn_27_160770(kind, vector, static_cast<u8*>(object) + 4, accesser);
}

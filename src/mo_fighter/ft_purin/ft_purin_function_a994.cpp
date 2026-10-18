#include <types.h>
#pragma force_active on

struct Vec2f;
class soModuleAccesser;

extern "C" void fn_27_160770(int kind, const Vec2f* vector, void* state, soModuleAccesser* accesser);

extern "C" {
void fn_124_A994(void* object, int kind, const Vec2f* vector, soModuleAccesser* accesser)
{
    fn_27_160770(kind, vector, static_cast<unsigned char*>(object) + 4, accesser);
}
}

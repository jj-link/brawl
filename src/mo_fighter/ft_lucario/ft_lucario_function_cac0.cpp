#pragma force_active on
typedef unsigned char u8;
class soModuleAccesser;
struct Vec2f { float x, y, z; };

extern "C" void fn_27_1603F4(const Vec2f* vector, void* state, soModuleAccesser* accesser);

extern "C" void fn_118_CAC0(void* object, const Vec2f* vector, soModuleAccesser* accesser) {
    fn_27_1603F4(vector, static_cast<u8*>(object) + 4, accesser);
}

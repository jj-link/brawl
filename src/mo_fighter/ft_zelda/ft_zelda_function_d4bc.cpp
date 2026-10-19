#pragma force_active on

struct Vec2f;
class soModuleAccesser;

extern "C" void fn_27_1603F4(const Vec2f* vector, void* state, soModuleAccesser* accesser);

extern "C" void fn_104_D4BC(void* object, const Vec2f* vector, soModuleAccesser* accesser) {
    fn_27_1603F4(vector, static_cast<unsigned char*>(object) + 4, accesser);
}

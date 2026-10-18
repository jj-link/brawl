#pragma force_active on
class soModuleAccesser;
struct Vec2f;

extern "C" void fn_27_160770(int kind, const Vec2f* vector, void* state, soModuleAccesser* accesser);

extern "C" void fn_98_CCF0(void* object, int kind, const Vec2f* vector, soModuleAccesser* accesser) {
    fn_27_160770(kind, vector, static_cast<unsigned char*>(object) + 4, accesser);
}

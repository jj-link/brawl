#pragma force_active on
struct Vec2f;
struct soModuleAccesser;

extern "C" void fn_27_160770(int kind, const Vec2f* vector, void* state, soModuleAccesser* accesser);

extern "C" void fn_114_FDA4(unsigned char* object, int kind, const Vec2f* vector, soModuleAccesser* accesser) {
    fn_27_160770(kind, vector, object + 4, accesser);
}

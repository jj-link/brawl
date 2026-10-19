#pragma force_active on
struct soModuleAccesser;
struct Vec2f { float x; float y; };
struct Vec3f { float x; float y; float z; };

extern "C" void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);

extern const float lbl_27_rodata_1FC0;

extern "C" void fn_27_162420(int, int, Vec2f* a, soModuleAccesser* b) {
    float f = lbl_27_rodata_1FC0;
    Vec3f zero = { f, f, f };
    fn_27_89D08(0, b, 0, a, &zero);
}

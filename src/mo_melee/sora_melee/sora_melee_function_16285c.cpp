#pragma force_active on
class soModuleAccesser;
struct Vec2f { float x; float y; };
struct Vec3f { float x; float y; float z; };

extern "C" {
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
void fn_27_16285C(int, int, Vec2f* v, soModuleAccesser* accesser) {
    Vec3f zero = { lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0 };
    fn_27_89D08(0, accesser, 4, v, &zero);
}
}

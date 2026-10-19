#pragma force_active on
struct Vec2f { float x; float y; };
struct Vec3f { float x; float y; float z; };
class soModuleAccesser;

extern "C" {
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
}

extern const float lbl_27_rodata_1FC0;

extern "C" {
void fn_27_162468(int, int, Vec2f* motion, soModuleAccesser* accesser) {
    Vec3f zero;
    zero.x = lbl_27_rodata_1FC0;
    zero.y = lbl_27_rodata_1FC0;
    zero.z = lbl_27_rodata_1FC0;
    fn_27_89D08(0, accesser, 1, motion, &zero);
}
}

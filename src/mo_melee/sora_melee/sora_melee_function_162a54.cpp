#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

class soModuleAccesser;

extern "C" {
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int, soModuleAccesser*, int, Vec3f*, Vec3f*);
}

extern "C" {
void fn_27_162A54(int, int, Vec3f* a, soModuleAccesser* b) {
    Vec3f zero;
    float z = lbl_27_rodata_1FC0;
    zero.x = z;
    zero.y = z;
    zero.z = z;
    fn_27_89D08(0, b, 11, a, &zero);
}
}

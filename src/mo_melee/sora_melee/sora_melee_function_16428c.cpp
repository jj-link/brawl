#pragma force_active on
struct soModuleAccesser;
struct Vec2f {
    float x;
    float y;
};
struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" {
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);

void fn_27_16428C(int, int, Vec2f* v, soModuleAccesser* accesser) {
    Vec3f zero;
    zero.x = lbl_27_rodata_1FC0;
    zero.y = lbl_27_rodata_1FC0;
    zero.z = lbl_27_rodata_1FC0;
    fn_27_89D08(3, accesser, 14, v, &zero);
}
}

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

extern "C" void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
extern "C" extern const float lbl_27_rodata_1FC0;

extern "C" {
void fn_27_161F80(int, int, Vec2f* a2, soModuleAccesser* a3) {
    Vec3f zero = {lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0};
    fn_27_89D08(3, a3, 0, a2, &zero);
}
}

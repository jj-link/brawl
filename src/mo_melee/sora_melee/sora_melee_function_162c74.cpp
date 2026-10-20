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
void fn_27_162C74(int, int, int, soModuleAccesser* a4) {
    Vec3f v3 = {lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0};
    Vec2f v2 = {lbl_27_rodata_1FC0, lbl_27_rodata_1FC0};
    fn_27_89D08(2, a4, 6, &v2, &v3);
}
}

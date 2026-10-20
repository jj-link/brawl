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
extern "C" const float lbl_27_rodata_1FC0;

extern "C" {
void fn_27_1641F4(int a1, int a2, Vec2f* a3, soModuleAccesser* a4, int a5, int a6) {
    Vec3f zero = {lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0};
    fn_27_89D08(2, a4, 10, a3, &zero);
}
}

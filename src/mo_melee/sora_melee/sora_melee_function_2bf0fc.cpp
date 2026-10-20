#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" const float lbl_27_rodata_5FB4;

extern "C" void fn_27_2BF0FC(Vec3f *v) {
    v->x = lbl_27_rodata_5FB4;
    v->y = lbl_27_rodata_5FB4;
    v->z = lbl_27_rodata_5FB4;
}

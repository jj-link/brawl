#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern const float lbl_27_rodata_B70;

extern "C" void fn_27_7C61C(Vec3f* v) {
    v->x = lbl_27_rodata_B70;
    v->y = lbl_27_rodata_B70;
    v->z = lbl_27_rodata_B70;
}

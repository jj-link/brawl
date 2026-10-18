#pragma force_active on
struct Vec3 {
    float x;
    float y;
    float z;
};

extern const float lbl_27_rodata_B70;

extern "C" void fn_27_7D51C(Vec3 *v) {
    v->x = lbl_27_rodata_B70;
    v->y = lbl_27_rodata_B70;
    v->z = lbl_27_rodata_B70;
}

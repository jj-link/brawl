#pragma force_active on
struct Vec3 {
    float x;
    float y;
    float z;
};

extern const float lbl_27_rodata_B70;

extern "C" {
void fn_27_7D4E0(Vec3 *v) {
    float f = lbl_27_rodata_B70;
    v->x = f;
    v->y = f;
    v->z = f;
}
}

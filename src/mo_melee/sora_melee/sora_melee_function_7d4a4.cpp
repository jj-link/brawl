#pragma force_active on
extern const float lbl_27_rodata_B70;

struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" {
void fn_27_7D4A4(Vec3f *v) {
    float f = lbl_27_rodata_B70;
    v->x = f;
    v->y = f;
    v->z = f;
}
}

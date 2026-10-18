#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern const float lbl_27_rodata_B74;

extern "C" {
void fn_27_7C750(Vec3f* v) {
    float c = lbl_27_rodata_B74;
    v->x = c;
    v->y = c;
    v->z = c;
}
}

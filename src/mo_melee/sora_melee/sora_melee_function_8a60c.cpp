#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern const float lbl_27_rodata_BA8;

extern "C" void fn_27_8A60C(Vec3f* v) {
    float f = lbl_27_rodata_BA8;
    v->x = f;
    v->y = f;
    v->z = f;
}

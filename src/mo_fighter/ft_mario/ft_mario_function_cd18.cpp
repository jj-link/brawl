#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};
extern "C" const float lbl_91_rodata_8;
extern "C" void fn_91_CD18(Vec3f* v) {
    float f = lbl_91_rodata_8;
    v->x = f;
    v->y = f;
    v->z = f;
}

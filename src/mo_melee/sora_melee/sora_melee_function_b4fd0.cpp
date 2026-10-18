#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern const float lbl_27_rodata_DFC;

extern "C" void fn_27_B4FD0(Vec3f* v) {
    v->x = lbl_27_rodata_DFC;
    v->y = lbl_27_rodata_DFC;
    v->z = lbl_27_rodata_DFC;
}

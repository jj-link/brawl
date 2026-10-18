#pragma force_active on
extern const float lbl_27_rodata_B70;

struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" void fn_27_7E050(Vec3* v) {
    v->x = lbl_27_rodata_B70;
    v->y = lbl_27_rodata_B70;
    v->z = lbl_27_rodata_B70;
}

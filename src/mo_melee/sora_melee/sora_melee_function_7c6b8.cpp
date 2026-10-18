#pragma force_active on
struct soVec3f {
    float x;
    float y;
    float z;
};

extern "C" {
extern const float lbl_27_rodata_B70;

void fn_27_7C6B8(soVec3f* v) {
    v->x = lbl_27_rodata_B70;
    v->y = lbl_27_rodata_B70;
    v->z = lbl_27_rodata_B70;
}
}

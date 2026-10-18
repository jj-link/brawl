#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" const float lbl_27_rodata_1F70[3];

extern "C" void fn_27_15D878(Vec3f* v) {
    float f = lbl_27_rodata_1F70[0];
    v->x = f;
    v->y = f;
    v->z = f;
}

#pragma force_active on
extern "C" {
extern const float lbl_98_rodata_8;
}

struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" void fn_98_C530(Vec3f* v) {
    float value = lbl_98_rodata_8;
    v->x = value;
    v->y = value;
    v->z = value;
}

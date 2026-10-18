#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" {
extern const float lbl_27_rodata_BD0;

void fn_27_8B160(Vec3f* v) {
    float f = lbl_27_rodata_BD0;
    v->x = f;
    v->y = f;
    v->z = f;
}
}

#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" {
extern const float lbl_106_rodata_8;
Vec3f* fn_106_77F4(Vec3f*, float, float, float);

Vec3f* fn_106_9610(Vec3f* v) {
    return fn_106_77F4(v, lbl_106_rodata_8, lbl_106_rodata_8, lbl_106_rodata_8);
}
}

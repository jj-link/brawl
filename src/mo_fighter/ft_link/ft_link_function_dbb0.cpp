#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" {
extern const float lbl_93_rodata_C;
Vec3f* fn_93_AC0C(Vec3f*, float, float, float);

Vec3f* fn_93_DBB0(Vec3f* v) {
    return fn_93_AC0C(v, lbl_93_rodata_C, lbl_93_rodata_C, lbl_93_rodata_C);
}
}

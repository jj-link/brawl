#pragma force_active on
struct Vec3f;

extern "C" {
extern const float lbl_117_rodata_C;
Vec3f* fn_117_92AC(Vec3f*, float, float, float);
}

extern "C" Vec3f* fn_117_D1F8(Vec3f* out) {
    float zero = lbl_117_rodata_C;
    return fn_117_92AC(out, zero, zero, zero);
}

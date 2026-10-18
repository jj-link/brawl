#pragma force_active on
struct Vec3f;

extern "C" {
extern const float lbl_96_rodata_8;
Vec3f* fn_96_BC54(Vec3f*, float, float, float);
}

extern "C" Vec3f* fn_96_1261C(Vec3f* v)
{
    return fn_96_BC54(v, lbl_96_rodata_8, lbl_96_rodata_8, lbl_96_rodata_8);
}

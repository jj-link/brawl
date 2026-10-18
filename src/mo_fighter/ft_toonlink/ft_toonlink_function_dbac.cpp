#pragma force_active on
typedef float f32;

struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
};

extern "C" {
extern const f32 lbl_121_rodata_C;
Vec3f* fn_121_AC08(Vec3f* dst, f32 x, f32 y, f32 z);
}

extern "C" Vec3f* fn_121_DBAC(Vec3f* dst)
{
    f32 c = lbl_121_rodata_C;
    return fn_121_AC08(dst, c, c, c);
}

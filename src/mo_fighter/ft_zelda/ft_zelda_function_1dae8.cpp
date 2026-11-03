#pragma force_active on
#pragma scheduling off
#pragma optimize_for_size on

struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;
};

extern "C" {
extern const float lbl_104_rodata_E8;

Vec3* fn_104_121E8(Vec3*, float, float, float);
void fn_27_89D08(int, void*, int, Vec2*, Vec3*);

void fn_104_1DAE8(void*, void*, const Vec2* source, void* accesser) {
    Vec2 a;
    Vec2 b;
    Vec3 rot0;
    Vec3 rot1;

    float t = source->y;
    a.x = lbl_104_rodata_E8;
    a.y = t;
    fn_27_89D08(1, accesser, 0, &a,
        fn_104_121E8(&rot0, lbl_104_rodata_E8,
                     lbl_104_rodata_E8, lbl_104_rodata_E8));

    b.x = source->x;
    b.y = lbl_104_rodata_E8;
    fn_27_89D08(0, accesser, 4, &b,
        fn_104_121E8(&rot1, lbl_104_rodata_E8,
                     lbl_104_rodata_E8, lbl_104_rodata_E8));
}
}
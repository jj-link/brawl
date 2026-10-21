#include <types.h>
#pragma force_active on
#pragma scheduling off
#pragma optimize_for_size on

struct Vec2 {
    f32 x, y;
};

struct Vec3 {
    f32 x, y, z;
};

struct Locals {
    u8 flag;
    Vec2 b;
    Vec2 a;
    Vec3 c;
    Vec3 d;
};

struct FloatOwner {
    u8 unknown[0x7C];
    f32 scaleA;
    f32 scaleB;
};

extern "C" {
extern const f32 lbl_27_rodata_76AC;

Vec3* fn_27_331BEC(Vec3*, f32, f32, f32);
void fn_27_89D08(s32, void*, s32, Vec2*, Vec3*);
f32 getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, u32, u32);

void fn_27_331C54(
    void* unused, FloatOwner* owner, const Vec2* source, void* accesser)
{
    Locals locals;

    locals.a.x = source->x;
    locals.a.y = lbl_27_rodata_76AC;
    fn_27_89D08(
        2, accesser, 0, &locals.a,
        fn_27_331BEC(&locals.d, lbl_27_rodata_76AC,
                     lbl_27_rodata_76AC, lbl_27_rodata_76AC));

    locals.b.x = source->y;
    locals.b.y = lbl_27_rodata_76AC;
    fn_27_89D08(
        1, accesser, 0, &locals.b,
        fn_27_331BEC(&locals.c, lbl_27_rodata_76AC,
                     lbl_27_rodata_76AC, lbl_27_rodata_76AC));

    locals.flag = 0;

    f32 scaleA = owner->scaleA;
    owner->scaleA =
        scaleA * getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                     accesser, 0xFBA, 0);

    f32 scaleB = owner->scaleB;
    owner->scaleB =
        scaleB * getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                     accesser, 0xFBA, 0);
}
}

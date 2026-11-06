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

void fn_27_331B04(
    void* unused, FloatOwner* owner, const f32* source, void* accesser)
{
    struct Locals {
        u8 flag;
        Vec2 b;
        Vec2 a;
        Vec3 c;
        Vec3 d;
    } locals;

    f32 val = *source;
    val *= getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xFB7, 0);
    locals.a.x = val;
    locals.a.y = lbl_27_rodata_76AC;
    fn_27_89D08(
        2, accesser, 0, &locals.a,
        fn_27_331BEC(&locals.d, lbl_27_rodata_76AC,
                     lbl_27_rodata_76AC, lbl_27_rodata_76AC));

    locals.b.x = lbl_27_rodata_76AC;
    locals.b.y = lbl_27_rodata_76AC;
    fn_27_89D08(
        1, accesser, 0, &locals.b,
        fn_27_331BEC(&locals.c, lbl_27_rodata_76AC,
                     lbl_27_rodata_76AC, lbl_27_rodata_76AC));

    locals.flag = 0;

    owner->scaleA = -getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xFB8, 0);
}
}
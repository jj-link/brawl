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
    u8 flag2;
    u8 flag1;
    Vec2 c;
    Vec2 limit;
    Vec2 brake;
    Vec2 a;
    Vec3 r2;
    Vec3 r1;
};

extern "C" {
extern const f32 lbl_103_rodata_14;

Vec3* fn_103_9594(Vec3*, f32, f32, f32);
void fn_27_89D08(s32, void*, s32, Vec2*, Vec3*);
void fn_103_C174(void*, const Vec2*);
f32 getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, u32, u32);

void fn_103_DD58(
    void* unused, u8* owner, const Vec2* source, void* accesser)
{
    Locals locals;

    locals.a.x = source->x;
    locals.a.y = lbl_103_rodata_14;
    fn_27_89D08(
        3, accesser, 6, &locals.a,
        fn_103_9594(&locals.r1, lbl_103_rodata_14,
                    lbl_103_rodata_14, lbl_103_rodata_14));

    locals.flag1 = 0;

    locals.brake.x = lbl_103_rodata_14;
    locals.brake.y = lbl_103_rodata_14;
    fn_103_C174(owner + 0x110, &locals.brake);

    locals.limit.x =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xFAE, 0);
    locals.limit.y = lbl_103_rodata_14;
    fn_103_C174(owner + 0x118, &locals.limit);

    f32 y = source->y;
    locals.c.x = lbl_103_rodata_14;
    locals.c.y = y;
    fn_27_89D08(
        1, accesser, 0, &locals.c,
        fn_103_9594(&locals.r2, lbl_103_rodata_14,
                    lbl_103_rodata_14, lbl_103_rodata_14));

    locals.flag2 = 0;

    *(f32*)(owner + 0x7C) =
        -getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xFAF, 0);
    *(f32*)(owner + 0x80) =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xFAD, 0);
}
}

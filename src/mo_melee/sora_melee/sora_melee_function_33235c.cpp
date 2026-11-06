#include <types.h>
#pragma force_active on
#pragma scheduling off

struct Vec2 {
    f32 x, y;
};

struct Vec3 {
    f32 x, y, z;
};

struct Locals {
    bool flag;
    Vec2 a, b, c, d, e, f;
    Vec3 h;
    Vec3 g;
};

extern "C" {
extern const f32 lbl_27_rodata_76AC;
extern const f32 lbl_27_rodata_76B0;

float fn_27_192278(void*, unsigned long);
Vec3* fn_27_331BEC(Vec3*, f32, f32, f32);
void fn_27_89D08(int, void*, int, Vec2*, Vec3*);
void fn_27_331AF0(void*, const Vec2*);

void fn_27_33235C(
    void* unused, unsigned char* owner, const Vec2* source, void* accesser)
{
    Locals locals;

    locals.f.x = source->x / fn_27_192278(accesser, 0xfa0);
    locals.f.y = lbl_27_rodata_76AC;
    fn_27_89D08(3, accesser, 6, &locals.f,
        fn_27_331BEC(&locals.g, lbl_27_rodata_76AC,
                     lbl_27_rodata_76AC, lbl_27_rodata_76AC));

    locals.flag = false;

    locals.e.x = lbl_27_rodata_76AC;
    locals.e.y = lbl_27_rodata_76AC;
    fn_27_331AF0(owner + 0x108, &locals.e);

    locals.d.x = lbl_27_rodata_76AC;
    locals.d.y = lbl_27_rodata_76AC;
    fn_27_331AF0(owner + 0x110, &locals.d);

    locals.c.x = fn_27_192278(accesser, 0xfa1);
    locals.c.y = lbl_27_rodata_76B0;
    fn_27_331AF0(owner + 0x118, &locals.c);

    locals.b.x = lbl_27_rodata_76B0;
    locals.b.y = lbl_27_rodata_76B0;
    fn_27_331AF0(owner + 0x120, &locals.b);

    float y = source->y;
    locals.a.x = lbl_27_rodata_76AC;
    locals.a.y = y;
    fn_27_89D08(1, accesser, 0, &locals.a,
        fn_27_331BEC(&locals.h, lbl_27_rodata_76AC,
                     lbl_27_rodata_76AC, lbl_27_rodata_76AC));
}
}

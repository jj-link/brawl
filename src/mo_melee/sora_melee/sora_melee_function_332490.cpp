#include <types.h>
#pragma force_active on
#pragma scheduling off
#pragma optimize_for_size on
struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual int slot17(u32);
    virtual void slot18(u32);
};
struct Modules { char pad[0x64]; Object_vptr_0* work; };
struct Accesser { char pad[0xd8]; Modules* modules; };
struct Owner { char pad[0x7c]; float a, b; char pad2[0x108 - 0x84]; Vec2 v0, v1, v2, v3; };
struct Locals {
    bool flag2, flag1;
    Vec2 e, f, g, h, i, j, k;
    Vec3 l, m, n;
};
extern "C" {
extern const float lbl_27_rodata_76AC;
extern const float lbl_27_rodata_76B0;
float fn_27_192278(void*, unsigned long);
Vec3* fn_27_331BEC(Vec3*, float, float, float);
void fn_27_89D08(int, Accesser*, int, Vec2*, Vec3*);
void fn_27_331AF0(void*, const Vec2*);
void fn_27_332490(void*, Owner* owner, const float* source, Accesser* accesser) {
    Locals locals;
    locals.k.x = *source;
    locals.k.y = lbl_27_rodata_76AC;
    fn_27_89D08(3, accesser, 6, &locals.k, fn_27_331BEC(&locals.n, lbl_27_rodata_76AC, lbl_27_rodata_76AC, lbl_27_rodata_76AC));
    locals.flag1 = false;
    locals.j.x = lbl_27_rodata_76AC;
    locals.j.y = lbl_27_rodata_76AC;
    fn_27_331AF0(&owner->v0, &locals.j);
    locals.i.x = lbl_27_rodata_76AC;
    locals.i.y = lbl_27_rodata_76AC;
    fn_27_331AF0(&owner->v1, &locals.i);
    locals.h.x = fn_27_192278(accesser, 0xfa1);
    locals.h.y = lbl_27_rodata_76B0;
    fn_27_331AF0(&owner->v2, &locals.h);
    locals.g.x = lbl_27_rodata_76B0;
    locals.g.y = lbl_27_rodata_76B0;
    fn_27_331AF0(&owner->v3, &locals.g);
    if (accesser->modules->work->slot17(0x1200003d) == 0) {
        float y = fn_27_192278(accesser, 0xfa2);
        locals.f.x = lbl_27_rodata_76AC;
        locals.f.y = y;
        fn_27_89D08(1, accesser, 0, &locals.f, fn_27_331BEC(&locals.m, lbl_27_rodata_76AC, lbl_27_rodata_76AC, lbl_27_rodata_76AC));
        accesser->modules->work->slot18(0x1200003d);
    } else {
        locals.e.x = lbl_27_rodata_76AC;
        locals.e.y = lbl_27_rodata_76AC;
        fn_27_89D08(1, accesser, 0, &locals.e, fn_27_331BEC(&locals.l, lbl_27_rodata_76AC, lbl_27_rodata_76AC, lbl_27_rodata_76AC));
    }
    locals.flag2 = false;
    owner->a = -fn_27_192278(accesser, 0xfa3);
    owner->b = fn_27_192278(accesser, 0xfa4);
}
}
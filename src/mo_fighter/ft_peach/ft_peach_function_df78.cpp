#include <types.h>
#pragma force_active on

struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
struct Locals {
    bool flag;
    Vec2 a, b, c, d, e, f;
    Vec3 g, h;
};
extern "C" {
extern const float lbl_103_rodata_14;
extern const float lbl_103_rodata_18;
float fn_27_192278(void*, unsigned long);
Vec3* fn_103_9594(Vec3*, float, float, float);
void fn_27_89D08(int, void*, int, Vec2*, Vec3*);
Vec2* fn_103_C174(Vec2*, const Vec2*);

void fn_103_DF78(void*, unsigned char* owner, const Vec2* source, void* accesser) {
    Locals locals;
    locals.f.x = source->x / fn_27_192278(accesser, 0xfa0);
    locals.f.y = lbl_103_rodata_14;
    fn_27_89D08(3, accesser, 6, &locals.f, fn_103_9594(&locals.h, lbl_103_rodata_14, lbl_103_rodata_14, lbl_103_rodata_14));
    locals.flag = false;
    locals.e.x = lbl_103_rodata_14;
    locals.e.y = lbl_103_rodata_14;
    fn_103_C174((Vec2*)(owner + 0x108), &locals.e);
    locals.d.x = lbl_103_rodata_14;
    locals.d.y = lbl_103_rodata_14;
    fn_103_C174((Vec2*)(owner + 0x110), &locals.d);
    locals.c.x = fn_27_192278(accesser, 0xfa1);
    locals.c.y = lbl_103_rodata_18;
    fn_103_C174((Vec2*)(owner + 0x118), &locals.c);
    locals.b.x = lbl_103_rodata_18;
    locals.b.y = lbl_103_rodata_18;
    fn_103_C174((Vec2*)(owner + 0x120), &locals.b);
    float y = source->y;
    locals.a.x = lbl_103_rodata_14;
    locals.a.y = y;
    fn_27_89D08(1, accesser, 0, &locals.a, fn_103_9594(&locals.g, lbl_103_rodata_14, lbl_103_rodata_14, lbl_103_rodata_14));
}
}
#include <types.h>
#pragma force_active on

extern const f32 lbl_27_rodata_5FC0;
extern const f32 lbl_27_rodata_5FC4;

struct Vec2 {
    f32 x, y;

    Vec2() {}
    Vec2(f32 a, f32 b) : x(a), y(b) {}

    void set(f32 a, f32 b) {
        x = a;
        y = b;
    }
};

class Obj {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;

    u32 pad4;
    Vec2 pos, a, b, c, d;
    u32 pad30, pad34;
    s32 i38;

    void reset() {
        Vec2 vd, vc, vb, va;
        va.set(lbl_27_rodata_5FC4, lbl_27_rodata_5FC4);
        vb.set(lbl_27_rodata_5FC4, lbl_27_rodata_5FC4);
        vc.set(lbl_27_rodata_5FC4, lbl_27_rodata_5FC4);
        vd.set(lbl_27_rodata_5FC0, lbl_27_rodata_5FC0);

        i38 = -1;
        a = va;
        b = vb;
        c = vc;
        d = vd;
    }
};

extern "C" void fn_27_2BF288(Obj* self, s32 arg1, const Vec2* arg2) {
    self->vf6();
    self->reset();
    self->pos = *arg2;
    self->i38 = arg1;
}

#pragma force_active on

extern const float lbl_27_rodata_BA8;
extern const float lbl_27_rodata_BB4;

struct Vec2 {
    float x, y;
};

struct Holder {
    int pad0, pad1;
    Vec2 a, b, c, d, e;
    unsigned char f30, f31, f32;
};

extern "C" void fn_27_8A58C(Holder* p) {
    Vec2 zero = {lbl_27_rodata_BA8, lbl_27_rodata_BA8};
    p->d.x = zero.x;
    p->d.y = zero.y;
    p->b.x = zero.x;
    p->b.y = zero.y;
    p->a.x = zero.x;
    p->a.y = zero.y;

    Vec2 one = {lbl_27_rodata_BB4, lbl_27_rodata_BB4};
    p->e.x = one.x;
    p->e.y = one.y;
    p->c.x = one.x;
    p->c.y = one.y;

    p->f31 = 0;
    p->f30 = 0;
    p->f32 = 1;
}

#pragma force_active on
struct Inner {
    float f0;
    char pad[0x24 - 4];
    float f24;
};

struct Outer {
    int pad0;
    Inner *inner;
    int pad8;
    int padC;
    float f10;
    float f14;
};

extern "C" {
void fn_27_368988(Outer *self, float f1)
{
    Inner *p = self->inner;
    self->f10 = p->f0 + f1;
    self->f14 = p->f24;
}
}

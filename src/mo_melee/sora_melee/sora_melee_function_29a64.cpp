#pragma force_active on
struct Inner {
    virtual void vf0();
    virtual Inner* vf1();
    char pad[0x14 - 4];
    float f14;
};

struct Outer {
    char pad[0x28];
    Inner* inner;
};

extern "C" {
void fn_27_29A64(Outer* self, float v) {
    Inner* p = self->inner->vf1();
    p->f14 = v;
}
}

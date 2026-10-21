#pragma force_active on
typedef unsigned char u8;

struct Inner {
    virtual void f00();
    virtual void f01(int a, int b);
    u8 field4;
};

struct Outer {
    u8 pad0[4];
    u8 field4;
    Inner* inner;
};

extern "C" void fn_802C8E48(Outer* self, int a, int b) {
    self->inner->f01(b, a);
    self->field4 = self->inner->field4;
}

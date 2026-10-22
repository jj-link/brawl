#pragma force_active on
class Iface {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual void f7(int a, int b);
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual float f14(int a);
    virtual void f15(int a, float b);
};

struct Holder {
    char pad[0x2aac];
    Iface obj;
};

extern "C" const float lbl_27_rodata_4610;

extern "C" void fn_27_28F6D4(Holder* self, int x, int y, float a, float b) {
    Iface* o = &self->obj;
    o->f7(x, 0x10000011);
    o->f7(3, 0x1000000F);
    o->f7(0, 0x10000010);
    o->f7(y, 0x10000012);
    float v = o->f14(0x1100000B);
    if (b >= lbl_27_rodata_4610) v = b;
    o->f15(0x11000009, v);
    o->f15(0x1100000A, a);
}

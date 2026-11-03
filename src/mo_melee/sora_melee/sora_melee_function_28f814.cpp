#pragma force_active on

class Iface {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int f6(int a);
    virtual void f7(int a, int b);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void f15(int a, float b);
};

struct Holder {
    char pad[0x2aac];
    Iface obj;
};

extern "C" void fn_27_28F814(Holder* self, float farg) {
    Iface* o = &self->obj;
    int val = o->f6(0x10000007);
    o->f7(val, 0x10000011);
    o->f7(4, 0x1000000F);
    o->f7(0, 0x10000010);
    o->f7(-1, 0x10000012);
    o->f15(0x1100000B, farg);
}
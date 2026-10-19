#pragma force_active on
class VirtObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual int f16();
};

struct Mid {
    char pad[0x70];
    VirtObj* vobj;
};

struct Holder {
    char pad[0xd8];
    Mid* mid;
};

struct Self {
    char pad[0x60];
    Holder* holder;
};

extern "C" int fn_121_FF28(char* self);

extern "C" int fn_121_A408(Self* self) {
    Holder* h = self->holder;
    int result = 0;
    VirtObj* obj = h->mid->vobj;
    if (obj->f16() == 0x116) {
        result = fn_121_FF28((char*)h);
    }
    return result;
}

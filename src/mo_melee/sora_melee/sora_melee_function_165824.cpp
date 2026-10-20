#pragma force_active on
typedef unsigned int u32;

class Base {
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
    virtual float getValue(u32 index);
    virtual void setValue(float value, u32 index);
};

struct Mid {
    char pad[0x64];
    Base* base;
};

struct Obj {
    char pad[0xd8];
    Mid* mid;
};

extern "C" {
int fn_27_165824(void* unused, Obj* obj) {
    Base* b = obj->mid->base;
    float v = b->getValue(0x21000004);
    b->setValue(-v, 0x21000004);
    return 0;
}
}

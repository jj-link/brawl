#pragma force_active on
class Obj {
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
};

struct Mid {
    char pad[0x3c];
    Obj* obj;
};

struct Top {
    char pad[0xd8];
    Mid* mid;
};

extern "C" void fn_27_1790A8(void* unused, Top* self) {
    return self->mid->obj->f13();
}

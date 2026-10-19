#pragma force_active on
struct Obj {
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
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19(int arg);
};

struct Holder {
    char pad[0x40];
    Obj* obj;
};

struct Ctx {
    char pad[0xd8];
    Holder* holder;
};

extern "C" bool fn_27_18778C(void* unused, Ctx* ctx) {
    ctx->holder->obj->f19(0);
    return true;
}

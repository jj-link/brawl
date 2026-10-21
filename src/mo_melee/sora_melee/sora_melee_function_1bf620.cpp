#pragma force_active on
struct Interface {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void call();
};

struct Object {
    char padding[0x10];
    Interface inner;
};

extern "C" void fn_27_1BF620(Object* obj) {
    obj->inner.call();
}

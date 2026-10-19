#pragma force_active on
struct Interface {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

extern "C" bool fn_66_EEB8(Interface* object) {
    return !object->f3();
}

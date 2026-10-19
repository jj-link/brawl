#pragma force_active on
struct Object {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual unsigned int check();
};

extern "C" bool fn_115_B9C8(Object* obj) {
    return obj->check() == 0;
}

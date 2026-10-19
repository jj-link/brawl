#pragma force_active on
struct Obj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

extern "C" bool fn_49_693C(Obj* object) {
    return object->f3() == 0;
}

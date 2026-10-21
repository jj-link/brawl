#pragma force_active on
struct SomeClass {
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
    virtual void f12(int);

    char padding[0xE0];
    int count;
};

extern "C" void fn_800F0954(SomeClass** arg) {
    SomeClass* obj = *arg;
    while (obj->count != 0) {
        if (obj->count != 0) {
            obj->f12(obj->count - 1);
        }
    }
}

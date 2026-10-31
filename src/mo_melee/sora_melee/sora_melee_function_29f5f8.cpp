#pragma force_active on
struct Work {
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
    virtual void setFlag(unsigned int);
};
struct Modules {
    char padding[0x64];
    Work* work;
};
struct Owner {
    char padding[0xD8];
    Modules* modules;
};
struct Object {
    char padding[0x60];
    Owner* owner;
};
extern "C" void fn_27_289040(Object*, int);
extern "C" void fn_27_29F5F8(void*, Object* object, int state) {
    Work* work = object->owner->modules->work;
    switch (state) {
    case 0:
        work->setFlag(0x12000000);
        return;
    case 1:
        fn_27_289040(object, 1);
        return;
    }
}

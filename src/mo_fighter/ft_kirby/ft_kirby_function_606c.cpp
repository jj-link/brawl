#pragma force_active on
extern "C" void* fn_96_4D6C(void*, void*, int, void*, int, void*, int);

struct SubObject {
    char padding[8];
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
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
};

struct Object {
    char padding[0x1C0];
    SubObject sub;
};

extern "C" void* fn_96_606C(Object* object) {
    fn_96_4D6C(&object->sub, object, 0x4D,
               (char*)object + 0x134, 0x20,
               (char*)object + 0x1B4, 3);
    object->sub.f25();
    return object;
}

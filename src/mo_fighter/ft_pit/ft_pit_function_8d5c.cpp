#pragma force_active on
extern "C" void* fn_112_885C(void*, void*, int, void*, int, void*, int);

struct PitBase {
    char data[8];
};

struct PitSub : PitBase {
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

extern "C" void* fn_112_8D5C(char* obj) {
    fn_112_885C(obj + 0x1C0, obj, 0x4D, obj + 0x134, 0x20, obj + 0x1B4, 3);
    ((PitSub*)(obj + 0x1C0))->f25();
    return obj;
}

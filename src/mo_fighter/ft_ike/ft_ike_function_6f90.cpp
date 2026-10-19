#pragma force_active on
struct Fn119Object {
    unsigned int secondaryTable;
    unsigned int reserved;
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
    unsigned int args[6];
};

extern "C" Fn119Object* fn_119_6A90(
    Fn119Object*, unsigned int, unsigned int, unsigned int,
    unsigned int, unsigned int, unsigned int);

extern "C" void* fn_119_6F90(unsigned char* object) {
    fn_119_6A90((Fn119Object*)(object + 0x1C0),
               (unsigned int)object, 0x4D,
               (unsigned int)(object + 0x134), 0x20,
               (unsigned int)(object + 0x1B4), 3);
    ((Fn119Object*)(object + 0x1C0))->f25();
    return object;
}

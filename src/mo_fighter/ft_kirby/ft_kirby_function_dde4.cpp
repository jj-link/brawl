#pragma force_active on

struct Iface {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int a, int b, bool c);
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual int f10(int a);
};

extern "C" void fn_96_DDE4(void* self) {
    char* s = (char*)self;
    char* r31 = *(char**)(s + 0x60);
    
    if (((Iface*)(*(char**)(*(char**)(r31 + 0xd8) + 0x58)))->f10(0) == 0 ||
        ((Iface*)(*(char**)(*(char**)(r31 + 0xd8) + 0x58)))->f10(0) == 1) {
        if (((Iface*)(*(char**)(*(char**)(r31 + 0xd8) + 0x58)))->f10(1) == 1) {
            ((Iface*)(*(char**)(*(char**)(r31 + 0xd8) + 0x58)))->f3(0, 1, true);
        } else {
            ((Iface*)(*(char**)(*(char**)(r31 + 0xd8) + 0x58)))->f3(0, 0, true);
        }
    }
}
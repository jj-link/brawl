#pragma force_active on
struct VIface {
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11(int, int);
    virtual unsigned int f12(int);
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual int f19(int);
};

extern "C" void fn_96_16AB4(void*, char* obj) {
    VIface* a = *(VIface**)(*(char**)(obj + 0xd8) + 0x64);
    if (a->f19(0x22000016) == 0) {
        VIface* b = *(VIface**)(*(char**)(obj + 0xd8) + 0x54);
        if (b->f12(0) == 1) {
            VIface* c = *(VIface**)(*(char**)(obj + 0xd8) + 0x3c);
            c->f11(0, 1);
        }
    }
}

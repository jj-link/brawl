#pragma force_active on

struct Module48 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void call(int, int);
};

struct Module64 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void call(int, bool, bool);
};

struct Modules {
    char pad[0x84];
    Module48* module48;
    Module64* module64;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_115_10368(void* arg0, Accesser* accesser, int status) {
    switch (status) {
    case 0x128:
    case 0x129:
        return;
    default: {
        Module48* m48 = accesser->modules->module48;
        m48->call(1, 0);
        Module64* m64 = accesser->modules->module64;
        int x = 1;
        m64->call(0x1C0002, x, x);
        break;
    }
    }
}

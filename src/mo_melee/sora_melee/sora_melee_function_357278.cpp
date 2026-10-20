#pragma force_active on
extern "C" {
extern unsigned char lbl_27_bss_7B0C[];
int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
}

struct Target {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void call(int, int);
};

struct Modules {
    unsigned char pad[0x3c];
    Target* target;
};

struct Accesser {
    unsigned char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_357278(void*, Accesser* accesser, int status) {
    switch (fn_27_30FACC(lbl_27_bss_7B0C, 0, status, accesser, 1)) {
    case 0x3b:
    case 0x11a:
    case 0x11b:
        break;
    default:
        Target* target = accesser->modules->target;
        target->call(0, 0);
        break;
    }
}

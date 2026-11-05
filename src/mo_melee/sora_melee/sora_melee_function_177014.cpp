#pragma force_active on

struct ColorObj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void target(int a, float b);
};

struct StatusObj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual int get();
};

struct SubObj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
};

struct Modules {
    char pad0[0x48];
    SubObj* sub;
    char pad1[0x18];
    ColorObj* color;
    char pad2[8];
    StatusObj* status;
};

struct Owner {
    char pad[0xD8];
    Modules* modules;
};

struct Local {
    int a;
    int b;
    float c;
    float d;
    char pad[0x10];
};

extern "C" void fn_27_1744D4(void*, void*);
extern "C" void fn_27_174C08(int, void*, void*);
extern "C" void fn_27_17754C(int, void*, void*);
extern "C" void fn_27_177B2C(int, void*, void*);
extern "C" void fn_27_177BB0(int, void*, void*);
extern "C" void fn_27_177CE8(int, void*, void*);

extern "C" void fn_27_177014(int arg0, Owner* arg1) {
    Local local;
    fn_27_1744D4((void*)arg0, arg1);
    local.a = 0x14;
    local.b = 0;
    fn_27_174C08(arg0, &local, arg1);
    arg1->modules->color->target(0x21000004, local.c);
    arg1->modules->color->target(0x21000005, local.d);
    int result = arg1->modules->status->get();
    switch (result) {
    case 0x92:
        arg1->modules->sub->m3();
        fn_27_177B2C(arg0, arg1, &local);
        return;
    case 0x93:
        arg1->modules->sub->m3();
        fn_27_177BB0(arg0, arg1, &local);
        return;
    case 0x94:
        fn_27_17754C(arg0, arg1, &local);
        return;
    case 0x95:
        fn_27_177CE8(arg0, arg1, &local);
        return;
    }
}

#pragma force_active on

struct Iface1 {
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
    virtual int s14(int, int);
};

struct Iface2 {
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
    virtual int s17(int);
    virtual void s18(int);
};

struct X38Base {
    int a;
    int b;
};

struct X38 : X38Base {
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
    virtual void s17(int);
};

struct Modules {
    char pad0[0x1c];
    Iface1* iface1;
    char pad1[0x18];
    X38* x38;
    char pad2[0x28];
    Iface2* iface2;
};

struct Object {
    char pad[0xd8];
    Modules* modules;
};

extern "C" float fn_27_192278(void*, unsigned long);

extern "C" void fn_27_3A21F8(void*, Object* obj) {
    if (obj->modules->iface1->s14(0, 0) != 0) {
        if (obj->modules->iface2->s17(0x22000012) == 0) {
            fn_27_192278(obj, 0xfa2);
            obj->modules->x38->s17(0);
            obj->modules->iface2->s18(0x22000012);
        }
    }
}

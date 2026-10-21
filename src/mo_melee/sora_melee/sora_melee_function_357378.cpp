#pragma force_active on

extern const float lbl_27_rodata_79A8;

struct Params {
    int kind;
    bool flag;
    int value;
    int a;
    int b;
    int c;
    float f;
    bool enabled;
};

struct Module54 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void init(int, Params*, int);
    virtual void v19();
    virtual void v20();
    virtual int get(int);
};

struct Module64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void set(int, unsigned int);
};

struct Modules {
    char pad[0x54];
    Module54* m54;
    char pad2[0xC];
    Module64* m64;
};

struct Owner {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_27_357378(void*, Owner* owner) {
    Params p;
    p.kind = 0x10;
    p.flag = false;
    p.value = 0;
    p.a = -1;
    p.b = -1;
    p.c = -1;
    p.f = lbl_27_rodata_79A8;
    p.enabled = true;

    owner->modules->m54->init(0, &p, 0);
    owner->modules->m64->set(owner->modules->m54->get(0), 0x20000002);
    owner->modules->m64->set(p.a, 0x20000003);
    owner->modules->m64->set(p.b, 0x20000004);
}

#pragma force_active on

extern "C" const float lbl_92_rodata_A0;

struct Params {
    int kind;
    unsigned char flag;
    int a;
    int b;
    int c;
    int d;
    float value;
    unsigned char enabled;
};

class Module54 {
public:
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
    virtual void send(int, Params*, int);
    virtual void v17();
    virtual void v18();
    virtual int get(int);
};

class Module64 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int get(int);
    virtual void set(int, unsigned int);
};

struct Modules {
    char pad[0x54];
    Module54* mod54;
    char pad58[0xC];
    Module64* mod64;
};

struct Fighter {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_92_10140(void*, Fighter* fighter) {
    Params p;
    int val = fighter->modules->mod64->get(0x20000000);
    p.kind = 0x1c;
    p.flag = 0;
    p.a = val - 0x39;
    p.b = -1;
    p.c = -1;
    p.d = -1;
    p.value = lbl_92_rodata_A0;
    p.enabled = 1;

    fighter->modules->mod54->send(0, &p, 0);
    Module64* mod64 = fighter->modules->mod64;
    mod64->set(fighter->modules->mod54->get(0), 0x20000002);
    fighter->modules->mod64->set(p.b, 0x20000003);
    fighter->modules->mod64->set(p.c, 0x20000004);
}
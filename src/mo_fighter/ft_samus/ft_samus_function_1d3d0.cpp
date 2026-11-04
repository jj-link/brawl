#pragma force_active on

extern "C" void fn_27_1DA030(void*);
extern "C" const float lbl_94_rodata_88;

struct Msg {
    int a;
    float b;
    float c;
    char d;
    char e;
    char f;
    char g;
};

class ObjA {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6(int);
    virtual void v7(int, int);
};

class ObjB {
public:
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
    virtual float v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32(Msg*);
};

struct B {
    char pad0[0x8];
    ObjB* p8;
    char pad1[0x64 - 0xC];
    ObjA* p64;
};

struct A {
    char pad[0xD8];
    B* b;
};

struct Arg {
    char pad[0x60];
    A* a;
};

extern "C" void fn_94_1D3D0(Arg* arg0) {
    Msg m;

    fn_27_1DA030(arg0);
    int r = arg0->a->b->p64->v6(0x10000009);
    if (r != -1) {
        float f = arg0->a->b->p8->v14();
        m.a = r;
        m.b = f;
        m.c = lbl_94_rodata_88;
        m.d = 0;
        m.e = 0;
        m.f = 1;
        m.g = 0;
        arg0->a->b->p8->v32(&m);
        arg0->a->b->p64->v7(-1, 0x10000009);
    }
}

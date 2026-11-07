#pragma force_active on
extern "C" void fn_27_39F2B0(int, float, float, float);
extern "C" int fn_27_39FA04(int);
extern "C" void fn_27_39B854(void*, int);

struct Q {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual float f9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual void b18();
    virtual void b19();
    virtual void b20();
    virtual void b21();
    virtual float f22();
};

struct R {
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5(int, unsigned long);
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual float c12(unsigned long);
};

struct P {
    char pad0[0xc];
    Q* q;
    char pad1[0x54];
    R* r;
};

struct Obj {
    char pad[0xd8];
    P* p;
};

extern "C" int fn_27_39B34C(void* unused, int p, Obj* obj) {
    float f31 = obj->p->q->f9();
    float f30 = obj->p->q->f22();
    float f2 = obj->p->r->c12(0x11000013);
    fn_27_39F2B0(p, f31, f2, f30);
    fn_27_39B854(obj, fn_27_39FA04(p));
    obj->p->r->c5(7, 0x10000042);
    return 0;
}

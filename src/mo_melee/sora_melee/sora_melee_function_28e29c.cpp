#pragma force_active on

extern "C" void fn_27_28DEE0(void* self, void* arg, float f1, float f2);
extern "C" void fn_27_28C418(void* self, int a, int b);

class A {
public:
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual void a4(); virtual void a5();
};

class B {
public:
    virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3();
    virtual void b4();
    virtual void s7(int, int, float);
    virtual void b6(); virtual void b7(); virtual void b8(); virtual void b9();
    virtual void b10(); virtual void b11(); virtual void b12(); virtual void b13();
    virtual void b14(); virtual void b15(); virtual void b16();
    virtual int s19(int);
    virtual void s20(int);
};

class C {
public:
    virtual void c0(); virtual void c1(); virtual void c2();
    virtual void s5(int, void*);
};

class D {
public:
    virtual void d0(); virtual void d1();
    virtual unsigned int* s4(int);
};

#define F10(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7(); virtual void p##8(); virtual void p##9();

class E {
public:
    F10(e) F10(f) F10(g) F10(h)
    virtual void e40();
    virtual void s43(float*);
    virtual void e42(); virtual void e43(); virtual void e44();
    virtual void s47();
    virtual void e46();
    virtual void s49();
};

struct LblBase {
    int a;
};

class Lbl : public LblBase {
public:
    virtual void l0(); virtual void l1(); virtual void l2(); virtual void l3();
    virtual void l4();
    virtual void s7(void*, int, int);
};

extern Lbl lbl_27_bss_71C8;

class H {
public:
    F10(h) virtual void h10(); virtual void h11(); virtual void h12();
    virtual void h13(); virtual void h14(); virtual void h15();
    virtual int s18();
};

struct V2r {
    float y;
    float x;
};

struct Mid {
    char pad[0x70];
    H* h;
};

struct Frame {
    char pad0[0xCC];
    char cc[4];
    char pad1[0x1A4 - 0xD0];
    Mid* mid;
    char pad2[0xDB4 - 0x1A8];
    A a;
    char pad3[0x15C0 - 0xDB8];
    E e;
    char pad4[0x297C - 0x15C4];
    D d;
    char pad5[0x2AAC - 0x2980];
    B b;
    char pad6[0x2C34 - 0x2AB0];
    C c;
};

extern "C" void fn_27_28E29C(Frame* arg0, int unused, float farg0, float farg1, float* arg2) {
    V2r local;
    V2r copy;

    arg0->a.a5();
    fn_27_28DEE0(arg0, arg2, farg0, farg1);
    fn_27_28C418(arg0->cc, 5, 0);
    local.y = arg2[0];
    local.x = arg2[1];
    arg0->b.s7(0, 0x1000001C, local.y);
    arg0->c.s5(5, arg0->cc);
    if (arg0->mid->h->s18() == 5) {
        arg0->b.s20(0x22000000);
        if (arg0->b.s19(0x22000000) != 0) {
            if (!(*arg0->d.s4(8) & 0x4c00)) {
                float x = local.x;
                float y = local.y;
                copy.x = x;
                copy.y = y;
                arg0->e.s43(&copy.y);
                Lbl* lp = &lbl_27_bss_71C8;
                lp->s7(arg0->cc, 0xD6F, 0);
                arg0->e.s47();
                lp->s7(arg0->cc, 0xD70, 0);
                arg0->e.s49();
            }
        }
    }
}

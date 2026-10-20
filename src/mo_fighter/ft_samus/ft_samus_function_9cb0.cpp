#pragma force_active on

struct B0 { char pad[0x3c]; };
struct VA : B0 {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
    virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9();
    virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3(); virtual void b4();
    virtual void b5(); virtual void b6(); virtual void b7(); virtual void b8(); virtual void b9();
    virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4();
    virtual void c5(); virtual void c6(); virtual void c7(); virtual void c8(); virtual void c9();
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4();
    virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
    virtual int g();
};
struct PP {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8();
    virtual void f();
};
struct D { char pad[0xc]; PP* p; };
struct F { char pad[8]; VA* o; char pad2[0xcc]; D* d; };

extern unsigned char g_ftCommonDataAccesser[];
extern "C" void fn_27_149400(void*, int);
extern "C" void fn_27_2F3AAC(void*);

extern "C" int fn_94_9CB0(void* self, F* f) {
    fn_27_149400(g_ftCommonDataAccesser, f->o->g());
    f->d->p->f();
    fn_27_2F3AAC(self);
    return 1;
}
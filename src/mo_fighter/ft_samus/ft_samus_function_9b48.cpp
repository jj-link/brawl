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
struct VB {
 virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
 virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void f();
};
struct I2 { char pad[0xc]; VB* p; };
struct F2 { char pad[8]; VA* o; char pad2[0xd8-0xc]; I2* d; };

extern unsigned char g_ftCommonDataAccesser[];
extern "C" void fn_27_149400(void*, int);
extern "C" void fn_27_2F210C(void*);

extern "C" int fn_94_9B48(void* self, F2* f) {
    fn_27_149400(g_ftCommonDataAccesser, f->o->g());
    f->d->p->f();
    fn_27_2F210C(self);
    return 1;
}

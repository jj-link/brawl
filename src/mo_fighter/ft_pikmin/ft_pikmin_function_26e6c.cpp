#pragma force_active on
extern "C" void fn_113_26470(void*, void*);
struct Pad8 { int a, b; };
struct A : Pad8 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
    virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44();
    virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49();
    virtual void s50(); virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54();
    virtual unsigned long f55(int, int);
};
struct B {
    virtual void s0(); virtual void s1(); virtual void s2();
    virtual void f3(int, void*);
};
struct C {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16();
    virtual unsigned long f17(unsigned long);
    virtual void s18();
    virtual void f19(unsigned long);
};
struct E { virtual void s0(); virtual void s1(); virtual long long f2(); };
struct D {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5();
    virtual E* f6(int);
};
struct F {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8();
    virtual float f9();
    virtual void f10(float);
    virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18();
    virtual void f19();
};
struct Mods {
    char p0[0xc]; F* f;
    A* a;
    char p2[0x50]; C* c64;
    char p3[0x8]; B* b70;
    char p4[0x8]; D* d7c;
};
struct Obj { char p[0xd8]; Mods* m; };
extern "C" void fn_113_26E6C(void* self, Obj* o) {
    if (o->m->a->f55(8, 0) == 1) {
        o->m->b70->f3(6, o);
        return;
    }
    fn_113_26470(self, o);
    if (o->m->c64->f17(0x22000001) == 1) {
        o->m->c64->f19(0x22000001);
        o->m->b70->f3(12, o);
    }
    long long ll = o->m->d7c->f6(0)->f2();
    float f31 = *(float*)&ll;
    if (f31 * o->m->f->f9() < 0.0f) {
        float v = f31 < 0.0f ? -1 : 1;
        o->m->f->f10(v);
        o->m->f->f19();
    }
}

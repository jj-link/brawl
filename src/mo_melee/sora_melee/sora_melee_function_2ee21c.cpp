#pragma force_active on
typedef unsigned int u32;
typedef unsigned long long u64;
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" u32 fn_27_2ED9D4(void* self);
extern "C" char lbl_27_data_7DFD8[];
extern "C" char lbl_27_data_248[];
extern "C" char lbl_27_data_457C0[];
extern "C" char lbl_27_data_CDF8[];
extern float lbl_27_rodata_6470;

struct Obj {
    virtual void s0(); virtual void s1(); virtual u64 s2(); virtual void s3();
    virtual void s4(); virtual void s5(int, float*, float*, void*, float);
};
struct A {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual int s16();
};
struct B { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual float s9(); };
struct D { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void* s6(int); };
struct E { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33();
    virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(int*); };
struct W { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(int, int); };
struct Mods {
    char pad0[0xc]; B* b;
    char pad1[0x1c - 0x10]; E* e;
    char pad2[0x64 - 0x20]; W* w;
    char pad3[0x70 - 0x68]; A* a;
    char pad4[0x7c - 0x74]; D* d;
};
struct Self { char pad[8]; void* owner; char pad2[0xd8 - 0xc]; Mods* m; };
struct Par { char pad[4]; int x; char pad2[4]; float f; };

extern "C" void fn_27_2EE21C(void*, Self* self) {
    switch (self->m->a->s16()) {
    case 1: break;
    case 0: {
    void* c = __dynamic_cast(self->owner, 0x3c, lbl_27_data_7DFD8, lbl_27_data_248, 1);
    char* q = (char*)fn_27_2ED9D4(c);
    Par* p = *(Par**)(q + 0x34);
    float f = self->m->b->s9();
    int v = p->x;
    void* r0 = self->m->d->s6(0);
    Obj* o = (Obj*)__dynamic_cast(r0, 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1);
    float a[3]; float b[2];
    a[0] = lbl_27_rodata_6470; a[1] = lbl_27_rodata_6470; a[2] = lbl_27_rodata_6470;
    b[0] = p->f * f;
    b[1] = lbl_27_rodata_6470;
    o->s5(0, b, a, self, lbl_27_rodata_6470);
    ((unsigned char*)o)[5] |= 0x80;
    u64 r = o->s2();
    int t[2]; t[0] = (int)(r >> 32); t[1] = (int)r;
    self->m->e->s41(t);
    self->m->w->s5(0, 0x10000006);
    self->m->w->s5(v, 0x10000005);
    }
    }
}
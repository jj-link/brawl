#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void fn_27_23313C(void*, void*, void*, int);
extern "C" unsigned int fn_41_11CBC(void*, float*, int);
extern "C" void fn_41_B8D4();
extern "C" float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
extern int g_stTriggerMng;
extern char lbl_41_data_1EE8[];
extern char lbl_41_data_2210[];

struct V {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3(int, void*);
};
struct W {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual int s3();
};
struct M { char p[0x14]; W* a; char q[0x70-0x18]; V* c; };
struct O { char p[0xd8]; M* m; };
struct B { char p[0x38]; void* x; };
struct S {
    char p0[0x28]; int f28; char p1[0x60-0x2c]; O* o; char p2[0xb0-0x64]; void* b0;
    char p3[0xdc-0xb4]; char acc[0xd8]; B* b1b4;
};
struct A { int t; char c4, c5, c6, c7; int i8; char pc[4]; char pd[4]; float f14; };
struct C { char p[0x28]; int f28; unsigned f2c; };

extern "C" void fn_41_3BE44(S* self, A* a, int, C* c) {
    switch (a->t) {
    case 6: {
    a->c4 = 1; a->c6 = 1; a->c5 = 0; a->i8 = -1;
    a->f14 = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self->acc, 0xfa2, 0);
    void* r = __dynamic_cast(self->b1b4->x, 8, lbl_41_data_1EE8, lbl_41_data_2210, 1);
    if (g_stTriggerMng) {
        fn_27_23313C(self->b0, (void*)c->f28, (void*)self->f28, (int)((c->f2c << 17) & 0xFF800000) >> 24);
    }
    float sp = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self->acc, 0xfa4, 0);
    if (fn_41_11CBC(r, &sp, 0) == 1) {
        self->o->m->c->s3(7, self->o);
    } else if (self->o->m->a->s3() == 0) {
        self->o->m->c->s3(0xe, self->o);
    } else {
        self->o->m->c->s3(0xf, self->o);
    }
    break; }
    default: fn_41_B8D4();
    }
}
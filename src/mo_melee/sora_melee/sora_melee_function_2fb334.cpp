#pragma force_active on
extern "C" {
extern char lbl_27_data_80608[];
extern char lbl_27_data_C938[];
extern char lbl_27_data_2C0C0[];
extern char lbl_27_data_CBA0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_2FF5DC(void*, int, int, int, int);
}

struct Obj {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual int kind();
};
struct Base { char pad[8]; };
struct Module : Base {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void* get();
};
struct Target {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual int get(int);
};
struct Leaf { virtual void a(); virtual void b(); virtual int c(); };
struct Mid { virtual void a(); virtual void b(); virtual Leaf* c(); };
struct EBase { char pad[0x28]; int f28; char pad2[0x10]; };
struct E : EBase {
    virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3(); virtual void g4();
    virtual void g5(); virtual void g6(); virtual void g7(); virtual void g8(); virtual void g9();
    virtual void g10(); virtual void g11(); virtual void g12(); virtual void g13(); virtual void g14();
    virtual void g15(); virtual void g16(); virtual void g17(); virtual void g18(); virtual void g19();
    virtual void g20(); virtual void g21(); virtual void g22(); virtual void g23(); virtual void g24();
    virtual void g25(); virtual void g26(); virtual void g27(); virtual void g28(); virtual void g29();
    virtual void g30(); virtual void g31(); virtual void g32(); virtual void g33(); virtual void g34();
    virtual void g35(); virtual void g36(); virtual void g37(); virtual void g38(); virtual void g39();
    virtual int fn();
};
struct P { Module* mod; char pad[0x14]; Mid* mid; };
struct Ctx {
    char pad[8];
    E* e;
    char pad2[0xcc];
    P* p;
};

extern "C" int fn_27_2FB334(void* self, Obj* obj, Ctx* ctx) {
    if (obj->kind() == 13) {
        obj = (Obj*)__dynamic_cast(obj, 0, lbl_27_data_80608, lbl_27_data_C938, 0);
        if (!obj)
            return 0;
        Target* t = (Target*)__dynamic_cast(ctx->p->mod->get(), 0, lbl_27_data_2C0C0, lbl_27_data_CBA0, 1);
        int a = t->get(3);
        E* e = ctx->e;
        Mid* m = ctx->p->mid;
        int b = e->f28;
        fn_27_2FF5DC(obj, b, a, m->c()->c(), e->fn());
        return 1;
    }
    return 0;
}

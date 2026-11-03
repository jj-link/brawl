#pragma force_active on

struct Sub_base { char pad[0xc]; };
struct Sub : Sub_base {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void call(int, int, int);
};

#define V8(p) \
    virtual void p##0(); \
    virtual void p##1(); \
    virtual void p##2(); \
    virtual void p##3(); \
    virtual void p##4(); \
    virtual void p##5(); \
    virtual void p##6(); \
    virtual void p##7();

#define V32(p) V8(p##0) V8(p##1) V8(p##2) V8(p##3)

struct ObjectBase {
    char pad[0x3c];
};

struct Obj : ObjectBase {
    V32(a) V32(b) V32(c) V32(d) V32(e)
    V8(f0) V8(f1) V8(f2)
    virtual void h184();
    virtual Sub* get();
};

struct Module8 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void k(float);
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual unsigned isX();
    V8(p17) V8(p18) V8(p19)
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual int f(int);
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void g(int, float);
    virtual void s50();
    virtual void s51();
    virtual unsigned h(int);
};

struct Mod50 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void call(int, int, int, int);
};

struct Mod5C {
    V32(a)
    V8(b)
    virtual void c40();
    virtual unsigned mask();
};

struct Work {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int get(int);
    virtual void set(int, int);
    virtual void s6();
    virtual void clear(int);
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual int isOn(int);
};

struct ModA8 {
    V32(a)
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual int get(int);
};

struct Modules {
    char pad0[8];
    Module8* m8;
    char padC[0x50 - 0xc];
    Mod50* m50;
    char pad54[8];
    Mod5C* m5c;
    char pad60[4];
    Work* work;
    char pad68[0xa8 - 0x68];
    ModA8* ma8;
};

struct Access {
    char pad[8];
    void* obj;
    char padC[0xcc];
    Modules* modules;
};

extern "C" {
    void fn_27_17BF48(void*, Access*);
    void fn_27_17C174(void*, Access*);
    void fn_27_17C32C(void*, Access*);
    void fn_27_1D6434(int, int, int, Sub*, Access*);
    void* __dynamic_cast(void*, long, const void*, const void*, short);
    unsigned getButtonMask__12soControllerFQ212soController9PadButton(int);
    int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(Access*, unsigned, unsigned);
    extern const char lbl_27_data_69C0[];
    extern const char lbl_27_data_248[];
    extern float lbl_27_rodata_2378;
}

extern "C" void fn_27_17BA0C(void* self, Access* acc) {
    switch (acc->modules->work->get(0x2000000C)) {
    case 0: {
        acc->modules->work->clear(0x2000000E);
        unsigned r;
        if (acc->modules->m8->f(1) != -1) {
            r = acc->modules->m8->h(1);
        } else {
            r = acc->modules->m8->isX();
        }
        if (r == 1) {
            if (acc->modules->work->isOn(0x22000013) != 0) {
                fn_27_17C174(self, acc);
                if (acc->modules->ma8->get(0) > 0) {
                    Obj* o = (Obj*)__dynamic_cast(
                        acc->obj, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
                    o->get()->call(1, 0x1d, 0);
                }
            } else {
                acc->modules->work->set(2, 0x2000000C);
                acc->modules->m50->call(0x1f93, 0, 0, 0);
                Obj* o = (Obj*)__dynamic_cast(
                    acc->obj, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
                fn_27_1D6434(2, 0x66, 1, o->get(), acc);
            }
        }
        break;
    }
    case 1: {
        unsigned r;
        if (acc->modules->m8->f(1) != -1) {
            r = acc->modules->m8->h(1);
        } else {
            r = acc->modules->m8->isX();
        }
        if (r == 1) {
            int n = acc->modules->work->get(0x2000000D);
            acc->modules->work->set(n - 1, 0x2000000D);
            if (n - 1 <= 0) {
                fn_27_17C32C(self, acc);
                break;
            }
            if (acc->modules->m8->f(1) != -1) {
                acc->modules->m8->g(1, lbl_27_rodata_2378);
            } else {
                acc->modules->m8->k(lbl_27_rodata_2378);
            }
            if (acc->modules->ma8->get(0) == 0) {
                acc->modules->m50->call(0x1f9d, 0, 0, 0);
            }
        }
        break;
    }
    case 2: {
        acc->modules->work->clear(0x2000000E);
        int n = acc->modules->work->get(0x2000000E);
        Mod5C* c = acc->modules->m5c;
        unsigned m = getButtonMask__12soControllerFQ212soController9PadButton(0);
        unsigned k = c->mask();
        if ((k & m) == 0 ||
            n >= getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0x5a5f, 0)) {
            fn_27_17BF48(self, acc);
        }
        break;
    }
    }
}

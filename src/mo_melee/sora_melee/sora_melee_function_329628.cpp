#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_87F80[];
extern char lbl_27_data_C938[];
extern float lbl_27_rodata_75D8;
extern float lbl_27_rodata_75DC;
extern "C" void fn_27_32D368(void*, int, int, void*, float);

struct Vec { float x, y, z; Vec() {} Vec(const Vec& o) { x = o.x; y = o.y; z = o.z; } };

#define F5(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4();
struct Bs { F5(a) virtual void a5(); virtual int kind(); };
struct Zz { F5(a) virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual float f9();
  F5(b) F5(c) virtual void c5(); virtual void c6(); virtual float f22(); };
struct Pp { virtual void a0(); virtual void a1(); virtual int get(); };
struct Qq { virtual void a0(); virtual void a1(); virtual Pp* get(); };

struct YB { char pad[8]; };
struct Y : YB {
    F5(a) F5(b) F5(c) F5(d) F5(e) F5(f) F5(g) virtual void h0();
    virtual Vec get(int, int);
};
struct AB { char pad[0x28]; int f28; char pad2[0x10]; };
struct A : AB {
    F5(a) F5(b) F5(c) F5(d) F5(e) F5(f) F5(g) F5(h) virtual int chk();
};
struct D { char pad[4]; Y* y; char pad2[4]; Zz* z; char pad3[8]; Qq* q; };
struct Acc {
    char pad[8];
    A* a;
    char pad2[0xCC];
    D* d;
};

extern "C" int fn_27_329628(void*, Bs* obj, Acc* acc) {
    switch (obj->kind()) {
    case 0xD: {
        obj = (Bs*)__dynamic_cast(obj, 0, lbl_27_data_87F80, lbl_27_data_C938, 0);
        int id = acc->a->chk() == 5 ? 0x198 : 0x2A;
        Vec v = acc->d->y->get(id, 0);
        float f31 = acc->d->z->f9();
        float f = acc->d->z->f22();
        v.y = v.y + lbl_27_rodata_75D8 * f;
        v.z = lbl_27_rodata_75DC;
        int r31 = acc->a->f28;
        fn_27_32D368(obj, r31, acc->d->q->get()->get(), &v, f31);
        return 1;
    }
    default:
        return 0;
    }
}

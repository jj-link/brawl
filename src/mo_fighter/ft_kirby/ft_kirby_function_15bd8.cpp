#pragma force_active on
typedef unsigned char u8;

#define V8(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
#define V32(p) V8(p##0) V8(p##1) V8(p##2) V8(p##3)

struct Access;

struct Mod90 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void x14(int, int, int);
};

struct Link {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual int s6(int);
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual int s19(int);
    virtual void s20(int);
};

struct Other {
    virtual void f0(); virtual void f1(); virtual void f2();
    virtual void r05(int, Access*);
};

struct ObjectBase {
    char pad[0x3c];
};

struct Obj : ObjectBase {
    V32(a) V32(b) V32(c) V32(d) V32(e) V8(f0) V8(f1) V8(f2)
    virtual void h184();
    virtual int g00();
};

struct Modules {
    char pad0[0x64];
    Link* link;
    char pad1[0x8];
    Other* other;
    char pad2[0x1c];
    Mod90* x90;
};

struct Access {
    char pad0[0x8];
    void* obj8;
    char pad1[0xcc];
    Modules* modules;
};

extern "C" {
int fn_96_1DD84(int index);
int fn_27_1119B8(int);
void fn_27_1D6434(int, int, int, int, Access*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_96_data_6024[];
extern char lbl_96_data_68D8[];
}

extern "C" void fn_96_15BD8(void* self, Access* acc) {
    Link* link = acc->modules->link;
    acc->modules->x90->x14(9, 1, -1);
    if (link->s19(0x12000042) != 0) {
        int v = link->s6(0x10000048);
        if (v != -1) {
            int idx = fn_96_1DD84(v);
            if (idx != -1) {
                acc->modules->x90->x14(9, 0, -1);
                acc->modules->other->r05(idx, acc);
            }
        }
    } else {
        Obj* o = (Obj*)__dynamic_cast(acc->obj8, 0x3c, lbl_96_data_6024, lbl_96_data_68D8, (short)1);
        if ((fn_27_1119B8(o->g00()) & 0xff) == 0xc) {
            acc->modules->link->s20(0x2200001b);
        }
        fn_27_1D6434(2, 0x13, 0, o->g00(), acc);
    }
}

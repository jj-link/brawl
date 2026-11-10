#pragma force_active on
#include <types.h>
#include <mt/mt_vector.h>

#define V8(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
#define V32(p) V8(p##0) V8(p##1) V8(p##2) V8(p##3)

struct Sp18 {
    s32 a;
    f32 b;
    f32 c;
    s8 d[4];
};

struct Pad8 { char pad[8]; };

class ObjV8 : public Pad8 {
public:
    V32(a)
    virtual void b00();
    virtual u32 b01(u32);
    virtual u32 b02(u32);
    virtual void b03();
    virtual Vec3f b04(u32, u32);
    virtual void b05(u32);
    virtual void b06();
    virtual void b07();
    virtual void b10(u32);
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual void b20();
    virtual void b21();
    virtual void b22();
    virtual void b23();
    virtual Vec3f b24(u32, Vec3f*);
    virtual void b25();
    virtual void b26();
    virtual void b27();
    V8(b3)
    V32(c)
    V8(d)
    virtual void e0();
    virtual void e1(u32, u32, u32);
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual f32 f5();
};

class ObjV0 {
public:
    virtual void n0();
    virtual void n1();
    virtual void n2();
    virtual void n3();
    virtual void n4();
    virtual void s5(Vec3f*);
    virtual void n6();
    virtual void s7(f32);
    virtual void n8();
    virtual void n9();
    virtual void s10();
    virtual void n11();
    virtual void n12();
    virtual void n13();
    virtual void n14();
    virtual void n15();
    virtual void n16();
    virtual void n17();
    virtual void n18();
    virtual void s19();
    virtual void n20();
    virtual void n21();
    virtual void n22();
    virtual void n23();
    virtual void n24();
    virtual void n25();
    virtual void n26();
    virtual void n27();
    virtual void n28();
    virtual void n29();
    virtual void s30(Sp18*, f32);
};

struct Self;

class Arg0 {
public:
    virtual void n0();
    virtual void n1();
    virtual void n2();
    virtual void n3();
    virtual void n4();
    virtual void n5();
    virtual void n6();
    virtual void s7(Self*);
};

struct PadC { char pad[0xc]; };

class ObjVc : public PadC {
public:
    V8(a)
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void s13(u32, u32, u32);
};

struct ObjectBase { char pad[0x3c]; };

class Obj : public ObjectBase {
public:
    V32(a) V32(b) V32(c) V32(d) V32(e)
    V8(f0) V8(f1) V8(f2)
    virtual void h184();
    virtual ObjVc* get();
};

struct Ctx {
    char pad0[4];
    ObjV8* d;
    ObjV0* c;
    ObjV0* b;
    ObjV8* a;
};

struct Self {
    char pad0[8];
    Obj* e;
    char pad1[0xcc];
    Ctx* ctx;
};

extern "C" {
    void* __dynamic_cast(void*, long, const void*, const void*, short);
    extern const char lbl_27_data_69C0[];
    extern const char lbl_27_data_248[];
    extern float lbl_27_rodata_2230;
    extern float lbl_27_rodata_2234;
}

extern "C" void fn_27_1707AC(Arg0* arg0, Self* self) {
    if (self->ctx->a->b02(0) == 1) {
        ObjV8* d = self->ctx->d;
        u32 x = d->b01(0x12d);
        Vec3f pos = d->b04(x, 0);
        self->ctx->a->b10(0);
        self->ctx->b->s10();
        self->ctx->a->e1(9, 1, 0);
        Sp18 sp;
        sp.a = 0xd5;
        sp.b = lbl_27_rodata_2230;
        sp.c = lbl_27_rodata_2234;
        sp.d[0] = 0;
        sp.d[1] = 0;
        sp.d[2] = 0;
        sp.d[3] = 0;
        self->ctx->c->s30(&sp, lbl_27_rodata_2230);
        self->ctx->c->s7(lbl_27_rodata_2230);
        self->ctx->b->s19();
        self->e->b13();
        ObjV8* d2 = self->ctx->d;
        u32 x2 = d2->b01(0x12d);
        Vec3f tmp = d2->b24(x2, &pos);
        pos = tmp;
        pos.m_z = self->ctx->a->f5();
        self->ctx->b->s5(&pos);
        self->ctx->a->e1(9, 1, 0);
        arg0->s7(self);
        self->e->b13();
        self->ctx->a->b05(0);
        Obj* r = (Obj*)__dynamic_cast(self->e, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
        ObjVc* r2 = r->get();
        r2->s13(1, 0x1c, 0);
    }
}

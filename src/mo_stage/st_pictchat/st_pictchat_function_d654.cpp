#pragma force_active on
typedef unsigned int u32;

class SubV {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int, int);
};

struct Sub {
    SubV* vt;
    u32* p4;
    int f8;
};

struct Base {
    char pad0[0x3C];
};

struct Obj : Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();

    char pad40[0x90];
    Sub sub;
    char padDC[0x19C - 0xDC];
    unsigned char b19c;
    char pad19d[3];
    float f1a0;
    u32 w1a4;
    unsigned char b1a8;
    char pad1a9[3];
    u32 w1ac;
    u32 w1b0;
    u32 w1b4;
    unsigned char b1b8;
    unsigned char b1b9;
};

extern "C" void __ct__15grGimmickSpringFPCc(Obj*, const char*);
extern "C" char lbl_73_data_5098[];
extern "C" const float lbl_73_rodata_118;

extern "C" Obj* fn_73_D654(Obj* self, const char* name) {
    __ct__15grGimmickSpringFPCc(self, name);
    self->b19c = 0;
    *(void**)((char*)self + 0x3C) = lbl_73_data_5098;
    self->f1a0 = lbl_73_rodata_118;
    self->w1a4 = 0;
    self->b1a8 = 0;
    self->w1ac = 0;
    self->w1b0 = 0;
    self->w1b4 = 0;
    self->b1b8 = 0;
    self->b1b9 = 0;

    Sub* s = &self->sub;
    if (s == 0) {
        return self;
    }
    s->f8 = 1;
    ((SubV*)s)->v4(0, 15);
    u32* p = s->p4;
    p[1] |= 1;
    self->f26();
    return self;
}

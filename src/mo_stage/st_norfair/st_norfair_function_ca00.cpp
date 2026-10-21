#pragma force_active on
typedef unsigned int u32;

struct Obj;

struct VT { void (*f[7])(void*, int, int); };
extern VT lbl_54_data_2A10;

class SubV {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int, int);
};

struct Sub {
    SubV* vt;
    void* p4;
    int f8;
};

struct Base { char pad[0x3c]; };

struct Obj : Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();

    char pad40[0xd0 - 0x40];
    Sub sub;
    char padDC[0x15c - 0xdc];
    u32 w15c;
    u32 w160;
    float f164;
    float f168;
    float f16c;
    float f170;
    float f174;
    float f178;
    unsigned char b17c;
    unsigned char b17d;
};

extern "C" Obj* fn_54_2C48(Obj* self, const char* name);
extern const float lbl_54_rodata_110;

extern "C" Obj* fn_54_CA00(Obj* self, const char* name) {
    fn_54_2C48(self, name);
    self->w15c = 0;
    *(VT**)((char*)self + 0x3c) = &lbl_54_data_2A10;
    self->w160 = 0;
    const float f = lbl_54_rodata_110;
    self->f164 = f;
    self->f168 = f;
    self->f16c = f;
    self->f170 = f;
    self->f174 = f;
    self->f178 = f;
    self->b17c = 0;
    self->b17d = 1;

    Sub* s = &self->sub;
    if (s == 0) {
        return self;
    }
    s->f8 = 1;
    ((SubV*)s)->v6(0, 0xf);
    u32* p = (u32*)s->p4;
    p[1] |= 0x10;
    return self;
}

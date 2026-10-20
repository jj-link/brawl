#pragma force_active on
typedef unsigned int u32;

struct Obj;

struct VT { void (*f[7])(void*, int, int); };
extern VT lbl_52_data_3300;

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
    char padDC[0x160 - 0xdc];
    unsigned char b160;
    char pad161[3];
    u32 w164;
    u32 w168;
    unsigned char b16c;
    char pad16d[3];
    float f170;
    float f174;
    float f178;
    float f17c;
    unsigned char b180;
    char pad181[3];
    float f184;
};

extern "C" Obj* fn_52_35D0(Obj* self, const char* name);
extern const float lbl_52_rodata_2B0;

extern "C" Obj* fn_52_F77C(Obj* self, const char* name) {
    fn_52_35D0(self, name);
    self->b160 = 0;
    *(VT**)((char*)self + 0x3c) = &lbl_52_data_3300;
    self->w164 = 0;
    self->w168 = 0;
    self->b16c = 0;
    const float f = lbl_52_rodata_2B0;
    self->f170 = f;
    self->f174 = f;
    self->f178 = f;
    self->f17c = f;
    self->b180 = 9;
    self->f184 = f;
    Sub* s = &self->sub;
    if (s == 0) {
        return self;
    }
    s->f8 = 1;
    ((SubV*)s)->v6(0, 0xf);
    u32* p = (u32*)s->p4;
    p[1] |= 8;
    return self;
}

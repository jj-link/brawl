#pragma force_active on
typedef unsigned int u32;

struct Obj;

struct VT { void (*f[7])(void*, int, int); };
extern VT lbl_47_data_2E28;

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
    char padDC[0x158 - 0xdc];
    unsigned char b158;
    unsigned char b159;
    char pad15a[2];
    float f15c;
    float f160;
    float f164;
    u32 w168;
    float f16c;
    float f170;
    float f174;
    u32 w178;
    u32 w17c;
    float f180;
    float f184;
    float f188;
    float f18c;
    unsigned char b190;
    unsigned char b191;
    char pad192[2];
    float f194;
    unsigned char b198;
    char pad199[3];
    float f19c;
    float f1a0;
};

extern "C" Obj* fn_47_1750(Obj* self, const char* name);
extern const float lbl_47_rodata_110;

extern "C" Obj* fn_47_B9A0(Obj* self, const char* name) {
    fn_47_1750(self, name);
    self->b158 = 0;
    *(VT**)((char*)self + 0x3c) = &lbl_47_data_2E28;
    self->b159 = 0;
    const float f = lbl_47_rodata_110;
    self->f15c = f;
    self->f160 = f;
    self->f164 = f;
    self->w168 = 0;
    self->f16c = f;
    self->f170 = f;
    self->f174 = f;
    self->w178 = 0;
    self->w17c = 0;
    self->f184 = f;
    self->f188 = f;
    self->f18c = f;
    self->b190 = 1;
    self->b191 = 0;
    self->f194 = f;
    self->b198 = 1;
    self->f19c = f;
    self->f1a0 = f;
    Sub* s = &self->sub;
    if (s == 0) {
        return self;
    }
    s->f8 = 1;
    ((SubV*)s)->v6(0, 0xf);
    u32* p = (u32*)s->p4;
    p[1] |= 1;
    return self;
}
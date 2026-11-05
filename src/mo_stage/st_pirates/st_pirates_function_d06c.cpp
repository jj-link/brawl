#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

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
    void* p4;
    u32 state;
};

struct Obj {
    char pad0[0x3c];
    void* tbl;
    char pad40[0xd0 - 0x40];
    Sub sub;
    char padDC[0x160 - 0xDC];
    u8 b160;
    char pad161[3];
    u32 i164;
    u32 i168;
    u32 i16c;
    u32 i170;
    u32 i174;
    float f178;
    float f17c;
    float f180;
    float f184;
    float f188;
    float f18c;
    float f190;
    float f194;
    float f198;
    float f19c;
    float f1a0;
    float f1a4;
    u8 b1a8;
};

extern "C" void fn_52_35D0(Obj* self);
extern "C" char lbl_52_data_2B60[];
extern "C" const float lbl_52_rodata_200;

extern "C" Obj* fn_52_D06C(Obj* self) {
    fn_52_35D0(self);
    const float f = lbl_52_rodata_200;
    self->b160 = 0;
    self->tbl = lbl_52_data_2B60;
    self->i164 = 0;
    self->i168 = 0;
    self->i16c = 0;
    self->i170 = 0;
    self->i174 = 0;
    self->f178 = f;
    self->f17c = f;
    self->f180 = f;
    self->f184 = f;
    self->f188 = f;
    self->f18c = f;
    self->f190 = f;
    self->f194 = f;
    self->f198 = f;
    self->f19c = f;
    self->f1a0 = f;
    self->f1a4 = f;
    self->b1a8 = 0;
    Sub* s = &self->sub;
    if (s == 0) return self;
    s->state = 1;
    ((SubV*)s)->v4(0, 15);
    u32* p = (u32*)s->p4;
    p[1] |= 8;
    return self;
}
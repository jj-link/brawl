#pragma force_active on
typedef unsigned int u32;

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

struct Obj {
    char pad0[0x3c];
    void* vtable;
    char pad40[0xd0 - 0x40];
    Sub sub;
    char padDC[0x158 - 0xdc];
    u32 w158;
    u32 w15c;
    unsigned char b160;
    unsigned char b161;
    float f164;
    float f168;
    float f16c;
    unsigned char b170;
    char pad171[3];
    float f174;
};

extern "C" void fn_88_4368(Obj*);
extern char lbl_88_data_20F0[];
extern const float lbl_88_rodata_158;

extern "C" Obj* fn_88_7460(Obj* self) {
    fn_88_4368(self);
    self->w158 = 0;
    self->vtable = lbl_88_data_20F0;
    self->w15c = 0;
    self->b160 = 0;
    self->b161 = 0;
    const float f = lbl_88_rodata_158;
    self->f164 = f;
    self->f168 = f;
    self->f16c = f;
    self->b170 = 3;
    self->f174 = f;
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

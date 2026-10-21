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
    u32 f8;
};

struct Base { char pad[0x3c]; };

struct Obj : Base {
    void* vt;
    char pad40[0xd0 - 0x40];
    Sub sub;
    char padDC[0x1d0 - 0xdc];
    unsigned char b1d0;
    char pad1d1[3];
    float f1d4;
    u32 w1d8;
    float f1dc;
    float f1e0;
    float f1e4;
    float f1e8;
    float f1ec;
    unsigned char b1f0;
    unsigned char b1f1;
};

extern "C" void fn_60_6424(Obj* self);
extern char lbl_60_data_FF0[];
extern const float lbl_60_rodata_108;

extern "C" Obj* fn_60_7230(Obj* self) {
    fn_60_6424(self);
    const float f = lbl_60_rodata_108;
    self->b1d0 = 0;
    self->vt = lbl_60_data_FF0;
    self->f1d4 = f;
    self->w1d8 = 0;
    self->f1dc = f;
    self->f1e0 = f;
    self->f1e4 = f;
    self->f1e8 = f;
    self->f1ec = f;
    self->b1f0 = 0;
    self->b1f1 = 0;
    Sub* s = &self->sub;
    if (s == 0) {
        return self;
    }
    s->f8 = 1;
    ((SubV*)s)->v6(0, 15);
    u32* p = (u32*)s->p4;
    p[1] |= 1;
    return self;
}

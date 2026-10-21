#pragma force_active on
typedef unsigned int u32;

struct Obj;

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
    unsigned char b161;
    char pad162[2];
    u32 w164;
    u32 w168;
    u32 w16c;
    u32 w170;
    unsigned char b174;
    char pad175[3];
    u32 w178;
    u32 w17c;
    unsigned char b180;
    char pad181[3];
    float f184;
};

extern "C" Obj* fn_52_35D0(Obj* self);
extern char lbl_52_data_3580[];
extern const float lbl_52_rodata_2D0;

extern "C" Obj* fn_52_10228(Obj* self) {
    fn_52_35D0(self);
    const float f = lbl_52_rodata_2D0;
    self->b160 = 0;
    *(char**)((char*)self + 0x3c) = lbl_52_data_3580;
    self->b161 = 0;
    self->w164 = 0;
    self->w168 = 0;
    self->w16c = 0;
    self->w170 = 0;
    self->b174 = 0;
    self->w178 = 0;
    self->w17c = 0;
    self->b180 = 0x11;
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

#pragma force_active on
typedef unsigned int u32;

struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void clear(int, int);
    void* p4;
    int f8;
};

struct Obj {
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    Sub sub;
    char padDC[0x160 - 0xdc];
    unsigned char b160;
    unsigned char b161;
    char pad162[2];
    u32 w164;
    u32 w168;
    unsigned char b16c;
    unsigned char b16d;
    char pad16e[2];
    float f170;
};

extern "C" Obj* fn_52_35D0(Obj*);
extern "C" char lbl_52_data_2108[];
extern "C" const float lbl_52_rodata_148;

extern "C" Obj* fn_52_9A0C(Obj* self) {
    fn_52_35D0(self);
    self->b160 = 0;
    self->vtable = lbl_52_data_2108;
    self->b161 = 0;
    self->w164 = 0;
    self->w168 = 0;
    self->b16c = 0;
    self->b16d = 2;
    self->f170 = lbl_52_rodata_148;

    Sub* s = &self->sub;
    if (!s)
        return self;

    s->f8 = 1;
    s->clear(0, 15);
    u32* p = (u32*)s->p4;
    p[1] |= 8;
    return self;
}

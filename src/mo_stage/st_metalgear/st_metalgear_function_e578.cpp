#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 pad;
    u32 flags;
};

struct Part {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void clear(int, int);

    Flags* data;
    u32 state;
};

struct Obj {
    char pad0[0x3c];
    void* vt;
    char pad40[0x90];
    Part sub;
    char padDC[0x158 - 0xdc];
    u32 w158;
    u32 w15c;
    u32 w160;
    float f164;
    float f168;
    float f16c;
    u32 w170;
    unsigned char b174;
    unsigned char b175;
    unsigned char b176;
    u32 w178;
};

extern "C" void fn_71_2708(Obj*);
extern "C" char lbl_71_data_37D0[];
extern "C" const float lbl_71_rodata_238;

extern "C" {
Obj* fn_71_E578(Obj* self) {
    fn_71_2708(self);
    self->w158 = 0;
    self->vt = lbl_71_data_37D0;
    self->w15c = 0;
    self->w160 = 0;
    const float f = lbl_71_rodata_238;
    self->f164 = f;
    self->f168 = f;
    self->f16c = f;
    self->w170 = 0;
    self->b174 = 9;
    self->b175 = 0;
    self->b176 = 0;
    self->w178 = 0;

    Part* p = &self->sub;
    if (p == 0) {
        return self;
    }
    p->state = 1;
    p->clear(0, 15);
    p->data->flags |= 1;
    return self;
}
}

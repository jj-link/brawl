#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 pad;
    u32 flags;
};

struct Anim {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void set(int, int);
    Flags* data;
    u32 state;
};

struct Self {
    char pad0[0x3c];
    void* tbl;
    char pad1[0xd0 - 0x40];
    Anim anim;
    char pad2[0x158 - 0xdc];
    u32 i158;
    u32 i15c;
    u32 i160;
    float f164;
    float f168;
    float f16c;
    unsigned char b170;
    unsigned char b171;
    u32 i174;
};

extern "C" void fn_51_2838(void*);
extern "C" char lbl_51_data_97C8[];
extern "C" const float lbl_51_rodata_2A0;

extern "C" Self* fn_51_15998(Self* self) {
    fn_51_2838(self);
    self->tbl = lbl_51_data_97C8;
    self->i158 = 0;
    self->i15c = 0;
    self->i160 = 0;
    self->f164 = lbl_51_rodata_2A0;
    self->f168 = lbl_51_rodata_2A0;
    self->f16c = lbl_51_rodata_2A0;
    self->b170 = 0;
    self->b171 = 0;
    self->i174 = 0;

    Anim* a = &self->anim;
    if (a == 0) {
        return self;
    }
    a->state = 1;
    a->set(0, 15);
    a->data->flags |= 1;
    a->data->flags |= 0x10;
    return self;
}

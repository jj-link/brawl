#pragma force_active on
typedef unsigned int u32;

struct Node {
    u32 unk0;
    u32 flags;
    char pad[0x7C];
    u32 flags2;
};

struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int, int);
    Node* node;
    u32 state;
};

struct Self {
    char pad0[0x3C];
    void* vtable;
    char pad40[0x90];
    Sub sub;
    char padDC[0x8C];
    float f168;
    float f16C;
    float f170;
    float f174;
    float f178;
    float f17C;
    u32 f180;
    u32 f184;
};

extern "C" void fn_70_2088(Self* self);
extern "C" const float lbl_70_rodata_120;
extern "C" char lbl_70_data_4090[];

extern "C" Self* fn_70_CE1C(Self* self) {
    fn_70_2088(self);
    self->f180 = 0;
    self->vtable = lbl_70_data_4090;
    self->f168 = lbl_70_rodata_120;
    self->f16C = lbl_70_rodata_120;
    self->f170 = lbl_70_rodata_120;
    self->f174 = lbl_70_rodata_120;
    self->f178 = lbl_70_rodata_120;
    self->f17C = lbl_70_rodata_120;
    self->f184 = 0;

    Sub* p = &self->sub;
    if (p == 0) return self;

    p->state = 2;
    p->f4(0, 0xF);
    p->node->flags |= 0x20;
    p->node->flags2 |= 0x20;

    return self;
}

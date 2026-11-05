#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Node {
    u32 unk0;
    u32 flags;
    char pad[0x7C];
    u32 flags2;
};

struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int a, int b);
    Node* node;
    u32 state;
};

struct Self {
    char pad0[0x3C];
    void* vtable;
    char pad40[0x90];
    Sub sub;
    char padDC[0x8C];
    u8 b168;
    u8 b169;
    u8 pad16A[2];
    float f16C;
    float f170;
    u32 w174;
    u32 w178;
    float f17C;
    float f180;
    float f184;
    float f188;
    float f18C;
    float f190;
    float f194;
    float f198;
    float f19C;
    u32 w1A0;
    u32 w1A4;
    u8 b1A8;
    u8 b1A9;
    u8 pad1AA[2];
    u32 w1AC;
    u32 w1B0;
    u32 w1B4;
    u32 w1B8;
    u8 b1BC;
    u8 pad1BD[3];
    float f1C0;
    u8 b1C4;
    u8 b1C5;
    u8 b1C6;
    u8 pad1C7;
    u32 w1C8;
};

extern "C" void fn_70_2088(Self* self, const char* name);
extern "C" const float lbl_70_rodata_48;
extern "C" char lbl_70_data_21D0[];

extern "C" Self* fn_70_2C28(Self* self, const char* name) {
    fn_70_2088(self, name);
    self->vtable = lbl_70_data_21D0;
    self->b168 = 0;
    self->f16C = lbl_70_rodata_48;
    self->b169 = 0;
    self->f170 = lbl_70_rodata_48;
    self->w174 = 0;
    self->w178 = 0;
    self->f17C = lbl_70_rodata_48;
    self->f180 = lbl_70_rodata_48;
    self->f184 = lbl_70_rodata_48;
    self->f188 = lbl_70_rodata_48;
    self->f18C = lbl_70_rodata_48;
    self->f190 = lbl_70_rodata_48;
    self->f194 = lbl_70_rodata_48;
    self->f198 = lbl_70_rodata_48;
    self->f19C = lbl_70_rodata_48;
    self->w1A0 = 0;
    self->w1A4 = 0;
    self->b1A8 = 0;
    self->b1A9 = 0x27;
    self->w1AC = 0;
    self->w1B0 = -1;
    self->w1B4 = 0;
    self->w1B8 = 0;
    self->b1BC = 5;
    self->f1C0 = lbl_70_rodata_48;
    self->b1C4 = 0;
    self->b1C5 = 8;
    self->b1C6 = 6;
    self->w1C8 = 0;

    Sub* s = &self->sub;
    if (s == 0) return self;

    s->state = 2;
    s->v4(0, 0xF);
    s->node->flags |= 1;
    s->node->flags |= 2;
    s->node->flags2 |= 2;

    return self;
}
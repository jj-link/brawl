#pragma force_active on

struct Inner {
    int a;
    unsigned int flags;
};

struct Sub {
    int x0;
    Inner* inner;
};

struct Obj {
    char pad0[0x3c];
    void* data3c;
    char pad1[0xd0 - 0x40];
    Sub sub;
    char pad2[0x164 - 0xd8];
    int f164;
    int f168;
    float f16c[9];
    unsigned char b190;
    unsigned char b191;
    unsigned char b192;
    unsigned char b193;
    unsigned char b194;
    int f198;
    int f19c;
};

extern "C" {
extern char lbl_50_data_2990[];
extern const float lbl_50_rodata_158;
void fn_50_1F78(void*);

void* fn_50_9E80(void* arg) {
    Obj* self = (Obj*)arg;
    fn_50_1F78(self);
    self->data3c = lbl_50_data_2990;
    self->f164 = 0;
    self->f168 = 0;
    self->f16c[0] = lbl_50_rodata_158;
    self->f16c[1] = lbl_50_rodata_158;
    self->f16c[2] = lbl_50_rodata_158;
    self->f16c[3] = lbl_50_rodata_158;
    self->f16c[4] = lbl_50_rodata_158;
    self->f16c[5] = lbl_50_rodata_158;
    self->f16c[6] = lbl_50_rodata_158;
    self->f16c[7] = lbl_50_rodata_158;
    self->f16c[8] = lbl_50_rodata_158;
    self->b190 = 6;
    self->b191 = 8;
    self->b192 = 0;
    self->b193 = 0;
    self->b194 = 0;
    self->f198 = 0;
    self->f19c = -1;
    Sub* s = &self->sub;
    if (s == 0) {
        return self;
    }
    s->inner->flags |= 1;
    s->inner->flags |= 2;
    return self;
}
}

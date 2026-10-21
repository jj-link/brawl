#pragma force_active on

extern "C" {
void fn_63_2B6C(void*);
void* __ct__14snd3DGeneratorFv(void*);
extern char lbl_63_data_4AF0[];
extern const float lbl_63_rodata_138;
}

struct Obj {
    char pad0[0x3C];
    void* data;
    char pad1[0x174 - 0x40];
    int a174;
    int a178;
    unsigned char b17c;
    char pad2[3];
    float f180;
    float f184;
    float f188;
    unsigned char b18c;
    unsigned char b18d;
    unsigned char b18e;
    char pad3;
    int a190;
    int a194;
    int a198;
    int a19c;
    int a1a0;
};

extern "C" Obj* fn_63_10C5C(Obj* self) {
    fn_63_2B6C(self);
    self->data = lbl_63_data_4AF0;
    __ct__14snd3DGeneratorFv((char*)self + 0x1A4);
    self->a174 = 0;
    self->a178 = 0;
    self->b17c = 4;
    self->f180 = lbl_63_rodata_138;
    self->f184 = lbl_63_rodata_138;
    self->f188 = lbl_63_rodata_138;
    self->b18c = 0x10;
    self->b18d = 0;
    self->b18e = 0;
    self->a190 = 0;
    self->a194 = 0;
    self->a198 = 0;
    self->a19c = 0;
    self->a1a0 = 0;

    int* p = (int*)((char*)self + 0xD0);
    if (!p) {
        return self;
    }
    int* q = (int*)p[1];
    q[1] |= 1;
    return self;
}

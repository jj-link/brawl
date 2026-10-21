#pragma force_active on

typedef unsigned char u8;
typedef signed short s16;

extern "C" void fn_27_27A8DC(void*);
extern "C" unsigned char lbl_27_data_5A4D4[];
extern "C" const float lbl_27_rodata_4550[7];

struct Object {
    char pad0[0x3C];
    void* vtable;
    char pad1[0x11C];
    int unk15c;
    u8 unk160;
    char pad2[3];
    int unk164;
    u8 unk168;
    char pad3[3];
    float unk16c;
    int unk170;
    float unk174, unk178, unk17c, unk180;
    float unk184, unk188, unk18c;
    s16 unk190, unk192, unk194, unk196;
    s16 unk198, unk19a, unk19c;
    u8 unk19e;
};

extern "C" void* fn_27_27ABB4(Object* self) {
    float* c = (float*)lbl_27_rodata_4550;
    fn_27_27A8DC(self);
    self->unk19e = 0;
    self->vtable = lbl_27_data_5A4D4;
    self->unk160 = (self->unk160 | 0x80) & ~0x70;
    self->unk16c = c[0];
    self->unk164 = 0;
    self->unk19e = 0;
    self->unk170 = 0;
    self->unk15c = 0;
    self->unk174 = c[1];
    self->unk178 = c[1];
    self->unk17c = c[2];
    self->unk180 = c[3] * c[1];
    self->unk184 = c[4];
    self->unk190 = -190;
    self->unk194 = -120;
    self->unk192 = 190;
    self->unk196 = 90;
    self->unk198 = -11;
    self->unk19a = -22;
    self->unk19c = -1;
    self->unk168 = 0;
    self->unk188 = c[5] * self->unk180;
    self->unk18c = c[6] * c[1];
    return self;
}

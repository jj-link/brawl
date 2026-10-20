#pragma force_active on
struct BigBlue {
    unsigned char pad0[0x3C];
    void* vtable;
    unsigned char pad40[0x118];
    float x, y, z;
    unsigned int a, b, c, d;
    unsigned char state;
    unsigned char pad175[3];
    unsigned int e, f, g, h;
};

extern "C" void __ct__11grDxBigBlueFPCc(BigBlue*, const char*);
extern "C" const float lbl_81_rodata_B0;
extern "C" unsigned char lbl_81_data_C50[];

extern "C" BigBlue* fn_81_4740(BigBlue* self, const char* name) {
    __ct__11grDxBigBlueFPCc(self, name);
    self->vtable = lbl_81_data_C50;
    self->x = lbl_81_rodata_B0;
    self->y = lbl_81_rodata_B0;
    self->z = lbl_81_rodata_B0;
    self->a = 0;
    self->b = 0;
    self->c = 0;
    self->d = 0;
    self->state = 12;
    self->e = 0;
    self->f = 0;
    self->g = 0;
    self->h = 0;
    return self;
}

#pragma force_active on
extern "C" const float lbl_72_rodata_6C;

struct St {
    unsigned char pad[0x60];
    float f60;
    float f64;
    float f68;
    unsigned char pad2[8];
    unsigned long f74;
};

extern "C" void fn_72_4D84(St* self) {
    float z = lbl_72_rodata_6C;
    self->f60 = z;
    self->f64 = z;
    self->f68 = z;
    self->f74 = self->f74 & ~31UL;
}

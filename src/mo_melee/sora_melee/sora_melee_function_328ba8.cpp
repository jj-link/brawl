#pragma force_active on
extern "C" void fn_27_2D935C(void* self);
extern "C" unsigned char lbl_27_data_87A20[];

extern "C" {
void* fn_27_328BA8(void* self) {
    fn_27_2D935C(self);
    unsigned char* s = (unsigned char*)self;
    unsigned char* base = lbl_27_data_87A20;
    *(unsigned char**)(s + 0x3C) = base;
    *(unsigned char**)(s + 0x40) = base + 0x64;
    *(unsigned char**)(s + 0x48) = base + 0x70;
    *(unsigned char**)(s + 0x54) = base + 0x84;
    *(unsigned char**)(s + 0x64) = base + 0xDC;
    *(unsigned char**)(s + 0x70) = base + 0xEC;
    *(unsigned char**)(s + 0x7C) = base + 0x100;
    *(unsigned char**)(s + 0x88) = base + 0x118;
    *(unsigned char**)(s + 0x90) = base + 0x124;
    return self;
}
}

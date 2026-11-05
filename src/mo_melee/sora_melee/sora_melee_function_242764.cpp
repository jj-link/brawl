#include <gm/gm_global.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_4E250[];
extern char lbl_27_data_4E2AC[];
extern const unsigned char lbl_27_rodata_3E08[];
void* fn_27_241E30(void* self, const char* name);
}

struct Appearance {
    char pad0[0x3C];
    void* vtable;
    u8 f40;
    char pad41[7];
    u8 f48;
    char pad49[3];
    float f4C, f50, f54, f58, f5C, f60, f64, f68, f6C;
    char pad70[4];
    int f74, f78, f7C, f80, f84, f88, f8C, f90;
    u8 f94, f95;
    char pad96[0x188 - 0x96];
    float f188;
    char pad18C[4];
    int f190;
    char pad194[4];
    float f198, f19C;
    char pad1A0[4];
    u8 f1A4;
    char pad1A5[3];
    float f1A8;
    int f1AC, f1B0;
    u8 f1B4;
};

extern "C" Appearance* fn_27_242764(Appearance* self) {
    const float* base = (const float*)lbl_27_rodata_3E08;
    fn_27_241E30(self, lbl_27_data_4E250);
    self->vtable = lbl_27_data_4E2AC;
    self->f48 = 0;
    self->f4C = base[0];
    self->f68 = base[0];
    self->f6C = base[0];
    self->f90 = 0;
    self->f94 = 0;
    self->f95 = 0;
    self->f188 = base[0];
    self->f198 = base[1];
    self->f19C = base[1];
    self->f1A4 = 0;
    self->f1A8 = base[0];
    self->f1AC = 0;
    self->f1B0 = 0;
    self->f1B4 = 0;
    self->f40 = 0;
    self->f190 = 0;
    self->f50 = base[0];
    self->f54 = base[2];
    self->f58 = base[3];
    self->f5C = base[0];
    self->f60 = base[2];
    self->f64 = base[3];
    self->f74 = 0;
    self->f78 = 0;
    self->f7C = 0;
    self->f80 = 0;
    self->f84 = 0;
    self->f88 = 0;
    self->f8C = 0;
    gmGlobalModeMelee* melee = g_GameGlobal->m_modeMelee;
    self->f1A8 = base[1];
    switch ((int)*(u16*)((char*)melee + 0x1A)) {
    case 0x3B:
        self->f5C = base[0];
        self->f60 = base[2];
        self->f64 = base[4];
        break;
    default:
        self->f50 = base[0];
        self->f54 = base[2];
        self->f58 = base[5];
        self->f5C = base[0];
        self->f60 = base[2];
        self->f64 = base[6];
        break;
    case 0x20:
        self->f50 = base[0];
        self->f54 = base[2];
        self->f58 = base[5];
        self->f5C = base[0];
        self->f60 = base[2];
        self->f64 = base[7];
        break;
    case 0x21:
        self->f50 = base[0];
        self->f54 = base[2];
        self->f58 = base[8];
        self->f5C = base[0];
        self->f60 = base[2];
        self->f64 = base[9];
        break;
    case 0xB:
        self->f50 = base[0];
        self->f54 = base[2];
        self->f58 = base[5];
        self->f5C = base[0];
        self->f60 = base[2];
        self->f64 = base[10];
        break;
    case 2:
        self->f50 = base[0];
        self->f54 = base[2];
        self->f58 = base[5];
        self->f5C = base[0];
        self->f60 = base[2];
        self->f64 = base[11];
        break;
    case 3:
        self->f50 = base[0];
        self->f54 = base[2];
        self->f58 = base[5];
        self->f5C = base[0];
        self->f60 = base[2];
        self->f64 = base[5];
        break;
    case 4:
        self->f50 = base[0];
        self->f54 = base[2];
        self->f58 = base[5];
        self->f5C = base[0];
        self->f60 = base[2];
        self->f64 = base[12];
        break;
    }
    return self;
}

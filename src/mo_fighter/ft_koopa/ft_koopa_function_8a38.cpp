#pragma force_active on
typedef unsigned char u8;

struct KoopaParamA {
    float f0;
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    int i18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
    float f38;
    int i3C;
    int i40;
    float f44;
    float f48;
    float f4C;
};

struct KoopaParamB {
    float f0;
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    float f18;
    float f1C;
    int i20;
    int i24;
    int i28;
    int i2C;
};

struct KoopaParamC {
    float f0;
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    float f18;
    float f1C;
};

struct KoopaParamD {
    float f0;
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
};

struct KoopaAccesser {
    u8 pad[0x10];
    float* floats[2][47];
    int* ints[2][8];
};

extern "C" void fn_102_8A38(KoopaAccesser* self, const u8* data)
{
    for (int i = 0; i < 2; ++i) {
        self->floats[i][0] = &(*(KoopaParamA**)(data + 0x7C))->f0;
        self->floats[i][1] = &(*(KoopaParamA* const*)(data + 0x7C))->f4;
        self->floats[i][2] = &(*(KoopaParamA* const*)(data + 0x7C))->f8;
        self->floats[i][3] = &(*(KoopaParamA* const*)(data + 0x7C))->fC;
        self->floats[i][4] = &(*(KoopaParamA* const*)(data + 0x7C))->f10;
        self->floats[i][5] = &(*(KoopaParamA* const*)(data + 0x7C))->f14;
        self->floats[i][6] = &(*(KoopaParamA* const*)(data + 0x7C))->f1C;
        self->floats[i][7] = &(*(KoopaParamA* const*)(data + 0x7C))->f20;
        self->floats[i][8] = &(*(KoopaParamA* const*)(data + 0x7C))->f24;
        self->floats[i][9] = &(*(KoopaParamA* const*)(data + 0x7C))->f28;
        self->floats[i][10] = &(*(KoopaParamA* const*)(data + 0x7C))->f2C;
        self->floats[i][11] = &(*(KoopaParamA* const*)(data + 0x7C))->f30;
        self->floats[i][12] = &(*(KoopaParamA* const*)(data + 0x7C))->f34;
        self->floats[i][13] = &(*(KoopaParamA* const*)(data + 0x7C))->f38;
        self->floats[i][14] = &(*(KoopaParamA* const*)(data + 0x7C))->f44;
        self->floats[i][15] = &(*(KoopaParamA* const*)(data + 0x7C))->f48;
        self->floats[i][16] = &(*(KoopaParamA* const*)(data + 0x7C))->f4C;
        self->floats[i][17] = &(*(KoopaParamB**)(data + 0x80))->f0;
        self->floats[i][18] = &(*(KoopaParamB* const*)(data + 0x80))->f4;
        self->floats[i][19] = &(*(KoopaParamB* const*)(data + 0x80))->f8;
        self->floats[i][20] = &(*(KoopaParamB* const*)(data + 0x80))->fC;
        self->floats[i][21] = &(*(KoopaParamB* const*)(data + 0x80))->f10;
        self->floats[i][22] = &(*(KoopaParamB* const*)(data + 0x80))->f14;
        self->floats[i][23] = &(*(KoopaParamB* const*)(data + 0x80))->f18;
        self->floats[i][24] = &(*(KoopaParamB* const*)(data + 0x80))->f1C;
        self->floats[i][25] = &(*(KoopaParamC**)(data + 0x84))->f0;
        self->floats[i][26] = &(*(KoopaParamC* const*)(data + 0x84))->f4;
        self->floats[i][27] = &(*(KoopaParamC* const*)(data + 0x84))->f8;
        self->floats[i][28] = &(*(KoopaParamC* const*)(data + 0x84))->fC;
        self->floats[i][29] = &(*(KoopaParamC* const*)(data + 0x84))->f10;
        self->floats[i][30] = &(*(KoopaParamC* const*)(data + 0x84))->f14;
        self->floats[i][31] = &(*(KoopaParamC* const*)(data + 0x84))->f18;
        self->floats[i][32] = &(*(KoopaParamC* const*)(data + 0x84))->f1C;
        self->floats[i][33] = &(*(KoopaParamD**)(data + 0x88))->f0;
        self->floats[i][34] = &(*(KoopaParamD* const*)(data + 0x88))->f4;
        self->floats[i][35] = &(*(KoopaParamD* const*)(data + 0x88))->f8;
        self->floats[i][36] = &(*(KoopaParamD* const*)(data + 0x88))->fC;
        self->floats[i][37] = &(*(KoopaParamD* const*)(data + 0x88))->f10;
        self->floats[i][38] = &(*(KoopaParamD* const*)(data + 0x88))->f14;
        self->floats[i][39] = &(*(KoopaParamD* const*)(data + 0x88))->f18;
        self->floats[i][40] = &(*(KoopaParamD* const*)(data + 0x88))->f1C;
        self->floats[i][41] = &(*(KoopaParamD* const*)(data + 0x88))->f20;
        self->floats[i][42] = &(*(KoopaParamD* const*)(data + 0x88))->f24;
        self->floats[i][43] = &(*(KoopaParamD* const*)(data + 0x88))->f28;
        self->floats[i][44] = &(*(KoopaParamD* const*)(data + 0x88))->f2C;
        self->floats[i][45] = &(*(KoopaParamD* const*)(data + 0x88))->f30;

        self->ints[i][0] = &(*(KoopaParamA* const*)(data + 0x7C))->i18;
        self->ints[i][1] = &(*(KoopaParamA* const*)(data + 0x7C))->i3C;
        self->ints[i][2] = &(*(KoopaParamA* const*)(data + 0x7C))->i40;
        self->ints[i][3] = &(*(KoopaParamB* const*)(data + 0x80))->i20;
        self->ints[i][4] = &(*(KoopaParamB* const*)(data + 0x80))->i24;
        self->ints[i][5] = &(*(KoopaParamB* const*)(data + 0x80))->i28;
        self->ints[i][6] = &(*(KoopaParamB* const*)(data + 0x80))->i2C;
    }
}

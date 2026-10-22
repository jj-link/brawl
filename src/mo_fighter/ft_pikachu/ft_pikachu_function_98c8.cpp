#pragma force_active on
struct PikachuParam1 {
    float f0, f4, f8, fC;
    int i10;
};

struct PikachuParam2 {
    float f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C, f30, f34, f38, f3C;
    int i40;
};

struct PikachuParam3 {
    int i0, i4;
    float f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C, f30, f34, f38, f3C, f40;
    int i44;
    float f48;
    int i4C;
    float f50, f54;
};

struct PikachuParam4 {
    float f0, f4, f8, fC;
};

struct PikachuParam5 {
    float f0, f4, f8;
    int iC, i10;
};

struct PikachuAccesser {
    unsigned char pad[0x10];
    float* floats[2][46];
    int* ints[2][9];
};

extern "C" void fn_98_98C8(PikachuAccesser* accesser, const unsigned char* data)
{
    for (int i = 0; i < 2; ++i) {
        accesser->floats[i][0] = &(*(PikachuParam1**)(data + 0x7C))->f0;
        accesser->floats[i][1] = &(*(PikachuParam1* const*)(data + 0x7C))->f4;
        accesser->floats[i][2] = &(*(PikachuParam1* const*)(data + 0x7C))->f8;
        accesser->floats[i][3] = &(*(PikachuParam1* const*)(data + 0x7C))->fC;

        accesser->floats[i][4] = &(*(PikachuParam2**)(data + 0x80))->f0;
        accesser->floats[i][5] = &(*(PikachuParam2* const*)(data + 0x80))->f4;
        accesser->floats[i][6] = &(*(PikachuParam2* const*)(data + 0x80))->f8;
        accesser->floats[i][7] = &(*(PikachuParam2* const*)(data + 0x80))->fC;
        accesser->floats[i][8] = &(*(PikachuParam2* const*)(data + 0x80))->f10;
        accesser->floats[i][9] = &(*(PikachuParam2* const*)(data + 0x80))->f14;
        accesser->floats[i][10] = &(*(PikachuParam2* const*)(data + 0x80))->f18;
        accesser->floats[i][11] = &(*(PikachuParam2* const*)(data + 0x80))->f1C;
        accesser->floats[i][12] = &(*(PikachuParam2* const*)(data + 0x80))->f20;
        accesser->floats[i][13] = &(*(PikachuParam2* const*)(data + 0x80))->f24;
        accesser->floats[i][14] = &(*(PikachuParam2* const*)(data + 0x80))->f28;
        accesser->floats[i][15] = &(*(PikachuParam2* const*)(data + 0x80))->f2C;
        accesser->floats[i][16] = &(*(PikachuParam2* const*)(data + 0x80))->f30;
        accesser->floats[i][17] = &(*(PikachuParam2* const*)(data + 0x80))->f34;
        accesser->floats[i][18] = &(*(PikachuParam2* const*)(data + 0x80))->f38;
        accesser->floats[i][19] = &(*(PikachuParam2* const*)(data + 0x80))->f3C;

        accesser->floats[i][20] = &(*(PikachuParam3* const*)(data + 0x84))->f8;
        accesser->floats[i][21] = &(*(PikachuParam3* const*)(data + 0x84))->fC;
        accesser->floats[i][22] = &(*(PikachuParam3* const*)(data + 0x84))->f10;
        accesser->floats[i][23] = &(*(PikachuParam3* const*)(data + 0x84))->f14;
        accesser->floats[i][24] = &(*(PikachuParam3* const*)(data + 0x84))->f18;
        accesser->floats[i][25] = &(*(PikachuParam3* const*)(data + 0x84))->f1C;
        accesser->floats[i][26] = &(*(PikachuParam3* const*)(data + 0x84))->f20;
        accesser->floats[i][27] = &(*(PikachuParam3* const*)(data + 0x84))->f24;
        accesser->floats[i][28] = &(*(PikachuParam3* const*)(data + 0x84))->f28;
        accesser->floats[i][29] = &(*(PikachuParam3* const*)(data + 0x84))->f2C;
        accesser->floats[i][30] = &(*(PikachuParam3* const*)(data + 0x84))->f30;
        accesser->floats[i][31] = &(*(PikachuParam3* const*)(data + 0x84))->f34;
        accesser->floats[i][32] = &(*(PikachuParam3* const*)(data + 0x84))->f38;
        accesser->floats[i][33] = &(*(PikachuParam3* const*)(data + 0x84))->f3C;
        accesser->floats[i][34] = &(*(PikachuParam3* const*)(data + 0x84))->f40;
        accesser->floats[i][35] = &(*(PikachuParam3* const*)(data + 0x84))->f48;
        accesser->floats[i][36] = &(*(PikachuParam3* const*)(data + 0x84))->f50;
        accesser->floats[i][37] = &(*(PikachuParam3* const*)(data + 0x84))->f54;

        accesser->floats[i][38] = &(*(PikachuParam4**)(data + 0x88))->f0;
        accesser->floats[i][39] = &(*(PikachuParam4* const*)(data + 0x88))->f4;
        accesser->floats[i][40] = &(*(PikachuParam4* const*)(data + 0x88))->f8;
        accesser->floats[i][41] = &(*(PikachuParam4* const*)(data + 0x88))->fC;

        accesser->floats[i][42] = &(*(PikachuParam5**)(data + 0x8C))->f0;
        accesser->floats[i][43] = &(*(PikachuParam5* const*)(data + 0x8C))->f4;
        accesser->floats[i][44] = &(*(PikachuParam5* const*)(data + 0x8C))->f8;

        accesser->ints[i][0] = &(*(PikachuParam1* const*)(data + 0x7C))->i10;
        accesser->ints[i][1] = &(*(PikachuParam2* const*)(data + 0x80))->i40;
        accesser->ints[i][2] = &(*(PikachuParam3**)(data + 0x84))->i0;
        accesser->ints[i][3] = &(*(PikachuParam3* const*)(data + 0x84))->i4;
        accesser->ints[i][4] = &(*(PikachuParam3* const*)(data + 0x84))->i44;
        accesser->ints[i][5] = &(*(PikachuParam3* const*)(data + 0x84))->i4C;
        accesser->ints[i][6] = &(*(PikachuParam5* const*)(data + 0x8C))->iC;
        accesser->ints[i][7] = &(*(PikachuParam5* const*)(data + 0x8C))->i10;
    }
}

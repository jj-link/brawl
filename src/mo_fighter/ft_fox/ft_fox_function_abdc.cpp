#pragma force_active on
struct FoxParam1 {
    float f0, f4, f8, fC, f10, f14;
    int i18;
};

struct FoxParam2 {
    int i0;
    float f4, f8, fC, f10, f14, f18, f1C;
    int i20;
    float f24, f28;
    int i2C;
};

struct FoxParam3 {
    int i0;
    float f4, f8, fC, f10, f14;
    int i18, i1C, i20;
    float f24, f28, f2C, f30, f34, f38;
    int i3C;
};

struct FoxParam4 {
    int i0, i4;
    float f8, fC;
};

struct FoxParam5 {
    float f0;
    int i4;
};

struct FoxAccesser {
    char pad[0x10];
    float* floats[2][30];
    int* ints[2][13];
};

extern "C" void fn_97_ABDC(FoxAccesser* a, const unsigned char* data)
{
    for (int i = 0; i < 2; ++i) {
        a->floats[i][0] = &(*(FoxParam1**)(data + 0x7C))->f0;
        a->floats[i][1] = &(*(FoxParam1* const*)(data + 0x7C))->f4;
        a->floats[i][2] = &(*(FoxParam1* const*)(data + 0x7C))->f8;
        a->floats[i][3] = &(*(FoxParam1* const*)(data + 0x7C))->fC;
        a->floats[i][4] = &(*(FoxParam1* const*)(data + 0x7C))->f10;
        a->floats[i][5] = &(*(FoxParam1* const*)(data + 0x7C))->f14;

        a->floats[i][6] = &(*(FoxParam2* const*)(data + 0x80))->f4;
        a->floats[i][7] = &(*(FoxParam2* const*)(data + 0x80))->f8;
        a->floats[i][8] = &(*(FoxParam2* const*)(data + 0x80))->fC;
        a->floats[i][9] = &(*(FoxParam2* const*)(data + 0x80))->f10;
        a->floats[i][10] = &(*(FoxParam2* const*)(data + 0x80))->f14;
        a->floats[i][11] = &(*(FoxParam2* const*)(data + 0x80))->f18;
        a->floats[i][12] = &(*(FoxParam2* const*)(data + 0x80))->f1C;
        a->floats[i][13] = &(*(FoxParam2* const*)(data + 0x80))->f24;
        a->floats[i][14] = &(*(FoxParam2* const*)(data + 0x80))->f28;

        a->floats[i][15] = &(*(FoxParam3* const*)(data + 0x84))->f4;
        a->floats[i][16] = &(*(FoxParam3* const*)(data + 0x84))->f8;
        a->floats[i][17] = &(*(FoxParam3* const*)(data + 0x84))->fC;
        a->floats[i][18] = &(*(FoxParam3* const*)(data + 0x84))->f10;
        a->floats[i][19] = &(*(FoxParam3* const*)(data + 0x84))->f14;
        a->floats[i][20] = &(*(FoxParam3* const*)(data + 0x84))->f24;
        a->floats[i][21] = &(*(FoxParam3* const*)(data + 0x84))->f28;
        a->floats[i][22] = &(*(FoxParam3* const*)(data + 0x84))->f2C;
        a->floats[i][23] = &(*(FoxParam3* const*)(data + 0x84))->f30;
        a->floats[i][24] = &(*(FoxParam3* const*)(data + 0x84))->f34;
        a->floats[i][25] = &(*(FoxParam3* const*)(data + 0x84))->f38;

        a->floats[i][26] = &(*(FoxParam4* const*)(data + 0x88))->f8;
        a->floats[i][27] = &(*(FoxParam4* const*)(data + 0x88))->fC;
        a->floats[i][28] = &(*(FoxParam5**)(data + 0x8C))->f0;

        a->ints[i][0] = &(*(FoxParam1* const*)(data + 0x7C))->i18;
        a->ints[i][1] = &(*(FoxParam2**)(data + 0x80))->i0;
        a->ints[i][2] = &(*(FoxParam2* const*)(data + 0x80))->i20;
        a->ints[i][3] = &(*(FoxParam2* const*)(data + 0x80))->i2C;
        a->ints[i][4] = &(*(FoxParam3**)(data + 0x84))->i0;
        a->ints[i][5] = &(*(FoxParam3* const*)(data + 0x84))->i18;
        a->ints[i][6] = &(*(FoxParam3* const*)(data + 0x84))->i1C;
        a->ints[i][7] = &(*(FoxParam3* const*)(data + 0x84))->i20;
        a->ints[i][8] = &(*(FoxParam3* const*)(data + 0x84))->i3C;
        a->ints[i][9] = &(*(FoxParam4**)(data + 0x88))->i0;
        a->ints[i][10] = &(*(FoxParam4* const*)(data + 0x88))->i4;
        a->ints[i][11] = &(*(FoxParam5* const*)(data + 0x8C))->i4;
    }
}

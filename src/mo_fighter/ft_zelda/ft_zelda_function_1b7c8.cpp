#pragma force_active on
typedef unsigned char u8;

struct ZeldaParam1 {
    float f0, f4, f8, fC, f10;
};

struct ZeldaParam2 {
    int i0, i4, i8, iC, i10, i14;
    float f18;
};

struct ZeldaParam3 {
    float f0, f4, f8;
    int iC, i10;
    float f14, f18, f1C, f20;
    int i24;
    float f28, f2C, f30, f34, f38;
};

struct ZeldaParam4 {
    float f0, f4, f8, fC, f10;
};

struct ZeldaParam5 {
    float f0, f4, f8, fC, f10, f14, f18;
};

struct ZeldaAccesser {
    u8 pad[0x10];
    float* floats[2][31];
    int* ints[2][10];
};

extern "C" void fn_104_1B7C8(ZeldaAccesser* self, const u8* data)
{
    for (int i = 0; i < 2; ++i) {
        self->floats[i][0] = &(*(ZeldaParam1**)(data + 0x7C))->f0;
        self->floats[i][1] = &(*(ZeldaParam1* const*)(data + 0x7C))->f4;
        self->floats[i][2] = &(*(ZeldaParam1* const*)(data + 0x7C))->f8;
        self->floats[i][3] = &(*(ZeldaParam1* const*)(data + 0x7C))->fC;
        self->floats[i][4] = &(*(ZeldaParam1* const*)(data + 0x7C))->f10;
        self->floats[i][5] = &(*(ZeldaParam2* const*)(data + 0x80))->f18;
        self->floats[i][6] = &(*(ZeldaParam3**)(data + 0x84))->f0;
        self->floats[i][7] = &(*(ZeldaParam3* const*)(data + 0x84))->f4;
        self->floats[i][8] = &(*(ZeldaParam3* const*)(data + 0x84))->f8;
        self->floats[i][9] = &(*(ZeldaParam3* const*)(data + 0x84))->f14;
        self->floats[i][10] = &(*(ZeldaParam3* const*)(data + 0x84))->f18;
        self->floats[i][11] = &(*(ZeldaParam3* const*)(data + 0x84))->f1C;
        self->floats[i][12] = &(*(ZeldaParam3* const*)(data + 0x84))->f20;
        self->floats[i][13] = &(*(ZeldaParam3* const*)(data + 0x84))->f28;
        self->floats[i][14] = &(*(ZeldaParam3* const*)(data + 0x84))->f2C;
        self->floats[i][15] = &(*(ZeldaParam3* const*)(data + 0x84))->f30;
        self->floats[i][16] = &(*(ZeldaParam3* const*)(data + 0x84))->f34;
        self->floats[i][17] = &(*(ZeldaParam3* const*)(data + 0x84))->f38;
        self->floats[i][18] = &(*(ZeldaParam4**)(data + 0x88))->f0;
        self->floats[i][19] = &(*(ZeldaParam4* const*)(data + 0x88))->f4;
        self->floats[i][20] = &(*(ZeldaParam4* const*)(data + 0x88))->f8;
        self->floats[i][21] = &(*(ZeldaParam4* const*)(data + 0x88))->fC;
        self->floats[i][22] = &(*(ZeldaParam4* const*)(data + 0x88))->f10;
        self->floats[i][23] = &(*(ZeldaParam5**)(data + 0x8C))->f0;
        self->floats[i][24] = &(*(ZeldaParam5* const*)(data + 0x8C))->f4;
        self->floats[i][25] = &(*(ZeldaParam5* const*)(data + 0x8C))->f8;
        self->floats[i][26] = &(*(ZeldaParam5* const*)(data + 0x8C))->fC;
        self->floats[i][27] = &(*(ZeldaParam5* const*)(data + 0x8C))->f10;
        self->floats[i][28] = &(*(ZeldaParam5* const*)(data + 0x8C))->f14;
        self->floats[i][29] = &(*(ZeldaParam5* const*)(data + 0x8C))->f18;

        self->ints[i][0] = &(*(ZeldaParam2**)(data + 0x80))->i0;
        self->ints[i][1] = &(*(ZeldaParam2* const*)(data + 0x80))->i4;
        self->ints[i][2] = &(*(ZeldaParam2* const*)(data + 0x80))->i8;
        self->ints[i][3] = &(*(ZeldaParam2* const*)(data + 0x80))->iC;
        self->ints[i][4] = &(*(ZeldaParam2* const*)(data + 0x80))->i10;
        self->ints[i][5] = &(*(ZeldaParam2* const*)(data + 0x80))->i14;
        self->ints[i][6] = &(*(ZeldaParam3* const*)(data + 0x84))->iC;
        self->ints[i][7] = &(*(ZeldaParam3* const*)(data + 0x84))->i10;
        self->ints[i][8] = &(*(ZeldaParam3* const*)(data + 0x84))->i24;
    }
}

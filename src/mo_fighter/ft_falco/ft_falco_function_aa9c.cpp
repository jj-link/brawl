#pragma force_active on
struct FalcoParam1 {
    float f0, f4, f8, fC, f10, f14;
    int i18;
};

struct FalcoParam2 {
    int i0;
    float f4, f8, fC, f10, f14, f18, f1C;
    int i20;
    float f24, f28;
    int i2C;
};

struct FalcoParam3 {
    int i0;
    float f4, f8, fC, f10, f14;
    int i18, i1C, i20;
    float f24, f28, f2C, f30, f34, f38;
    int i3C;
};

struct FalcoParam4 {
    int i0;
    int i4;
    float f8, fC;
};

struct FalcoParam5 {
    float f0;
    int i4;
};

struct FalcoAccesser {
    unsigned char pad[0x10];
    float* m_floats[2][28];
    int* m_ints[2][12];
};

extern "C" void fn_108_AA9C(FalcoAccesser* accesser, const unsigned char* data)
{
    for (int i = 0; i < 2; ++i) {
        accesser->m_floats[i][0] = &(*(FalcoParam1**)(data + 0x7C))->f0;
        accesser->m_floats[i][1] = &(*(FalcoParam1* const*)(data + 0x7C))->f4;
        accesser->m_floats[i][2] = &(*(FalcoParam1* const*)(data + 0x7C))->f8;
        accesser->m_floats[i][3] = &(*(FalcoParam1* const*)(data + 0x7C))->fC;
        accesser->m_floats[i][4] = &(*(FalcoParam1* const*)(data + 0x7C))->f10;
        accesser->m_floats[i][5] = &(*(FalcoParam1* const*)(data + 0x7C))->f14;
        accesser->m_floats[i][6] = &(*(FalcoParam2* const*)(data + 0x80))->f4;
        accesser->m_floats[i][7] = &(*(FalcoParam2* const*)(data + 0x80))->f8;
        accesser->m_floats[i][8] = &(*(FalcoParam2* const*)(data + 0x80))->fC;
        accesser->m_floats[i][9] = &(*(FalcoParam2* const*)(data + 0x80))->f10;
        accesser->m_floats[i][10] = &(*(FalcoParam2* const*)(data + 0x80))->f14;
        accesser->m_floats[i][11] = &(*(FalcoParam2* const*)(data + 0x80))->f18;
        accesser->m_floats[i][12] = &(*(FalcoParam2* const*)(data + 0x80))->f1C;
        accesser->m_floats[i][13] = &(*(FalcoParam2* const*)(data + 0x80))->f24;
        accesser->m_floats[i][14] = &(*(FalcoParam2* const*)(data + 0x80))->f28;
        accesser->m_floats[i][15] = &(*(FalcoParam3* const*)(data + 0x84))->f4;
        accesser->m_floats[i][16] = &(*(FalcoParam3* const*)(data + 0x84))->f8;
        accesser->m_floats[i][17] = &(*(FalcoParam3* const*)(data + 0x84))->fC;
        accesser->m_floats[i][18] = &(*(FalcoParam3* const*)(data + 0x84))->f10;
        accesser->m_floats[i][19] = &(*(FalcoParam3* const*)(data + 0x84))->f14;
        accesser->m_floats[i][20] = &(*(FalcoParam3* const*)(data + 0x84))->f24;
        accesser->m_floats[i][21] = &(*(FalcoParam3* const*)(data + 0x84))->f28;
        accesser->m_floats[i][22] = &(*(FalcoParam3* const*)(data + 0x84))->f2C;
        accesser->m_floats[i][23] = &(*(FalcoParam3* const*)(data + 0x84))->f30;
        accesser->m_floats[i][24] = &(*(FalcoParam3* const*)(data + 0x84))->f34;
        accesser->m_floats[i][25] = &(*(FalcoParam3* const*)(data + 0x84))->f38;
        accesser->m_floats[i][26] = &(*(FalcoParam5**)(data + 0x8C))->f0;

        accesser->m_ints[i][0] = &(*(FalcoParam1* const*)(data + 0x7C))->i18;
        accesser->m_ints[i][1] = &(*(FalcoParam2**)(data + 0x80))->i0;
        accesser->m_ints[i][2] = &(*(FalcoParam2* const*)(data + 0x80))->i20;
        accesser->m_ints[i][3] = &(*(FalcoParam2* const*)(data + 0x80))->i2C;
        accesser->m_ints[i][4] = &(*(FalcoParam3**)(data + 0x84))->i0;
        accesser->m_ints[i][5] = &(*(FalcoParam3* const*)(data + 0x84))->i18;
        accesser->m_ints[i][6] = &(*(FalcoParam3* const*)(data + 0x84))->i1C;
        accesser->m_ints[i][7] = &(*(FalcoParam3* const*)(data + 0x84))->i20;
        accesser->m_ints[i][8] = &(*(FalcoParam3* const*)(data + 0x84))->i3C;
        accesser->m_ints[i][9] = &(*(FalcoParam4**)(data + 0x88))->i0;
        accesser->m_ints[i][10] = &(*(FalcoParam5* const*)(data + 0x8C))->i4;
    }
}
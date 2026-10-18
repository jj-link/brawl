#pragma force_active on
struct WolfParam1 {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
    float unk10;
    float unk14;
    int unk18;
};

struct WolfParam2 {
    int unk0;
    float unk4;
    float unk8;
    float unkC;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    int unk20;
    float unk24;
    float unk28;
    int unk2C;
};

struct WolfParam3 {
    int unk0;
    float unk4;
    float unk8;
    float unkC;
    float unk10;
    float unk14;
    int unk18;
    int unk1C;
    int unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
    float unk38;
    int unk3C;
};

struct WolfParam4 {
    int unk0;
    int unk4;
    float unk8;
    float unkC;
};

struct WolfParam5 {
    float unk0;
    int unk4;
};

struct WolfAccesser {
    unsigned char pad[0x10];
    float* m_floats[2][30];
    int* m_ints[2][13];
};

extern "C" void fn_125_AAF4(WolfAccesser* accesser, const unsigned char* data)
{
    for (int i = 0; i < 2; ++i) {
        accesser->m_floats[i][0] = &(*(WolfParam1**)(data + 0x7C))->unk0;
        accesser->m_floats[i][1] = &(*(WolfParam1* const*)(data + 0x7C))->unk4;
        accesser->m_floats[i][2] = &(*(WolfParam1* const*)(data + 0x7C))->unk8;
        accesser->m_floats[i][3] = &(*(WolfParam1* const*)(data + 0x7C))->unkC;
        accesser->m_floats[i][4] = &(*(WolfParam1* const*)(data + 0x7C))->unk10;
        accesser->m_floats[i][5] = &(*(WolfParam1* const*)(data + 0x7C))->unk14;
        accesser->m_floats[i][6] = &(*(WolfParam2* const*)(data + 0x80))->unk4;
        accesser->m_floats[i][7] = &(*(WolfParam2* const*)(data + 0x80))->unk8;
        accesser->m_floats[i][8] = &(*(WolfParam2* const*)(data + 0x80))->unkC;
        accesser->m_floats[i][9] = &(*(WolfParam2* const*)(data + 0x80))->unk10;
        accesser->m_floats[i][10] = &(*(WolfParam2* const*)(data + 0x80))->unk14;
        accesser->m_floats[i][11] = &(*(WolfParam2* const*)(data + 0x80))->unk18;
        accesser->m_floats[i][12] = &(*(WolfParam2* const*)(data + 0x80))->unk1C;
        accesser->m_floats[i][13] = &(*(WolfParam2* const*)(data + 0x80))->unk24;
        accesser->m_floats[i][14] = &(*(WolfParam2* const*)(data + 0x80))->unk28;
        accesser->m_floats[i][15] = &(*(WolfParam3* const*)(data + 0x84))->unk4;
        accesser->m_floats[i][16] = &(*(WolfParam3* const*)(data + 0x84))->unk8;
        accesser->m_floats[i][17] = &(*(WolfParam3* const*)(data + 0x84))->unkC;
        accesser->m_floats[i][18] = &(*(WolfParam3* const*)(data + 0x84))->unk10;
        accesser->m_floats[i][19] = &(*(WolfParam3* const*)(data + 0x84))->unk14;
        accesser->m_floats[i][20] = &(*(WolfParam3* const*)(data + 0x84))->unk24;
        accesser->m_floats[i][21] = &(*(WolfParam3* const*)(data + 0x84))->unk28;
        accesser->m_floats[i][22] = &(*(WolfParam3* const*)(data + 0x84))->unk2C;
        accesser->m_floats[i][23] = &(*(WolfParam3* const*)(data + 0x84))->unk30;
        accesser->m_floats[i][24] = &(*(WolfParam3* const*)(data + 0x84))->unk34;
        accesser->m_floats[i][25] = &(*(WolfParam3* const*)(data + 0x84))->unk38;
        accesser->m_floats[i][26] = &(*(WolfParam4* const*)(data + 0x88))->unk8;
        accesser->m_floats[i][27] = &(*(WolfParam4* const*)(data + 0x88))->unkC;
        accesser->m_floats[i][28] = &(*(WolfParam5**)(data + 0x8C))->unk0;

        accesser->m_ints[i][0] = &(*(WolfParam1* const*)(data + 0x7C))->unk18;
        accesser->m_ints[i][1] = &(*(WolfParam2**)(data + 0x80))->unk0;
        accesser->m_ints[i][2] = &(*(WolfParam2* const*)(data + 0x80))->unk20;
        accesser->m_ints[i][3] = &(*(WolfParam2* const*)(data + 0x80))->unk2C;
        accesser->m_ints[i][4] = &(*(WolfParam3**)(data + 0x84))->unk0;
        accesser->m_ints[i][5] = &(*(WolfParam3* const*)(data + 0x84))->unk18;
        accesser->m_ints[i][6] = &(*(WolfParam3* const*)(data + 0x84))->unk1C;
        accesser->m_ints[i][7] = &(*(WolfParam3* const*)(data + 0x84))->unk20;
        accesser->m_ints[i][8] = &(*(WolfParam3* const*)(data + 0x84))->unk3C;
        accesser->m_ints[i][9] = &(*(WolfParam4**)(data + 0x88))->unk0;
        accesser->m_ints[i][10] = &(*(WolfParam4* const*)(data + 0x88))->unk4;
        accesser->m_ints[i][11] = &(*(WolfParam5* const*)(data + 0x8C))->unk4;
    }
}

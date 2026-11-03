#pragma force_active on
struct Accesser {
    unsigned char pad[0x10];
    unsigned char* floats[2][54];
    unsigned char* ints[2][14];
};

extern "C" void fn_120_923C(Accesser* accesser, const unsigned char* data)
{
    for (int i = 0; i < 2; ++i) {
        accesser->floats[i][0] = *(unsigned char**)(data + 0x7C);
        accesser->floats[i][1] = *(unsigned char* const*)(data + 0x7C) + 0x4;
        accesser->floats[i][2] = *(unsigned char* const*)(data + 0x7C) + 0x8;
        accesser->floats[i][3] = *(unsigned char* const*)(data + 0x7C) + 0xC;
        accesser->floats[i][4] = *(unsigned char* const*)(data + 0x7C) + 0x10;
        accesser->floats[i][5] = *(unsigned char* const*)(data + 0x7C) + 0x14;
        accesser->floats[i][6] = *(unsigned char* const*)(data + 0x7C) + 0x18;
        accesser->floats[i][7] = *(unsigned char* const*)(data + 0x7C) + 0x1C;
        accesser->floats[i][8] = *(unsigned char* const*)(data + 0x7C) + 0x20;
        accesser->floats[i][9] = *(unsigned char* const*)(data + 0x7C) + 0x24;
        accesser->floats[i][10] = *(unsigned char* const*)(data + 0x7C) + 0x28;
        accesser->floats[i][11] = *(unsigned char* const*)(data + 0x7C) + 0x34;
        accesser->floats[i][12] = *(unsigned char* const*)(data + 0x7C) + 0x38;
        accesser->floats[i][13] = *(unsigned char* const*)(data + 0x7C) + 0x3C;

        accesser->floats[i][14] = *(unsigned char**)(data + 0x80);
        accesser->floats[i][15] = *(unsigned char* const*)(data + 0x80) + 0x4;
        accesser->floats[i][16] = *(unsigned char* const*)(data + 0x80) + 0x8;
        accesser->floats[i][17] = *(unsigned char* const*)(data + 0x80) + 0xC;
        accesser->floats[i][18] = *(unsigned char* const*)(data + 0x80) + 0x10;
        accesser->floats[i][19] = *(unsigned char* const*)(data + 0x80) + 0x14;
        accesser->floats[i][20] = *(unsigned char* const*)(data + 0x80) + 0x18;
        accesser->floats[i][21] = *(unsigned char* const*)(data + 0x80) + 0x1C;
        accesser->floats[i][22] = *(unsigned char* const*)(data + 0x80) + 0x24;
        accesser->floats[i][23] = *(unsigned char* const*)(data + 0x80) + 0x28;
        accesser->floats[i][24] = *(unsigned char* const*)(data + 0x80) + 0x2C;
        accesser->floats[i][25] = *(unsigned char* const*)(data + 0x80) + 0x34;
        accesser->floats[i][26] = *(unsigned char* const*)(data + 0x80) + 0x38;
        accesser->floats[i][27] = *(unsigned char* const*)(data + 0x80) + 0x3C;
        accesser->floats[i][28] = *(unsigned char* const*)(data + 0x80) + 0x40;
        accesser->floats[i][29] = *(unsigned char* const*)(data + 0x80) + 0x4C;
        accesser->floats[i][30] = *(unsigned char* const*)(data + 0x80) + 0x50;

        accesser->floats[i][31] = *(unsigned char**)(data + 0x84);
        accesser->floats[i][32] = *(unsigned char* const*)(data + 0x84) + 0x4;
        accesser->floats[i][33] = *(unsigned char* const*)(data + 0x84) + 0x8;
        accesser->floats[i][34] = *(unsigned char* const*)(data + 0x84) + 0xC;
        accesser->floats[i][35] = *(unsigned char* const*)(data + 0x84) + 0x10;
        accesser->floats[i][36] = *(unsigned char* const*)(data + 0x84) + 0x14;
        accesser->floats[i][37] = *(unsigned char* const*)(data + 0x84) + 0x1C;
        accesser->floats[i][38] = *(unsigned char* const*)(data + 0x84) + 0x20;
        accesser->floats[i][39] = *(unsigned char* const*)(data + 0x84) + 0x24;
        accesser->floats[i][40] = *(unsigned char* const*)(data + 0x84) + 0x28;
        accesser->floats[i][41] = *(unsigned char* const*)(data + 0x84) + 0x2C;
        accesser->floats[i][42] = *(unsigned char* const*)(data + 0x84) + 0x30;
        accesser->floats[i][43] = *(unsigned char* const*)(data + 0x84) + 0x34;
        accesser->floats[i][44] = *(unsigned char* const*)(data + 0x84) + 0x38;
        accesser->floats[i][45] = *(unsigned char* const*)(data + 0x84) + 0x3C;
        accesser->floats[i][46] = *(unsigned char* const*)(data + 0x84) + 0x40;

        accesser->floats[i][47] = *(unsigned char**)(data + 0x88);
        accesser->floats[i][48] = *(unsigned char* const*)(data + 0x88) + 0x4;
        accesser->floats[i][49] = *(unsigned char* const*)(data + 0x88) + 0x8;
        accesser->floats[i][50] = *(unsigned char* const*)(data + 0x88) + 0xC;
        accesser->floats[i][51] = *(unsigned char* const*)(data + 0x88) + 0x10;

        accesser->floats[i][52] = *(unsigned char* const*)(data + 0x8C) + 0x4;

        accesser->ints[i][0] = *(unsigned char* const*)(data + 0x7C) + 0x2C;
        accesser->ints[i][1] = *(unsigned char* const*)(data + 0x7C) + 0x30;
        accesser->ints[i][2] = *(unsigned char* const*)(data + 0x80) + 0x20;
        accesser->ints[i][3] = *(unsigned char* const*)(data + 0x80) + 0x30;
        accesser->ints[i][4] = *(unsigned char* const*)(data + 0x80) + 0x44;
        accesser->ints[i][5] = *(unsigned char* const*)(data + 0x80) + 0x48;
        accesser->ints[i][6] = *(unsigned char* const*)(data + 0x84) + 0x18;
        accesser->ints[i][7] = *(unsigned char* const*)(data + 0x88) + 0x14;
        accesser->ints[i][8] = *(unsigned char**)(data + 0x8C);
        accesser->ints[i][9] = *(unsigned char* const*)(data + 0x8C) + 0x8;
        accesser->ints[i][10] = *(unsigned char* const*)(data + 0x8C) + 0xC;
        accesser->ints[i][11] = *(unsigned char* const*)(data + 0x8C) + 0x10;
        accesser->ints[i][12] = *(unsigned char* const*)(data + 0x8C) + 0x14;
    }
}

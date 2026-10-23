#pragma force_active on
typedef unsigned char u8;

struct FtAccesser {
    u8 pad[0x10];
    float* floats[2][53];
    int* ints[2][7];
};

extern "C" void fn_118_9C58(FtAccesser* self, const u8* data)
{
    for (int i = 0; i < 2; ++i) {
        self->floats[i][0] = (float*)(*(u8* const*)(data + 0x7C) + 0x4);
        self->floats[i][1] = (float*)(*(u8* const*)(data + 0x7C) + 0x8);
        self->floats[i][2] = (float*)(*(u8* const*)(data + 0x7C) + 0xC);
        self->floats[i][3] = (float*)(*(u8* const*)(data + 0x7C) + 0x14);
        self->floats[i][4] = (float*)(*(u8* const*)(data + 0x7C) + 0x18);
        self->floats[i][5] = (float*)(*(u8* const*)(data + 0x7C) + 0x1C);
        self->floats[i][6] = (float*)(*(u8**)(data + 0x80));
        self->floats[i][7] = (float*)(*(u8* const*)(data + 0x80) + 0x4);
        self->floats[i][8] = (float*)(*(u8* const*)(data + 0x80) + 0x8);
        self->floats[i][9] = (float*)(*(u8* const*)(data + 0x80) + 0xC);
        self->floats[i][10] = (float*)(*(u8**)(data + 0x84));
        self->floats[i][11] = (float*)(*(u8* const*)(data + 0x84) + 0x4);
        self->floats[i][12] = (float*)(*(u8* const*)(data + 0x84) + 0x8);
        self->floats[i][13] = (float*)(*(u8* const*)(data + 0x84) + 0xC);
        self->floats[i][14] = (float*)(*(u8* const*)(data + 0x84) + 0x10);
        self->floats[i][15] = (float*)(*(u8* const*)(data + 0x84) + 0x14);
        self->floats[i][16] = (float*)(*(u8* const*)(data + 0x84) + 0x18);
        self->floats[i][17] = (float*)(*(u8* const*)(data + 0x84) + 0x1C);
        self->floats[i][18] = (float*)(*(u8**)(data + 0x88));
        self->floats[i][19] = (float*)(*(u8* const*)(data + 0x88) + 0x4);
        self->floats[i][20] = (float*)(*(u8* const*)(data + 0x88) + 0x8);
        self->floats[i][21] = (float*)(*(u8* const*)(data + 0x88) + 0xC);
        self->floats[i][22] = (float*)(*(u8* const*)(data + 0x88) + 0x10);
        self->floats[i][23] = (float*)(*(u8* const*)(data + 0x88) + 0x14);
        self->floats[i][24] = (float*)(*(u8**)(data + 0x8C));
        self->floats[i][25] = (float*)(*(u8* const*)(data + 0x8C) + 0x4);
        self->floats[i][26] = (float*)(*(u8* const*)(data + 0x8C) + 0x8);
        self->floats[i][27] = (float*)(*(u8* const*)(data + 0x8C) + 0xC);
        self->floats[i][28] = (float*)(*(u8* const*)(data + 0x8C) + 0x10);
        self->floats[i][29] = (float*)(*(u8* const*)(data + 0x8C) + 0x14);
        self->floats[i][30] = (float*)(*(u8* const*)(data + 0x8C) + 0x18);
        self->floats[i][31] = (float*)(*(u8* const*)(data + 0x8C) + 0x1C);
        self->floats[i][32] = (float*)(*(u8* const*)(data + 0x8C) + 0x24);
        self->floats[i][33] = (float*)(*(u8* const*)(data + 0x8C) + 0x28);
        self->floats[i][34] = (float*)(*(u8* const*)(data + 0x8C) + 0x2C);
        self->floats[i][35] = (float*)(*(u8* const*)(data + 0x8C) + 0x30);
        self->floats[i][36] = (float*)(*(u8* const*)(data + 0x8C) + 0x38);
        self->floats[i][37] = (float*)(*(u8**)(data + 0x90));
        self->floats[i][38] = (float*)(*(u8* const*)(data + 0x90) + 0x4);
        self->floats[i][39] = (float*)(*(u8* const*)(data + 0x90) + 0x8);
        self->floats[i][40] = (float*)(*(u8* const*)(data + 0x90) + 0x10);
        self->floats[i][41] = (float*)(*(u8* const*)(data + 0x90) + 0x14);
        self->floats[i][42] = (float*)(*(u8**)(data + 0x94));
        self->floats[i][43] = (float*)(*(u8* const*)(data + 0x94) + 0x4);
        self->floats[i][44] = (float*)(*(u8* const*)(data + 0x94) + 0x8);
        self->floats[i][45] = (float*)(*(u8**)(data + 0x98));
        self->floats[i][46] = (float*)(*(u8* const*)(data + 0x98) + 0x4);
        self->floats[i][47] = (float*)(*(u8* const*)(data + 0x98) + 0x8);
        self->floats[i][48] = (float*)(*(u8* const*)(data + 0x98) + 0xC);
        self->floats[i][49] = (float*)(*(u8* const*)(data + 0x98) + 0x10);
        self->floats[i][50] = (float*)(*(u8* const*)(data + 0x98) + 0x14);
        self->floats[i][51] = (float*)(*(u8* const*)(data + 0x98) + 0x18);

        self->ints[i][0] = (int*)(*(u8**)(data + 0x7C));
        self->ints[i][1] = (int*)(*(u8* const*)(data + 0x7C) + 0x10);
        self->ints[i][2] = (int*)(*(u8* const*)(data + 0x8C) + 0x20);
        self->ints[i][3] = (int*)(*(u8* const*)(data + 0x8C) + 0x34);
        self->ints[i][4] = (int*)(*(u8* const*)(data + 0x90) + 0xC);
        self->ints[i][5] = (int*)(*(u8* const*)(data + 0x90) + 0x18);
    }
}

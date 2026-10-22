#pragma force_active on
typedef unsigned char Byte;
struct ParamBlock { int values[30]; };
struct Destination {
    Byte pad[0x10];
    int* first[2][41];
    int* second[2][6];
};
inline int* blk(const Byte* data, int offset) {
    return *(int* const*)(data + offset);
}
inline int* prm(const Byte* data, int offset) {
    return (*(ParamBlock* const*)(data + offset))->values;
}

extern "C" void fn_116_18620(Destination* dst, const Byte* src) {
    for (int i = 0; i < 2; ++i) {
        dst->first[i][0] = prm(src, 0x80) + 1;
        dst->first[i][1] = prm(src, 0x80) + 2;
        dst->first[i][2] = prm(src, 0x80) + 3;
        dst->first[i][3] = prm(src, 0x80) + 4;
        dst->first[i][4] = prm(src, 0x80) + 5;
        dst->first[i][5] = prm(src, 0x80) + 6;
        dst->first[i][6] = prm(src, 0x80) + 8;
        dst->first[i][7] = blk(src, 0x84);
        dst->first[i][8] = prm(src, 0x84) + 1;
        dst->first[i][9] = prm(src, 0x84) + 2;
        dst->first[i][10] = prm(src, 0x84) + 3;
        dst->first[i][11] = prm(src, 0x84) + 4;
        dst->first[i][12] = prm(src, 0x84) + 5;
        dst->first[i][13] = prm(src, 0x84) + 6;
        dst->first[i][14] = prm(src, 0x84) + 7;
        dst->first[i][15] = prm(src, 0x84) + 8;
        dst->first[i][16] = prm(src, 0x84) + 9;
        dst->first[i][17] = prm(src, 0x84) + 10;
        dst->first[i][18] = prm(src, 0x84) + 11;
        dst->first[i][19] = prm(src, 0x84) + 12;
        dst->first[i][20] = prm(src, 0x84) + 13;
        dst->first[i][21] = prm(src, 0x84) + 14;
        dst->first[i][22] = prm(src, 0x84) + 15;
        dst->first[i][23] = prm(src, 0x84) + 16;
        dst->first[i][24] = prm(src, 0x84) + 17;
        dst->first[i][25] = prm(src, 0x84) + 18;
        dst->first[i][26] = prm(src, 0x84) + 19;
        dst->first[i][27] = prm(src, 0x84) + 23;
        dst->first[i][28] = prm(src, 0x84) + 24;
        dst->first[i][29] = prm(src, 0x84) + 25;
        dst->first[i][30] = blk(src, 0x88);
        dst->first[i][31] = prm(src, 0x88) + 1;
        dst->first[i][32] = prm(src, 0x88) + 2;
        dst->first[i][33] = prm(src, 0x88) + 3;
        dst->first[i][34] = prm(src, 0x88) + 4;
        dst->first[i][35] = prm(src, 0x88) + 5;
        dst->first[i][36] = prm(src, 0x88) + 6;
        dst->first[i][37] = blk(src, 0x8C);
        dst->first[i][38] = prm(src, 0x8C) + 1;
        dst->first[i][39] = prm(src, 0x8C) + 2;
        dst->second[i][0] = blk(src, 0x80);
        dst->second[i][1] = prm(src, 0x80) + 7;
        dst->second[i][2] = prm(src, 0x84) + 20;
        dst->second[i][3] = prm(src, 0x84) + 21;
        dst->second[i][4] = prm(src, 0x84) + 22;
    }
}

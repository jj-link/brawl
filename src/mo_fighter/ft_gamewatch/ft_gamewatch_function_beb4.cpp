#pragma force_active on

struct Destination {
    unsigned char pad[0x10];
    float* first[2][25];
    float* second[2][2];
};

extern "C" void fn_107_BEB4(Destination* dst, const unsigned char* src) {
    for (int i = 0; i < 2; ++i) {
        dst->first[i][0] = *(float**)(src + 0x7C);
        dst->first[i][1] = *(float**)(src + 0x80);
        dst->first[i][2] = *(float* const*)(src + 0x80) + 1;
        dst->first[i][3] = *(float* const*)(src + 0x80) + 2;
        dst->first[i][4] = *(float* const*)(src + 0x80) + 3;
        dst->first[i][5] = *(float* const*)(src + 0x80) + 4;
        dst->first[i][6] = *(float**)(src + 0x84);
        dst->first[i][7] = *(float* const*)(src + 0x84) + 1;
        dst->first[i][8] = *(float* const*)(src + 0x84) + 2;
        dst->first[i][9] = *(float* const*)(src + 0x84) + 3;
        dst->first[i][10] = *(float**)(src + 0x88);
        dst->first[i][11] = *(float* const*)(src + 0x88) + 1;
        dst->first[i][12] = *(float* const*)(src + 0x88) + 2;
        dst->first[i][13] = *(float* const*)(src + 0x88) + 3;
        dst->first[i][14] = *(float* const*)(src + 0x88) + 4;
        dst->first[i][15] = *(float* const*)(src + 0x88) + 5;
        dst->first[i][16] = *(float* const*)(src + 0x88) + 6;
        dst->first[i][17] = *(float* const*)(src + 0x88) + 7;
        dst->first[i][18] = *(float**)(src + 0x8C);
        dst->first[i][19] = *(float* const*)(src + 0x8C) + 1;
        dst->first[i][20] = *(float* const*)(src + 0x8C) + 2;
        dst->first[i][21] = *(float* const*)(src + 0x8C) + 3;
        dst->first[i][22] = *(float* const*)(src + 0x8C) + 4;
        dst->first[i][23] = *(float**)(src + 0x90);
        dst->second[i][0] = *(float* const*)(src + 0x7C) + 1;
    }
}

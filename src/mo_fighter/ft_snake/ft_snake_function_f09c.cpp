#pragma force_active on
struct Source {
    unsigned char pad[0x7C];
    float* a;
    float* b;
    float* c;
    float* d;
};

struct Destination {
    unsigned char pad[0x10];
    float* first[2][26];
    float* second[2][7];
};

extern "C" void fn_122_F09C(Destination* dst, Source* src) {
    float* a;
    float* b;
    int i;
    for (i = 0; i < 2; ++i) {
        dst->first[i][0] = src->a;
        a = src->a;
        dst->first[i][1] = a + 1;
        dst->first[i][2] = a + 2;
        dst->first[i][3] = a + 3;
        dst->first[i][4] = a + 4;
        dst->first[i][5] = a + 5;
        dst->first[i][6] = a + 6;
        dst->first[i][7] = a + 7;
        dst->first[i][8] = a + 8;
        dst->first[i][9] = src->b;
        b = src->b;
        dst->first[i][10] = b + 1;
        dst->first[i][11] = b + 2;
        dst->first[i][12] = b + 3;
        dst->first[i][13] = b + 4;
        dst->first[i][14] = b + 5;
        dst->first[i][15] = b + 6;
        dst->first[i][16] = b + 7;
        dst->first[i][17] = b + 8;
        dst->first[i][18] = b + 10;
        dst->first[i][19] = b + 11;
        dst->first[i][20] = b + 16;
        dst->first[i][21] = b + 17;
        dst->first[i][22] = b + 18;
        dst->first[i][23] = b + 19;
        dst->first[i][24] = src->d;
        dst->second[i][0] = b + 9;
        dst->second[i][1] = b + 12;
        dst->second[i][2] = b + 13;
        dst->second[i][3] = b + 14;
        dst->second[i][4] = b + 15;
        dst->second[i][5] = src->c;
    }
}

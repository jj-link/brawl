#pragma force_active on

struct Destination {
    unsigned char pad[0x10];
    float* first[2][27];
    float* second[2][2];
};

struct Source {
    unsigned char pad[0x7C];
    float* a;
    float* b;
    float* c;
    float* d;
};

extern "C" void fn_109_8B6C(Destination* dst, Source* src) {
    float* a;
    float* b;
    float* c;
    float* d;
    int i;
    for (i = 0; i < 2; ++i) {
        dst->first[i][0] = src->a;
        a = src->a;
        dst->first[i][1] = a + 1;
        dst->first[i][2] = a + 2;
        dst->first[i][3] = a + 3;
        dst->first[i][4] = a + 4;
        dst->first[i][5] = src->b;
        b = src->b;
        dst->first[i][6] = b + 1;
        dst->first[i][7] = b + 2;
        dst->first[i][8] = b + 3;
        dst->first[i][9] = b + 4;
        dst->first[i][10] = b + 5;
        dst->first[i][11] = b + 6;
        dst->first[i][12] = b + 7;
        dst->first[i][13] = src->c;
        c = src->c;
        dst->first[i][14] = c + 1;
        dst->first[i][15] = c + 2;
        dst->first[i][16] = c + 3;
        dst->first[i][17] = c + 4;
        dst->first[i][18] = c + 5;
        dst->first[i][19] = c + 6;
        dst->first[i][20] = c + 7;
        dst->first[i][21] = src->d;
        d = src->d;
        dst->first[i][22] = d + 2;
        dst->first[i][23] = d + 3;
        dst->first[i][24] = d + 4;
        dst->first[i][25] = d + 5;
        dst->second[i][0] = d + 1;
    }
}
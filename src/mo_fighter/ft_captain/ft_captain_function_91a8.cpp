#pragma force_active on

struct Destination {
    unsigned char pad[0x10];
    float* first[2][37];
    float* second[2][2];
};

struct Source {
    unsigned char pad[0x7C];
    float* a;
    float* b;
    float* c;
    float* d;
    float* e;
    float* f;
};

extern "C" void fn_100_91A8(Destination* dst, Source* src) {
    float* a;
    float* b;
    float* c;
    float* e;
    float* f;
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
        dst->first[i][10] = src->c;
        c = src->c;
        dst->first[i][11] = c + 1;
        dst->first[i][12] = c + 2;
        dst->first[i][13] = c + 3;
        dst->first[i][14] = c + 4;
        dst->first[i][15] = c + 5;
        dst->first[i][16] = c + 6;
        dst->first[i][17] = c + 7;
        dst->first[i][18] = c + 8;
        dst->first[i][19] = src->d;
        d = src->d;
        dst->first[i][20] = d + 1;
        dst->first[i][21] = d + 3;
        dst->first[i][22] = d + 4;
        dst->first[i][23] = d + 5;
        dst->first[i][24] = d + 6;
        dst->first[i][25] = src->e;
        e = src->e;
        dst->first[i][26] = e + 1;
        dst->first[i][27] = e + 2;
        dst->first[i][28] = src->f;
        f = src->f;
        dst->first[i][29] = f + 1;
        dst->first[i][30] = f + 2;
        dst->first[i][31] = f + 3;
        dst->first[i][32] = f + 4;
        dst->first[i][33] = f + 5;
        dst->first[i][34] = f + 6;
        dst->first[i][35] = f + 7;
        dst->second[i][0] = d + 2;
    }
}
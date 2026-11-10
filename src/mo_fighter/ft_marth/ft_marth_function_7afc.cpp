#pragma force_active on

struct Destination {
    unsigned char pad[0x10];
    float* first[2][32];
    float* second[2][9];
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

extern "C" void fn_106_7AFC(Destination* dst, Source* src) {
    float* a;
    float* b;
    float* c;
    float* e;
    float* f;
    float* d;

    for (int i = 0; i < 2; ++i) {
        dst->first[i][0] = (a = src->a) + 3;
        dst->first[i][1] = a + 4;
        dst->first[i][2] = src->b;
        b = src->b;
        dst->first[i][3] = b + 1;
        dst->first[i][4] = b + 2;
        dst->first[i][5] = b + 3;
        dst->first[i][6] = b + 4;
        dst->first[i][7] = src->c;
        c = src->c;
        dst->first[i][8] = c + 1;
        dst->first[i][9] = c + 2;
        dst->first[i][10] = c + 3;
        dst->first[i][11] = c + 4;
        dst->first[i][12] = c + 5;
        dst->first[i][13] = c + 6;
        dst->first[i][14] = c + 7;
        dst->first[i][15] = c + 8;
        dst->first[i][16] = src->d;
        d = src->d;
        dst->first[i][17] = d + 1;
        dst->first[i][18] = d + 2;
        dst->first[i][19] = d + 3;
        dst->first[i][20] = d + 4;
        dst->first[i][21] = d + 5;
        dst->first[i][22] = d + 7;
        dst->first[i][23] = d + 8;
        dst->first[i][24] = d + 9;
        e = src->e;
        dst->first[i][25] = e + 1;
        dst->first[i][26] = e + 2;
        dst->first[i][27] = e + 3;
        dst->first[i][28] = e + 4;
        dst->first[i][29] = src->f;
        f = src->f;
        dst->first[i][30] = f + 2;

        dst->second[i][0] = src->a;
        dst->second[i][1] = a + 1;
        dst->second[i][2] = a + 2;
        dst->second[i][3] = d + 6;
        dst->second[i][4] = src->e;
        dst->second[i][5] = f + 1;
        dst->second[i][6] = f + 3;
        dst->second[i][7] = f + 4;
    }
}

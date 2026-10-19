#pragma force_active on
struct Source {
    unsigned char pad[0x80];
    float* a;
    float* b;
    float* c;
};

struct Destination {
    unsigned char pad[0x10];
    float* first[2][11];
    float* second[2][5];
};

extern "C" void fn_116_202A8(Destination* dst, Source* src) {
    float* b;
    float* a;
    int i;

    for (i = 0; i < 2; ++i) {
        dst->first[i][0] = (a = src->a) + 1;
        dst->first[i][1] = a + 2;
        dst->first[i][2] = src->b;
        b = src->b;
        dst->first[i][3] = b + 2;
        dst->first[i][4] = b + 3;
        dst->first[i][5] = b + 4;
        dst->first[i][6] = b + 5;
        dst->first[i][7] = b + 6;
        dst->first[i][8] = b + 7;
        dst->first[i][9] = src->c;
        dst->second[i][0] = src->a;
        dst->second[i][1] = a + 3;
        dst->second[i][2] = a + 4;
        dst->second[i][3] = b + 1;
    }
}

#pragma force_active on
#pragma fp_contract on

struct Data {
    char pad0[0x5c];
    float scale;
    char pad60[0x30];
    float x;
    float y;
    float z;
    float w;
};

extern "C" void fn_803144D4(const Data* a, const Data* b, float* outA, float* outB, float scale) {
    float sa = a->scale;
    float sb = b->scale;
    float ta = scale * sa;
    float tb = scale * sb;

    outA[0] = ta * a->x;
    outA[1] = ta * a->y;
    outA[2] = ta * a->z;
    outA[3] = ta * a->w;

    outB[0] = tb * b->x;
    outB[1] = tb * b->y;
    outB[2] = tb * b->z;
    outB[3] = tb * b->w;
}
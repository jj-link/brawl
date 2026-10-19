#pragma force_active on
struct SamusParam1 {
    float x0, x4;
};

struct SamusParam2 {
    float x0;
};

struct SamusParam3 {
    float x0;
    int x4;
    float x8, xC, x10, x14, x18, x1C, x20;
};

struct SamusParam4 {
    float x0, x4;
};

struct SamusAccesser {
    unsigned char pad[0x10];
    float* floats[2][14];
    int* ints[2][2];
};

extern "C" void fn_94_1862C(SamusAccesser* a, const unsigned char* data)
{
    for (int i = 0; i < 2; ++i) {
        a->floats[i][0] = &(*(SamusParam1**)(data + 0x7C))->x0;
        a->floats[i][1] = &(*(SamusParam1* const*)(data + 0x7C))->x4;
        a->floats[i][2] = &(*(SamusParam2**)(data + 0x80))->x0;
        a->floats[i][3] = &(*(SamusParam3**)(data + 0x84))->x0;
        a->floats[i][4] = &(*(SamusParam3* const*)(data + 0x84))->x8;
        a->floats[i][5] = &(*(SamusParam3* const*)(data + 0x84))->xC;
        a->floats[i][6] = &(*(SamusParam3* const*)(data + 0x84))->x10;
        a->floats[i][7] = &(*(SamusParam3* const*)(data + 0x84))->x14;
        a->floats[i][8] = &(*(SamusParam3* const*)(data + 0x84))->x18;
        a->floats[i][9] = &(*(SamusParam3* const*)(data + 0x84))->x1C;
        a->floats[i][10] = &(*(SamusParam3* const*)(data + 0x84))->x20;
        a->floats[i][11] = &(*(SamusParam4**)(data + 0x88))->x0;
        a->floats[i][12] = &(*(SamusParam4* const*)(data + 0x88))->x4;
        a->ints[i][0] = &(*(SamusParam3* const*)(data + 0x84))->x4;
    }
}

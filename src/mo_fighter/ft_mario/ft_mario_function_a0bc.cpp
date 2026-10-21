#include <types.h>
#pragma force_active on

struct MarioParam1 {
    float f0, f4, f8, fC, f10;
};

struct MarioParam2 {
    float f0, f4, f8;
};

struct MarioParam3 {
    float f0, f4, f8, fC, f10;
};

struct MarioParam4 {
    int i0;
    float f4;
    int i8;
    float fC;
    int i10;
};

struct MarioAccesser {
    u8 pad[0x10];
    float* floats[2][16];
    int* ints[2][4];
};

struct MarioParameters {
    u8 pad[0x7C];
    MarioParam1* group1;
    MarioParam2* group2;
    MarioParam3* group3;
    MarioParam4* group4;
};

extern "C" void fn_91_A0BC(MarioAccesser* a, const MarioParameters* p) {
    for (s32 i = 0; i < 2; ++i) {
        a->floats[i][0] = &p->group1->f0;
        a->floats[i][1] = &p->group1->f4;
        a->floats[i][2] = &p->group1->f8;
        a->floats[i][3] = &p->group1->fC;
        a->floats[i][4] = &p->group1->f10;
        a->floats[i][5] = &p->group2->f0;
        a->floats[i][6] = &p->group2->f4;
        a->floats[i][7] = &p->group2->f8;
        a->floats[i][8] = &p->group3->f0;
        a->floats[i][9] = &p->group3->f4;
        a->floats[i][10] = &p->group3->f8;
        a->floats[i][11] = &p->group3->fC;
        a->floats[i][12] = &p->group3->f10;
        a->floats[i][13] = &p->group4->f4;
        a->floats[i][14] = &p->group4->fC;
        a->ints[i][0] = &p->group4->i0;
        a->ints[i][1] = &p->group4->i8;
        a->ints[i][2] = &p->group4->i10;
    }
}

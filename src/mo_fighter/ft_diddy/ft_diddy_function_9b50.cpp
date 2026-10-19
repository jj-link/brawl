#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct ParameterGroup1 {
    float f0, f4, f8, fC, f10, f14, f18;
    s32 i1C;
    float f20, f24;
};

struct ParameterGroup2 {
    float f0, f4, f8;
};

struct ParameterGroup3 {
    float f0, f4;
    s32 i8;
    float fC, f10, f14, f18, f1C, f20, f24, f28, f2C, f30, f34;
};

struct ParameterGroup4 {
    float f0, f4, f8;
    s32 iC;
};

struct ParameterGroup5 {
    float f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C, f30, f34, f38, f3C, f40, f44;
    s32 i48, i4C;
    float f50, f54, f58, f5C, f60, f64, f68;
};

struct Parameters {
    u8 prefix[0x7C];
    const ParameterGroup1 *group1;
    const ParameterGroup2 *group2;
    const ParameterGroup3 *group3;
    const ParameterGroup4 *group4;
    const ParameterGroup5 *group5;
};

struct PointerTables {
    u8 prefix[0x10];
    const float *floats[2][54];
    const s32 *ints[2][6];
};

extern "C" void fn_115_9B50(PointerTables *tables, const Parameters *parameters)
{
    for (s32 variation = 0; variation < 2; ++variation) {
        tables->floats[variation][0] = &parameters->group1->f0;
        tables->floats[variation][1] = &parameters->group1->f4;
        tables->floats[variation][2] = &parameters->group1->f8;
        tables->floats[variation][3] = &parameters->group1->fC;
        tables->floats[variation][4] = &parameters->group1->f10;
        tables->floats[variation][5] = &parameters->group1->f14;
        tables->floats[variation][6] = &parameters->group1->f18;
        tables->floats[variation][7] = &parameters->group1->f20;
        tables->floats[variation][8] = &parameters->group1->f24;
        tables->floats[variation][9] = &parameters->group2->f0;
        tables->floats[variation][10] = &parameters->group2->f4;
        tables->floats[variation][11] = &parameters->group2->f8;
        tables->floats[variation][12] = &parameters->group3->f0;
        tables->floats[variation][13] = &parameters->group3->f4;
        tables->floats[variation][14] = &parameters->group3->fC;
        tables->floats[variation][15] = &parameters->group3->f10;
        tables->floats[variation][16] = &parameters->group3->f14;
        tables->floats[variation][17] = &parameters->group3->f18;
        tables->floats[variation][18] = &parameters->group3->f1C;
        tables->floats[variation][19] = &parameters->group3->f20;
        tables->floats[variation][20] = &parameters->group3->f24;
        tables->floats[variation][21] = &parameters->group3->f28;
        tables->floats[variation][22] = &parameters->group3->f2C;
        tables->floats[variation][23] = &parameters->group3->f30;
        tables->floats[variation][24] = &parameters->group3->f34;
        tables->floats[variation][25] = &parameters->group4->f0;
        tables->floats[variation][26] = &parameters->group4->f4;
        tables->floats[variation][27] = &parameters->group4->f8;
        tables->floats[variation][28] = &parameters->group5->f0;
        tables->floats[variation][29] = &parameters->group5->f4;
        tables->floats[variation][30] = &parameters->group5->f8;
        tables->floats[variation][31] = &parameters->group5->fC;
        tables->floats[variation][32] = &parameters->group5->f10;
        tables->floats[variation][33] = &parameters->group5->f14;
        tables->floats[variation][34] = &parameters->group5->f18;
        tables->floats[variation][35] = &parameters->group5->f1C;
        tables->floats[variation][36] = &parameters->group5->f20;
        tables->floats[variation][37] = &parameters->group5->f24;
        tables->floats[variation][38] = &parameters->group5->f28;
        tables->floats[variation][39] = &parameters->group5->f2C;
        tables->floats[variation][40] = &parameters->group5->f30;
        tables->floats[variation][41] = &parameters->group5->f34;
        tables->floats[variation][42] = &parameters->group5->f38;
        tables->floats[variation][43] = &parameters->group5->f3C;
        tables->floats[variation][44] = &parameters->group5->f40;
        tables->floats[variation][45] = &parameters->group5->f44;
        tables->floats[variation][46] = &parameters->group5->f50;
        tables->floats[variation][47] = &parameters->group5->f54;
        tables->floats[variation][48] = &parameters->group5->f58;
        tables->floats[variation][49] = &parameters->group5->f5C;
        tables->floats[variation][50] = &parameters->group5->f60;
        tables->floats[variation][51] = &parameters->group5->f64;
        tables->floats[variation][52] = &parameters->group5->f68;
        tables->ints[variation][0] = &parameters->group1->i1C;
        tables->ints[variation][1] = &parameters->group3->i8;
        tables->ints[variation][2] = &parameters->group4->iC;
        tables->ints[variation][3] = &parameters->group5->i48;
        tables->ints[variation][4] = &parameters->group5->i4C;
    }
}

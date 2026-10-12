#include <types.h>

// ABI view of ftExtendParamAccesserEx<3999, 41, 24999, 14>.
// The last entry in each variation is reserved and is not initialized here.
struct DededeParameterTables {
    u8 prefix[0x10];
    const float* floats[2][42];
    const s32* ints[2][15];
};

struct DededeParameterGroup1 {
    s32 int0;
    float float4, float8, floatC, float10, float14, float18, float1C;
    s32 int20;
    float float24, float28, float2C;
};
struct DededeParameterGroup2 {
    float float0, float4, float8, floatC, float10;
    s32 int14;
    float float18, float1C, float20, float24;
    s32 int28;
    float float2C;
};
struct DededeParameterGroup3 {
    float float0, float4, float8, floatC, float10, float14, float18, float1C;
    s32 int20, int24;
    float float28, float2C, float30, float34;
};
struct DededeParameterGroup4 {
    float float0;
    s32 int4;
    float float8;
    s32 intC, int10;
};
struct DededeParameterGroup5 {
    s32 int0, int4, int8, intC, int10;
    float float14, float18, float1C, float20, float24, float28, float2C;
};
struct DededeExtendedParameters {
    u8 prefix[0x7C];
    const DededeParameterGroup1* group1;
    const DededeParameterGroup2* group2;
    const DededeParameterGroup3* group3;
    const DededeParameterGroup4* group4;
    const DededeParameterGroup5* group5;
};

extern "C" void fn_117_9F48(DededeParameterTables* tables, const DededeExtendedParameters* parameters) {
    for (s32 variation = 0; variation < 2; ++variation) {
        tables->floats[variation][0] = &parameters->group1->float4;
        tables->floats[variation][1] = &parameters->group1->float8;
        tables->floats[variation][2] = &parameters->group1->floatC;
        tables->floats[variation][3] = &parameters->group1->float10;
        tables->floats[variation][4] = &parameters->group1->float14;
        tables->floats[variation][5] = &parameters->group1->float18;
        tables->floats[variation][6] = &parameters->group1->float1C;
        tables->floats[variation][7] = &parameters->group1->float24;
        tables->floats[variation][8] = &parameters->group1->float28;
        tables->floats[variation][9] = &parameters->group1->float2C;
        tables->floats[variation][10] = &parameters->group2->float0;
        tables->floats[variation][11] = &parameters->group2->float4;
        tables->floats[variation][12] = &parameters->group2->float8;
        tables->floats[variation][13] = &parameters->group2->floatC;
        tables->floats[variation][14] = &parameters->group2->float10;
        tables->floats[variation][15] = &parameters->group2->float18;
        tables->floats[variation][16] = &parameters->group2->float1C;
        tables->floats[variation][17] = &parameters->group2->float20;
        tables->floats[variation][18] = &parameters->group2->float24;
        tables->floats[variation][19] = &parameters->group2->float2C;
        tables->floats[variation][20] = &parameters->group3->float0;
        tables->floats[variation][21] = &parameters->group3->float4;
        tables->floats[variation][22] = &parameters->group3->float8;
        tables->floats[variation][23] = &parameters->group3->floatC;
        tables->floats[variation][24] = &parameters->group3->float10;
        tables->floats[variation][25] = &parameters->group3->float14;
        tables->floats[variation][26] = &parameters->group3->float18;
        tables->floats[variation][27] = &parameters->group3->float1C;
        tables->floats[variation][28] = &parameters->group3->float28;
        tables->floats[variation][29] = &parameters->group3->float2C;
        tables->floats[variation][30] = &parameters->group3->float30;
        tables->floats[variation][31] = &parameters->group3->float34;
        tables->floats[variation][32] = &parameters->group4->float0;
        tables->floats[variation][33] = &parameters->group4->float8;
        tables->floats[variation][34] = &parameters->group5->float14;
        tables->floats[variation][35] = &parameters->group5->float18;
        tables->floats[variation][36] = &parameters->group5->float1C;
        tables->floats[variation][37] = &parameters->group5->float20;
        tables->floats[variation][38] = &parameters->group5->float24;
        tables->floats[variation][39] = &parameters->group5->float28;
        tables->floats[variation][40] = &parameters->group5->float2C;
        tables->ints[variation][0] = &parameters->group1->int0;
        tables->ints[variation][1] = &parameters->group1->int20;
        tables->ints[variation][2] = &parameters->group2->int14;
        tables->ints[variation][3] = &parameters->group2->int28;
        tables->ints[variation][4] = &parameters->group3->int20;
        tables->ints[variation][5] = &parameters->group3->int24;
        tables->ints[variation][6] = &parameters->group4->int4;
        tables->ints[variation][7] = &parameters->group4->intC;
        tables->ints[variation][8] = &parameters->group4->int10;
        tables->ints[variation][9] = &parameters->group5->int0;
        tables->ints[variation][10] = &parameters->group5->int4;
        tables->ints[variation][11] = &parameters->group5->int8;
        tables->ints[variation][12] = &parameters->group5->intC;
        tables->ints[variation][13] = &parameters->group5->int10;
    }
}

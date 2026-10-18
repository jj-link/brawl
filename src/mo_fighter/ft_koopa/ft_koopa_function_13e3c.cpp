#include <ft/ft_extend_param_accesser.h>
#pragma force_active on

struct KoopaParam1 {
    int p0;
    int p1;
    int p2;
};

struct KoopaParam2 {
    float p0;
    float p1;
    float p2;
    float p3;
    float p4;
    float p5;
    int p6;
    float p7;
    float p8;
    float p9;
    float p10;
    float p11;
    float p12;
    float p13;
    float p14;
    int p15;
    int p16;
    float p17;
    float p18;
    float p19;
};

struct KoopaParam3 {
    float p0;
    float p1;
    float p2;
    float p3;
    float p4;
    float p5;
    float p6;
    float p7;
    int p8;
    int p9;
    int p10;
    int p11;
};

struct KoopaParam4 {
    float p0;
    float p1;
    float p2;
    float p3;
    float p4;
    float p5;
    float p6;
    float p7;
};

struct KoopaParam5 {
    float p0;
    float p1;
    float p2;
    float p3;
    float p4;
    float p5;
    float p6;
    float p7;
    float p8;
    float p9;
    float p10;
    float p11;
    float p12;
};

class KoopaSetup : public ftExtendParamAccesserEx<3999, 46, 24999, 10> {
public:
    void setupParameters(const u8* data) {
        for (s32 i = 0; i < NumVariations; ++i) {
            m_floats[i][0] = &(*(KoopaParam2**)(data + 0x80))->p0;
            m_floats[i][1] = &(*(KoopaParam2* const*)(data + 0x80))->p1;
            m_floats[i][2] = &(*(KoopaParam2* const*)(data + 0x80))->p2;
            m_floats[i][3] = &(*(KoopaParam2* const*)(data + 0x80))->p3;
            m_floats[i][4] = &(*(KoopaParam2* const*)(data + 0x80))->p4;
            m_floats[i][5] = &(*(KoopaParam2* const*)(data + 0x80))->p5;
            m_floats[i][6] = &(*(KoopaParam2* const*)(data + 0x80))->p7;
            m_floats[i][7] = &(*(KoopaParam2* const*)(data + 0x80))->p8;
            m_floats[i][8] = &(*(KoopaParam2* const*)(data + 0x80))->p9;
            m_floats[i][9] = &(*(KoopaParam2* const*)(data + 0x80))->p10;
            m_floats[i][10] = &(*(KoopaParam2* const*)(data + 0x80))->p11;
            m_floats[i][11] = &(*(KoopaParam2* const*)(data + 0x80))->p12;
            m_floats[i][12] = &(*(KoopaParam2* const*)(data + 0x80))->p13;
            m_floats[i][13] = &(*(KoopaParam2* const*)(data + 0x80))->p14;
            m_floats[i][14] = &(*(KoopaParam2* const*)(data + 0x80))->p17;
            m_floats[i][15] = &(*(KoopaParam2* const*)(data + 0x80))->p18;
            m_floats[i][16] = &(*(KoopaParam2* const*)(data + 0x80))->p19;
            m_floats[i][17] = &(*(KoopaParam3**)(data + 0x84))->p0;
            m_floats[i][18] = &(*(KoopaParam3* const*)(data + 0x84))->p1;
            m_floats[i][19] = &(*(KoopaParam3* const*)(data + 0x84))->p2;
            m_floats[i][20] = &(*(KoopaParam3* const*)(data + 0x84))->p3;
            m_floats[i][21] = &(*(KoopaParam3* const*)(data + 0x84))->p4;
            m_floats[i][22] = &(*(KoopaParam3* const*)(data + 0x84))->p5;
            m_floats[i][23] = &(*(KoopaParam3* const*)(data + 0x84))->p6;
            m_floats[i][24] = &(*(KoopaParam3* const*)(data + 0x84))->p7;
            m_floats[i][25] = &(*(KoopaParam4**)(data + 0x88))->p0;
            m_floats[i][26] = &(*(KoopaParam4* const*)(data + 0x88))->p1;
            m_floats[i][27] = &(*(KoopaParam4* const*)(data + 0x88))->p2;
            m_floats[i][28] = &(*(KoopaParam4* const*)(data + 0x88))->p3;
            m_floats[i][29] = &(*(KoopaParam4* const*)(data + 0x88))->p4;
            m_floats[i][30] = &(*(KoopaParam4* const*)(data + 0x88))->p5;
            m_floats[i][31] = &(*(KoopaParam4* const*)(data + 0x88))->p6;
            m_floats[i][32] = &(*(KoopaParam4* const*)(data + 0x88))->p7;
            m_floats[i][33] = &(*(KoopaParam5**)(data + 0x8c))->p0;
            m_floats[i][34] = &(*(KoopaParam5* const*)(data + 0x8c))->p1;
            m_floats[i][35] = &(*(KoopaParam5* const*)(data + 0x8c))->p2;
            m_floats[i][36] = &(*(KoopaParam5* const*)(data + 0x8c))->p3;
            m_floats[i][37] = &(*(KoopaParam5* const*)(data + 0x8c))->p4;
            m_floats[i][38] = &(*(KoopaParam5* const*)(data + 0x8c))->p5;
            m_floats[i][39] = &(*(KoopaParam5* const*)(data + 0x8c))->p6;
            m_floats[i][40] = &(*(KoopaParam5* const*)(data + 0x8c))->p7;
            m_floats[i][41] = &(*(KoopaParam5* const*)(data + 0x8c))->p8;
            m_floats[i][42] = &(*(KoopaParam5* const*)(data + 0x8c))->p9;
            m_floats[i][43] = &(*(KoopaParam5* const*)(data + 0x8c))->p10;
            m_floats[i][44] = &(*(KoopaParam5* const*)(data + 0x8c))->p11;
            m_floats[i][45] = &(*(KoopaParam5* const*)(data + 0x8c))->p12;

            m_ints[i][0] = &(*(KoopaParam1**)(data + 0x7c))->p0;
            m_ints[i][1] = &(*(KoopaParam1* const*)(data + 0x7c))->p1;
            m_ints[i][2] = &(*(KoopaParam1* const*)(data + 0x7c))->p2;
            m_ints[i][3] = &(*(KoopaParam2* const*)(data + 0x80))->p6;
            m_ints[i][4] = &(*(KoopaParam2* const*)(data + 0x80))->p15;
            m_ints[i][5] = &(*(KoopaParam2* const*)(data + 0x80))->p16;
            m_ints[i][6] = &(*(KoopaParam3* const*)(data + 0x84))->p8;
            m_ints[i][7] = &(*(KoopaParam3* const*)(data + 0x84))->p9;
            m_ints[i][8] = &(*(KoopaParam3* const*)(data + 0x84))->p10;
            m_ints[i][9] = &(*(KoopaParam3* const*)(data + 0x84))->p11;
        }
    }
};

extern "C" void fn_102_13E3C(KoopaSetup* accesser, const u8* data) {
    accesser->setupParameters(data);
}

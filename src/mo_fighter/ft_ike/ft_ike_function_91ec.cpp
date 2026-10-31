#include <ft/ft_extend_param_accesser.h>
#pragma force_active on

struct IkeGroup1 {
    int i0;
    int i4;
    int i8;
    float fC;
    float f10;
    float f14;
};

struct IkeGroup2 {
    int i0;
    int i4;
    float f8;
    float fC;
    float f10;
    float f14;
    float f18;
    float f1C;
    int i20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
    float f38;
    float f3C;
    float f40;
    float f44;
};

struct IkeGroup3 {
    float f0;
    float f4;
    float f8;
    int iC;
};

struct IkeGroup4 {
    float f0;
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    int i18;
    float f1C;
    float f20;
    float f24;
};

struct IkeGroup5 {
    int i0;
    float f4;
    float f8;
    float fC;
    float f10;
};

struct IkeGroup6 {
    float f0;
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    float f18;
    int i1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
};

class IkeSetup : public ftExtendParamAccesserEx<3999, 47, 24999, 10> {
    const IkeGroup1* group1(const u8* base) {
        return *(IkeGroup1* const*)(base + 0x7C);
    }
    const IkeGroup1* group1Cast(const u8* base) {
        return *(IkeGroup1**)(base + 0x7C);
    }
    const IkeGroup2* group2(const u8* base) {
        return *(IkeGroup2* const*)(base + 0x80);
    }
    const IkeGroup2* group2Cast(const u8* base) {
        return *(IkeGroup2**)(base + 0x80);
    }
    const IkeGroup3* group3(const u8* base) {
        return *(IkeGroup3* const*)(base + 0x84);
    }
    const IkeGroup3* group3Cast(const u8* base) {
        return *(IkeGroup3**)(base + 0x84);
    }
    const IkeGroup4* group4(const u8* base) {
        return *(IkeGroup4* const*)(base + 0x88);
    }
    const IkeGroup4* group4Cast(const u8* base) {
        return *(IkeGroup4**)(base + 0x88);
    }
    const IkeGroup5* group5(const u8* base) {
        return *(IkeGroup5* const*)(base + 0x8C);
    }
    const IkeGroup5* group5Cast(const u8* base) {
        return *(IkeGroup5**)(base + 0x8C);
    }
    const IkeGroup6* group6(const u8* base) {
        return *(IkeGroup6* const*)(base + 0x90);
    }
    const IkeGroup6* group6Cast(const u8* base) {
        return *(IkeGroup6**)(base + 0x90);
    }

public:
    void setupParameters(const u8* data) {
        for (s32 i = 0; i < NumVariations; ++i) {
            m_floats[i][0] = &group1(data)->fC;
            m_floats[i][1] = &group1(data)->f10;
            m_floats[i][2] = &group1(data)->f14;
            m_floats[i][3] = &group2(data)->f8;
            m_floats[i][4] = &group2(data)->fC;
            m_floats[i][5] = &group2(data)->f10;
            m_floats[i][6] = &group2(data)->f14;
            m_floats[i][7] = &group2(data)->f18;
            m_floats[i][8] = &group2(data)->f1C;
            m_floats[i][9] = &group2(data)->f24;
            m_floats[i][10] = &group2(data)->f28;
            m_floats[i][11] = &group2(data)->f2C;
            m_floats[i][12] = &group2(data)->f30;
            m_floats[i][13] = &group2(data)->f34;
            m_floats[i][14] = &group2(data)->f38;
            m_floats[i][15] = &group2(data)->f3C;
            m_floats[i][16] = &group2(data)->f40;
            m_floats[i][17] = &group2(data)->f44;
            m_floats[i][18] = &group3Cast(data)->f0;
            m_floats[i][19] = &group3(data)->f4;
            m_floats[i][20] = &group3(data)->f8;
            m_floats[i][21] = &group4Cast(data)->f0;
            m_floats[i][22] = &group4(data)->f4;
            m_floats[i][23] = &group4(data)->f8;
            m_floats[i][24] = &group4(data)->fC;
            m_floats[i][25] = &group4(data)->f10;
            m_floats[i][26] = &group4(data)->f14;
            m_floats[i][27] = &group4(data)->f1C;
            m_floats[i][28] = &group4(data)->f20;
            m_floats[i][29] = &group4(data)->f24;
            m_floats[i][30] = &group5(data)->f4;
            m_floats[i][31] = &group5(data)->f8;
            m_floats[i][32] = &group5(data)->fC;
            m_floats[i][33] = &group5(data)->f10;
            m_floats[i][34] = &group6Cast(data)->f0;
            m_floats[i][35] = &group6(data)->f4;
            m_floats[i][36] = &group6(data)->f8;
            m_floats[i][37] = &group6(data)->fC;
            m_floats[i][38] = &group6(data)->f10;
            m_floats[i][39] = &group6(data)->f14;
            m_floats[i][40] = &group6(data)->f18;
            m_floats[i][41] = &group6(data)->f20;
            m_floats[i][42] = &group6(data)->f24;
            m_floats[i][43] = &group6(data)->f28;
            m_floats[i][44] = &group6(data)->f2C;
            m_floats[i][45] = &group6(data)->f30;
            m_floats[i][46] = &group6(data)->f34;

            m_ints[i][0] = &group1Cast(data)->i0;
            m_ints[i][1] = &group1(data)->i4;
            m_ints[i][2] = &group1(data)->i8;
            m_ints[i][3] = &group2Cast(data)->i0;
            m_ints[i][4] = &group2(data)->i4;
            m_ints[i][5] = &group2(data)->i20;
            m_ints[i][6] = &group3(data)->iC;
            m_ints[i][7] = &group4(data)->i18;
            m_ints[i][8] = &group5Cast(data)->i0;
            m_ints[i][9] = &group6(data)->i1C;
        }
    }
};

extern "C" void fn_119_91EC(IkeSetup* accesser, const u8* data) {
    accesser->setupParameters(data);
}

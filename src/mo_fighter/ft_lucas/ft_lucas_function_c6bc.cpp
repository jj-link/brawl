#include <ft/ft_extend_param_accesser.h>
#pragma force_active on

// Extended parameter blocks contain both integer and floating-point entries.
struct LucasExtendParam1 {
    int unk0, unk4, unk8;
    float unkC, unk10;
};
struct LucasExtendParam2 {
    float unk0, unk4, unk8, unkC, unk10, unk14, unk18;
};
struct LucasExtendParam3 {
    float unk0;
    int unk4, unk8, unkC;
    float unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
};
struct LucasExtendParam4 {
    int unk0, unk4;
    float unk8, unkC, unk10, unk14, unk18;
};
struct LucasExtendParam5 {
    float unk0, unk4, unk8, unkC, unk10;
};
struct LucasExtendParam6 {
    float unk0, unk4, unk8, unkC, unk10, unk14;
    int unk18;
};

class LucasExtendParamSetup : public ftExtendParamAccesserEx<3999, 34, 24999, 9> {
public:
    void setupParameters(const u8* data) {
        for (s32 i = 0; i < NumVariations; ++i) {
            m_floats[i][0] = &(*(LucasExtendParam1* const*)(data + 0x7C))->unkC;
            m_floats[i][1] = &(*(LucasExtendParam1* const*)(data + 0x7C))->unk10;
            m_floats[i][2] = &(*(LucasExtendParam2**)(data + 0x80))->unk0;
            m_floats[i][3] = &(*(LucasExtendParam2* const*)(data + 0x80))->unk4;
            m_floats[i][4] = &(*(LucasExtendParam2* const*)(data + 0x80))->unk8;
            m_floats[i][5] = &(*(LucasExtendParam2* const*)(data + 0x80))->unkC;
            m_floats[i][6] = &(*(LucasExtendParam2* const*)(data + 0x80))->unk10;
            m_floats[i][7] = &(*(LucasExtendParam2* const*)(data + 0x80))->unk14;
            m_floats[i][8] = &(*(LucasExtendParam2* const*)(data + 0x80))->unk18;
            m_floats[i][9] = &(*(LucasExtendParam3**)(data + 0x84))->unk0;
            m_floats[i][10] = &(*(LucasExtendParam3* const*)(data + 0x84))->unk10;
            m_floats[i][11] = &(*(LucasExtendParam3* const*)(data + 0x84))->unk14;
            m_floats[i][12] = &(*(LucasExtendParam3* const*)(data + 0x84))->unk18;
            m_floats[i][13] = &(*(LucasExtendParam3* const*)(data + 0x84))->unk1C;
            m_floats[i][14] = &(*(LucasExtendParam3* const*)(data + 0x84))->unk20;
            m_floats[i][15] = &(*(LucasExtendParam3* const*)(data + 0x84))->unk24;
            m_floats[i][16] = &(*(LucasExtendParam3* const*)(data + 0x84))->unk28;
            m_floats[i][17] = &(*(LucasExtendParam3* const*)(data + 0x84))->unk2C;
            m_floats[i][18] = &(*(LucasExtendParam4* const*)(data + 0x88))->unk8;
            m_floats[i][19] = &(*(LucasExtendParam4* const*)(data + 0x88))->unkC;
            m_floats[i][20] = &(*(LucasExtendParam4* const*)(data + 0x88))->unk10;
            m_floats[i][21] = &(*(LucasExtendParam4* const*)(data + 0x88))->unk14;
            m_floats[i][22] = &(*(LucasExtendParam4* const*)(data + 0x88))->unk18;
            m_floats[i][23] = &(*(LucasExtendParam5**)(data + 0x8C))->unk0;
            m_floats[i][24] = &(*(LucasExtendParam5* const*)(data + 0x8C))->unk4;
            m_floats[i][25] = &(*(LucasExtendParam5* const*)(data + 0x8C))->unk8;
            m_floats[i][26] = &(*(LucasExtendParam5* const*)(data + 0x8C))->unkC;
            m_floats[i][27] = &(*(LucasExtendParam5* const*)(data + 0x8C))->unk10;
            m_floats[i][28] = &(*(LucasExtendParam6**)(data + 0x90))->unk0;
            m_floats[i][29] = &(*(LucasExtendParam6* const*)(data + 0x90))->unk4;
            m_floats[i][30] = &(*(LucasExtendParam6* const*)(data + 0x90))->unk8;
            m_floats[i][31] = &(*(LucasExtendParam6* const*)(data + 0x90))->unkC;
            m_floats[i][32] = &(*(LucasExtendParam6* const*)(data + 0x90))->unk10;
            m_floats[i][33] = &(*(LucasExtendParam6* const*)(data + 0x90))->unk14;

            m_ints[i][0] = &(*(LucasExtendParam1**)(data + 0x7C))->unk0;
            m_ints[i][1] = &(*(LucasExtendParam1* const*)(data + 0x7C))->unk4;
            m_ints[i][2] = &(*(LucasExtendParam1* const*)(data + 0x7C))->unk8;
            m_ints[i][3] = &(*(LucasExtendParam3* const*)(data + 0x84))->unk4;
            m_ints[i][4] = &(*(LucasExtendParam3* const*)(data + 0x84))->unk8;
            m_ints[i][5] = &(*(LucasExtendParam3* const*)(data + 0x84))->unkC;
            m_ints[i][6] = &(*(LucasExtendParam4**)(data + 0x88))->unk0;
            m_ints[i][7] = &(*(LucasExtendParam4* const*)(data + 0x88))->unk4;
            m_ints[i][8] = &(*(LucasExtendParam6* const*)(data + 0x90))->unk18;
        }
    }
};
static_assert(sizeof(LucasExtendParamSetup) == 0x178, "Lucas parameter accesser layout");

extern "C" void fn_114_C6BC(LucasExtendParamSetup* accesser, const u8* data)
{
    accesser->setupParameters(data);
}

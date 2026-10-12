#include <ft/ft_extend_param_accesser.h>

// Extended parameter blocks contain both integer and floating-point entries.
struct NessExtendParam1 {
    int unk0, unk4, unk8;
    float unkC, unk10;
};
struct NessExtendParam2 {
    float unk0, unk4, unk8, unkC, unk10, unk14, unk18;
};
struct NessExtendParam3 {
    float unk0;
    int unk4, unk8, unkC;
    float unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
};
struct NessExtendParam4 {
    int unk0, unk4;
    float unk8, unkC, unk10, unk14, unk18;
};
struct NessExtendParam5 {
    float unk0, unk4, unk8, unkC, unk10;
};
struct NessExtendParam6 {
    float unk0, unk4, unk8, unkC, unk10, unk14;
    int unk18;
};

class NessExtendParamSetup : public ftExtendParamAccesserEx<3999, 34, 24999, 9> {
public:
    void setupParameters(const u8* data) {
        for (s32 i = 0; i < NumVariations; ++i) {
            m_floats[i][0] = &(*(NessExtendParam1* const*)(data + 0x7C))->unkC;
            m_floats[i][1] = &(*(NessExtendParam1* const*)(data + 0x7C))->unk10;
            m_floats[i][2] = &(*(NessExtendParam2**)(data + 0x80))->unk0;
            m_floats[i][3] = &(*(NessExtendParam2* const*)(data + 0x80))->unk4;
            m_floats[i][4] = &(*(NessExtendParam2* const*)(data + 0x80))->unk8;
            m_floats[i][5] = &(*(NessExtendParam2* const*)(data + 0x80))->unkC;
            m_floats[i][6] = &(*(NessExtendParam2* const*)(data + 0x80))->unk10;
            m_floats[i][7] = &(*(NessExtendParam2* const*)(data + 0x80))->unk14;
            m_floats[i][8] = &(*(NessExtendParam2* const*)(data + 0x80))->unk18;
            m_floats[i][9] = &(*(NessExtendParam3**)(data + 0x84))->unk0;
            m_floats[i][10] = &(*(NessExtendParam3* const*)(data + 0x84))->unk10;
            m_floats[i][11] = &(*(NessExtendParam3* const*)(data + 0x84))->unk14;
            m_floats[i][12] = &(*(NessExtendParam3* const*)(data + 0x84))->unk18;
            m_floats[i][13] = &(*(NessExtendParam3* const*)(data + 0x84))->unk1C;
            m_floats[i][14] = &(*(NessExtendParam3* const*)(data + 0x84))->unk20;
            m_floats[i][15] = &(*(NessExtendParam3* const*)(data + 0x84))->unk24;
            m_floats[i][16] = &(*(NessExtendParam3* const*)(data + 0x84))->unk28;
            m_floats[i][17] = &(*(NessExtendParam3* const*)(data + 0x84))->unk2C;
            m_floats[i][18] = &(*(NessExtendParam4* const*)(data + 0x88))->unk8;
            m_floats[i][19] = &(*(NessExtendParam4* const*)(data + 0x88))->unkC;
            m_floats[i][20] = &(*(NessExtendParam4* const*)(data + 0x88))->unk10;
            m_floats[i][21] = &(*(NessExtendParam4* const*)(data + 0x88))->unk14;
            m_floats[i][22] = &(*(NessExtendParam4* const*)(data + 0x88))->unk18;
            m_floats[i][23] = &(*(NessExtendParam5**)(data + 0x8C))->unk0;
            m_floats[i][24] = &(*(NessExtendParam5* const*)(data + 0x8C))->unk4;
            m_floats[i][25] = &(*(NessExtendParam5* const*)(data + 0x8C))->unk8;
            m_floats[i][26] = &(*(NessExtendParam5* const*)(data + 0x8C))->unkC;
            m_floats[i][27] = &(*(NessExtendParam5* const*)(data + 0x8C))->unk10;
            m_floats[i][28] = &(*(NessExtendParam6**)(data + 0x90))->unk0;
            m_floats[i][29] = &(*(NessExtendParam6* const*)(data + 0x90))->unk4;
            m_floats[i][30] = &(*(NessExtendParam6* const*)(data + 0x90))->unk8;
            m_floats[i][31] = &(*(NessExtendParam6* const*)(data + 0x90))->unkC;
            m_floats[i][32] = &(*(NessExtendParam6* const*)(data + 0x90))->unk10;
            m_floats[i][33] = &(*(NessExtendParam6* const*)(data + 0x90))->unk14;

            m_ints[i][0] = &(*(NessExtendParam1**)(data + 0x7C))->unk0;
            m_ints[i][1] = &(*(NessExtendParam1* const*)(data + 0x7C))->unk4;
            m_ints[i][2] = &(*(NessExtendParam1* const*)(data + 0x7C))->unk8;
            m_ints[i][3] = &(*(NessExtendParam3* const*)(data + 0x84))->unk4;
            m_ints[i][4] = &(*(NessExtendParam3* const*)(data + 0x84))->unk8;
            m_ints[i][5] = &(*(NessExtendParam3* const*)(data + 0x84))->unkC;
            m_ints[i][6] = &(*(NessExtendParam4**)(data + 0x88))->unk0;
            m_ints[i][7] = &(*(NessExtendParam4* const*)(data + 0x88))->unk4;
            m_ints[i][8] = &(*(NessExtendParam6* const*)(data + 0x90))->unk18;
        }
    }
};
static_assert(sizeof(NessExtendParamSetup) == 0x178, "Ness parameter accesser layout");

extern "C" void fn_101_CC80(NessExtendParamSetup* accesser, const u8* data)
{
    accesser->setupParameters(data);
}

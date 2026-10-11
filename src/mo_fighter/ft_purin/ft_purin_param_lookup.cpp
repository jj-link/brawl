#include <ft/ft_extend_param_accesser.h>
#include <types.h>

// Variation storage belongs to sora_melee; these accessors read its first signed word.
extern "C" u8 lbl_27_bss_1B18[];

typedef ftExtendParamAccesserEx<3999, 49, 24999, 4> ftPurinExtendParamAccesserEx;

template<>
float ftPurinExtendParamAccesserEx::getParamFloat(soModuleAccesser* moduleAccesser, s32 p2, s32 p3) {
    return m_floats[soValueAccesser::getValueVariation()][p2 - OffsetFloat][p3];
}

#pragma dont_inline on
int soValueAccesser::getValueVariation() {
    return *reinterpret_cast<s32*>(lbl_27_bss_1B18);
}
#pragma dont_inline reset

template<>
s32 ftPurinExtendParamAccesserEx::getParamInt(soModuleAccesser* moduleAccesser, s32 p2, s32 p3) {
    return m_ints[soValueAccesser::getValueVariation()][p2 - OffsetInt][p3];
}

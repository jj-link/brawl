#include <ft/ft_common_data_accesser.h>
#pragma force_active on

extern "C" s32 fn_27_145598(void*, u32 p1, u32 p2) {
    return g_ftCommonData.commonIntParams[p1 - 160].m_0[p2 - 470];
}

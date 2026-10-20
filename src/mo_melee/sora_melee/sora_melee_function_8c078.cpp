#include <types.h>
#pragma force_active on

class soCommonDataAccesser {
public:
    s32 getParamCommonIndefinite(u32, u32);
};

extern soCommonDataAccesser g_soCommonDataAccesser;
extern s32 lbl_27_bss_1B18;

extern "C" s32 fn_27_8C078(s32, s32, u32 arg2)
{
    return g_soCommonDataAccesser.getParamCommonIndefinite(lbl_27_bss_1B18, arg2);
}

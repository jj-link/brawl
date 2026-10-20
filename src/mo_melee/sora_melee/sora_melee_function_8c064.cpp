#pragma force_active on
typedef unsigned long u32;
typedef long s32;

class soCommonDataAccesser {
public:
    s32 getParamCommonInt(u32, u32);
};

extern soCommonDataAccesser g_soCommonDataAccesser;
extern s32 lbl_27_bss_1B18;

extern "C" {
s32 fn_27_8C064(u32, u32, u32 param)
{
    return g_soCommonDataAccesser.getParamCommonInt(lbl_27_bss_1B18, param);
}
}

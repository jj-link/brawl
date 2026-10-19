#include <types.h>
#include <ft/ft_common_data_accesser.h>
#pragma force_active on

extern "C" s32 fn_27_1454C0(const void* self);

extern "C" void* fn_27_14548C(const void* self) {
    s32 idx = fn_27_1454C0(self);
    return g_ftCommonData.commonParams[idx];
}

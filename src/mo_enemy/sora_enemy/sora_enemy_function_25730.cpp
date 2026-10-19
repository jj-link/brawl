#include <em/em_area_module_impl.h>
#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_41_25524(void* out, soModuleAccesser* acc, s32 p2, s32 flag);
extern "C" s32 fn_41_242EC(soModuleAccesser* acc, void* info);

s32 emAreaModuleImpl::getTargetFoundDistance(soModuleAccesser* acc, s32 p2) {
    u8 buf[8];
    fn_41_25524(buf, acc, p2, 1);
    return fn_41_242EC(acc, buf);
}

#include <em/em_area_module_impl.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_41_244DC(soModuleAccesser*, Vec3f*);

extern "C" void fn_41_24570(soModuleAccesser* acc, u32 target) {
    Vec3f pos = emAreaModuleImpl::getTargetPos(acc, target, true);
    fn_41_244DC(acc, &pos);
}

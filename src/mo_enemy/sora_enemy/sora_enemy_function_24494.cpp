#include <em/em_area_module_impl.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_41_242EC(void*, Vec3f*);

extern "C" void fn_41_24494(void* self, u32 target) {
    Vec3f pos = emAreaModuleImpl::getTargetPos(
        static_cast<soModuleAccesser*>(self), target, true);
    fn_41_242EC(self, &pos);
}

#include <so/model/so_model_module_impl.h>
#include <types.h>
#pragma force_active on

namespace {
struct soModelModuleImplFlagsOverlay {
    char pad[0xC5];
    u8 : 1;
    u8 lockMtx : 1;
};
}

void soModelModuleImpl::setLockMtx(bool lock) {
    reinterpret_cast<soModelModuleImplFlagsOverlay*>(this)->lockMtx = lock;
}

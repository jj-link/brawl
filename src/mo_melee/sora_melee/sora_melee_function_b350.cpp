#include <so/model/so_model_module_impl.h>
#pragma force_active on

extern "C" void nwSMSetVisibility__FPQ34nw4r3g3d12ScnMdlSimpleb(nw4r::g3d::ScnMdlSimple*, bool);

void soModelModuleImpl::setVisibility(bool visibility, bool p2) {
    if (getScnMdl(p2)) {
        nwSMSetVisibility__FPQ34nw4r3g3d12ScnMdlSimpleb(getScnMdl(p2), visibility);
    }
}

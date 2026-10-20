#include <nw4r/g3d/g3d_scnmdl.h>
#include <so/model/so_model_module_impl.h>
#pragma force_active on

namespace nw4r { namespace g3d { class ScnMdl; } }
extern "C" void nwSMSetNodeVisibility__FPQ34nw4r3g3d6ScnMdlUlb(nw4r::g3d::ScnMdl* mdl, u32 nodeId, bool visibility);

void soModelModuleImpl::setNodeVisibility(u32 nodeId, bool visibility, bool b) {
    if (getScnMdl(b) != 0) {
        nwSMSetNodeVisibility__FPQ34nw4r3g3d6ScnMdlUlb(getScnMdl(b), nodeId, visibility);
    }
}

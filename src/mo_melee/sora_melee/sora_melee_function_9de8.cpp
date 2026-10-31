#include <StaticAssert.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <so/model/so_model_module_impl.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_80047560(nw4r::g3d::ScnMdl*);

void soModelModuleImpl::setUpSkinningMtx() {
    nw4r::g3d::ScnMdl** p = reinterpret_cast<nw4r::g3d::ScnMdl**>(this);
    nw4r::g3d::ScnMdl* mdl = p[3];
    if (mdl) {
        fn_80047560(mdl);
    }
}

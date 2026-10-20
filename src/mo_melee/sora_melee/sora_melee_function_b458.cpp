#include <so/model/so_model_module_impl.h>
#include <types.h>
#include <ut/ut_nw.h>
#pragma force_active on

extern "C" void fn_27_B458(soModelModuleImpl* self, s32 numIds, const u32* nodeIds, bool vis, bool p4) {
    if (self->getScnMdl(p4)) {
        nwSMSetNodeVisibility(self->getScnMdl(p4), numIds, nodeIds, vis);
    }
}

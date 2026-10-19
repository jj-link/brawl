#include <nw4r/g3d/g3d_resfile.h>
#include <so/model/so_model_module_impl.h>
#include <types.h>
#pragma force_active on

u32 soModelModuleImpl::getNodeNum(bool b) const {
    nw4r::g3d::ScnMdl* scnMdl = getScnMdl(b);
    nw4r::g3d::ResMdl mdl = *(nw4r::g3d::ResMdl*)((u8*)scnMdl + 0xe8);
    return mdl.GetResNodeNumEntries();
}

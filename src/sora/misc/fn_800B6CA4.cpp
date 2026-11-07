#include <nw4r/g3d/g3d_resmdl.h>
#include <ut/ut_nw.h>
#pragma force_active on

struct Outer {
    char pad[0x10];
    nw4r::g3d::ScnMdlSimple* obj;
    char pad2[0x20];
    u32 node;
};

extern "C" Vec3f fn_800B6CA4(Outer* arg) {
    nw4r::g3d::ResMdl mdl = arg->obj->m_resMdl;
    nw4r::g3d::ResNode node = mdl.GetResNode(arg->node);
    return nwSMGetGlobalPosition(arg->obj, node.IsValid() ? node->m_nodeIndex : 0);
}
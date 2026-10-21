#include <gf/gf_model.h>
#pragma force_active on

void gfModelAnimation::bindTexAnim(nw4r::g3d::ScnMdl* sceneModel) {
    if (m_anmObjTexPatRes != NULL) {
        sceneModel->SetAnmObj((nw4r::g3d::AnmObj*)m_anmObjTexPatRes,
                              nw4r::g3d::ScnMdlSimple::ANMOBJTYPE_TEXPAT);
    }
}

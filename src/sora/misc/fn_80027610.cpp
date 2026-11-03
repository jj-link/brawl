#include <gf/gf_model.h>
#pragma force_active on

void gfModelAnimation::bind(nw4r::g3d::ScnMdl* sceneModel, gfModelAnimation* modelAnim) {
    if (modelAnim->m_anmObjChrRes)
        sceneModel->SetAnmObj((nw4r::g3d::AnmObj*)modelAnim->m_anmObjChrRes, nw4r::g3d::ScnMdlSimple::ANMOBJTYPE_CHR);
    if (modelAnim->m_anmObjVisRes)
        sceneModel->SetAnmObj((nw4r::g3d::AnmObj*)modelAnim->m_anmObjVisRes, nw4r::g3d::ScnMdlSimple::ANMOBJTYPE_VIS);
    if (modelAnim->m_anmObjTexPatRes)
        sceneModel->SetAnmObj((nw4r::g3d::AnmObj*)modelAnim->m_anmObjTexPatRes, nw4r::g3d::ScnMdlSimple::ANMOBJTYPE_TEXPAT);
    if (modelAnim->m_anmObjTexSrtRes)
        sceneModel->SetAnmObj((nw4r::g3d::AnmObj*)modelAnim->m_anmObjTexSrtRes, nw4r::g3d::ScnMdlSimple::ANMOBJTYPE_TEXSRT);
    if (modelAnim->m_anmObjMatClrRes)
        sceneModel->SetAnmObj((nw4r::g3d::AnmObj*)modelAnim->m_anmObjMatClrRes, nw4r::g3d::ScnMdlSimple::ANMOBJTYPE_MATCLR);
    if (modelAnim->m_anmObjShpRes)
        sceneModel->SetAnmObj((nw4r::g3d::AnmObj*)modelAnim->m_anmObjShpRes, nw4r::g3d::ScnMdlSimple::ANMOBJTYPE_SHP);
}
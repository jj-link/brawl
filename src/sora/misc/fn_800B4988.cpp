#pragma force_active on
#include <gf/gf_model.h>
#include <gf/gf_heap_manager.h>

extern "C" {
nw4r::g3d::ResAnmVis fn_8018D7DC(nw4r::g3d::ResFile* res, const char* name);
void fn_800B458C();
extern int lbl_8059C648;
}

class MuObject {
public:
    char pad0[4];
    nw4r::g3d::ResFile m_resFile;
    nw4r::g3d::ResMdl m_resMdl;
    nw4r::g3d::ScnMdl* m_scnMdl;
    nw4r::g3d::ScnMdl* m_sceneModel;
    gfModelAnimation* m_modelAnim;
    char unk18[0x3C];
    int m_heap;

    bool changeVisAnimNIf(const char* animName);
};

inline void makeVis(nw4r::g3d::ResAnmVis anim, gfModelAnimation* modelAnim, nw4r::g3d::ResMdl model, int heap) {
    int instanceSize;
    MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)heap);
    if (anim.IsValid()) {
        nw4r::g3d::AnmObjVisRes* anmObj =
            nw4r::g3d::AnmObjVisRes::Construct(allocator, &instanceSize, anim, model);
        if (anmObj != NULL) {
            anmObj->Bind(model);
            if (modelAnim->m_anmObjVisRes != NULL) {
                modelAnim->m_anmObjVisRes->Destroy();
            }
            modelAnim->m_anmObjVisRes = anmObj;
        }
    }
}
bool MuObject::changeVisAnimNIf(const char* animName) {
    nw4r::g3d::ResAnmVis anim = fn_8018D7DC(&m_resFile, animName);
    if (!anim.IsValid()) {
        return false;
    }
    m_modelAnim->unbindVisibleAnim(m_sceneModel);
    makeVis(anim, m_modelAnim, m_resMdl, m_heap);
    m_modelAnim->bindVisibleAnim(m_sceneModel);
    nw4r::g3d::AnmObjVisRes* visObj = m_modelAnim->m_anmObjVisRes;
    int idx = *(int*)((char*)visObj->m_anmVisFile.ptr() + 0x20);
    void* cb;
    if (idx == 0) {
        cb = (void*)fn_800B458C;
    } else {
        cb = ((void**)&lbl_8059C648)[idx];
    }
    *(void**)((char*)visObj + 0x28) = cb;
    nw4r::g3d::ScnMdl* mdl = m_sceneModel;
    mdl->SetScnObjOption(2, 0);
    mdl->SetScnObjOption(5, 0);
    return true;
}
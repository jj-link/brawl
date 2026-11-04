#pragma force_active on
#include <gf/gf_model.h>
#include <gf/gf_heap_manager.h>

extern "C" {
void* fn_8018D5D4(void*);
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

    void changeNodeAnimN(const char*);
};


void MuObject::changeNodeAnimN(const char*) {
    nw4r::g3d::ResAnmChr anim(fn_8018D5D4(&m_resFile));
    if (!anim.IsValid()) return;
    m_modelAnim->unbindNodeAnim(m_sceneModel);
    int instanceSize;
    nw4r::g3d::ResMdl model = m_resMdl;
    gfModelAnimation* modelAnim = m_modelAnim;
    MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)m_heap);
    if (anim.IsValid()) {
        nw4r::g3d::AnmObjChrRes* anmObj =
            nw4r::g3d::AnmObjChrRes::Construct(allocator, &instanceSize, anim, model, false);
        if (anmObj != NULL) {
            anmObj->Bind(model);
            if (modelAnim->m_anmObjChrRes != NULL) {
                modelAnim->m_anmObjChrRes->Destroy();
            }
            modelAnim->m_anmObjChrRes = anmObj;
        }
    }

    m_modelAnim->bindNodeAnim(m_sceneModel);
    nw4r::g3d::AnmObjChrRes* chrObj = m_modelAnim->m_anmObjChrRes;
    int idx = *(int*)((char*)chrObj->m_anmChrFile.ptr() + 0x20);
    void* cb;
    if (idx == 0) cb = (void*)fn_800B458C;
    else cb = ((void**)&lbl_8059C648)[idx];
    *(void**)((char*)chrObj + 0x28) = cb;
    nw4r::g3d::ScnMdl* mdl = m_sceneModel;
    mdl->SetScnObjOption(2, 0);
    mdl->SetScnObjOption(5, 0);
}

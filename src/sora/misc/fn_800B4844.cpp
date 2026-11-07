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
    nw4r::g3d::ResFile m_resFile;      // 0x04
    nw4r::g3d::ResMdl m_resMdl;        // 0x08
    nw4r::g3d::ScnMdl* m_scnMdl;       // 0x0C
    nw4r::g3d::ScnMdl* m_sceneModel;   // 0x10
    gfModelAnimation* m_modelAnim;     // 0x14
    char unk18[0x3C];                 // 0x18
    int m_heap;                        // 0x54

    void changeVisAnimN(const char* animName);
};

void MuObject::changeVisAnimN(const char* animName) {
    nw4r::g3d::ResAnmVis anim(fn_8018D7DC(&m_resFile, animName));
    if (!anim.IsValid()) {
        return;
    }
    m_modelAnim->unbindVisibleAnim(m_sceneModel);
    int instanceSize;
    Heaps::HeapType heap = (Heaps::HeapType)m_heap;
    nw4r::g3d::ResMdl model = m_resMdl;
    gfModelAnimation* modelAnim = m_modelAnim;
    MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
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
}
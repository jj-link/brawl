#pragma force_active on
#include <gf/gf_model.h>
#include <gf/gf_heap_manager.h>

extern "C" {
void* fn_8018DBEC(void* resFile);
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
    char unk18[0x3C];                  // 0x18
    int m_heap;                        // 0x54

    bool changeTexPatAnimNIf(const char* animName);
};

static inline void setTexPatAnimInline(nw4r::g3d::ResAnmTexPat anim, gfModelAnimation* modelAnim,
                                       nw4r::g3d::ResMdl model, Heaps::HeapType heap) {
    int instanceSize;
    if (anim.IsValid()) {
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
        nw4r::g3d::AnmObjTexPatRes* anmObj =
            nw4r::g3d::AnmObjTexPatRes::Construct(allocator, &instanceSize, anim, model, false);
        if (anmObj != NULL) {
            anmObj->Bind(model);
            if (modelAnim->m_anmObjTexPatRes != NULL) {
                modelAnim->m_anmObjTexPatRes->Destroy();
            }
            modelAnim->m_anmObjTexPatRes = anmObj;
        }
    }
}

bool MuObject::changeTexPatAnimNIf(const char* animName) {
    nw4r::g3d::ResAnmTexPat anim(fn_8018DBEC(&m_resFile));
    if (!anim.IsValid()) {
        return false;
    }
    m_modelAnim->unbindTexAnim(m_sceneModel);
    setTexPatAnimInline(anim, m_modelAnim, m_resMdl, (Heaps::HeapType)m_heap);
    m_modelAnim->bindTexAnim(m_sceneModel);
    nw4r::g3d::AnmObjTexPatRes* texPatObj = m_modelAnim->m_anmObjTexPatRes;
    int idx = *(int*)((char*)texPatObj->m_anmTexPatFile.ptr() + 0x34);
    void* cb;
    if (idx == 0) {
        cb = (void*)fn_800B458C;
    } else {
        cb = ((void**)&lbl_8059C648)[idx];
    }
    *(void**)((char*)texPatObj + 0x28) = cb;
    m_sceneModel->SetScnObjOption(3, 0);
    return true;
}

#pragma force_active on
#include <gf/gf_model.h>
#include <gf/gf_heap_manager.h>

extern "C" {
void* fn_8018DDF4(void* resFile);
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

    void changeTexSrtAnimN(const char* animName);
};

void MuObject::changeTexSrtAnimN(const char* animName) {
    nw4r::g3d::ResAnmTexSrt anim(fn_8018DDF4(&m_resFile));
    if (!anim.IsValid()) {
        return;
    }
    m_modelAnim->unbindTexSrtAnim(m_sceneModel);
    int instanceSize;
    Heaps::HeapType heap = (Heaps::HeapType)m_heap;
    nw4r::g3d::ResMdl model = m_resMdl;
    gfModelAnimation* modelAnim = m_modelAnim;
    if (anim.IsValid()) {
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
        nw4r::g3d::AnmObjTexSrtRes* anmObj =
            nw4r::g3d::AnmObjTexSrtRes::Construct(allocator, &instanceSize, anim, model, false);
        if (anmObj != NULL) {
            anmObj->Bind(model);
            if (modelAnim->m_anmObjTexSrtRes != NULL) {
                modelAnim->m_anmObjTexSrtRes->Destroy();
            }
            modelAnim->m_anmObjTexSrtRes = anmObj;
        }
    }
    m_modelAnim->bindTexSrtAnim(m_sceneModel);
    nw4r::g3d::AnmObjTexSrtRes* texSrtObj = m_modelAnim->m_anmObjTexSrtRes;
    int idx = *(int*)((char*)texSrtObj->m_anmTexSrtFile.ptr() + 0x24);
    void* cb;
    if (idx == 0) {
        cb = (void*)fn_800B458C;
    } else {
        cb = ((void**)&lbl_8059C648)[idx];
    }
    *(void**)((char*)texSrtObj + 0x28) = cb;
    m_sceneModel->SetScnObjOption(3, 0);
}

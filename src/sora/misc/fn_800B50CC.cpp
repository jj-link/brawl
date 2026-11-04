#pragma force_active on
#include <gf/gf_model.h>
#include <gf/gf_heap_manager.h>

extern "C" {
void* fn_8018D9E4(void* resFile);
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

    void changeClrAnimN(const char* animName);
};

void MuObject::changeClrAnimN(const char* animName) {
    nw4r::g3d::ResAnmClr anim(fn_8018D9E4(&m_resFile));
    if (!anim.IsValid()) {
        return;
    }
    m_modelAnim->unbindMatColAnim(m_sceneModel);
    int instanceSize;
    Heaps::HeapType heap = (Heaps::HeapType)m_heap;
    nw4r::g3d::ResMdl model = m_resMdl;
    gfModelAnimation* modelAnim = m_modelAnim;
    if (anim.IsValid()) {
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
        nw4r::g3d::AnmObjMatClrRes* anmObj =
            nw4r::g3d::AnmObjMatClrRes::Construct(allocator, &instanceSize, anim, model, false);
        if (anmObj != NULL) {
            anmObj->Bind(model);
            if (modelAnim->m_anmObjMatClrRes != NULL) {
                modelAnim->m_anmObjMatClrRes->Destroy();
            }
            modelAnim->m_anmObjMatClrRes = anmObj;
        }
    }
    m_modelAnim->bindMatColAnim(m_sceneModel);
    nw4r::g3d::AnmObjMatClrRes* matClrObj = m_modelAnim->m_anmObjMatClrRes;
    int idx = *(int*)((char*)matClrObj->m_anmMatClrFile.ptr() + 0x20);
    void* cb;
    if (idx == 0) {
        cb = (void*)fn_800B458C;
    } else {
        cb = ((void**)&lbl_8059C648)[idx];
    }
    *(void**)((char*)matClrObj + 0x28) = cb;
    m_sceneModel->SetScnObjOption(3, 0);
}
#pragma force_active on
#include <gf/gf_model.h>
#include <gf/gf_heap_manager.h>

extern "C" {
void* fn_8018DCF0(void*, u32);
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
    void changeTexPatAnim(const char* index);
};

void MuObject::changeTexPatAnim(const char* index) {
    if ((u32)index < m_resFile.GetResAnmTexPatNumEntries()) {
        m_modelAnim->unbindTexAnim(m_sceneModel);
        gfModelAnimation* modelAnim = m_modelAnim;
        Heaps::HeapType heap = (Heaps::HeapType)m_heap;
        nw4r::g3d::ResMdl model = m_resMdl;
        if ((u32)index < modelAnim->m_resFile.GetResAnmTexPatNumEntries()) {
            nw4r::g3d::ResAnmTexPat anim(fn_8018DCF0(modelAnim, (u32)index));
            if (anim.IsValid()) {
                int instanceSize;
                MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
                nw4r::g3d::AnmObjTexPatRes* anmObj = nw4r::g3d::AnmObjTexPatRes::Construct(allocator, &instanceSize, anim, model, false);
                if (anmObj != NULL) {
                    anmObj->Bind(model);
                    if (modelAnim->m_anmObjTexPatRes != NULL)
                        modelAnim->m_anmObjTexPatRes->Destroy();
                    modelAnim->m_anmObjTexPatRes = anmObj;
                }
            }
        }
        m_modelAnim->bindTexAnim(m_sceneModel);
        nw4r::g3d::AnmObjTexPatRes* obj = m_modelAnim->m_anmObjTexPatRes;
        int idx = *(int*)((char*)obj->m_anmTexPatFile.ptr() + 0x34);
        void* cb;
        if (idx == 0) cb = (void*)fn_800B458C;
        else cb = ((void**)&lbl_8059C648)[idx];
        *(void**)((char*)obj + 0x28) = cb;
        m_sceneModel->SetScnObjOption(3, 0);
    }
}
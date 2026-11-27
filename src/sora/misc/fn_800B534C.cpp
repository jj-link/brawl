#pragma force_active on
#include <types.h>
#include <gf/gf_model.h>
#include <gf/gf_heap_manager.h>
#include <mu/mu_object.h>

extern "C" {
void* fn_8018D5D4(void*, const char*);
void* fn_8018D7DC(void*, const char*);
void* fn_8018DBEC(void*, const char*);
void* fn_8018DDF4(void*, const char*);
void* fn_8018D9E4(void*, const char*);
void fn_800B458C();
extern int lbl_8059C648;
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int, int);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
};

class AnimationInstanceSize {
    int value;
public:
    AnimationInstanceSize() {}
    operator int*() { return &value; }
};

void MuObject::changeAnimN(const char* animName) {

    const int& m_heap = *reinterpret_cast<const int*>(unk2 + 0x3C);
    gfModelAnimation* a1;
    nw4r::g3d::AnmObjChrRes* obj1;
    nw4r::g3d::AnmObjVisRes* obj2;
    gfModelAnimation* a2;
    nw4r::g3d::ScnMdl* mdl1;
    nw4r::g3d::ResAnmChr chr(fn_8018D5D4(&m_resFile, animName));
    if (chr.IsValid()) {
        m_modelAnim->unbindNodeAnim(m_sceneModel);
        nw4r::g3d::ResMdl model = m_resMdl;
        a1 = m_modelAnim;
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)m_heap);
        if (chr.IsValid()) {
            obj1 = nw4r::g3d::AnmObjChrRes::Construct(allocator, AnimationInstanceSize(), chr, model, false);
            if (obj1) {
                obj1->Bind(model);
                if (a1->m_anmObjChrRes)
                    a1->m_anmObjChrRes->Destroy();
                a1->m_anmObjChrRes = obj1;
            }
        }
        m_modelAnim->bindNodeAnim(m_sceneModel);
        {
            nw4r::g3d::AnmObjChrRes* x = m_modelAnim->m_anmObjChrRes;
            int idx = *(int*)(*(char**)((char*)x + 0x2C) + 0x20);
            void* cb;
            if (idx == 0)
                cb = (void*)fn_800B458C;
            else
                cb = ((void**)&lbl_8059C648)[idx];
            *(void**)((char*)x + 0x28) = cb;
        }
        mdl1 = m_sceneModel;
        mdl1->SetScnObjOption(2, 0);
        mdl1->SetScnObjOption(5, 0);
    }

    nw4r::g3d::ResAnmVis vis(fn_8018D7DC(&m_resFile, animName));
    if (vis.IsValid()) {
        m_modelAnim->unbindVisibleAnim(m_sceneModel);
        nw4r::g3d::ResMdl model = m_resMdl;
        a2 = m_modelAnim;
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)m_heap);
        if (vis.IsValid()) {
            obj2 = nw4r::g3d::AnmObjVisRes::Construct(allocator, AnimationInstanceSize(), vis, model);
            if (obj2) {
                obj2->Bind(model);
                if (a2->m_anmObjVisRes)
                    a2->m_anmObjVisRes->Destroy();
                a2->m_anmObjVisRes = obj2;
            }
        }
        m_modelAnim->bindVisibleAnim(m_sceneModel);
        nw4r::g3d::AnmObjVisRes* x = m_modelAnim->m_anmObjVisRes;
        int idx = *(int*)(*(char**)((char*)x + 0x2C) + 0x20);
        void* cb = idx == 0 ? (void*)fn_800B458C : ((void**)&lbl_8059C648)[idx];
        *(void**)((char*)x + 0x28) = cb;
        nw4r::g3d::ScnMdl* mdl = m_sceneModel;
        mdl->SetScnObjOption(2, 0);
        mdl->SetScnObjOption(5, 0);
    }

    nw4r::g3d::ResAnmTexPat pat(fn_8018DBEC(&m_resFile, animName));
    if (pat.IsValid()) {
        m_modelAnim->unbindTexAnim(m_sceneModel);
        nw4r::g3d::AnmObjTexPatRes* obj;
        Heaps::HeapType heap = (Heaps::HeapType)m_heap;
        nw4r::g3d::ResMdl model = m_resMdl;
        gfModelAnimation* a = m_modelAnim;
        if (pat.IsValid()) {
            MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
            obj = nw4r::g3d::AnmObjTexPatRes::Construct(allocator, AnimationInstanceSize(), pat, model, false);
            if (obj) {
                obj->Bind(model);
                if (a->m_anmObjTexPatRes)
                    a->m_anmObjTexPatRes->Destroy();
                a->m_anmObjTexPatRes = obj;
            }
        }
        m_modelAnim->bindTexAnim(m_sceneModel);
        nw4r::g3d::AnmObjTexPatRes* x = m_modelAnim->m_anmObjTexPatRes;
        int idx = *(int*)(*(char**)((char*)x + 0x2C) + 0x34);
        void* cb = idx == 0 ? (void*)fn_800B458C : ((void**)&lbl_8059C648)[idx];
        *(void**)((char*)x + 0x28) = cb;
        m_sceneModel->SetScnObjOption(3, 0);
    }

    nw4r::g3d::ResAnmTexSrt srt(fn_8018DDF4(&m_resFile, animName));
    if (srt.IsValid()) {
        m_modelAnim->unbindTexSrtAnim(m_sceneModel);
        nw4r::g3d::AnmObjTexSrtRes* obj;
        Heaps::HeapType heap = (Heaps::HeapType)m_heap;
        nw4r::g3d::ResMdl model = m_resMdl;
        gfModelAnimation* a = m_modelAnim;
        if (srt.IsValid()) {
            MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
            obj = nw4r::g3d::AnmObjTexSrtRes::Construct(allocator, AnimationInstanceSize(), srt, model, false);
            if (obj) {
                obj->Bind(model);
                if (a->m_anmObjTexSrtRes)
                    a->m_anmObjTexSrtRes->Destroy();
                a->m_anmObjTexSrtRes = obj;
            }
        }
        m_modelAnim->bindTexSrtAnim(m_sceneModel);
        nw4r::g3d::AnmObjTexSrtRes* x = m_modelAnim->m_anmObjTexSrtRes;
        int idx = *(int*)(*(char**)((char*)x + 0x2C) + 0x24);
        void* cb = idx == 0 ? (void*)fn_800B458C : ((void**)&lbl_8059C648)[idx];
        *(void**)((char*)x + 0x28) = cb;
        m_sceneModel->SetScnObjOption(3, 0);
    }

    animName = (const char*)fn_8018D9E4(&m_resFile, animName);
    nw4r::g3d::ResAnmClr clr((void*)animName);
    if (clr.IsValid()) {
        m_modelAnim->unbindMatColAnim(m_sceneModel);
        nw4r::g3d::AnmObjMatClrRes* obj;
        Heaps::HeapType heap = (Heaps::HeapType)m_heap;
        nw4r::g3d::ResMdl model = m_resMdl;
        gfModelAnimation* a = m_modelAnim;
        if (clr.IsValid()) {
            MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
            obj = nw4r::g3d::AnmObjMatClrRes::Construct(allocator, AnimationInstanceSize(), clr, model, false);
            if (obj) {
                obj->Bind(model);
                if (a->m_anmObjMatClrRes)
                    a->m_anmObjMatClrRes->Destroy();
                a->m_anmObjMatClrRes = obj;
            }
        }
        m_modelAnim->bindMatColAnim(m_sceneModel);
        nw4r::g3d::AnmObjMatClrRes* x = m_modelAnim->m_anmObjMatClrRes;
        int idx = *(int*)(*(char**)((char*)x + 0x2C) + 0x20);
        void* cb = idx == 0 ? (void*)fn_800B458C : ((void**)&lbl_8059C648)[idx];
        *(void**)((char*)x + 0x28) = cb;
        m_sceneModel->SetScnObjOption(3, 0);
    }
}

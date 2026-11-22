#include <gf/gf_model.h>
#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
};

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad2[0x114];
    u8 current;
};

extern "C" {
nw4r::g3d::ResAnmChr fn_8018D6D8(void*, u32);
nw4r::g3d::ResAnmVis fn_8018D8E0(void*, u32);
void setLoopNode__16gfModelAnimationFd(gfModelAnimation*, bool);
void setLoopVisible__16gfModelAnimationFd(gfModelAnimation*, bool);
extern const float lbl_71_rodata_168;
extern const float lbl_71_rodata_16C;
}

inline void chrAt(u8 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
    int size;
    nw4r::g3d::ResAnmChr res = fn_8018D6D8(a, i);
    MEMAllocator* alloc = gfHeapManager::getMEMAllocator(heap);
    if (res.IsValid()) {
        nw4r::g3d::AnmObjChrRes* obj = nw4r::g3d::AnmObjChrRes::Construct(alloc, &size, res, model, false);
        if (obj) {
            obj->Bind(model);
            if (a->m_anmObjChrRes) a->m_anmObjChrRes->Destroy();
            a->m_anmObjChrRes = obj;
        }
    }
}
inline void chr(u8 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
    if (i < a->m_resFile.GetResAnmChrNumEntries()) chrAt(i, model, a, heap);
}
inline void visAt(u8 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
    int size;
    nw4r::g3d::ResAnmVis res = fn_8018D8E0(a, i);
    MEMAllocator* alloc = gfHeapManager::getMEMAllocator(heap);
    if (res.IsValid()) {
        nw4r::g3d::AnmObjVisRes* obj = nw4r::g3d::AnmObjVisRes::Construct(alloc, &size, res, model);
        if (obj) {
            obj->Bind(model);
            if (a->m_anmObjVisRes) a->m_anmObjVisRes->Destroy();
            a->m_anmObjVisRes = obj;
        }
    }
}
inline void vis(u8 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
    if (i < a->m_resFile.GetResAnmVisNumEntries()) visAt(i, model, a, heap);
}
extern "C" void fn_71_67E8(Object* self, u8 index, bool loop, bool force, float* out) {
    if (self->current == index && !force)
        return;

    nw4r::g3d::ScnMdl* model = *self->models;
    if (!model)
        return;

    gfModelAnimation* animation = *self->animations;
    if (!animation)
        return;

    nw4r::g3d::ResMdl resource(*(void**)((char*)model + 0xE8));
    if (!resource.IsValid())
        return;

    animation->unbindNodeAnim(model);
    animation->unbindVisibleAnim(model);
    self->current = index;

    if (index >= 1u)
        return;

    {
        int has = index < animation->m_resFile.GetResAnmChrNumEntries();
        if (has)
            chr(index, resource, animation, Heaps::StageInstance);
    }
    {
        int has = index < animation->m_resFile.GetResAnmVisNumEntries();
        if (has)
            vis(index, resource, animation, Heaps::StageInstance);
    }

    gfModelAnimation::bind(model, animation);
    animation->m_anmObjChrRes->SetFrame(lbl_71_rodata_168);
    animation->m_anmObjVisRes->SetFrame(lbl_71_rodata_168);
    animation->setUpdateRate(lbl_71_rodata_16C);
    setLoopNode__16gfModelAnimationFd(animation, loop);
    setLoopVisible__16gfModelAnimationFd(animation, loop);

    if (out) {
        char* obj = *(char**)((char*)animation + 0xC);
        char* sub = *(char**)(obj + 0x2C);
        u16 n = *(u16*)(sub + 0x1C);
        *out = (float)n;
    }
}

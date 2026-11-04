#include <gf/gf_model.h>
#pragma force_active on

class Class_1A68 {
public:
    virtual void fn_52_8E6C();
    virtual void fn_52_828C();
    virtual void fn_52_829C();
    virtual void fn_52_75D0();
    virtual void fn_52_7344();
    virtual void fn_52_6ED8();
    virtual void fn_52_85C8();
    virtual void fn_52_8684();
    virtual void fn_52_8E24();
    virtual void fn_52_82AC();
    virtual int fn_52_7028(nw4r::g3d::ResMdl);
};

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad4C[0x130];
    u8 index;
};

extern "C" {
int __cntlzw(unsigned int);
nw4r::g3d::ResAnmChr fn_8018D6D8(void*, u32);
nw4r::g3d::ResAnmVis fn_8018D8E0(void*, u32);
nw4r::g3d::ResAnmTexPat fn_8018DCF0(void*, u32);
nw4r::g3d::ResAnmTexSrt fn_8018DEF8(void*, u32);
nw4r::g3d::ResAnmClr fn_8018DAE8(void*, u32);
void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
void setLoop__16gfModelAnimationFd(gfModelAnimation*, int);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
extern const float lbl_52_rodata_B8;
extern const float lbl_52_rodata_C0;
}

inline void customsetVisibilityAnim(u8 animId,nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
        int instanceSize;
        nw4r::g3d::ResAnmVis anim = fn_8018D8E0(&modelAnim->m_resFile, (u32)animId);

        MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
        if (anim.IsValid())
        {
            nw4r::g3d::AnmObjVisRes* anmObj = nw4r::g3d::AnmObjVisRes::Construct(allocator, &instanceSize, anim, model);
            if (anmObj != NULL)
            {
                anmObj->Bind(model);

                if (modelAnim->m_anmObjVisRes != NULL)
                {
                    modelAnim->m_anmObjVisRes->Destroy();
                }

                modelAnim->m_anmObjVisRes = anmObj;
            }
        }
}

inline void customsetVisibilityAnim2(u8 animId,nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmVisNumEntries()) {
        customsetVisibilityAnim(animId,model, modelAnim, heap);
    }
}


inline void customsetChrAnim(u8 animId,nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
        int instanceSize;
        nw4r::g3d::ResAnmChr anim = fn_8018D6D8(&modelAnim->m_resFile, (u32)animId);

        MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
        if (anim.IsValid())
        {
            nw4r::g3d::AnmObjChrRes* anmObj = nw4r::g3d::AnmObjChrRes::Construct(allocator, &instanceSize, anim, model, false);
            if (anmObj != NULL)
            {
                anmObj->Bind(model);

                if (modelAnim->m_anmObjChrRes != NULL)
                {
                    modelAnim->m_anmObjChrRes->Destroy();
                }

                modelAnim->m_anmObjChrRes = anmObj;
            }
        }
}

inline void customsetChrAnim2(u8 animId,nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmChrNumEntries()) {
        customsetChrAnim(animId,model, modelAnim,heap);
    }
}


inline void customsetTexPatAnim(u8 animId,nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
        int instanceSize;
        nw4r::g3d::ResAnmTexPat anim = fn_8018DCF0(&modelAnim->m_resFile, (u32)animId);

        if (anim.IsValid())
        {
            MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
            nw4r::g3d::AnmObjTexPatRes* anmObj = nw4r::g3d::AnmObjTexPatRes::Construct(allocator, &instanceSize, anim, model, false);
            if (anmObj != NULL)
            {
                anmObj->Bind(model);

                if (modelAnim->m_anmObjTexPatRes != NULL)
                {
                    modelAnim->m_anmObjTexPatRes->Destroy();
                }

                modelAnim->m_anmObjTexPatRes = anmObj;
            }
        }
}

inline void customsetTexPatAnim2(u8 animId,nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmTexPatNumEntries()) {
        customsetTexPatAnim(animId,model, modelAnim,heap);
    }
}


inline void customsetTexSortAnim(u8 animId,nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
        int instanceSize;
        nw4r::g3d::ResAnmTexSrt anim = fn_8018DEF8(&modelAnim->m_resFile, (u32)animId);

        if (anim.IsValid())
        {
            MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
            nw4r::g3d::AnmObjTexSrtRes* anmObj = nw4r::g3d::AnmObjTexSrtRes::Construct(allocator, &instanceSize, anim, model, false);
            if (anmObj != NULL)
            {
                anmObj->Bind(model);

                if (modelAnim->m_anmObjTexSrtRes != NULL)
                {
                    modelAnim->m_anmObjTexSrtRes->Destroy();
                }

                modelAnim->m_anmObjTexSrtRes = anmObj;
            }
        }
}

inline void customsetTexSortAnim2(u8 animId,nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmTexSrtNumEntries()) {
        customsetTexSortAnim(animId,model, modelAnim,heap);
    }
}


inline void customsetColorAnim(u8 animId,nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
        int instanceSize;
        nw4r::g3d::ResAnmClr anim = fn_8018DAE8(&modelAnim->m_resFile, (u32)animId);

        if (anim.IsValid())
        {
            MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
            nw4r::g3d::AnmObjMatClrRes* anmObj = nw4r::g3d::AnmObjMatClrRes::Construct(allocator, &instanceSize, anim, model, false);
            if (anmObj != NULL)
            {
                anmObj->Bind(model);

                if (modelAnim->m_anmObjMatClrRes != NULL)
                {
                    modelAnim->m_anmObjMatClrRes->Destroy();
                }

                modelAnim->m_anmObjMatClrRes = anmObj;
            }
        }
}

inline void customsetColorAnim2(u8 animId,nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmClrNumEntries()) {
        customsetColorAnim(animId,model, modelAnim,heap);
    }
}

extern "C" void fn_52_3DBC(Object* self, u8 index, int loop, int force, float* frameCount) {
    using namespace nw4r::g3d;
    if (self->index == index && !force)
        return;
    ScnMdl* scene = *self->models;
    if (!scene)
        return;
    gfModelAnimation* animation = *self->animations;
    if (!animation)
        return;
    ResMdl model = scene->m_resMdl;
    if (!model.IsValid())
        return;
    animation->unbindNodeAnim(scene);
    animation->unbindVisibleAnim(scene);
    animation->unbindTexAnim(scene);
    animation->unbindTexSrtAnim(scene);
    animation->unbindMatColAnim(scene);
    self->index = index;
    if (index >= 5)
        return;
    {
        u32 count = animation->m_resFile.GetResAnmChrNumEntries();
        if ((count << __cntlzw(count ^ index)) >> 31)
            customsetChrAnim2(index, model, animation, (Heaps::HeapType)15);
    }
    {
        u32 count = animation->m_resFile.GetResAnmVisNumEntries();
        if ((count << __cntlzw(count ^ index)) >> 31)
            customsetVisibilityAnim2(index, model, animation, (Heaps::HeapType)15);
    }
    {
        u32 count = animation->m_resFile.GetResAnmTexPatNumEntries();
        if ((count << __cntlzw(count ^ index)) >> 31)
            customsetTexPatAnim2(index, model, animation, (Heaps::HeapType)15);
    }
    {
        u32 count = animation->m_resFile.GetResAnmTexSrtNumEntries();
        if ((count << __cntlzw(count ^ index)) >> 31)
            customsetTexSortAnim2(index, model, animation, (Heaps::HeapType)15);
    }
    {
        u32 count = animation->m_resFile.GetResAnmClrNumEntries();
        if ((count << __cntlzw(count ^ index)) >> 31)
            customsetColorAnim2(index, model, animation, (Heaps::HeapType)15);
    }
    gfModelAnimation::bind(scene, animation);
    setFrame__16gfModelAnimationFd(animation, lbl_52_rodata_B8);
    animation->setUpdateRate(lbl_52_rodata_C0);
    setLoop__16gfModelAnimationFd(animation, loop);
    if (frameCount)
        *frameCount = getFrameCount__16gfModelAnimationFd(animation);
}

#include <gf/gf_model.h>
#pragma force_active on

struct gfModelHolder {
    char pad0[0x44];
    nw4r::g3d::ScnMdl** m_scnMdls;
    gfModelAnimation** m_modelAnims;
    char pad1[0x15C - 0x4C];
    u8 m_animId;
};

extern "C" {
void setLoop__16gfModelAnimationFd(gfModelAnimation* self, bool loop);
void setFrame__16gfModelAnimationFd(gfModelAnimation* self, double frame);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation* self);
nw4r::g3d::ResAnmChr fn_8018D6D8(nw4r::g3d::ResFile* file, u32 index);
nw4r::g3d::ResAnmVis fn_8018D8E0(nw4r::g3d::ResFile* file, u32 index);
nw4r::g3d::ResAnmTexPat fn_8018DCF0(nw4r::g3d::ResFile* file, u32 index);
nw4r::g3d::ResAnmTexSrt fn_8018DEF8(nw4r::g3d::ResFile* file, u32 index);
nw4r::g3d::ResAnmClr fn_8018DAE8(nw4r::g3d::ResFile* file, u32 index);
}

extern const f32 lbl_66_rodata_2A0;
extern const f32 lbl_66_rodata_2A4;

static inline void animChrH(u8 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    int instanceSize;
    nw4r::g3d::ResAnmChr anim = fn_8018D6D8(&modelAnim->m_resFile, (u32)animId);
    MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
    if (anim.IsValid()) {
        nw4r::g3d::AnmObjChrRes* anmObj = nw4r::g3d::AnmObjChrRes::Construct(allocator, &instanceSize, anim, model, false);
        if (anmObj != NULL) {
            anmObj->Bind(model);
            if (modelAnim->m_anmObjChrRes != NULL) {
                modelAnim->m_anmObjChrRes->Destroy();
            }
            modelAnim->m_anmObjChrRes = anmObj;
        }
    }
}

static inline void animVisH(u8 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    int instanceSize;
    nw4r::g3d::ResAnmVis anim = fn_8018D8E0(&modelAnim->m_resFile, (u32)animId);
    MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
    if (anim.IsValid()) {
        nw4r::g3d::AnmObjVisRes* anmObj = nw4r::g3d::AnmObjVisRes::Construct(allocator, &instanceSize, anim, model);
        if (anmObj != NULL) {
            anmObj->Bind(model);
            if (modelAnim->m_anmObjVisRes != NULL) {
                modelAnim->m_anmObjVisRes->Destroy();
            }
            modelAnim->m_anmObjVisRes = anmObj;
        }
    }
}

static inline void animTexPatH(u8 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    int instanceSize;
    nw4r::g3d::ResAnmTexPat anim = fn_8018DCF0(&modelAnim->m_resFile, (u32)animId);
    if (anim.IsValid()) {
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
        nw4r::g3d::AnmObjTexPatRes* anmObj = nw4r::g3d::AnmObjTexPatRes::Construct(allocator, &instanceSize, anim, model, false);
        if (anmObj != NULL) {
            anmObj->Bind(model);
            if (modelAnim->m_anmObjTexPatRes != NULL) {
                modelAnim->m_anmObjTexPatRes->Destroy();
            }
            modelAnim->m_anmObjTexPatRes = anmObj;
        }
    }
}

static inline void animTexSrtH(u8 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    int instanceSize;
    nw4r::g3d::ResAnmTexSrt anim = fn_8018DEF8(&modelAnim->m_resFile, (u32)animId);
    if (anim.IsValid()) {
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
        nw4r::g3d::AnmObjTexSrtRes* anmObj = nw4r::g3d::AnmObjTexSrtRes::Construct(allocator, &instanceSize, anim, model, false);
        if (anmObj != NULL) {
            anmObj->Bind(model);
            if (modelAnim->m_anmObjTexSrtRes != NULL) {
                modelAnim->m_anmObjTexSrtRes->Destroy();
            }
            modelAnim->m_anmObjTexSrtRes = anmObj;
        }
    }
}

static inline void animClrH(u8 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    int instanceSize;
    nw4r::g3d::ResAnmClr anim = fn_8018DAE8(&modelAnim->m_resFile, (u32)animId);
    if (anim.IsValid()) {
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
        nw4r::g3d::AnmObjMatClrRes* anmObj = nw4r::g3d::AnmObjMatClrRes::Construct(allocator, &instanceSize, anim, model, false);
        if (anmObj != NULL) {
            anmObj->Bind(model);
            if (modelAnim->m_anmObjMatClrRes != NULL) {
                modelAnim->m_anmObjMatClrRes->Destroy();
            }
            modelAnim->m_anmObjMatClrRes = anmObj;
        }
    }
}

static inline void animChr2H(u8 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmChrNumEntries()) {
        animChrH(animId, model, modelAnim, heap);
    }
}

static inline void animVis2H(u8 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmVisNumEntries()) {
        animVisH(animId, model, modelAnim, heap);
    }
}

static inline void animTexPat2H(u8 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmTexPatNumEntries()) {
        animTexPatH(animId, model, modelAnim, heap);
    }
}

static inline void animTexSrt2H(u8 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmTexSrtNumEntries()) {
        animTexSrtH(animId, model, modelAnim, heap);
    }
}

static inline void animClr2H(u8 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmClrNumEntries()) {
        animClrH(animId, model, modelAnim, heap);
    }
}

extern "C" void fn_66_131F8(gfModelHolder* self, u8 animId, bool loop, s32 force, f32* outFrame) {
    nw4r::g3d::ScnMdl* scnMdl;
    gfModelAnimation* anim;
    nw4r::g3d::ResMdl resMdl;
    if (self->m_animId != animId || force != 0) {
        scnMdl = self->m_scnMdls[0];
        if (scnMdl != NULL) {
            anim = self->m_modelAnims[0];
            if (anim != NULL) {
                resMdl = *(nw4r::g3d::ResMdl*)((char*)scnMdl + 0xE8);
                if (resMdl.IsValid()) {
                    anim->unbindNodeAnim(scnMdl);
                    anim->unbindVisibleAnim(scnMdl);
                    anim->unbindTexAnim(scnMdl);
                    anim->unbindTexSrtAnim(scnMdl);
                    anim->unbindMatColAnim(scnMdl);
                    self->m_animId = animId;
                    if (animId < 3) {
                        bool c0 = anim->m_resFile.GetResAnmChrNumEntries() > animId;
                        if (c0) {
                            animChr2H(animId, resMdl, anim, (Heaps::HeapType)15);
                        }
                        bool c1 = anim->m_resFile.GetResAnmVisNumEntries() > animId;
                        if (c1) {
                            animVis2H(animId, resMdl, anim, (Heaps::HeapType)15);
                        }
                        bool c2 = anim->m_resFile.GetResAnmTexPatNumEntries() > animId;
                        if (c2) {
                            animTexPat2H(animId, resMdl, anim, (Heaps::HeapType)15);
                        }
                        bool c3 = anim->m_resFile.GetResAnmTexSrtNumEntries() > animId;
                        if (c3) {
                            animTexSrt2H(animId, resMdl, anim, (Heaps::HeapType)15);
                        }
                        bool c4 = anim->m_resFile.GetResAnmClrNumEntries() > animId;
                        if (c4) {
                            animClr2H(animId, resMdl, anim, (Heaps::HeapType)15);
                        }
                        gfModelAnimation::bind(scnMdl, anim);
                        setFrame__16gfModelAnimationFd(anim, lbl_66_rodata_2A0);
                        anim->setUpdateRate(lbl_66_rodata_2A4);
                        setLoop__16gfModelAnimationFd(anim, loop);
                        if (outFrame != NULL) {
                            *outFrame = (f32)getFrameCount__16gfModelAnimationFd(anim);
                        }
                    }
                }
            }
        }
    }
}

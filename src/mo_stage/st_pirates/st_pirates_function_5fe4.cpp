#include <gf/gf_model.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on

struct ModelSlot {
    char pad0[0xE8];
    void* resMdl;
};

struct FnObj {
    char pad0[0x44];
    ModelSlot** models;
    gfModelAnimation** anims;
    char pad1[0x130];
    u8 state;
    char pad2[0x1B];
    u8 flag198;
    char pad3[0x7];
    u8 flag1A0;
};

extern "C" {
nw4r::g3d::ResAnmVis fn_8018D8E0(gfModelAnimation* self, u32 index);
nw4r::g3d::ResAnmChr fn_8018D6D8(gfModelAnimation* self, u32 index);
nw4r::g3d::ResAnmTexPat fn_8018DCF0(gfModelAnimation* self, u32 index);
nw4r::g3d::ResAnmTexSrt fn_8018DEF8(gfModelAnimation* self, u32 index);
nw4r::g3d::ResAnmClr fn_8018DAE8(gfModelAnimation* self, u32 index);
void setFrame__16gfModelAnimationFd(gfModelAnimation* self, f32 frame);
void setLoop__16gfModelAnimationFd(gfModelAnimation* self, bool loop);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation* self);
}

extern f32 lbl_52_rodata_12C;
extern f32 lbl_52_rodata_E8;

static inline void setVisAnimAt(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    int instanceSize;
    nw4r::g3d::ResAnmVis anim = fn_8018D8E0(modelAnim, animId);
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

static inline void setVisAnim2(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmVisNumEntries()) {
        setVisAnimAt(animId, model, modelAnim, heap);
    }
}

static inline void setChrAnimAt(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    int instanceSize;
    nw4r::g3d::ResAnmChr anim = fn_8018D6D8(modelAnim, animId);
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

static inline void setChrAnim2(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmChrNumEntries()) {
        setChrAnimAt(animId, model, modelAnim, heap);
    }
}

static inline void setTexPatAnimAt(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    int instanceSize;
    nw4r::g3d::ResAnmTexPat anim = fn_8018DCF0(modelAnim, animId);
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

static inline void setTexPatAnim2(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmTexPatNumEntries()) {
        setTexPatAnimAt(animId, model, modelAnim, heap);
    }
}

static inline void setTexSrtAnimAt(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    int instanceSize;
    nw4r::g3d::ResAnmTexSrt anim = fn_8018DEF8(modelAnim, animId);
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

static inline void setTexSrtAnim2(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmTexSrtNumEntries()) {
        setTexSrtAnimAt(animId, model, modelAnim, heap);
    }
}

static inline void setClrAnimAt(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    int instanceSize;
    nw4r::g3d::ResAnmClr anim = fn_8018DAE8(modelAnim, animId);
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

static inline void setClrAnim2(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmClrNumEntries()) {
        setClrAnimAt(animId, model, modelAnim, heap);
    }
}

extern "C" void fn_52_5FE4(FnObj* self, u32 state, bool loop, s32 force, f32* outFrame) {
    nw4r::g3d::ScnMdl* scn;
    if (self->state != state || force != 0) {
        ModelSlot* slot = *self->models;
        if (slot != NULL) {
            gfModelAnimation* anim = *self->anims;
            if (anim != NULL) {
                if (slot->resMdl != NULL) {
                    nw4r::g3d::ResMdl resMdl(slot->resMdl);
                    scn = (nw4r::g3d::ScnMdl*)slot;
                    anim->unbindNodeAnim(scn);
                    anim->unbindVisibleAnim(scn);
                    anim->unbindTexAnim(scn);
                    anim->unbindTexSrtAnim(scn);
                    anim->unbindMatColAnim(scn);
                    self->state = state;
                    if (state < 0x14) {
                        switch (state) {
                        case 0x10: {
                            bool hasVis = 0 < anim->m_resFile.GetResAnmVisNumEntries();
                            if (hasVis) {
                                setVisAnim2(0, resMdl, anim, Heaps::StageInstance);
                            }
                            break;
                        }
                        }
                        bool hasChr = state < anim->m_resFile.GetResAnmChrNumEntries();
                        if (hasChr) {
                            setChrAnim2(state, resMdl, anim, Heaps::StageInstance);
                        }
                        bool hasTexPat = state < anim->m_resFile.GetResAnmTexPatNumEntries();
                        if (hasTexPat) {
                            setTexPatAnim2(state, resMdl, anim, Heaps::StageInstance);
                        }
                        bool hasTexSrt = state < anim->m_resFile.GetResAnmTexSrtNumEntries();
                        if (hasTexSrt) {
                            setTexSrtAnim2(state, resMdl, anim, Heaps::StageInstance);
                        }
                        bool hasClr = state < anim->m_resFile.GetResAnmClrNumEntries();
                        if (hasClr) {
                            setClrAnim2(state, resMdl, anim, Heaps::StageInstance);
                        }
                        gfModelAnimation::bind(scn, anim);
                        setFrame__16gfModelAnimationFd(anim, lbl_52_rodata_E8);
                        anim->setUpdateRate(lbl_52_rodata_12C);
                        setLoop__16gfModelAnimationFd(anim, loop);
                        if (outFrame != NULL) {
                            *outFrame = getFrameCount__16gfModelAnimationFd(anim);
                        }
                        self->flag198 = 0;
                        self->flag1A0 = 0;
                    }
                }
            }
        }
    }
}

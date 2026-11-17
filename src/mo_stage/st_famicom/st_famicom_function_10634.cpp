#include <gf/gf_model.h>
#include <gf/gf_heap_manager.h>
#include <types.h>

#pragma force_active on

extern "C" {
int __cntlzw(unsigned int);

void* fn_8018D6D8(void*, u32);
void* fn_8018D8E0(void*, u32);
nw4r::g3d::ResAnmClr fn_8018DAE8(void*, u32);
void* fn_8018DCF0(void*, u32);
void* fn_8018DEF8(void*, u32);

nw4r::g3d::AnmObjChrRes* Construct__Q34nw4r3g3d12AnmObjChrResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmChrQ34nw4r3g3d6ResMdlb(MEMAllocator*, int*, nw4r::g3d::ResAnmChr*, nw4r::g3d::ResMdl*, bool);
nw4r::g3d::AnmObjVisRes* Construct__Q34nw4r3g3d12AnmObjVisResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmVisQ34nw4r3g3d6ResMdl(MEMAllocator*, int*, nw4r::g3d::ResAnmVis*, nw4r::g3d::ResMdl*);
nw4r::g3d::AnmObjTexPatRes* Construct__Q34nw4r3g3d15AnmObjTexPatResFP12MEMAllocatorPiQ34nw4r3g3d12ResAnmTexPatQ34nw4r3g3d6ResMdlb(MEMAllocator*, int*, nw4r::g3d::ResAnmTexPat*, nw4r::g3d::ResMdl*, bool);
nw4r::g3d::AnmObjTexSrtRes* Construct__Q34nw4r3g3d15AnmObjTexSrtResFP12MEMAllocatorPiQ34nw4r3g3d12ResAnmTexSrtQ34nw4r3g3d6ResMdlb(MEMAllocator*, int*, nw4r::g3d::ResAnmTexSrt*, nw4r::g3d::ResMdl*, bool);
nw4r::g3d::AnmObjMatClrRes* Construct__Q34nw4r3g3d15AnmObjMatClrResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmClrQ34nw4r3g3d6ResMdlb(MEMAllocator*, int*, nw4r::g3d::ResAnmClr*, nw4r::g3d::ResMdl*, bool);

void setFrame__16gfModelAnimationFd(gfModelAnimation*, f32);
void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
void setUpdateRate__16gfModelAnimationFf(gfModelAnimation*, f32);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
void bind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdlP16gfModelAnimation(nw4r::g3d::ScnMdl*, gfModelAnimation*);

extern const f32 lbl_68_rodata_198;
extern const f32 lbl_68_rodata_19C;
extern const double lbl_68_rodata_1B8;
}

class BindObject {
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
    virtual void bind(nw4r::g3d::ResMdl*);
};

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad2[0x158 - 0x4C];
    u8 current;
};

extern "C" void fn_68_10634(
    Object* self, u8 index, bool loop, bool force, f32* endFrame
) {
    int sizeChr;
    void* animChr;
    void* modelChr;
    void* bindChr;
    int sizeVis;
    void* animVis;
    void* modelVis;
    void* bindVis;
    int sizePat;
    void* animPat;
    void* modelPat;
    void* bindPat;
    int sizeSrt;
    void* animSrt;
    void* modelSrt;
    void* bindSrt;
    int sizeClr;
    void* animClr;
    void* modelClr;
    void* bindClr;

    if (self->current == index && !force)
        return;

    nw4r::g3d::ScnMdl* model = *self->models;
    if (!model)
        return;

    gfModelAnimation* animation = *self->animations;
    if (!animation)
        return;

    nw4r::g3d::ResMdl modelRes = model->m_resMdl;
    if (!modelRes.IsValid())
        return;

    animation->unbindNodeAnim(model);
    animation->unbindVisibleAnim(model);
    animation->unbindTexAnim(model);
    animation->unbindTexSrtAnim(model);
    animation->unbindMatColAnim(model);

    self->current = index;

    switch ((s32)index) {
    case 13: index = 1; break;
    case 14: index = 5; break;
    case 15: index = 9; break;
    }

    if (index >= 12)
        return;

    u32 count = animation->m_resFile.GetResAnmChrNumEntries();
    if (((count << __cntlzw(count ^ index)) >> 31) &&
        (index < animation->m_resFile.GetResAnmChrNumEntries())) {
        void* anim = fn_8018D6D8(&animation->m_resFile, index);
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)0xF);
        if (anim) {
            modelChr = *(void**)&modelRes;
            animChr = anim;
            nw4r::g3d::AnmObjChrRes* obj = Construct__Q34nw4r3g3d12AnmObjChrResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmChrQ34nw4r3g3d6ResMdlb(
                allocator, &sizeChr, (nw4r::g3d::ResAnmChr*)&animChr,
                (nw4r::g3d::ResMdl*)&modelChr, false);
            if (obj) {
                bindChr = *(void**)&modelRes;
                ((BindObject*)obj)->bind((nw4r::g3d::ResMdl*)&bindChr);
                if (animation->m_anmObjChrRes)
                    animation->m_anmObjChrRes->Destroy();
                animation->m_anmObjChrRes = obj;
            }
        }
    }

    count = animation->m_resFile.GetResAnmVisNumEntries();
    if (((count << __cntlzw(count ^ index)) >> 31) &&
        (index < animation->m_resFile.GetResAnmVisNumEntries())) {
        void* anim = fn_8018D8E0(&animation->m_resFile, index);
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)0xF);
        if (anim) {
            modelVis = *(void**)&modelRes;
            animVis = anim;
            nw4r::g3d::AnmObjVisRes* obj = Construct__Q34nw4r3g3d12AnmObjVisResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmVisQ34nw4r3g3d6ResMdl(
                allocator, &sizeVis, (nw4r::g3d::ResAnmVis*)&animVis,
                (nw4r::g3d::ResMdl*)&modelVis);
            if (obj) {
                bindVis = *(void**)&modelRes;
                ((BindObject*)obj)->bind((nw4r::g3d::ResMdl*)&bindVis);
                if (animation->m_anmObjVisRes)
                    animation->m_anmObjVisRes->Destroy();
                animation->m_anmObjVisRes = obj;
            }
        }
    }

    count = animation->m_resFile.GetResAnmTexPatNumEntries();
    if (((count << __cntlzw(count ^ index)) >> 31) &&
        (index < animation->m_resFile.GetResAnmTexPatNumEntries())) {
        void* anim = fn_8018DCF0(&animation->m_resFile, index);
        if (anim) {
            MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)0xF);
            modelPat = *(void**)&modelRes;
            animPat = anim;
            nw4r::g3d::AnmObjTexPatRes* obj = Construct__Q34nw4r3g3d15AnmObjTexPatResFP12MEMAllocatorPiQ34nw4r3g3d12ResAnmTexPatQ34nw4r3g3d6ResMdlb(
                allocator, &sizePat, (nw4r::g3d::ResAnmTexPat*)&animPat,
                (nw4r::g3d::ResMdl*)&modelPat, false);
            if (obj) {
                bindPat = *(void**)&modelRes;
                ((BindObject*)obj)->bind((nw4r::g3d::ResMdl*)&bindPat);
                if (animation->m_anmObjTexPatRes)
                    animation->m_anmObjTexPatRes->Destroy();
                animation->m_anmObjTexPatRes = obj;
            }
        }
    }

    count = animation->m_resFile.GetResAnmTexSrtNumEntries();
    if (((count << __cntlzw(count ^ index)) >> 31) &&
        (index < animation->m_resFile.GetResAnmTexSrtNumEntries())) {
        void* anim = fn_8018DEF8(&animation->m_resFile, index);
        if (anim) {
            MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)0xF);
            modelSrt = *(void**)&modelRes;
            animSrt = anim;
            nw4r::g3d::AnmObjTexSrtRes* obj = Construct__Q34nw4r3g3d15AnmObjTexSrtResFP12MEMAllocatorPiQ34nw4r3g3d12ResAnmTexSrtQ34nw4r3g3d6ResMdlb(
                allocator, &sizeSrt, (nw4r::g3d::ResAnmTexSrt*)&animSrt,
                (nw4r::g3d::ResMdl*)&modelSrt, false);
            if (obj) {
                bindSrt = *(void**)&modelRes;
                ((BindObject*)obj)->bind((nw4r::g3d::ResMdl*)&bindSrt);
                if (animation->m_anmObjTexSrtRes)
                    animation->m_anmObjTexSrtRes->Destroy();
                animation->m_anmObjTexSrtRes = obj;
            }
        }
    }

    count = animation->m_resFile.GetResAnmClrNumEntries();
    if (((count << __cntlzw(count ^ index)) >> 31) &&
        (index < animation->m_resFile.GetResAnmClrNumEntries())) {
        nw4r::g3d::ResAnmClr anim = fn_8018DAE8(&animation->m_resFile, index);
        if (anim.IsValid()) {
            MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)0xF);
            modelClr = *(void**)&modelRes;
            animClr = *(void**)&anim;
            nw4r::g3d::AnmObjMatClrRes* obj = Construct__Q34nw4r3g3d15AnmObjMatClrResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmClrQ34nw4r3g3d6ResMdlb(
                allocator, &sizeClr, (nw4r::g3d::ResAnmClr*)&animClr,
                (nw4r::g3d::ResMdl*)&modelClr, false);
            if (obj) {
                bindClr = *(void**)&modelRes;
                ((BindObject*)obj)->bind((nw4r::g3d::ResMdl*)&bindClr);
                if (animation->m_anmObjMatClrRes)
                    animation->m_anmObjMatClrRes->Destroy();
                animation->m_anmObjMatClrRes = obj;
            }
        }
    }

    bind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdlP16gfModelAnimation(model, animation);
    setFrame__16gfModelAnimationFd(animation, lbl_68_rodata_19C);
    setUpdateRate__16gfModelAnimationFf(animation, lbl_68_rodata_198);
    setLoop__16gfModelAnimationFd(animation, loop);

    if (endFrame)
        *endFrame = (f32)getFrameCount__16gfModelAnimationFd(animation);
}

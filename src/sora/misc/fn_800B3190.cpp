#include <gf/gf_model.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on

struct SrcRes {
    u32 pad0;
    u32 resFile;
    u32 resMdl;
};

struct Holder {
    u32 pad0;
    u32 resFile;
    u32 resMdl;
    nw4r::g3d::ScnMdl* scnMdl0;
    nw4r::g3d::ScnMdl* scnMdl1;
    gfModelAnimation* anim;
};

extern "C" {
int fn_8018E458(nw4r::g3d::ResFile* res);
int fn_8018E4A4(nw4r::g3d::ResFile* res);
int fn_8018E4F0(nw4r::g3d::ResFile* res);
int fn_8018E40C(nw4r::g3d::ResFile* res);
int fn_8018E53C(nw4r::g3d::ResFile* res);
void fn_801AAFF0(void* scn, int v);
void fn_801AB014(void* scn, int v);
nw4r::g3d::ScnMdl* fn_801B0B40(MEMAllocator* alloc, u32* size, nw4r::g3d::ResMdl* mdl, u32 flags, int one, void (*cb)(void));
void fn_801B0A28(void);
void* __nw__FUlQ25Heaps8HeapType(u32, Heaps::HeapType);
void* __ct__16gfModelAnimationFd(void*, void*, void*, int, int, Heaps::HeapType);
void setFrame__16gfModelAnimationFd(void*, double);
extern const f32 lbl_805A2200;

void fn_800B3190(Holder* self, SrcRes* src, int arg2, u32 animIndex, Heaps::HeapType heap) {
    u32 sp14;
    u32 sp10;
    void* spC;
    void* sp8;
    u32 flags;

    MEMAllocator* alloc = gfHeapManager::getMEMAllocator(heap);
    flags = 0;
    self->resFile = src->resFile;
    self->resMdl = src->resMdl;
    if (fn_8018E458((nw4r::g3d::ResFile*)&self->resFile) != 0) {
        flags |= 0x10b;
    }
    if (fn_8018E4A4((nw4r::g3d::ResFile*)&self->resFile) != 0) {
        flags |= 0x3;
    }
    if (fn_8018E4F0((nw4r::g3d::ResFile*)&self->resFile) != 0) {
        flags |= 0x204;
    }
    if (fn_8018E40C((nw4r::g3d::ResFile*)&self->resFile) != 0) {
        flags |= 0x40;
    }
    if (fn_8018E53C((nw4r::g3d::ResFile*)&self->resFile) != 0) {
        flags |= 0x7000;
    }
    sp10 = self->resMdl;
    nw4r::g3d::ScnMdl* scn = fn_801B0B40(alloc, &sp14, (nw4r::g3d::ResMdl*)&sp10, flags | 0x10b, 1, fn_801B0A28);
    if (arg2 != 0) {
        fn_801AAFF0(scn, arg2);
        fn_801AB014(scn, arg2);
    }
    gfModelAnimation* anim = (gfModelAnimation*)__nw__FUlQ25Heaps8HeapType(0x20, heap);
    if (anim != 0) {
        spC = (void*)self->resMdl;
        sp8 = (void*)src->resFile;
        anim = (gfModelAnimation*)__ct__16gfModelAnimationFd((void*)anim, &sp8, &spC, 1, (int)animIndex, heap);
    }
    gfModelAnimation::bind((nw4r::g3d::ScnMdl*)scn, anim);
    self->scnMdl0 = scn;
    f32 frame = lbl_805A2200;
    self->scnMdl1 = scn;
    self->anim = anim;
    anim->_spacer[0] = 0;
    setFrame__16gfModelAnimationFd(anim, frame);
}
}
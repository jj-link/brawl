#include <stdio.h>
#include <gf/gf_model.h>
#include <gf/gf_heap_manager.h>
#include <nw4r/g3d/g3d_anmchr.h>
#include <nw4r/g3d/g3d_anmvis.h>
#include <nw4r/g3d/g3d_anmtexpat.h>
#include <nw4r/g3d/g3d_anmtexsrt.h>
#include <nw4r/g3d/g3d_anmclr.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_8018D5D4(void* self, char* name);
void* fn_8018D7DC(void* self, char* name);
void* fn_8018D9E4(void* self, char* name);
void* fn_8018DBEC(void* self, char* name);
void* fn_8018DDF4(void* self, char* name);
void fn_800B458C();
extern int lbl_8059C648;
extern int lbl_8059DF20;
extern const f32 lbl_805A2200;
extern const f32 lbl_805A2204;
}

struct MuAnimOwner {
    char pad0[4];
    char unk4[4];
    void* unk8;
    char pad0C[4];
    nw4r::g3d::ScnMdl* unk10;
    gfModelAnimation* unk14;
    char pad18[0x3C];
    Heaps::HeapType unk54;
};

static inline void applyChrRes(nw4r::g3d::ResMdl model, nw4r::g3d::ResAnmChr anim, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    int instanceSize;
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

static inline void applyVisRes(nw4r::g3d::ResMdl model, nw4r::g3d::ResAnmVis anim, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    int instanceSize;
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

static inline void applyTexPatRes(nw4r::g3d::ResMdl model, nw4r::g3d::ResAnmTexPat anim, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    int instanceSize;
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

static inline void applyTexSrtRes(nw4r::g3d::ResMdl model, nw4r::g3d::ResAnmTexSrt anim, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    int instanceSize;
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

static inline void applyClrRes(nw4r::g3d::ResMdl model, nw4r::g3d::ResAnmClr anim, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    int instanceSize;
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

extern "C" void fn_800B5854(MuAnimOwner* self, s32 animIndex, u32 flags, s32 blend, s32 doFrame) {
    char buf[0x40];
    s32 nameOfs = *(s32*)((char*)self->unk8 + 0x3C);
    char* name = (nameOfs != 0) ? (char*)self->unk8 + nameOfs : NULL;
    sprintf(buf, (char*)&lbl_8059DF20, name, animIndex);
    f32 rate = (blend != 0) ? lbl_805A2204 : lbl_805A2200;

    if (flags & 1) {
        nw4r::g3d::ResAnmChr chrData(fn_8018D5D4(self->unk4, buf));
        if (chrData.IsValid()) {
            self->unk14->unbindNodeAnim(self->unk10);
            nw4r::g3d::ResMdl mdl(self->unk8);
            applyChrRes(mdl, chrData, self->unk14, self->unk54);
            self->unk14->bindNodeAnim(self->unk10);
            nw4r::g3d::AnmObjChrRes* chr = self->unk14->m_anmObjChrRes;
            s32 idx = *(s32*)(*(char**)((char*)chr + 0x2C) + 0x20);
            *(void**)((char*)chr + 0x28) = (idx == 0) ? (void*)fn_800B458C : ((void**)&lbl_8059C648)[idx];
            nw4r::g3d::ScnMdl* scn = self->unk10;
            scn->SetScnObjOption(2, 0);
            scn->SetScnObjOption(5, 0);
        }
        self->unk14->m_anmObjChrRes->SetUpdateRate(rate);
        if (doFrame != 0) {
            if (lbl_805A2200 != self->unk14->m_anmObjChrRes->GetFrame()) {
                nw4r::g3d::ScnMdl* scn = self->unk10;
                scn->SetScnObjOption(2, 0);
                scn->SetScnObjOption(5, 0);
            }
            self->unk14->m_anmObjChrRes->SetFrame(lbl_805A2200);
        }
    }

    if (flags & 2) {
        void* visData = fn_8018D7DC(self->unk4, buf);
        if (visData != NULL) {
            self->unk14->unbindVisibleAnim(self->unk10);
            nw4r::g3d::ResMdl mdl(self->unk8);
            applyVisRes(mdl, nw4r::g3d::ResAnmVis(visData), self->unk14, self->unk54);
            self->unk14->bindVisibleAnim(self->unk10);
            nw4r::g3d::AnmObjVisRes* vis = self->unk14->m_anmObjVisRes;
            s32 idx = *(s32*)(*(char**)((char*)vis + 0x2C) + 0x20);
            *(void**)((char*)vis + 0x28) = (idx == 0) ? (void*)fn_800B458C : ((void**)&lbl_8059C648)[idx];
            nw4r::g3d::ScnMdl* scn = self->unk10;
            scn->SetScnObjOption(2, 0);
            scn->SetScnObjOption(5, 0);
        }
        self->unk14->m_anmObjVisRes->SetUpdateRate(rate);
        if (doFrame != 0) {
            if (lbl_805A2200 != self->unk14->m_anmObjVisRes->GetFrame()) {
                nw4r::g3d::ScnMdl* scn = self->unk10;
                scn->SetScnObjOption(2, 0);
                scn->SetScnObjOption(5, 0);
            }
            self->unk14->m_anmObjVisRes->SetFrame(lbl_805A2200);
        }
    }

    if (flags & 4) {
        void* texData = fn_8018DBEC(self->unk4, buf);
        if (texData != NULL) {
            self->unk14->unbindTexAnim(self->unk10);
            Heaps::HeapType heap = self->unk54;
            nw4r::g3d::ResMdl mdl(self->unk8);
            applyTexPatRes(mdl, nw4r::g3d::ResAnmTexPat(texData), self->unk14, heap);
            self->unk14->bindTexAnim(self->unk10);
            nw4r::g3d::AnmObjTexPatRes* tp = self->unk14->m_anmObjTexPatRes;
            s32 idx = *(s32*)(*(char**)((char*)tp + 0x2C) + 0x34);
            *(void**)((char*)tp + 0x28) = (idx == 0) ? (void*)fn_800B458C : ((void**)&lbl_8059C648)[idx];
            nw4r::g3d::ScnMdl* scn = self->unk10;
            scn->SetScnObjOption(3, 0);
        }
        self->unk14->m_anmObjTexPatRes->SetUpdateRate(rate);
        if (doFrame != 0) {
            if (lbl_805A2200 != self->unk14->m_anmObjTexPatRes->GetFrame()) {
                nw4r::g3d::ScnMdl* scn = self->unk10;
                scn->SetScnObjOption(3, 0);
            }
            self->unk14->m_anmObjTexPatRes->SetFrame(lbl_805A2200);
        }
    }

    if (flags & 8) {
        void* srtData = fn_8018DDF4(self->unk4, buf);
        if (srtData != NULL) {
            self->unk14->unbindTexSrtAnim(self->unk10);
            Heaps::HeapType heap = self->unk54;
            nw4r::g3d::ResMdl mdl(self->unk8);
            applyTexSrtRes(mdl, nw4r::g3d::ResAnmTexSrt(srtData), self->unk14, heap);
            self->unk14->bindTexSrtAnim(self->unk10);
            nw4r::g3d::AnmObjTexSrtRes* srt = self->unk14->m_anmObjTexSrtRes;
            s32 idx = *(s32*)(*(char**)((char*)srt + 0x2C) + 0x24);
            *(void**)((char*)srt + 0x28) = (idx == 0) ? (void*)fn_800B458C : ((void**)&lbl_8059C648)[idx];
            nw4r::g3d::ScnMdl* scn = self->unk10;
            scn->SetScnObjOption(3, 0);
        }
        self->unk14->m_anmObjTexSrtRes->SetUpdateRate(rate);
        if (doFrame != 0) {
            if (lbl_805A2200 != self->unk14->m_anmObjTexSrtRes->GetFrame()) {
                nw4r::g3d::ScnMdl* scn = self->unk10;
                scn->SetScnObjOption(3, 0);
            }
            self->unk14->m_anmObjTexSrtRes->SetFrame(lbl_805A2200);
        }
    }

    if (flags & 0x10) {
        flags = (u32)fn_8018D9E4(self->unk4, buf);
        if (flags != 0) {
            self->unk14->unbindMatColAnim(self->unk10);
            Heaps::HeapType heap = self->unk54;
            nw4r::g3d::ResMdl mdl(self->unk8);
            applyClrRes(mdl, nw4r::g3d::ResAnmClr((void*)flags), self->unk14, heap);
            self->unk14->bindMatColAnim(self->unk10);
            nw4r::g3d::AnmObjMatClrRes* clr = self->unk14->m_anmObjMatClrRes;
            s32 idx = *(s32*)(*(char**)((char*)clr + 0x2C) + 0x20);
            *(void**)((char*)clr + 0x28) = (idx == 0) ? (void*)fn_800B458C : ((void**)&lbl_8059C648)[idx];
            nw4r::g3d::ScnMdl* scn = self->unk10;
            scn->SetScnObjOption(3, 0);
        }
        self->unk14->m_anmObjMatClrRes->SetUpdateRate(rate);
        if (doFrame != 0) {
            if (lbl_805A2200 != self->unk14->m_anmObjMatClrRes->GetFrame()) {
                nw4r::g3d::ScnMdl* scn = self->unk10;
                scn->SetScnObjOption(3, 0);
            }
            self->unk14->m_anmObjMatClrRes->SetFrame(lbl_805A2200);
        }
    }
}

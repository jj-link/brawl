#include <gf/gf_model.h>
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
    virtual void slot11(void* a, nw4r::g3d::ScnMdl* b);
    char pad[0xE0];
    void* fE4;
};

class Wrap {
public:
    virtual ~Wrap();
    void* sub;
};

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_801AB078(void*, int);
void fn_801AB0CC(void*, int);
extern unsigned char lbl_80453E40[];
void* fn_8018D174(void*, u32);
void* fn_8018D6D8(void*, u32);
void* fn_8018D8E0(void*, u32);
void* fn_8018DAE8(void*, u32);
void* fn_8018DCF0(void*, u32);
void* fn_8018DEF8(void*, u32);
void* fn_8018E100(void*, u32);
nw4r::g3d::ScnMdl* fn_801B0B40(MEMAllocator*, u32*, nw4r::g3d::ResMdl*, u32, int, void (*)());
void fn_801B0A28();
nw4r::g3d::AnmObjShpRes* fn_8019BC04(MEMAllocator*, int*, nw4r::g3d::ResAnmShp, nw4r::g3d::ResMdl, bool);
}

inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 i) { return ResAnmChr(fn_8018D6D8(this, i)); }
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 i) { return ResAnmVis(fn_8018D8E0(this, i)); }
inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 i) { return ResAnmTexPat(fn_8018DCF0(this, i)); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 i) { return ResAnmTexSrt(fn_8018DEF8(this, i)); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 i) { return fn_8018DAE8(this, i); }
inline nw4r::g3d::ResAnmShp nw4r::g3d::ResFile::GetResAnmShp(int i) { return ResAnmShp(fn_8018E100(this, i)); }

static inline void setChrInner(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    {
        int instanceSize;
        nw4r::g3d::ResAnmChr anim = modelAnim->m_resFile.GetResAnmChr(animId);
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
}
static inline void setChrAnimU(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmChrNumEntries()) setChrInner(animId, model, modelAnim, heap);
}

static inline void setVisInner(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    {
        int instanceSize;
        nw4r::g3d::ResAnmVis anim = modelAnim->m_resFile.GetResAnmVis(animId);
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
}
static inline void setVisAnimU(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmVisNumEntries()) setVisInner(animId, model, modelAnim, heap);
}

static inline void setTexPatInner(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    {
        int instanceSize;
        nw4r::g3d::ResAnmTexPat anim = modelAnim->m_resFile.GetResAnmTexPat(animId);
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
}
static inline void setTexPatAnimU(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmTexPatNumEntries()) setTexPatInner(animId, model, modelAnim, heap);
}

static inline void setTexSrtInner(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    {
        int instanceSize;
        nw4r::g3d::ResAnmTexSrt anim = modelAnim->m_resFile.GetResAnmTexSrt(animId);
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
}
static inline void setTexSrtAnimU(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmTexSrtNumEntries()) setTexSrtInner(animId, model, modelAnim, heap);
}

static inline void setClrInner(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    {
        int instanceSize;
        nw4r::g3d::ResAnmClr anim = modelAnim->m_resFile.GetResAnmClr(animId);
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
}
static inline void setClrAnimU(u32 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmClrNumEntries()) setClrInner(animId, model, modelAnim, heap);
}

static inline void setShpInner(u32 shp, nw4r::g3d::ResMdl m, gfModelAnimation* anim, Heaps::HeapType heap) {
    int instanceSize;
    nw4r::g3d::ResAnmShp anm = anim->m_resFile.GetResAnmShp(shp);
    if (anm.IsValid()) {
        MEMAllocator* a2 = gfHeapManager::getMEMAllocator(heap);
        nw4r::g3d::AnmObjShpRes* anmObj = fn_8019BC04(a2, &instanceSize, anm, m, false);
        if (anmObj != NULL) {
            anmObj->Bind(m);
            if (anim->m_anmObjShpRes != NULL) {
                anmObj->Destroy();
            }
            anim->m_anmObjShpRes = anmObj;
        }
    }
}
static inline void setShpAnimU(u32 shp, nw4r::g3d::ResMdl m, gfModelAnimation* anim, Heaps::HeapType heap) {
    if (shp < anim->m_resFile.GetResAnmShpNumEntries()) setShpInner(shp, m, anim, heap);
}

extern "C" void fn_80064920(nw4r::g3d::ScnMdl** scn, gfModelAnimation** anim, Wrap** wrap, nw4r::g3d::ResFile* res, u32 chr, u32 vis, u32 texPat, u32 texSrt, u32 clr, u32 shp, Object_vptr_0* obj, Heaps::HeapType heap) {
    u32 flags;
    u32 size;
    gfModelAnimation* ga;
    Wrap* w;

    *anim = NULL;
    flags = 0;
    if (res->GetResAnmVisNumEntries() != 0) {
        flags |= 0x40;
    }
    if (res->GetResAnmClrNumEntries() != 0) {
        flags |= 0x108;
    }
    flags |= 3;
    if (res->GetResAnmTexSrtNumEntries() != 0) {
        flags |= 0x204;
    }
    if (res->GetResAnmShpNumEntries() != 0) {
        flags |= 0x7000;
    }
    nw4r::g3d::ResMdl mdl(fn_8018D174(res, 0));
    MEMAllocator* alloc = gfHeapManager::getMEMAllocator(heap);
    *scn = fn_801B0B40(alloc, &size, &mdl, flags, 1, fn_801B0A28);
    if (*scn == NULL) {
        return;
    }

    if (wrap != NULL) {
        w = (Wrap*)__nw__FUlQ25Heaps8HeapType(8, heap);
        if (w != NULL) {
            void* s = (void*)*scn;
            *(void**)w = (void*)lbl_80453E40;
            w->sub = s;
            if (s != NULL) {
                *(int*)((char*)s + 0xD4) = 0;
                fn_801AB078(w->sub, 1);
                fn_801AB078(w->sub, 4);
                fn_801AB0CC(w->sub, 4);
            }
        }
        *wrap = w;
        if (w == NULL) {
            ((nw4r::g3d::G3dObj*)*scn)->Destroy();
            *scn = NULL;
            return;
        }
    }

    ga = (gfModelAnimation*)__nw__FUlQ25Heaps8HeapType(0x20, heap);
    if (ga != NULL) {
        ga->m_resFile = *res;
        ga->_spacer[0] = 1;
        ga->m_anmObjVisRes = NULL;
        ga->m_anmObjChrRes = NULL;
        ga->m_anmObjTexPatRes = NULL;
        ga->m_anmObjTexSrtRes = NULL;
        ga->m_anmObjMatClrRes = NULL;
        ga->m_anmObjShpRes = NULL;
    }
    *anim = ga;
    if (ga == NULL) {
        ((nw4r::g3d::G3dObj*)*scn)->Destroy();
        *scn = NULL;
        if (wrap != NULL) {
            w = *wrap;
            if (w != NULL) {
                delete w;
                *wrap = NULL;
            }
        }
        return;
    }

    { bool has = chr < (*anim)->m_resFile.GetResAnmChrNumEntries(); if (has) { nw4r::g3d::ResMdl m(fn_8018D174(res, 0)); setChrAnimU(chr, m, *anim, heap); } }
    { bool has = vis < (*anim)->m_resFile.GetResAnmVisNumEntries(); if (has) { nw4r::g3d::ResMdl m(fn_8018D174(res, 0)); setVisAnimU(vis, m, *anim, heap); } }
    { bool has = texPat < (*anim)->m_resFile.GetResAnmTexPatNumEntries(); if (has) { nw4r::g3d::ResMdl m(fn_8018D174(res, 0)); setTexPatAnimU(texPat, m, *anim, heap); } }
    { bool has = texSrt < (*anim)->m_resFile.GetResAnmTexSrtNumEntries(); if (has) { nw4r::g3d::ResMdl m(fn_8018D174(res, 0)); setTexSrtAnimU(texSrt, m, *anim, heap); } }
    { bool has = clr < (*anim)->m_resFile.GetResAnmClrNumEntries(); if (has) { nw4r::g3d::ResMdl m(fn_8018D174(res, 0)); setClrAnimU(clr, m, *anim, heap); } }
    {
        bool has = shp < (*anim)->m_resFile.GetResAnmShpNumEntries();
        if (has) {
            nw4r::g3d::ResMdl m(fn_8018D174(res, 0));
            setShpAnimU(shp, m, *anim, heap);
        }
    }

    (*anim)->_spacer[0] = 0;
    gfModelAnimation::bind(*scn, *anim);
    obj->slot11(obj->fE4, *scn);
}

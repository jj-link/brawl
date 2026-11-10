#include <types.h>
#include <gf/gf_model.h>
#pragma force_active on

using namespace nw4r::g3d;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(float);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(ResMdl);
};

struct Owner {
    char pad[0x3c];
    int current;
    char pad2[4];
    ScnMdl* model;
    gfModelAnimation* animation;
};

extern "C" {
void* fn_8018D6D8(ResFile*, u32);
void* fn_8018D8E0(ResFile*, u32);
void* fn_8018DCF0(ResFile*, u32);
void* fn_8018DEF8(ResFile*, u32);
void* fn_8018DAE8(ResFile*, u32);
void* fn_8018E100(ResFile*, u32);
AnmObjShpRes* fn_8019BC04(MEMAllocator*, int*, ResAnmShp, ResMdl, bool);
extern float lbl_805A1958;
}

inline void chrInner(u32 index, ResMdl model, gfModelAnimation* a) {
    int size;
    ResAnmChr anim(fn_8018D6D8(&a->m_resFile, index));
    MEMAllocator* alloc = gfHeapManager::getMEMAllocator((Heaps::HeapType)3);
    if (anim.IsValid()) {
        AnmObjChrRes* obj = AnmObjChrRes::Construct(alloc, &size, anim, model, false);
        if (obj) {
            obj->Bind(model);
            if (a->m_anmObjChrRes)
                a->m_anmObjChrRes->Destroy();
            a->m_anmObjChrRes = obj;
        }
    }
}

inline void chr(u32 index, ResMdl model, gfModelAnimation* a) {
    if (index < a->m_resFile.GetResAnmChrNumEntries())
        chrInner(index, model, a);
}

inline void visInner(ResMdl model, u32 index, gfModelAnimation* a) {
    int size;
    AnmObjVisRes* obj;
    void* anim = fn_8018D8E0(&a->m_resFile, index);
    MEMAllocator* alloc = gfHeapManager::getMEMAllocator((Heaps::HeapType)3);
    if (anim) {
        obj = AnmObjVisRes::Construct(alloc, &size, ResAnmVis(anim), model);
        if (obj) {
            obj->Bind(model);
            if (a->m_anmObjVisRes)
                a->m_anmObjVisRes->Destroy();
            a->m_anmObjVisRes = obj;
        }
    }
}

inline void vis(gfModelAnimation* a, void* model, u32 index) {
    if (index < a->m_resFile.GetResAnmVisNumEntries())
        visInner(ResMdl(model), index, a);
}

#define HELPER(name, count, resource, resType, objType, member) \
inline void name##Inner(u32 index, ResMdl model, gfModelAnimation* a) { \
    int size; \
    resType anim(resource(&a->m_resFile, index)); \
    if (anim.IsValid()) { \
        MEMAllocator* alloc = gfHeapManager::getMEMAllocator((Heaps::HeapType)3); \
        objType* obj = objType::Construct(alloc, &size, anim, model, false); \
        if (obj) { \
            obj->Bind(model); \
            if (a->member) a->member->Destroy(); \
            a->member = obj; \
        } \
    } \
} \
inline void name(u32 index, void* model, gfModelAnimation* a) { \
    if (index < a->m_resFile.count()) \
        name##Inner(index, ResMdl(model), a); \
}

HELPER(pat, GetResAnmTexPatNumEntries, fn_8018DCF0, ResAnmTexPat,
       AnmObjTexPatRes, m_anmObjTexPatRes)
HELPER(srt, GetResAnmTexSrtNumEntries, fn_8018DEF8, ResAnmTexSrt,
       AnmObjTexSrtRes, m_anmObjTexSrtRes)
HELPER(clr, GetResAnmClrNumEntries, fn_8018DAE8, ResAnmClr,
       AnmObjMatClrRes, m_anmObjMatClrRes)

inline void shpInner(u32& index, ResMdl model, gfModelAnimation* a) {
    int size;
    index = (u32)fn_8018E100(&a->m_resFile, index);
    if (index) {
        MEMAllocator* alloc = gfHeapManager::getMEMAllocator((Heaps::HeapType)3);
        AnmObjShpRes* obj = fn_8019BC04(alloc, &size, ResAnmShp((void*)index), model, false);
        if (obj) {
            obj->Bind(model);
            if (a->m_anmObjShpRes)
                obj->Destroy();
            a->m_anmObjShpRes = obj;
        }
    }
}

inline void shp(u32& index, void* model, gfModelAnimation* a) {
    if (index < a->m_resFile.GetResAnmShpNumEntries())
        shpInner(index, ResMdl(model), a);
}

extern "C" void fn_80063538(Owner* self, u32 index, int flags) {
    void* visModel;
    if (self->animation) {
        if (flags & 1) {
            u32 count = self->animation->m_resFile.GetResAnmChrNumEntries();
            if ((count << __cntlzw(count ^ index)) >> 31) {
                self->animation->unbindNodeAnim(self->model);
                chr(index, *(ResMdl*)((char*)self->model + 0xe8), self->animation);
                self->animation->bindNodeAnim(self->model);
                self->animation->m_anmObjChrRes->SetFrame(lbl_805A1958);
            }
        }

        if (flags & 2) {
            u32 count = self->animation->m_resFile.GetResAnmVisNumEntries();
            if ((count << __cntlzw(count ^ index)) >> 31) {
                self->animation->unbindVisibleAnim(self->model);
                visModel = *(void**)((char*)self->model + 0xe8);
                vis(self->animation, visModel, index);
                self->animation->bindVisibleAnim(self->model);
                self->animation->m_anmObjVisRes->SetFrame(lbl_805A1958);
            }
        }

        if (flags & 4) {
            u32 count = self->animation->m_resFile.GetResAnmTexPatNumEntries();
            if ((count << __cntlzw(count ^ index)) >> 31) {
                self->animation->unbindTexAnim(self->model);
                visModel = *(void**)((char*)self->model + 0xe8);
                pat(index, visModel, self->animation);
                self->animation->bindTexAnim(self->model);
                self->animation->m_anmObjTexPatRes->SetFrame(lbl_805A1958);
            }
        }

        if (flags & 8) {
            u32 count = self->animation->m_resFile.GetResAnmTexSrtNumEntries();
            if ((count << __cntlzw(count ^ index)) >> 31) {
                self->animation->unbindTexSrtAnim(self->model);
                visModel = *(void**)((char*)self->model + 0xe8);
                srt(index, visModel, self->animation);
                self->animation->bindTexSrtAnim(self->model);
                self->animation->m_anmObjTexSrtRes->SetFrame(lbl_805A1958);
            }
        }

        if (flags & 16) {
            u32 count = self->animation->m_resFile.GetResAnmClrNumEntries();
            if ((count << __cntlzw(count ^ index)) >> 31) {
                self->animation->unbindMatColAnim(self->model);
                visModel = *(void**)((char*)self->model + 0xe8);
                clr(index, visModel, self->animation);
                self->animation->bindMatColAnim(self->model);
                self->animation->m_anmObjMatClrRes->SetFrame(lbl_805A1958);
            }
        }

        if (flags & 32) {
            u32 count = self->animation->m_resFile.GetResAnmShpNumEntries();
            if ((count << __cntlzw(count ^ index)) >> 31) {
                self->animation->unbindShapeAnim(self->model);
                visModel = *(void**)((char*)self->model + 0xe8);
                shp(index, visModel, self->animation);
                self->animation->bindShapeAnim(self->model);
                self->animation->m_anmObjShpRes->SetFrame(lbl_805A1958);
            }
        }

        self->current = -1;
    }
}

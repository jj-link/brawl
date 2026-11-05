#include <gf/gf_model.h>
#pragma force_active on

class Class_2110 {
public:
    virtual void fn_57_C674();
    virtual void fn_57_BA94();
    virtual void fn_57_BAA4();
    virtual void fn_57_ADD8();
    virtual void fn_57_AB4C();
    virtual void fn_57_A6E0();
    virtual void fn_57_BDD0();
    virtual void fn_57_BE8C();
    virtual void fn_57_C62C();
    virtual void fn_57_BAB4();
    virtual void fn_57_A830();
};

extern "C" int __cntlzw(unsigned int);
extern "C" void* fn_8018DAE8(void*, unsigned int);
extern "C" void* fn_8018DEF8(void*, unsigned int);
extern "C" void* fn_8018DCF0(void*, unsigned int);
extern "C" void* fn_8018D8E0(void*, unsigned int);
extern "C" void* fn_8018D6D8(void*, unsigned int);

extern "C" void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
extern "C" void setLoop__16gfModelAnimationFd(gfModelAnimation*, int);
extern "C" unsigned int getFrameCount__16gfModelAnimationFd(gfModelAnimation*);

extern const float lbl_57_rodata_2C0;
extern const float lbl_57_rodata_2CC;

inline void visInner(unsigned int index, nw4r::g3d::ResMdl model, gfModelAnimation* anim) {
    int size;
    nw4r::g3d::ResAnmVis resource(fn_8018D8E0(anim, index));
    MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
    if (resource.IsValid()) {
        nw4r::g3d::AnmObjVisRes* obj =
            nw4r::g3d::AnmObjVisRes::Construct(allocator, &size, resource, model);
        if (obj) {
            obj->Bind(model);
            if (anim->m_anmObjVisRes)
                anim->m_anmObjVisRes->Destroy();
            anim->m_anmObjVisRes = obj;
        }
    }
}

inline void visHelper(unsigned int index, nw4r::g3d::ResMdl model, gfModelAnimation* anim) {
    if (index < anim->m_resFile.GetResAnmVisNumEntries())
        visInner(index, model, anim);
}

inline void patInner(unsigned int index, nw4r::g3d::ResMdl model, gfModelAnimation* anim) {
    int size;
    nw4r::g3d::ResAnmTexPat resource(fn_8018DCF0(anim, index));
    if (resource.IsValid()) {
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
        nw4r::g3d::AnmObjTexPatRes* obj =
            nw4r::g3d::AnmObjTexPatRes::Construct(allocator, &size, resource, model, false);
        if (obj) {
            obj->Bind(model);
            if (anim->m_anmObjTexPatRes)
                anim->m_anmObjTexPatRes->Destroy();
            anim->m_anmObjTexPatRes = obj;
        }
    }
}

inline void patHelper(unsigned int index, nw4r::g3d::ResMdl model, gfModelAnimation* anim) {
    if (index < anim->m_resFile.GetResAnmTexPatNumEntries())
        patInner(index, model, anim);
}

inline void clrInner(unsigned int& index, nw4r::g3d::ResMdl model, gfModelAnimation* anim) {
    int size;
    index = (unsigned int)fn_8018DAE8(anim, index);
    if (index) {
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
        nw4r::g3d::ResAnmClr resource((void*)index);
        nw4r::g3d::AnmObjMatClrRes* obj =
            nw4r::g3d::AnmObjMatClrRes::Construct(allocator, &size, resource, model, false);
        if (obj) {
            obj->Bind(model);
            if (anim->m_anmObjMatClrRes)
                anim->m_anmObjMatClrRes->Destroy();
            anim->m_anmObjMatClrRes = obj;
        }
    }
}

inline void clrHelper(unsigned int& index, nw4r::g3d::ResMdl model, gfModelAnimation* anim) {
    if (index < anim->m_resFile.GetResAnmClrNumEntries())
        clrInner(index, model, anim);
}

inline void srtInner(unsigned int index, nw4r::g3d::ResMdl model, gfModelAnimation* anim) {
    int size;
    nw4r::g3d::ResAnmTexSrt resource(fn_8018DEF8(anim, index));
    if (resource.IsValid()) {
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
        nw4r::g3d::AnmObjTexSrtRes* obj =
            nw4r::g3d::AnmObjTexSrtRes::Construct(allocator, &size, resource, model, false);
        if (obj) {
            obj->Bind(model);
            if (anim->m_anmObjTexSrtRes)
                anim->m_anmObjTexSrtRes->Destroy();
            anim->m_anmObjTexSrtRes = obj;
        }
    }
}

inline void srtHelper(unsigned int index, nw4r::g3d::ResMdl model, gfModelAnimation* anim) {
    if (index < anim->m_resFile.GetResAnmTexSrtNumEntries())
        srtInner(index, model, anim);
}

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad2[0x151];
    unsigned char current;
};

extern "C" void fn_57_E7E8(
    Object* self, unsigned int index, int loop, int force, float* count
) {
    if (self->current != index || force) {
        nw4r::g3d::ScnMdl* model = *self->models;
        if (model) {
            gfModelAnimation* anim = *self->animations;
            if (anim) {
                nw4r::g3d::ResMdl res(*(void**)((char*)model + 0xe8));
                if (res.IsValid()) {
                    anim->unbindNodeAnim(model);
                    anim->unbindVisibleAnim(model);
                    anim->unbindTexAnim(model);
                    anim->unbindTexSrtAnim(model);
                    anim->unbindMatColAnim(model);
                    self->current = index;

                    if (index < 4) {
                        unsigned int n = anim->m_resFile.GetResAnmChrNumEntries();
                        if ((n << __cntlzw(n ^ index)) >> 31) {
                            if (index < anim->m_resFile.GetResAnmChrNumEntries()) {
                                nw4r::g3d::ResAnmChr resource(fn_8018D6D8(anim, index));
                                MEMAllocator* allocator =
                                    gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
                                if (resource.IsValid()) {
                                    int size;
                                    nw4r::g3d::AnmObjChrRes* obj =
                                        nw4r::g3d::AnmObjChrRes::Construct(
                                            allocator, &size, resource, res, false);
                                    if (obj) {
                                        obj->Bind(res);
                                        if (anim->m_anmObjChrRes)
                                            anim->m_anmObjChrRes->Destroy();
                                        anim->m_anmObjChrRes = obj;
                                    }
                                }
                            }
                        }

                        n = anim->m_resFile.GetResAnmVisNumEntries();
                        if ((n << __cntlzw(n ^ index)) >> 31)
                            visHelper(index, res, anim);

                        n = anim->m_resFile.GetResAnmTexPatNumEntries();
                        if ((n << __cntlzw(n ^ index)) >> 31)
                            patHelper(index, res, anim);

                        n = anim->m_resFile.GetResAnmTexSrtNumEntries();
                        if ((n << __cntlzw(n ^ index)) >> 31)
                            srtHelper(index, res, anim);

                        n = anim->m_resFile.GetResAnmClrNumEntries();
                        if ((n << __cntlzw(n ^ index)) >> 31)
                            clrHelper(index, res, anim);

                        gfModelAnimation::bind(model, anim);
                        setFrame__16gfModelAnimationFd(anim, lbl_57_rodata_2C0);
                        anim->setUpdateRate(lbl_57_rodata_2CC);
                        setLoop__16gfModelAnimationFd(anim, loop);
                        if (count)
                            *count = (float)getFrameCount__16gfModelAnimationFd(anim);
                    }
                }
            }
        }
    }
}
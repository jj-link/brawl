#include <gf/gf_model.h>
#pragma force_active on

class Class_14D0 {
public:
    virtual void fn_77_5564();
    virtual void fn_77_4984();
    virtual void fn_77_4994();
    virtual void fn_77_3CC8();
    virtual void fn_77_3A3C();
    virtual void fn_77_35D0();
    virtual void fn_77_4CC0();
    virtual void fn_77_4D7C();
    virtual void fn_77_551C();
    virtual void fn_77_49A4();
    virtual void fn_77_3720();
};

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad2[0x10c];
    unsigned char current;
};

extern "C" void* fn_8018D6D8(void*, unsigned int);
extern "C" void* fn_8018D8E0(void*, unsigned int);
extern "C" void* fn_8018DCF0(void*, unsigned int);
extern "C" void* fn_8018DEF8(void*, unsigned int);
extern "C" void* fn_8018DAE8(void*, unsigned int);
extern "C" int __cntlzw(unsigned int);
extern "C" void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
extern "C" void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
extern "C" unsigned int getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
extern "C" const float lbl_77_rodata_48;
extern "C" const float lbl_77_rodata_80;

inline void customChr(unsigned int index, nw4r::g3d::ResMdl model, gfModelAnimation* animation) {
    int size;
    nw4r::g3d::ResAnmChr anim(fn_8018D6D8(&animation->m_resFile, index));
    MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
    if (anim.IsValid()) {
        nw4r::g3d::AnmObjChrRes* obj =
            nw4r::g3d::AnmObjChrRes::Construct(allocator, &size, anim, model, false);
        if (obj) {
            obj->Bind(model);
            if (animation->m_anmObjChrRes)
                animation->m_anmObjChrRes->Destroy();
            animation->m_anmObjChrRes = obj;
        }
    }
}

inline void customChr2(unsigned int index, nw4r::g3d::ResMdl model, gfModelAnimation* animation) {
    if (index < animation->m_resFile.GetResAnmChrNumEntries())
        customChr(index, model, animation);
}

inline void customVis(unsigned int index, nw4r::g3d::ResMdl model, gfModelAnimation* animation) {
    int size;
    nw4r::g3d::ResAnmVis anim(fn_8018D8E0(&animation->m_resFile, index));
    MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
    if (anim.IsValid()) {
        nw4r::g3d::AnmObjVisRes* obj =
            nw4r::g3d::AnmObjVisRes::Construct(allocator, &size, anim, model);
        if (obj) {
            obj->Bind(model);
            if (animation->m_anmObjVisRes)
                animation->m_anmObjVisRes->Destroy();
            animation->m_anmObjVisRes = obj;
        }
    }
}

inline void customVis2(unsigned int index, nw4r::g3d::ResMdl model, gfModelAnimation* animation) {
    if (index < animation->m_resFile.GetResAnmVisNumEntries())
        customVis(index, model, animation);
}

inline void customTexPat(unsigned int index, nw4r::g3d::ResMdl model, gfModelAnimation* animation) {
    int size;
    nw4r::g3d::ResAnmTexPat anim(fn_8018DCF0(&animation->m_resFile, index));
    if (anim.IsValid()) {
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
        nw4r::g3d::AnmObjTexPatRes* obj =
            nw4r::g3d::AnmObjTexPatRes::Construct(allocator, &size, anim, model, false);
        if (obj) {
            obj->Bind(model);
            if (animation->m_anmObjTexPatRes)
                animation->m_anmObjTexPatRes->Destroy();
            animation->m_anmObjTexPatRes = obj;
        }
    }
}

inline void customTexPat2(unsigned int index, nw4r::g3d::ResMdl model, gfModelAnimation* animation) {
    if (index < animation->m_resFile.GetResAnmTexPatNumEntries())
        customTexPat(index, model, animation);
}

inline void customTexSrt(unsigned int index, nw4r::g3d::ResMdl model, gfModelAnimation* animation) {
    int size;
    nw4r::g3d::ResAnmTexSrt anim(fn_8018DEF8(&animation->m_resFile, index));
    if (anim.IsValid()) {
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
        nw4r::g3d::AnmObjTexSrtRes* obj =
            nw4r::g3d::AnmObjTexSrtRes::Construct(allocator, &size, anim, model, false);
        if (obj) {
            obj->Bind(model);
            if (animation->m_anmObjTexSrtRes)
                animation->m_anmObjTexSrtRes->Destroy();
            animation->m_anmObjTexSrtRes = obj;
        }
    }
}

inline void customTexSrt2(unsigned int index, nw4r::g3d::ResMdl model, gfModelAnimation* animation) {
    if (index < animation->m_resFile.GetResAnmTexSrtNumEntries())
        customTexSrt(index, model, animation);
}

inline void customClr(nw4r::g3d::ResMdl model, gfModelAnimation* animation, void* resource) {
    int size;
    nw4r::g3d::ResAnmClr anim(resource);
    if (anim.IsValid()) {
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
        nw4r::g3d::AnmObjMatClrRes* obj =
            nw4r::g3d::AnmObjMatClrRes::Construct(allocator, &size, anim, model, false);
        if (obj) {
            obj->Bind(model);
            if (animation->m_anmObjMatClrRes)
                animation->m_anmObjMatClrRes->Destroy();
            animation->m_anmObjMatClrRes = obj;
        }
    }
}

inline void customClr2(unsigned int& index, nw4r::g3d::ResMdl model, gfModelAnimation* animation) {
    if (index < animation->m_resFile.GetResAnmClrNumEntries()) {
        index = (unsigned int)fn_8018DAE8(&animation->m_resFile, index);
        customClr(model, animation, (void*)index);
    }
}

extern "C" void fn_77_26F0(
    Object* self, unsigned int index, bool loop, bool force, float* frameCount
) {
    if (self->current != index || force) {
        nw4r::g3d::ScnMdl* scene = *self->models;
        if (scene) {
            gfModelAnimation* animation = *self->animations;
            if (animation) {
                nw4r::g3d::ResMdl model =
                    *(nw4r::g3d::ResMdl*)((char*)scene + 0xe8);
                if (model.IsValid()) {
                    animation->unbindNodeAnim(scene);
                    animation->unbindVisibleAnim(scene);
                    animation->unbindTexAnim(scene);
                    animation->unbindTexSrtAnim(scene);
                    animation->unbindMatColAnim(scene);
                    self->current = index;
                    if (index < 1) {
                        unsigned int count = animation->m_resFile.GetResAnmChrNumEntries();
                        if ((count << __cntlzw(count ^ index)) >> 31)
                            customChr2(index, model, animation);

                        count = animation->m_resFile.GetResAnmVisNumEntries();
                        if ((count << __cntlzw(count ^ index)) >> 31)
                            customVis2(index, model, animation);

                        count = animation->m_resFile.GetResAnmTexPatNumEntries();
                        if ((count << __cntlzw(count ^ index)) >> 31)
                            customTexPat2(index, model, animation);

                        count = animation->m_resFile.GetResAnmTexSrtNumEntries();
                        if ((count << __cntlzw(count ^ index)) >> 31)
                            customTexSrt2(index, model, animation);

                        count = animation->m_resFile.GetResAnmClrNumEntries();
                        if ((count << __cntlzw(count ^ index)) >> 31)
                            customClr2(index, model, animation);

                        gfModelAnimation::bind(scene, animation);
                        setFrame__16gfModelAnimationFd(animation, lbl_77_rodata_48);
                        animation->setUpdateRate(lbl_77_rodata_80);
                        setLoop__16gfModelAnimationFd(animation, loop);
                        if (frameCount)
                            *frameCount = getFrameCount__16gfModelAnimationFd(animation);
                    }
                }
            }
        }
    }
}

#include <types.h>
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
    virtual void slot10(int*);
};

struct Object {
    char pad0[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad50[0x111];
    u8 current;
};

extern "C" {
nw4r::g3d::ResAnmVis fn_8018D8E0(void*, u32);
void* fn_8018DAE8(void*, u32);
void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
void setUpdateRate__16gfModelAnimationFf(gfModelAnimation*, float);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
extern const float lbl_63_rodata_184;
extern const float lbl_63_rodata_18C;
}

inline nw4r::g3d::AnmObjMatClrRes* constructColor(
    MEMAllocator* allocator, nw4r::g3d::ResAnmClr res,
    nw4r::g3d::ResMdl resource) {
    int size;
    return nw4r::g3d::AnmObjMatClrRes::Construct(
        allocator, &size, res, resource, false);
}

inline nw4r::g3d::AnmObjVisRes* constructVisibility(
    MEMAllocator* allocator, nw4r::g3d::ResAnmVis res,
    nw4r::g3d::ResMdl resource) {
    int size;
    return nw4r::g3d::AnmObjVisRes::Construct(
        allocator, &size, res, resource);
}

inline void setColor(void* res, nw4r::g3d::ResMdl resource,
                     gfModelAnimation* anim) {
    if (res) {
        int bindArg;
        MEMAllocator* allocator =
            gfHeapManager::getMEMAllocator(Heaps::StageInstance);
        nw4r::g3d::AnmObjMatClrRes* obj =
            constructColor(allocator, nw4r::g3d::ResAnmClr(res), resource);
        if (obj) {
            bindArg = *(int*)&resource;
            ((Object_vptr_0*)obj)->slot10(&bindArg);
            if (anim->m_anmObjMatClrRes)
                anim->m_anmObjMatClrRes->Destroy();
            anim->m_anmObjMatClrRes = obj;
        }
    }
}

inline void setVisibility(nw4r::g3d::ResAnmVis res,
                          nw4r::g3d::ResMdl resource,
                          gfModelAnimation* anim) {
    MEMAllocator* allocator =
        gfHeapManager::getMEMAllocator(Heaps::StageInstance);
    if (res.IsValid()) {
        int bindArg;
        nw4r::g3d::AnmObjVisRes* obj =
            constructVisibility(allocator, res, resource);
        if (obj) {
            bindArg = *(int*)&resource;
            ((Object_vptr_0*)obj)->slot10(&bindArg);
            if (anim->m_anmObjVisRes)
                anim->m_anmObjVisRes->Destroy();
            anim->m_anmObjVisRes = obj;
        }
    }
}

extern "C" void fn_63_12D40(
    Object* self, u32 index, bool loop, bool force, float* frameCount
) {
    nw4r::g3d::ScnMdl* model;
    gfModelAnimation* anim;
    u8 old;

    old = self->current;
    if (old == index && !force)
        return;

    model = *self->models;
    if (!model)
        return;

    anim = *self->animations;
    if (!anim)
        return;

    nw4r::g3d::ResMdl resource = model->m_resMdl;
    if (!resource.IsValid())
        return;

    self->current = index;
    if (index == 2) {
        anim->unbindVisibleAnim(model);
        anim->unbindMatColAnim(model);
        return;
    }

    switch (old) {
    case 0:
        switch ((int)index) {
        case 1: {
            u32 n = anim->m_resFile.GetResAnmClrNumEntries();
            if ((((0 - n) | n) >> 31) != 0 &&
                anim->m_resFile.GetResAnmClrNumEntries() != 0) {
                setColor(fn_8018DAE8(anim, 0), resource, anim);
            }
            break;
        }
        }
        break;

    case 1:
        switch ((int)index) {
        case 0:
            anim->unbindMatColAnim(model);
            break;
        }
        break;

    default:
        switch (index) {
        case 0: {
            u32 n = anim->m_resFile.GetResAnmVisNumEntries();
            if ((((0 - n) | n) >> 31) != 0 &&
                anim->m_resFile.GetResAnmVisNumEntries() != 0) {
                setVisibility(fn_8018D8E0(anim, 0), resource, anim);
            }
            break;
        }

        case 1: {
            u32 n = anim->m_resFile.GetResAnmVisNumEntries();
            if ((((0 - n) | n) >> 31) != 0 &&
                anim->m_resFile.GetResAnmVisNumEntries() != 0) {
                setVisibility(fn_8018D8E0(anim, 0), resource, anim);
            }

            u32 c = anim->m_resFile.GetResAnmClrNumEntries();
            if ((((0 - c) | c) >> 31) != 0 &&
                anim->m_resFile.GetResAnmClrNumEntries() != 0) {
                setColor(fn_8018DAE8(anim, 0), resource, anim);
            }
            break;
        }
        }
        break;
    }

    gfModelAnimation::bind(model, anim);
    if (old == 2)
        setFrame__16gfModelAnimationFd(anim, lbl_63_rodata_18C);
    setUpdateRate__16gfModelAnimationFf(anim, lbl_63_rodata_184);
    setLoop__16gfModelAnimationFd(anim, loop);
    if (frameCount)
        *frameCount = (float)getFrameCount__16gfModelAnimationFd(anim);
}

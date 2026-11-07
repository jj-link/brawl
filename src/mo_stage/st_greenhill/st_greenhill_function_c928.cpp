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
};

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad2[0x114];
    u8 current;
};

extern "C" {
void* fn_8018D6D8(void*, u32);
nw4r::g3d::ResAnmVis fn_8018D8E0(void*, u32);
nw4r::g3d::ResAnmClr fn_8018DAE8(void*, u32);
void* fn_8018DCF0(void*, u32);
void* fn_8018DEF8(void*, u32);

void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
void setUpdateRate__16gfModelAnimationFf(gfModelAnimation*, float);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);

extern const float lbl_72_rodata_E8;
extern const float lbl_72_rodata_EC;
}

inline nw4r::g3d::ResAnmChr
nw4r::g3d::ResFile::GetResAnmChr(u32 index) {
    return ResAnmChr(fn_8018D6D8(this, index));
}

inline nw4r::g3d::ResAnmVis
nw4r::g3d::ResFile::GetResAnmVis(u32 index) {
    return fn_8018D8E0(this, index);
}

inline nw4r::g3d::ResAnmTexPat
nw4r::g3d::ResFile::GetResAnmTexPat(u32 index) {
    return ResAnmTexPat(fn_8018DCF0(this, index));
}

inline nw4r::g3d::ResAnmTexSrt
nw4r::g3d::ResFile::GetResAnmTexSrt(u32 index) {
    return ResAnmTexSrt(fn_8018DEF8(this, index));
}

inline nw4r::g3d::ResAnmClr
nw4r::g3d::ResFile::GetResAnmClr(u32 index) {
    return fn_8018DAE8(this, index);
}

extern "C" void fn_72_C928(
    Object* self, u8 index, bool loop, bool force, float* frameCount
) {
    if (self->current == index && !force)
        return;

    nw4r::g3d::ScnMdl* model = *self->models;
    if (!model)
        return;

    gfModelAnimation* animation = *self->animations;
    if (!animation)
        return;

    nw4r::g3d::ResMdl resource = model->m_resMdl;
    if (!resource.IsValid())
        return;

    animation->unbindNodeAnim(model);
    animation->unbindVisibleAnim(model);
    animation->unbindTexAnim(model);
    animation->unbindTexSrtAnim(model);
    animation->unbindMatColAnim(model);

    self->current = index;
    if (index >= 1u)
        return;

    {
        bool has = index < animation->m_resFile.GetResAnmChrNumEntries();
        if (has)
            setChrAnim2(index, resource, animation, Heaps::StageInstance);
    }
    {
        bool has = index < animation->m_resFile.GetResAnmTexPatNumEntries();
        if (has)
            setTexPatAnim2(index, resource, animation, Heaps::StageInstance);
    }
    {
        bool has = index < animation->m_resFile.GetResAnmTexSrtNumEntries();
        if (has)
            setTexSortAnim2(index, resource, animation, Heaps::StageInstance);
    }
    {
        bool has = index < animation->m_resFile.GetResAnmClrNumEntries();
        if (has)
            setColorAnim2(index, resource, animation, Heaps::StageInstance);
    }
    {
        bool has = index < animation->m_resFile.GetResAnmVisNumEntries();
        if (has)
            setVisibilityAnim2(index, resource, animation, Heaps::StageInstance);
    }

    gfModelAnimation::bind(model, animation);
    setFrame__16gfModelAnimationFd(animation, lbl_72_rodata_E8);
    setUpdateRate__16gfModelAnimationFf(animation, lbl_72_rodata_EC);
    setLoop__16gfModelAnimationFd(animation, loop);

    if (frameCount)
        *frameCount = (float)getFrameCount__16gfModelAnimationFd(animation);
}

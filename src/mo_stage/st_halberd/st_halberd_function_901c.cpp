#include <gf/gf_model.h>
#include <types.h>
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
    virtual int fn_57_A830(nw4r::g3d::ResMdl);
};

struct Object {
    char pad0[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad1[0x11C];
    u8 current;
};

extern "C" {
nw4r::g3d::ResAnmChr fn_8018D6D8(void*, u32);
nw4r::g3d::ResAnmVis fn_8018D8E0(void*, u32);
nw4r::g3d::ResAnmTexPat fn_8018DCF0(void*, u32);
nw4r::g3d::ResAnmTexSrt fn_8018DEF8(void*, u32);
nw4r::g3d::ResAnmClr fn_8018DAE8(void*, u32);
void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
extern const float lbl_57_rodata_260;
extern const float lbl_57_rodata_274;
}

inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 index) {
    return fn_8018D6D8(this, index);
}

inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 index) {
    return fn_8018D8E0(this, index);
}

inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 index) {
    return fn_8018DCF0(this, index);
}

inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 index) {
    return fn_8018DEF8(this, index);
}

inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 index) {
    return fn_8018DAE8(this, index);
}

extern "C" void fn_57_901C(Object* self, u8 index, bool loop, s32 force, float* frameCount) {
    if (self->current == index && !force)
        return;

    nw4r::g3d::ScnMdl* model;
    gfModelAnimation* animation;

    model = *self->models;
    if (model == NULL)
        return;

    animation = *self->animations;
    if (animation == NULL)
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
    if (index >= 3)
        return;

    {
        bool has = index < animation->m_resFile.GetResAnmChrNumEntries();
        if (has)
            setChrAnim2(index, resource, animation, Heaps::StageInstance);
    }
    {
        bool has = index < animation->m_resFile.GetResAnmVisNumEntries();
        if (has)
            setVisibilityAnim2(index, resource, animation, Heaps::StageInstance);
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

    gfModelAnimation::bind(model, animation);
    setFrame__16gfModelAnimationFd(animation, lbl_57_rodata_260);
    animation->setUpdateRate(lbl_57_rodata_274);
    setLoop__16gfModelAnimationFd(animation, loop);

    if (frameCount != NULL)
        *frameCount = (float)getFrameCount__16gfModelAnimationFd(animation);
}

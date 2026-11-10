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
    virtual void slot10();
};

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad4c[0x110];
    u8 current;
};

extern "C" {
void* fn_8018D6D8(void*, u32);
void* fn_8018D8E0(void*, u32);
nw4r::g3d::ResAnmClr fn_8018DAE8(void*, u32);
void* fn_8018DCF0(void*, u32);
void* fn_8018DEF8(void*, u32);
void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
extern const float lbl_51_rodata_48;
extern const float lbl_51_rodata_54;
}

inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 i) {
    return ResAnmChr(fn_8018D6D8(this, i));
}

inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 i) {
    return ResAnmVis(fn_8018D8E0(this, i));
}

inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 i) {
    return ResAnmTexPat(fn_8018DCF0(this, i));
}

inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 i) {
    return ResAnmTexSrt(fn_8018DEF8(this, i));
}

inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 i) {
    return fn_8018DAE8(this, i);
}

inline bool hasChr(gfModelAnimation* anim, u32 index) {
    return index < anim->m_resFile.GetResAnmChrNumEntries();
}

inline bool hasVis(gfModelAnimation* anim, u32 index) {
    return index < anim->m_resFile.GetResAnmVisNumEntries();
}

inline bool hasPat(gfModelAnimation* anim, u32 index) {
    return index < anim->m_resFile.GetResAnmTexPatNumEntries();
}

inline bool hasSrt(gfModelAnimation* anim, u32 index) {
    return index < anim->m_resFile.GetResAnmTexSrtNumEntries();
}

inline bool hasClr(gfModelAnimation* anim, u32 index) {
    return index < anim->m_resFile.GetResAnmClrNumEntries();
}

extern "C" void fn_51_2F14(
    Object* self, u8 index, bool loop, bool force, float* out
) {
    if (self->current == index && !force)
        return;

    nw4r::g3d::ScnMdl* model = *self->models;
    if (!model)
        return;

    gfModelAnimation* anim = *self->animations;
    if (!anim)
        return;

    nw4r::g3d::ResMdl resource = model->m_resMdl;
    if (!resource.IsValid())
        return;

    anim->unbindNodeAnim(model);
    anim->unbindVisibleAnim(model);
    anim->unbindTexAnim(model);
    anim->unbindTexSrtAnim(model);
    anim->unbindMatColAnim(model);

    self->current = index;
    if (index >= 1u)
        return;

    if (hasChr(anim, index))
        setChrAnim2(index, resource, anim, Heaps::StageInstance);
    if (hasVis(anim, index))
        setVisibilityAnim2(index, resource, anim, Heaps::StageInstance);
    if (hasPat(anim, index))
        setTexPatAnim2(index, resource, anim, Heaps::StageInstance);
    if (hasSrt(anim, index))
        setTexSortAnim2(index, resource, anim, Heaps::StageInstance);
    if (hasClr(anim, index))
        setColorAnim2(index, resource, anim, Heaps::StageInstance);

    gfModelAnimation::bind(model, anim);
    setFrame__16gfModelAnimationFd(anim, lbl_51_rodata_48);
    anim->setUpdateRate(lbl_51_rodata_54);
    setLoop__16gfModelAnimationFd(anim, loop);
    if (out)
        *out = getFrameCount__16gfModelAnimationFd(anim);
}

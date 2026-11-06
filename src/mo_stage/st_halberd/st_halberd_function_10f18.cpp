#include <gf/gf_model.h>
#pragma force_active on

class Class_2110 {
public:
    virtual void fn_57_C674();  // offset 0x8
    virtual void fn_57_BA94();  // offset 0xc
    virtual void fn_57_BAA4();  // offset 0x10
    virtual void fn_57_ADD8();  // offset 0x14
    virtual void fn_57_AB4C();  // offset 0x18
    virtual void fn_57_A6E0();  // offset 0x1c
    virtual void fn_57_BDD0();  // offset 0x20
    virtual void fn_57_BE8C();  // offset 0x24
    virtual void fn_57_C62C();  // offset 0x28
    virtual void fn_57_BAB4();  // offset 0x2c
    virtual int fn_57_A830(nw4r::g3d::ResMdl);  // offset 0x30
};

struct Object {
    char pad0[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad4C[0x11D];
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
extern const float lbl_57_rodata_360;
extern const float lbl_57_rodata_378;
}

inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 index) { return ResAnmChr(fn_8018D6D8(this, index)); }
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 index) { return ResAnmVis(fn_8018D8E0(this, index)); }
inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 index) { return ResAnmTexPat(fn_8018DCF0(this, index)); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 index) { return ResAnmTexSrt(fn_8018DEF8(this, index)); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 index) { return fn_8018DAE8(this, index); }

extern "C" void fn_57_10F18(Object* self, u8 index, bool loop, bool force, float* frameCount) {
    if (self->current == index && !force)
        return;
    nw4r::g3d::ScnMdl* model = *self->models;
    if (!model) return;
    gfModelAnimation* animation = *self->animations;
    if (!animation) return;
    nw4r::g3d::ResMdl resource = model->m_resMdl;
    if (!resource.IsValid()) return;

    animation->unbindNodeAnim(model);
    animation->unbindVisibleAnim(model);
    animation->unbindTexAnim(model);
    animation->unbindTexSrtAnim(model);
    animation->unbindMatColAnim(model);
    self->current = index;
    if (index >= 3u) return;

    { bool has = index < animation->m_resFile.GetResAnmChrNumEntries(); if (has) setChrAnim2(index, resource, animation, Heaps::StageInstance); }
    { bool has = index < animation->m_resFile.GetResAnmVisNumEntries(); if (has) setVisibilityAnim2(index, resource, animation, Heaps::StageInstance); }
    { bool has = index < animation->m_resFile.GetResAnmTexPatNumEntries(); if (has) setTexPatAnim2(index, resource, animation, Heaps::StageInstance); }
    { bool has = index < animation->m_resFile.GetResAnmTexSrtNumEntries(); if (has) setTexSortAnim2(index, resource, animation, Heaps::StageInstance); }
    { bool has = index < animation->m_resFile.GetResAnmClrNumEntries(); if (has) setColorAnim2(index, resource, animation, Heaps::StageInstance); }

    gfModelAnimation::bind(model, animation);
    setFrame__16gfModelAnimationFd(animation, lbl_57_rodata_360);
    animation->setUpdateRate(lbl_57_rodata_378);
    setLoop__16gfModelAnimationFd(animation, loop);
    if (frameCount) *frameCount = getFrameCount__16gfModelAnimationFd(animation);
}

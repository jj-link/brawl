#include <gf/gf_model.h>
#pragma force_active on

class Class_3790 {
public:
    virtual void fn_70_B644();
    virtual void fn_70_AB0C();
    virtual void fn_70_AB1C();
    virtual void fn_70_9164();
    virtual void fn_70_8EEC();
    virtual void fn_70_8A50();
    virtual void fn_70_AE10();
    virtual void fn_70_AECC();
    virtual void fn_70_B5FC();
    virtual void fn_70_AB2C();
    virtual void fn_70_8C08();
};

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad2[0x168 - 0x4C];
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
extern const float lbl_70_rodata_30;
extern const float lbl_70_rodata_38;
}

inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 i) { return ResAnmChr(fn_8018D6D8(this,i)); }
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 i) { return ResAnmVis(fn_8018D8E0(this,i)); }
inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 i) { return ResAnmTexPat(fn_8018DCF0(this,i)); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 i) { return ResAnmTexSrt(fn_8018DEF8(this,i)); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 i) { return fn_8018DAE8(this,i); }

inline bool hasChr(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmChrNumEntries(); }
inline bool hasVis(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmVisNumEntries(); }
inline bool hasTexPat(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmTexPatNumEntries(); }
inline bool hasTexSrt(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmTexSrtNumEntries(); }
inline bool hasClr(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmClrNumEntries(); }

extern "C" void fn_70_2738(Object* self, u8 index, bool loop, bool force, float* frameCount) {
    if (self->current == index && !force) return;
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
    if (index >= 1u) return;
    if (hasVis(animation, index)) setVisibilityAnim2(index, resource, animation, Heaps::StageInstance);
    if (hasChr(animation, index)) setChrAnim2(index, resource, animation, Heaps::StageInstance);
    if (hasTexPat(animation, index)) setTexPatAnim2(index, resource, animation, Heaps::StageInstance);
    if (hasTexSrt(animation, index)) setTexSortAnim2(index, resource, animation, Heaps::StageInstance);
    if (hasClr(animation, index)) setColorAnim2(index, resource, animation, Heaps::StageInstance);
    gfModelAnimation::bind(model, animation);
    setFrame__16gfModelAnimationFd(animation, lbl_70_rodata_30);
    animation->setUpdateRate(lbl_70_rodata_38);
    setLoop__16gfModelAnimationFd(animation, loop);
    if (frameCount) *frameCount = getFrameCount__16gfModelAnimationFd(animation);
}

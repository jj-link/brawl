#include <gf/gf_model.h>
#pragma force_active on

class Class_1A68 {
public:
    virtual void fn_52_8E6C();
    virtual void fn_52_828C();
    virtual void fn_52_829C();
    virtual void fn_52_75D0();
    virtual void fn_52_7344();
    virtual void fn_52_6ED8();
    virtual void fn_52_85C8();
    virtual void fn_52_8684();
    virtual void fn_52_8E24();
    virtual void fn_52_82AC();
    virtual void fn_52_7028();
};

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad2[0x134];
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
extern const float lbl_52_rodata_2B0;
extern const float lbl_52_rodata_2C4;
extern const double lbl_52_rodata_2C8;
}

inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 index) { return ResAnmChr(fn_8018D6D8(this, index)); }
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 index) { return ResAnmVis(fn_8018D8E0(this, index)); }
inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 index) { return ResAnmTexPat(fn_8018DCF0(this, index)); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 index) { return ResAnmTexSrt(fn_8018DEF8(this, index)); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 index) { return fn_8018DAE8(this, index); }

inline bool hasChr(gfModelAnimation* animation, u32 index) { return index < animation->m_resFile.GetResAnmChrNumEntries(); }
inline bool hasVis(gfModelAnimation* animation, u32 index) { return index < animation->m_resFile.GetResAnmVisNumEntries(); }
inline bool hasTexPat(gfModelAnimation* animation, u32 index) { return index < animation->m_resFile.GetResAnmTexPatNumEntries(); }
inline bool hasTexSrt(gfModelAnimation* animation, u32 index) { return index < animation->m_resFile.GetResAnmTexSrtNumEntries(); }
inline bool hasClr(gfModelAnimation* animation, u32 index) { return index < animation->m_resFile.GetResAnmClrNumEntries(); }

extern "C" void fn_52_FD38(Object* self, u8 index, bool loop, bool force, float* frameCount) {
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
    if (index >= 9u) return;

    if (hasChr(animation, index)) setChrAnim2(index, resource, animation, Heaps::StageInstance);
    if (hasVis(animation, index)) setVisibilityAnim2(index, resource, animation, Heaps::StageInstance);
    if (hasTexPat(animation, index)) setTexPatAnim2(index, resource, animation, Heaps::StageInstance);
    if (hasTexSrt(animation, index)) setTexSortAnim2(index, resource, animation, Heaps::StageInstance);
    if (hasClr(animation, index)) setColorAnim2(index, resource, animation, Heaps::StageInstance);

    gfModelAnimation::bind(model, animation);
    setFrame__16gfModelAnimationFd(animation, lbl_52_rodata_2B0);
    animation->setUpdateRate(lbl_52_rodata_2C4);
    setLoop__16gfModelAnimationFd(animation, loop);
    if (frameCount) *frameCount = getFrameCount__16gfModelAnimationFd(animation);
}

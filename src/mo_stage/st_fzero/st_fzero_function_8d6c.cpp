#include <gf/gf_model.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void fn_61_BFE0();
    virtual void fn_61_B400();
    virtual void fn_61_B410();
    virtual void slot3();
    virtual void fn_61_A438();
    virtual void slot5();
    virtual void fn_61_B73C();
    virtual void fn_61_B7F8();
    virtual void fn_61_BF98();
    virtual void fn_61_B420();
    virtual void fn_61_9E1C();
};

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad2[0x168];
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
extern const float lbl_61_rodata_118;
extern const float lbl_61_rodata_140;
}

inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 index) {
    return ResAnmChr(fn_8018D6D8(this, index));
}

inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 index) {
    return ResAnmVis(fn_8018D8E0(this, index));
}

inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 index) {
    return ResAnmTexPat(fn_8018DCF0(this, index));
}

inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 index) {
    return ResAnmTexSrt(fn_8018DEF8(this, index));
}

inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 index) {
    return fn_8018DAE8(this, index);
}

inline bool hasChr(gfModelAnimation* animation, u32 index) {
    return index < animation->m_resFile.GetResAnmChrNumEntries();
}

inline bool hasVis(gfModelAnimation* animation, u32 index) {
    return index < animation->m_resFile.GetResAnmVisNumEntries();
}

inline bool hasTexPat(gfModelAnimation* animation, u32 index) {
    return index < animation->m_resFile.GetResAnmTexPatNumEntries();
}

inline bool hasTexSrt(gfModelAnimation* animation, u32 index) {
    return index < animation->m_resFile.GetResAnmTexSrtNumEntries();
}

inline bool hasClr(gfModelAnimation* animation, u32 index) {
    return index < animation->m_resFile.GetResAnmClrNumEntries();
}

extern "C" void fn_61_8D6C(Object* self, u8 index, bool loop, bool force, float* frameCount) {
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
    if (index >= 5u) return;

    if (hasChr(animation, index))
        setChrAnim2(index, resource, animation, Heaps::StageInstance);
    if (hasVis(animation, index))
        setVisibilityAnim2(index, resource, animation, Heaps::StageInstance);
    if (hasTexPat(animation, index))
        setTexPatAnim2(index, resource, animation, Heaps::StageInstance);
    if (hasTexSrt(animation, index))
        setTexSortAnim2(index, resource, animation, Heaps::StageInstance);
    if (hasClr(animation, index))
        setColorAnim2(index, resource, animation, Heaps::StageInstance);

    gfModelAnimation::bind(model, animation);
    setFrame__16gfModelAnimationFd(animation, lbl_61_rodata_118);
    animation->setUpdateRate(lbl_61_rodata_140);
    setLoop__16gfModelAnimationFd(animation, loop);
    if (frameCount) *frameCount = getFrameCount__16gfModelAnimationFd(animation);
}

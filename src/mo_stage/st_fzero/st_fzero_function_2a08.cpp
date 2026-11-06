#include <gf/gf_model.h>
#pragma force_active on

class Class_2AF8 {
public:
    virtual void fn_61_BFE0();  // offset 0x8
    virtual void fn_61_B400();  // offset 0xc
    virtual void fn_61_B410();  // offset 0x10
    virtual void fn_61_A744();  // offset 0x14
    virtual void fn_61_A438();  // offset 0x18
    virtual void fn_61_9C8C();  // offset 0x1c
    virtual void fn_61_B73C();  // offset 0x20
    virtual void fn_61_B7F8();  // offset 0x24
    virtual void fn_61_BF98();  // offset 0x28
    virtual void fn_61_B420();  // offset 0x2c
    virtual void fn_61_9E1C();  // offset 0x30
};

class Class_3B48 {
public:
    virtual void fn_61_BFE0();  // offset 0x8
    virtual void fn_61_B400();  // offset 0xc
    virtual void fn_61_B410();  // offset 0x10
    virtual void fn_61_E788();  // offset 0x14
    virtual void fn_61_A438();  // offset 0x18
    virtual void fn_61_E6A0();  // offset 0x1c
    virtual void fn_61_B73C();  // offset 0x20
    virtual void fn_61_B7F8();  // offset 0x24
    virtual void fn_61_BF98();  // offset 0x28
    virtual void fn_61_B420();  // offset 0x2c
    virtual void fn_61_9E1C();  // offset 0x30
};

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad2[0x130];
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
extern const float lbl_61_rodata_30;
extern const float lbl_61_rodata_38;
extern const double lbl_61_rodata_40;
}

inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 index) { return ResAnmChr(fn_8018D6D8(this, index)); }
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 index) { return ResAnmVis(fn_8018D8E0(this, index)); }
inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 index) { return ResAnmTexPat(fn_8018DCF0(this, index)); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 index) { return ResAnmTexSrt(fn_8018DEF8(this, index)); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 index) { return fn_8018DAE8(this, index); }

inline bool hasChr(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmChrNumEntries(); }
inline bool hasVis(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmVisNumEntries(); }
inline bool hasTexPat(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmTexPatNumEntries(); }
inline bool hasTexSrt(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmTexSrtNumEntries(); }
inline bool hasClr(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmClrNumEntries(); }

extern "C" void fn_61_2A08(Object* self, u8 index, bool loop, bool force, float* frameCount) {
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
    if (index >= 7u) return;

    if (hasChr(animation, index)) setChrAnim2(index, resource, animation, Heaps::StageInstance);
    if (hasVis(animation, index)) setVisibilityAnim2(index, resource, animation, Heaps::StageInstance);
    if (hasTexPat(animation, index)) setTexPatAnim2(index, resource, animation, Heaps::StageInstance);
    if (hasTexSrt(animation, index)) setTexSortAnim2(index, resource, animation, Heaps::StageInstance);
    if (hasClr(animation, index)) setColorAnim2(index, resource, animation, Heaps::StageInstance);

    gfModelAnimation::bind(model, animation);
    setFrame__16gfModelAnimationFd(animation, lbl_61_rodata_30);
    animation->setUpdateRate(lbl_61_rodata_38);
    setLoop__16gfModelAnimationFd(animation, loop);
    if (frameCount) *frameCount = getFrameCount__16gfModelAnimationFd(animation);
}

#include <gf/gf_model.h>
#pragma force_active on

class Class_1870 {
public:
    virtual void fn_68_94B0();  // offset 0x8
    virtual void fn_68_8978();  // offset 0xc
    virtual void fn_68_8988();  // offset 0x10
    virtual void fn_68_64EC();  // offset 0x14
    virtual void fn_68_61AC();  // offset 0x18
    virtual void fn_68_5D78();  // offset 0x1c
    virtual void fn_68_8C7C();  // offset 0x20
    virtual void fn_68_8D38();  // offset 0x24
    virtual void fn_68_9468();  // offset 0x28
    virtual void fn_68_8998();  // offset 0x2c
    virtual void fn_68_5EC8();  // offset 0x30
};

class Class_2428 {
public:
    virtual void fn_68_E3F0();  // offset 0x8
    virtual void fn_68_D810();  // offset 0xc
    virtual void fn_68_D820();  // offset 0x10
    virtual void fn_68_D700();  // offset 0x14
    virtual void fn_68_D53C();  // offset 0x18
    virtual void fn_68_D120();  // offset 0x1c
    virtual void fn_68_DB4C();  // offset 0x20
    virtual void fn_68_DC08();  // offset 0x24
    virtual void fn_68_E3A8();  // offset 0x28
    virtual void fn_68_D830();  // offset 0x2c
    virtual void fn_68_D220();  // offset 0x30
};

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad2[0x10C];
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
extern const float lbl_68_rodata_148;
extern const float lbl_68_rodata_154;
}

inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 i) { return ResAnmChr(fn_8018D6D8(this, i)); }
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 i) { return ResAnmVis(fn_8018D8E0(this, i)); }
inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 i) { return ResAnmTexPat(fn_8018DCF0(this, i)); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 i) { return ResAnmTexSrt(fn_8018DEF8(this, i)); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 i) { return fn_8018DAE8(this, i); }

inline bool hasChr(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmChrNumEntries(); }
inline bool hasVis(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmVisNumEntries(); }
inline bool hasTexPat(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmTexPatNumEntries(); }
inline bool hasTexSrt(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmTexSrtNumEntries(); }
inline bool hasClr(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmClrNumEntries(); }

extern "C" void fn_68_ED60(Object* self, u8 index, bool loop, bool force, float* frameCount) {
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
    if (index >= 12u) return;

    switch (index) {
    case 1:
        if (hasChr(animation, 0)) setChrAnim2(0, resource, animation, Heaps::StageInstance);
        if (hasVis(animation, 0)) setVisibilityAnim2(0, resource, animation, Heaps::StageInstance);
        break;
    case 5:
        if (hasChr(animation, 1)) setChrAnim2(1, resource, animation, Heaps::StageInstance);
        if (hasVis(animation, 1)) setVisibilityAnim2(1, resource, animation, Heaps::StageInstance);
        break;
    case 9:
        if (hasChr(animation, 2)) setChrAnim2(2, resource, animation, Heaps::StageInstance);
        if (hasVis(animation, 2)) setVisibilityAnim2(2, resource, animation, Heaps::StageInstance);
        break;
    }

    if (hasTexPat(animation, index)) setTexPatAnim2(index, resource, animation, Heaps::StageInstance);
    if (hasTexSrt(animation, index)) setTexSortAnim2(index, resource, animation, Heaps::StageInstance);
    if (hasClr(animation, index)) setColorAnim2(index, resource, animation, Heaps::StageInstance);

    gfModelAnimation::bind(model, animation);
    setFrame__16gfModelAnimationFd(animation, lbl_68_rodata_148);
    animation->setUpdateRate(lbl_68_rodata_154);
    setLoop__16gfModelAnimationFd(animation, loop);
    if (frameCount) *frameCount = getFrameCount__16gfModelAnimationFd(animation);
}

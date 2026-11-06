#include <gf/gf_model.h>
#pragma force_active on

class Class_1898 {
public:
    virtual void fn_67_818C();  // offset 0x8
    virtual void fn_67_7654();  // offset 0xc
    virtual void fn_67_7664();  // offset 0x10
    virtual void fn_67_51C8();  // offset 0x14
    virtual void fn_67_4E88();  // offset 0x18
    virtual void fn_67_4A54();  // offset 0x1c
    virtual void fn_67_7958();  // offset 0x20
    virtual void fn_67_7A14();  // offset 0x24
    virtual void fn_67_8144();  // offset 0x28
    virtual void fn_67_7674();  // offset 0x2c
    virtual void fn_67_4BA4();  // offset 0x30
};

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;      /* 0x44 */
    char pad2[0x124];                /* 0x48 */
    gfModelAnimation* animation;     /* 0x16C */
    char pad3[1];                    /* 0x170 */
    u8 current;                      /* 0x171 */
    char pad4[6];                    /* 0x172 */
    u8 flag;                         /* 0x178 */
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
extern const float lbl_67_rodata_B0;
extern const float lbl_67_rodata_BC;
}

inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 i) { return ResAnmChr(fn_8018D6D8(this, i)); }
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 i) { return ResAnmVis(fn_8018D8E0(this, i)); }
inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 i) { return ResAnmTexPat(fn_8018DCF0(this, i)); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 i) { return ResAnmTexSrt(fn_8018DEF8(this, i)); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 i) { return fn_8018DAE8(this, i); }

extern "C" void fn_67_9B3C(Object* self, u8 index, bool loop, bool force, float* frameCount) {
    if (self->current == index && !force) return;
    nw4r::g3d::ScnMdl* model = *self->models;
    if (!model) return;
    gfModelAnimation* animation = self->animation;
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

    { bool has = index < animation->m_resFile.GetResAnmVisNumEntries(); if (has) setVisibilityAnim2(index, resource, animation, Heaps::StageInstance); }
    { bool has = index < animation->m_resFile.GetResAnmChrNumEntries(); if (has) setChrAnim2(index, resource, animation, Heaps::StageInstance); }
    { bool has = index < animation->m_resFile.GetResAnmTexPatNumEntries(); if (has) setTexPatAnim2(index, resource, animation, Heaps::StageInstance); }
    { bool has = index < animation->m_resFile.GetResAnmTexSrtNumEntries(); if (has) setTexSortAnim2(index, resource, animation, Heaps::StageInstance); }
    { bool has = index < animation->m_resFile.GetResAnmClrNumEntries(); if (has) setColorAnim2(index, resource, animation, Heaps::StageInstance); }

    gfModelAnimation::bind(model, animation);
    setFrame__16gfModelAnimationFd(animation, lbl_67_rodata_B0);
    animation->setUpdateRate(lbl_67_rodata_BC);
    setLoop__16gfModelAnimationFd(animation, loop);
    if (frameCount) *frameCount = getFrameCount__16gfModelAnimationFd(animation);
    self->flag = 1;
}

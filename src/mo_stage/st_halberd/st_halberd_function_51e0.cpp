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
    virtual void fn_57_A830();
};

struct Object {
    char pad0[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad4C[0x118];
    u8 texsrt;
    u8 current;
};

extern "C" {
void* fn_8018D6D8(void*, u32);
nw4r::g3d::ResAnmTexSrt fn_8018DEF8(void*, u32);
nw4r::g3d::ResAnmClr fn_8018DAE8(void*, u32);
void setLoopNode__16gfModelAnimationFd(gfModelAnimation*, bool);
void setLoopMatCol__16gfModelAnimationFd(gfModelAnimation*, bool);
void setLoopTexSrt__16gfModelAnimationFd(gfModelAnimation*, bool);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
extern const float lbl_57_rodata_188;
extern const float lbl_57_rodata_18C;
extern const double lbl_57_rodata_190;
}

inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 index) { return ResAnmChr(fn_8018D6D8(this, index)); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 index) { return fn_8018DEF8(this, index); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 index) { return fn_8018DAE8(this, index); }

extern "C" void fn_57_51E0(Object* self, u8 index, bool loop, bool force, float* frameCount) {
    if (self->current == index && !force)
        return;
    nw4r::g3d::ScnMdl* model = *self->models;
    if (!model) return;
    gfModelAnimation* animation = *self->animations;
    if (!animation) return;
    nw4r::g3d::ResMdl resource = model->m_resMdl;
    if (!resource.IsValid()) return;

    animation->unbindNodeAnim(model);
    animation->unbindMatColAnim(model);
    if (self->texsrt == 0)
        animation->unbindTexSrtAnim(model);
    self->current = index;
    if (index >= 2u) return;

    { bool has = index < animation->m_resFile.GetResAnmChrNumEntries(); if (has) setChrAnim2(index, resource, animation, Heaps::StageInstance); }
    { bool has = index < animation->m_resFile.GetResAnmClrNumEntries(); if (has) setColorAnim2(index, resource, animation, Heaps::StageInstance); }
    if (self->texsrt == 0) {
        bool has = index < animation->m_resFile.GetResAnmTexSrtNumEntries();
        if (has) setTexSortAnim2(index, resource, animation, Heaps::StageInstance);
    }

    gfModelAnimation::bind(model, animation);
    animation->m_anmObjChrRes->SetFrame(lbl_57_rodata_188);
    animation->m_anmObjMatClrRes->SetFrame(lbl_57_rodata_188);
    if (self->texsrt == 0)
        animation->m_anmObjTexSrtRes->SetFrame(lbl_57_rodata_188);
    animation->setUpdateRate(lbl_57_rodata_18C);
    setLoopNode__16gfModelAnimationFd(animation, loop);
    setLoopMatCol__16gfModelAnimationFd(animation, loop);
    if (self->texsrt == 0)
        setLoopTexSrt__16gfModelAnimationFd(animation, loop);
    if (frameCount)
        *frameCount = getFrameCount__16gfModelAnimationFd(animation);
}

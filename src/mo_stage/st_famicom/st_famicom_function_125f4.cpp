#include <gf/gf_model.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_8018D6D8(void*, u32);
void* fn_8018D8E0(void*, u32);
void* fn_8018DCF0(void*, u32);
void* fn_8018DEF8(void*, u32);
nw4r::g3d::ResAnmClr fn_8018DAE8(void*, u32);
void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
extern const float lbl_68_rodata_1D8;
extern const float lbl_68_rodata_1F4;
}
inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 i) { return ResAnmChr(fn_8018D6D8(this, i)); }
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 i) { return ResAnmVis(fn_8018D8E0(this, i)); }
inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 i) { return ResAnmTexPat(fn_8018DCF0(this, i)); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 i) { return ResAnmTexSrt(fn_8018DEF8(this, i)); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 i) { return fn_8018DAE8(this, i); }

struct Fn68Object {
    char pad0[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad1[0x170 - 0x4C];
    u8 unk170;
};
extern "C" void fn_68_125F4(Fn68Object* self, u8 index, bool loop, s32 force, f32* frameOut) {
    if (self->unk170 == index && force == 0) return;
    nw4r::g3d::ScnMdl* scnMdl = self->models[0];
    if (!scnMdl) return;
    gfModelAnimation* anim = self->animations[0];
    if (!anim) return;
    nw4r::g3d::ResMdl model = scnMdl->m_resMdl;
    if (!model.IsValid()) return;
    anim->unbindNodeAnim(scnMdl);
    anim->unbindVisibleAnim(scnMdl);
    anim->unbindTexAnim(scnMdl);
    anim->unbindTexSrtAnim(scnMdl);
    anim->unbindMatColAnim(scnMdl);
    self->unk170 = index;
    if (index >= 1) return;
    bool hasChr = index < anim->m_resFile.GetResAnmChrNumEntries();
    if (hasChr) setChrAnim2(index, model, anim, (Heaps::HeapType)15);
    bool hasVis = index < anim->m_resFile.GetResAnmVisNumEntries();
    if (hasVis) setVisibilityAnim2(index, model, anim, (Heaps::HeapType)15);
    bool hasTexPat = index < anim->m_resFile.GetResAnmTexPatNumEntries();
    if (hasTexPat) setTexPatAnim2(index, model, anim, (Heaps::HeapType)15);
    bool hasTexSrt = index < anim->m_resFile.GetResAnmTexSrtNumEntries();
    if (hasTexSrt) setTexSortAnim2(index, model, anim, (Heaps::HeapType)15);
    bool hasClr = index < anim->m_resFile.GetResAnmClrNumEntries();
    if (hasClr) setColorAnim2(index, model, anim, (Heaps::HeapType)15);
    gfModelAnimation::bind(scnMdl, anim);
    setFrame__16gfModelAnimationFd(anim, lbl_68_rodata_1D8);
    anim->setUpdateRate(lbl_68_rodata_1F4);
    setLoop__16gfModelAnimationFd(anim, loop);
    if (frameOut) *frameOut = (f32)getFrameCount__16gfModelAnimationFd(anim);
}

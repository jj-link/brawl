#include <gf/gf_model.h>
#pragma force_active on
class Class_2110 {
public:
 virtual void fn_57_C674(); virtual void fn_57_BA94(); virtual void fn_57_BAA4(); virtual void fn_57_ADD8(); virtual void fn_57_AB4C(); virtual void fn_57_A6E0(); virtual void fn_57_BDD0(); virtual void fn_57_BE8C(); virtual void fn_57_C62C(); virtual void fn_57_BAB4(); virtual int fn_57_A830(nw4r::g3d::ResMdl);
};
struct Object {
 char pad[0x44];
 nw4r::g3d::ScnMdl** models;
 gfModelAnimation** animations;
 char pad2[0x120];
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
extern const float lbl_57_rodata_198;
extern const float lbl_57_rodata_1B8;
}
inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 i) { return ResAnmChr(fn_8018D6D8(this,i)); }
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 i) { return ResAnmVis(fn_8018D8E0(this,i)); }
inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 i) { return ResAnmTexPat(fn_8018DCF0(this,i)); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 i) { return ResAnmTexSrt(fn_8018DEF8(this,i)); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 i) { return fn_8018DAE8(this,i); }
extern "C" void fn_57_6328(Object* self, u8 index, bool loop, bool force, float* frameCount) {
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
 { bool has = index < animation->m_resFile.GetResAnmChrNumEntries(); if (has) setChrAnim2(index, resource, animation, Heaps::StageInstance); }
 { bool has = index < animation->m_resFile.GetResAnmVisNumEntries(); if (has) setVisibilityAnim2(index, resource, animation, Heaps::StageInstance); }
 { bool has = index < animation->m_resFile.GetResAnmTexPatNumEntries(); if (has) setTexPatAnim2(index, resource, animation, Heaps::StageInstance); }
 { bool has = index < animation->m_resFile.GetResAnmTexSrtNumEntries(); if (has) setTexSortAnim2(index, resource, animation, Heaps::StageInstance); }
 { bool has = index < animation->m_resFile.GetResAnmClrNumEntries(); if (has) setColorAnim2(index, resource, animation, Heaps::StageInstance); }
 gfModelAnimation::bind(model, animation);
 setFrame__16gfModelAnimationFd(animation, lbl_57_rodata_198);
 animation->setUpdateRate(lbl_57_rodata_1B8);
 setLoop__16gfModelAnimationFd(animation, loop);
 if (frameCount) *frameCount = getFrameCount__16gfModelAnimationFd(animation);
}
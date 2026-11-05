#include <gf/gf_model.h>
#pragma force_active on
class Class_1F70 { public: virtual void fn_66_CA8C(); virtual void fn_66_BF54(); virtual void fn_66_BF64(); virtual void fn_66_A44C(); virtual void fn_66_A094(); virtual void fn_66_971C(); virtual void fn_66_C258(); virtual void fn_66_C314(); virtual void fn_66_CA44(); virtual void fn_66_BF74(); virtual void fn_66_9A60(); };
class Class_2068 { public: virtual void fn_66_D8D4(); virtual void fn_66_CCF4(); virtual void fn_66_CD04(); virtual void fn_66_A4E4(); virtual void fn_66_A060(); virtual void fn_66_9840(); virtual void fn_66_D030(); virtual void fn_66_D0EC(); virtual void fn_66_D88C(); virtual void fn_66_CD14(); virtual void fn_66_9D44(); };
class Class_3340 { public: virtual void fn_66_CA8C(); virtual void fn_66_BF54(); virtual void fn_66_BF64(); virtual void fn_66_11350(); virtual void fn_66_A094(); virtual void fn_66_11268(); virtual void fn_66_C258(); virtual void fn_66_C314(); virtual void fn_66_CA44(); virtual void fn_66_BF74(); virtual void fn_66_9A60(); };
struct Object { char pad[0x44]; nw4r::g3d::ScnMdl** models; gfModelAnimation** animations; };
extern "C" {
void* fn_8018D6D8(void*, u32);
void* fn_8018D8E0(void*, u32);
nw4r::g3d::ResAnmClr fn_8018DAE8(void*, u32);
void* fn_8018DCF0(void*, u32);
void* fn_8018DEF8(void*, u32);
void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
extern const float lbl_66_rodata_220;
extern const float lbl_66_rodata_234;
}
inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 i) { return ResAnmChr(fn_8018D6D8(this,i)); }
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 i) { return ResAnmVis(fn_8018D8E0(this,i)); }
inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 i) { return ResAnmTexPat(fn_8018DCF0(this,i)); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 i) { return ResAnmTexSrt(fn_8018DEF8(this,i)); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 i) { return fn_8018DAE8(this,i); }
extern "C" void fn_66_11BDC(Object* self, u8 index, bool loop, float* frameCount) {
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
 if (index >= 3u) return;
 { bool has = index < animation->m_resFile.GetResAnmChrNumEntries(); if (has) setChrAnim2(index, resource, animation, Heaps::StageInstance); }
 { bool has = index < animation->m_resFile.GetResAnmVisNumEntries(); if (has) setVisibilityAnim2(index, resource, animation, Heaps::StageInstance); }
 { bool has = index < animation->m_resFile.GetResAnmTexPatNumEntries(); if (has) setTexPatAnim2(index, resource, animation, Heaps::StageInstance); }
 { bool has = index < animation->m_resFile.GetResAnmTexSrtNumEntries(); if (has) setTexSortAnim2(index, resource, animation, Heaps::StageInstance); }
 { bool has = index < animation->m_resFile.GetResAnmClrNumEntries(); if (has) setColorAnim2(index, resource, animation, Heaps::StageInstance); }
 gfModelAnimation::bind(model, animation);
 setFrame__16gfModelAnimationFd(animation, lbl_66_rodata_220);
 animation->setUpdateRate(lbl_66_rodata_234);
 setLoop__16gfModelAnimationFd(animation, loop);
 if (frameCount) *frameCount = getFrameCount__16gfModelAnimationFd(animation);
}
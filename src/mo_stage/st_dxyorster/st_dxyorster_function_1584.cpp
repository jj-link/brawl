#include <gf/gf_model.h>
#pragma force_active on
class Class_1AB0 {
public:
 virtual void fn_76_6F4C(); virtual void fn_76_6414(); virtual void fn_76_6424();
 virtual void fn_76_3F88(); virtual void fn_76_3BC8(); virtual void fn_76_3314();
 virtual void fn_76_6718(); virtual void fn_76_67D4(); virtual void fn_76_6F04();
 virtual void fn_76_6434(); virtual void fn_76_3524();
};
struct Object {
 char pad[0x44];
 nw4r::g3d::ScnMdl** models;
 gfModelAnimation** animations;
 char pad2[0x115];
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
extern const float lbl_76_rodata_20;
extern const float lbl_76_rodata_2C;
}
inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 i) { return ResAnmChr(fn_8018D6D8(this,i)); }
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 i) { return ResAnmVis(fn_8018D8E0(this,i)); }
inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 i) { return ResAnmTexPat(fn_8018DCF0(this,i)); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 i) { return ResAnmTexSrt(fn_8018DEF8(this,i)); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 i) { return fn_8018DAE8(this,i); }
extern "C" void fn_76_1584(Object* self, u8 index, bool loop, bool force, float* frameCount) {
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
 if (index >= 3u) return;
 { bool has = index < animation->m_resFile.GetResAnmChrNumEntries(); if (has) setChrAnim2(index, resource, animation, Heaps::StageInstance); }
 { bool has = index < animation->m_resFile.GetResAnmVisNumEntries(); if (has) setVisibilityAnim2(index, resource, animation, Heaps::StageInstance); }
 { bool has = index < animation->m_resFile.GetResAnmTexPatNumEntries(); if (has) setTexPatAnim2(index, resource, animation, Heaps::StageInstance); }
 { bool has = index < animation->m_resFile.GetResAnmTexSrtNumEntries(); if (has) setTexSortAnim2(index, resource, animation, Heaps::StageInstance); }
 { bool has = index < animation->m_resFile.GetResAnmClrNumEntries(); if (has) setColorAnim2(index, resource, animation, Heaps::StageInstance); }
 gfModelAnimation::bind(model, animation);
 setFrame__16gfModelAnimationFd(animation, lbl_76_rodata_20);
 animation->setUpdateRate(lbl_76_rodata_2C);
 setLoop__16gfModelAnimationFd(animation, loop);
 if (frameCount) *frameCount = getFrameCount__16gfModelAnimationFd(animation);
}
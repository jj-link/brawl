#include <gf/gf_model.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10();
};
struct Object {
 char pad[0x44];
 nw4r::g3d::ScnMdl** models;
 gfModelAnimation** animations;
 char pad2[0x111];
 u8 current;
};
extern "C" {
void* fn_8018D8E0(void*, u32);
nw4r::g3d::ResAnmClr fn_8018DAE8(void*, u32);
void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
extern const float lbl_63_rodata_208;
extern const float lbl_63_rodata_210;
}
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 i) { return ResAnmVis(fn_8018D8E0(this, i)); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 i) { return fn_8018DAE8(this, i); }
extern "C" void fn_63_16044(Object* self, u32 index, bool loop, bool force, float* frames) {
 if (self->current != index || force) {
  nw4r::g3d::ScnMdl* model = *self->models;
  if (model) {
   gfModelAnimation* anim = *self->animations;
   if (anim) {
    nw4r::g3d::ResMdl res = model->m_resMdl;
    if (res.IsValid()) {
     anim->unbindNodeAnim(model);
     anim->unbindVisibleAnim(model);
     anim->unbindTexAnim(model);
     anim->unbindTexSrtAnim(model);
     anim->unbindMatColAnim(model);
     self->current = index;
     if (index != 2) {
      switch (index) {
      case 0:
       { bool has = 0 < anim->m_resFile.GetResAnmVisNumEntries(); if (has) setVisibilityAnim2(0, res, anim, Heaps::StageInstance); }
       break;
      case 1:
       { bool has = 0 < anim->m_resFile.GetResAnmClrNumEntries(); if (has) setColorAnim2(0, res, anim, Heaps::StageInstance); }
       break;
      }
      gfModelAnimation::bind(model, anim);
      setFrame__16gfModelAnimationFd(anim, lbl_63_rodata_208);
      anim->setUpdateRate(lbl_63_rodata_210);
      setLoop__16gfModelAnimationFd(anim, loop);
      if (frames) *frames = getFrameCount__16gfModelAnimationFd(anim);
     }
    }
   }
  }
 }
}
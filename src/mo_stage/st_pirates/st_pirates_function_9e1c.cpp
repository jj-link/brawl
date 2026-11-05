#include <gf/gf_model.h>
#pragma force_active on

class Class_1A68 {
public:
 virtual void fn_52_8E6C(); virtual void fn_52_828C(); virtual void fn_52_829C();
 virtual void fn_52_75D0(); virtual void fn_52_7344(); virtual void fn_52_6ED8();
 virtual void fn_52_85C8(); virtual void fn_52_8684(); virtual void fn_52_8E24();
 virtual void fn_52_82AC(); virtual void fn_52_7028();
};
struct ModelSlot { char pad[0xE8]; void* resMdl; };
struct Obj { char pad[0x44]; ModelSlot** models; gfModelAnimation** anims; char pad2[0x121]; u8 state; };
extern "C" {
nw4r::g3d::ResAnmChr fn_8018D6D8(gfModelAnimation*, u32);
nw4r::g3d::ResAnmVis fn_8018D8E0(gfModelAnimation*, u32);
nw4r::g3d::ResAnmTexSrt fn_8018DEF8(gfModelAnimation*, u32);
void setFrame__16gfModelAnimationFd(gfModelAnimation*, float);
void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
}
extern float lbl_52_rodata_148;
extern float lbl_52_rodata_150;

static inline void chrAt(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a) {
  int size; nw4r::g3d::ResAnmChr res = fn_8018D6D8(a, i);
  MEMAllocator* alloc = gfHeapManager::getMEMAllocator(Heaps::StageInstance);
  if (res.IsValid()) {
   nw4r::g3d::AnmObjChrRes* obj = nw4r::g3d::AnmObjChrRes::Construct(alloc, &size, res, model, false);
   if (obj) { obj->Bind(model); if (a->m_anmObjChrRes) a->m_anmObjChrRes->Destroy(); a->m_anmObjChrRes = obj; }
  }
}
static inline void chr(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a) {
 if (i < a->m_resFile.GetResAnmChrNumEntries()) chrAt(i, model, a);
}
static inline void visAt(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a) {
  int size; nw4r::g3d::ResAnmVis res = fn_8018D8E0(a, i);
  MEMAllocator* alloc = gfHeapManager::getMEMAllocator(Heaps::StageInstance);
  if (res.IsValid()) {
   nw4r::g3d::AnmObjVisRes* obj = nw4r::g3d::AnmObjVisRes::Construct(alloc, &size, res, model);
   if (obj) { obj->Bind(model); if (a->m_anmObjVisRes) a->m_anmObjVisRes->Destroy(); a->m_anmObjVisRes = obj; }
  }
}
static inline void vis(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a) {
 if (i < a->m_resFile.GetResAnmVisNumEntries()) visAt(i, model, a);
}
static inline void texAt(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a) {
  int size; nw4r::g3d::ResAnmTexSrt res = fn_8018DEF8(a, i);
  if (res.IsValid()) {
   MEMAllocator* alloc = gfHeapManager::getMEMAllocator(Heaps::StageInstance);
   nw4r::g3d::AnmObjTexSrtRes* obj = nw4r::g3d::AnmObjTexSrtRes::Construct(alloc, &size, res, model, false);
   if (obj) { obj->Bind(model); if (a->m_anmObjTexSrtRes) a->m_anmObjTexSrtRes->Destroy(); a->m_anmObjTexSrtRes = obj; }
  }
}
static inline void tex(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a) {
 if (i < a->m_resFile.GetResAnmTexSrtNumEntries()) texAt(i, model, a);
}
extern "C" void fn_52_9E1C(Obj* self, u32 state, bool loop, int force, float* out) {
 nw4r::g3d::ScnMdl* scn;
 if (self->state != state || force) {
  ModelSlot* slot = *self->models;
  if (slot) {
   gfModelAnimation* a = *self->anims;
   if (a) {
    if (slot->resMdl) {
     nw4r::g3d::ResMdl model(slot->resMdl);
     scn = (nw4r::g3d::ScnMdl*)slot;
     a->unbindNodeAnim(scn); a->unbindVisibleAnim(scn); a->unbindTexAnim(scn); a->unbindTexSrtAnim(scn); a->unbindMatColAnim(scn);
     self->state = state;
     if (state < 2) {
      switch (state) {
       case 0:
        { bool has = 0 < a->m_resFile.GetResAnmChrNumEntries(); if (has) chr(0, model, a); }
        { bool has = 0 < a->m_resFile.GetResAnmTexSrtNumEntries(); if (has) tex(0, model, a); }
        break;
       case 1:
        { bool has = 1 < a->m_resFile.GetResAnmChrNumEntries(); if (has) chr(1, model, a); }
        { bool has = 0 < a->m_resFile.GetResAnmVisNumEntries(); if (has) vis(0, model, a); }
        { bool has = 1 < a->m_resFile.GetResAnmTexSrtNumEntries(); if (has) tex(1, model, a); }
        break;
       default: return;
      }
      gfModelAnimation::bind(scn, a);
      setFrame__16gfModelAnimationFd(a, lbl_52_rodata_148);
      a->setUpdateRate(lbl_52_rodata_150);
      setLoop__16gfModelAnimationFd(a, loop);
      if (out) *out = getFrameCount__16gfModelAnimationFd(a);
     }
    }
   }
  }
 }
}
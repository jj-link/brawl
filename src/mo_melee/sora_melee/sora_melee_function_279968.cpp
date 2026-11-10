#include <gf/gf_model.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10();
};
struct grMadein { char pad[0x44]; nw4r::g3d::ScnMdl** models; gfModelAnimation** animations; char pad2[0x24]; Heaps::HeapType heap; void setMotionDetails(u32, u32, u32, u32, u32); };
extern "C" {
nw4r::g3d::ResAnmChr fn_8018D6D8(void*, u32);
nw4r::g3d::ResAnmVis fn_8018D8E0(void*, u32);
nw4r::g3d::ResAnmClr fn_8018DAE8(void*, u32);
nw4r::g3d::ResAnmTexPat fn_8018DCF0(void*, u32);
nw4r::g3d::ResAnmTexSrt fn_8018DEF8(void*, u32);
}
inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 i) { return fn_8018D6D8(this,i); }
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 i) { return fn_8018D8E0(this,i); }
inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 i) { return fn_8018DCF0(this,i); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 i) { return fn_8018DEF8(this,i); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 i) { return fn_8018DAE8(this,i); }
inline void makeChrInner(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
 int size;
 nw4r::g3d::ResAnmChr anim = a->m_resFile.GetResAnmChr(i);
 MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
 if (anim.IsValid()) {
  nw4r::g3d::AnmObjChrRes* p = nw4r::g3d::AnmObjChrRes::Construct(allocator, &size, anim, model, false);
  if (p) {
   p->Bind(model);
   if (a->m_anmObjChrRes) a->m_anmObjChrRes->Destroy();
   a->m_anmObjChrRes = p;
  }
 }
}
inline void makeChr(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
 if (i < a->m_resFile.GetResAnmChrNumEntries()) makeChrInner(i, model, a, heap);
}
inline void makeVisInner(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
 int size;
 nw4r::g3d::ResAnmVis anim = a->m_resFile.GetResAnmVis(i);
 MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
 if (anim.IsValid()) {
  nw4r::g3d::AnmObjVisRes* p = nw4r::g3d::AnmObjVisRes::Construct(allocator, &size, anim, model);
  if (p) {
   p->Bind(model);
   if (a->m_anmObjVisRes) a->m_anmObjVisRes->Destroy();
   a->m_anmObjVisRes = p;
  }
 }
}
inline void makeVis(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
 if (i < a->m_resFile.GetResAnmVisNumEntries()) makeVisInner(i, model, a, heap);
}
inline void makeTexPatInner(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
 int size;
 nw4r::g3d::ResAnmTexPat anim = a->m_resFile.GetResAnmTexPat(i);
 if (anim.IsValid()) {
  MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
  nw4r::g3d::AnmObjTexPatRes* p = nw4r::g3d::AnmObjTexPatRes::Construct(allocator, &size, anim, model, false);
  if (p) {
   p->Bind(model);
   if (a->m_anmObjTexPatRes) a->m_anmObjTexPatRes->Destroy();
   a->m_anmObjTexPatRes = p;
  }
 }
}
inline void makeTexPat(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
 if (i < a->m_resFile.GetResAnmTexPatNumEntries()) makeTexPatInner(i, model, a, heap);
}
inline void makeTexSrtInner(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
 int size;
 nw4r::g3d::ResAnmTexSrt anim = a->m_resFile.GetResAnmTexSrt(i);
 if (anim.IsValid()) {
  MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
  nw4r::g3d::AnmObjTexSrtRes* p = nw4r::g3d::AnmObjTexSrtRes::Construct(allocator, &size, anim, model, false);
  if (p) {
   p->Bind(model);
   if (a->m_anmObjTexSrtRes) a->m_anmObjTexSrtRes->Destroy();
   a->m_anmObjTexSrtRes = p;
  }
 }
}
inline void makeTexSrt(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
 if (i < a->m_resFile.GetResAnmTexSrtNumEntries()) makeTexSrtInner(i, model, a, heap);
}
inline void makeClrInner(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
 int size;
 nw4r::g3d::ResAnmClr anim = a->m_resFile.GetResAnmClr(i);
 if (anim.IsValid()) {
  MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
  nw4r::g3d::AnmObjMatClrRes* p = nw4r::g3d::AnmObjMatClrRes::Construct(allocator, &size, anim, model, false);
  if (p) {
   p->Bind(model);
   if (a->m_anmObjMatClrRes) a->m_anmObjMatClrRes->Destroy();
   a->m_anmObjMatClrRes = p;
  }
 }
}
inline void makeClr(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
 if (i < a->m_resFile.GetResAnmClrNumEntries()) makeClrInner(i, model, a, heap);
}
void grMadein::setMotionDetails(u32 anmChrIndex, u32 anmVisIndex, u32 anmTexPatIndex, u32 anmTexSrtIndex, u32 anmClrIndex) {
 nw4r::g3d::ScnMdl* model = *models;
 if (!model) return;
 gfModelAnimation* animation = *animations;
 if (!animation) return;
 nw4r::g3d::ResMdl resource = model->m_resMdl;
 if (!resource.IsValid()) return;
 animation->unbindNodeAnim(model);
 animation->unbindVisibleAnim(model);
 animation->unbindTexAnim(model);
 animation->unbindTexSrtAnim(model);
 animation->unbindMatColAnim(model);
 { bool has = anmChrIndex < animation->m_resFile.GetResAnmChrNumEntries(); if (has) makeChr(anmChrIndex, resource, animation, heap); }
 { bool has = anmVisIndex < animation->m_resFile.GetResAnmVisNumEntries(); if (has) makeVis(anmVisIndex, resource, animation, heap); }
 { bool has = anmTexPatIndex < animation->m_resFile.GetResAnmTexPatNumEntries(); if (has) makeTexPat(anmTexPatIndex, resource, animation, heap); }
 { bool has = anmTexSrtIndex < animation->m_resFile.GetResAnmTexSrtNumEntries(); if (has) makeTexSrt(anmTexSrtIndex, resource, animation, heap); }
 { bool has = anmClrIndex < animation->m_resFile.GetResAnmClrNumEntries(); if (has) makeClr(anmClrIndex, resource, animation, heap); }
 gfModelAnimation::bind(model, animation);
}

#include <gf/gf_model.h>
#pragma force_active on
class Class_1640 { public:
virtual void fn_47_7394(); virtual void fn_47_685C(); virtual void fn_47_686C(); virtual void fn_47_4D54(); virtual void fn_47_499C(); virtual void fn_47_4024(); virtual void fn_47_6B60(); virtual void fn_47_6C1C(); virtual void fn_47_734C(); virtual void fn_47_687C(); virtual void fn_47_4368();
};
class Class_18E8 { public:
virtual void fn_47_8D88(); virtual void fn_47_81A8(); virtual void fn_47_81B8(); virtual void fn_47_4EB4(); virtual void fn_47_4968(); virtual void fn_47_41B0(); virtual void fn_47_84E4(); virtual void fn_47_85A0(); virtual void fn_47_8D40(); virtual void fn_47_81C8(); virtual void fn_47_464C();
};
struct Object { char pad[0x44]; nw4r::g3d::ScnMdl** models; gfModelAnimation** animations; char pad2[0x11e]; u8 current; };
extern "C" int __cntlzw(unsigned int);
extern "C" void* fn_8018D6D8(void*, u32);
extern "C" void* fn_8018D8E0(void*, u32);
extern "C" void* fn_8018DCF0(void*, u32);
extern "C" void* fn_8018DEF8(void*, u32);
extern "C" void* fn_8018DAE8(void*, u32);
extern "C" void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
extern "C" void setLoop__16gfModelAnimationFd(gfModelAnimation*, int);
extern "C" const float lbl_47_rodata_F4;
extern "C" const float lbl_47_rodata_100;
inline void innerChr(u32 index, nw4r::g3d::ResMdl model, gfModelAnimation* anim) {
 int size;
 nw4r::g3d::ResAnmChr resource(fn_8018D6D8(&anim->m_resFile, index));
 MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
 if (resource.IsValid()) {
 
 nw4r::g3d::AnmObjChrRes* object = nw4r::g3d::AnmObjChrRes::Construct(allocator, &size, resource, model, false);
 if (object) {
 object->Bind(model);
 if (anim->m_anmObjChrRes) anim->m_anmObjChrRes->Destroy();
 anim->m_anmObjChrRes = object;
 }
 }
}
inline void applyChr(u32 index, nw4r::g3d::ResMdl model, gfModelAnimation* anim) {
 if (index < anim->m_resFile.GetResAnmChrNumEntries()) innerChr(index, model, anim);
}
inline void innerVis(u32 index, nw4r::g3d::ResMdl model, gfModelAnimation* anim) {
 int size;
 nw4r::g3d::ResAnmVis resource(fn_8018D8E0(&anim->m_resFile, index));
 MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
 if (resource.IsValid()) {
 
 nw4r::g3d::AnmObjVisRes* object = nw4r::g3d::AnmObjVisRes::Construct(allocator, &size, resource, model);
 if (object) {
 object->Bind(model);
 if (anim->m_anmObjVisRes) anim->m_anmObjVisRes->Destroy();
 anim->m_anmObjVisRes = object;
 }
 }
}
inline void applyVis(u32 index, nw4r::g3d::ResMdl model, gfModelAnimation* anim) {
 if (index < anim->m_resFile.GetResAnmVisNumEntries()) innerVis(index, model, anim);
}
inline void innerTexPat(u32 index, nw4r::g3d::ResMdl model, gfModelAnimation* anim) {
 int size;
 nw4r::g3d::ResAnmTexPat resource(fn_8018DCF0(&anim->m_resFile, index));
 
 if (resource.IsValid()) {
 MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
 nw4r::g3d::AnmObjTexPatRes* object = nw4r::g3d::AnmObjTexPatRes::Construct(allocator, &size, resource, model, false);
 if (object) {
 object->Bind(model);
 if (anim->m_anmObjTexPatRes) anim->m_anmObjTexPatRes->Destroy();
 anim->m_anmObjTexPatRes = object;
 }
 }
}
inline void applyTexPat(u32 index, nw4r::g3d::ResMdl model, gfModelAnimation* anim) {
 if (index < anim->m_resFile.GetResAnmTexPatNumEntries()) innerTexPat(index, model, anim);
}
inline void innerTexSrt(u32 index, nw4r::g3d::ResMdl model, gfModelAnimation* anim) {
 int size;
 nw4r::g3d::ResAnmTexSrt resource(fn_8018DEF8(&anim->m_resFile, index));
 
 if (resource.IsValid()) {
 MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
 nw4r::g3d::AnmObjTexSrtRes* object = nw4r::g3d::AnmObjTexSrtRes::Construct(allocator, &size, resource, model, false);
 if (object) {
 object->Bind(model);
 if (anim->m_anmObjTexSrtRes) anim->m_anmObjTexSrtRes->Destroy();
 anim->m_anmObjTexSrtRes = object;
 }
 }
}
inline void applyTexSrt(u32 index, nw4r::g3d::ResMdl model, gfModelAnimation* anim) {
 if (index < anim->m_resFile.GetResAnmTexSrtNumEntries()) innerTexSrt(index, model, anim);
}
inline void innerClr(u32& index, nw4r::g3d::ResMdl model, gfModelAnimation* anim) {
 int size;
 index = (u32)fn_8018DAE8(&anim->m_resFile, index);
 nw4r::g3d::ResAnmClr resource((void*)index);
 
 if (resource.IsValid()) {
 MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
 nw4r::g3d::AnmObjMatClrRes* object = nw4r::g3d::AnmObjMatClrRes::Construct(allocator, &size, resource, model, false);
 if (object) {
 object->Bind(model);
 if (anim->m_anmObjMatClrRes) anim->m_anmObjMatClrRes->Destroy();
 anim->m_anmObjMatClrRes = object;
 }
 }
}
inline void applyClr(u32& index, nw4r::g3d::ResMdl model, gfModelAnimation* anim) {
 if (index < anim->m_resFile.GetResAnmClrNumEntries()) innerClr(index, model, anim);
}
extern "C" void fn_47_B4AC(Object* self, u32 index, int loop, int force, float* length) {
 if (self->current != index || force) {
  nw4r::g3d::ScnMdl* scene = *self->models;
  if (scene) {
   gfModelAnimation* anim = *self->animations;
   if (anim) {
    nw4r::g3d::ResMdl model = scene->m_resMdl;
    if (model.IsValid()) {
     anim->unbindNodeAnim(scene); anim->unbindVisibleAnim(scene); anim->unbindTexAnim(scene);
     anim->unbindTexSrtAnim(scene); anim->unbindMatColAnim(scene);
     self->current = index;
     if (index < 1) {
      u32 count = anim->m_resFile.GetResAnmChrNumEntries();
      if ((count << __cntlzw(count ^ index)) >> 31) applyChr(index, model, anim);
      count = anim->m_resFile.GetResAnmVisNumEntries();
      if ((count << __cntlzw(count ^ index)) >> 31) applyVis(index, model, anim);
      count = anim->m_resFile.GetResAnmTexPatNumEntries();
      if ((count << __cntlzw(count ^ index)) >> 31) applyTexPat(index, model, anim);
      count = anim->m_resFile.GetResAnmTexSrtNumEntries();
      if ((count << __cntlzw(count ^ index)) >> 31) applyTexSrt(index, model, anim);
      count = anim->m_resFile.GetResAnmClrNumEntries();
      if ((count << __cntlzw(count ^ index)) >> 31) applyClr(index, model, anim);
      gfModelAnimation::bind(scene, anim);
      setFrame__16gfModelAnimationFd(anim, lbl_47_rodata_F4);
      anim->setUpdateRate(lbl_47_rodata_100);
      setLoop__16gfModelAnimationFd(anim, loop);
      if (length) *length = anim->m_anmObjMatClrRes->m_anmMatClrFile.ptr()->m_animLength;
     }
    }
   }
  }
 }
}
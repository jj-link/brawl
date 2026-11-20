#include <types.h>
#include <gf/gf_task.h>
#include <it/item.h>
#include <so/so_external_value_accesser.h>
#pragma force_active on
#define V(n) virtual void slot##n();
class Object_vptr_0 {
public:
 V(0) V(1) V(2)
 virtual int slot3(int = 0, void* = 0);
 V(4) V(5) V(6) V(7) V(8) V(9)
 virtual void slot10(float);
 V(11) V(12) V(13) V(14)
 virtual void slot15(Vec3f*, int);
 virtual int slot16();
 virtual int slot17(u32, void*);
 V(18)
 virtual void slot19();
};
class LinkModule {
public:
 V(0) V(1) V(2) virtual int slot3();
 V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
};
#undef V
struct Modules { char p0[12]; Object_vptr_0* anim; char p10[4]; LinkModule* link; char p18[0x4c]; Object_vptr_0* search; char p68[8]; Object_vptr_0* mode; };
struct Owner { char pad[0xd8]; Modules* modules; };
struct StateHolder { char pad[0x70]; Object_vptr_0* state; };
extern "C" {
extern char lbl_27_data_248[];
extern char __RTTI__6gfTask[];
extern const float lbl_27_rodata_46C8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f fn_27_290060(BaseItem*);
s32 sendTouchMessage__8BaseItemFiP5Vec3ff(BaseItem*, s32, Vec3f*, f32);
}
static inline Modules* modOf(BaseItem* item) {
 return (*(Owner**)((char*)item + 0x60))->modules;
}
extern "C" int fn_27_29B064(void* self, void* itemArg, s32 taskId, void* unused, Vec3f* pos) {
 BaseItem* item = (BaseItem*)itemArg;
 const float* k = lbl_27_rodata_46C8;
 if ((*(StateHolder**)((char*)item + 0x1a4))->state->slot16() == 6) return 0;
 if (modOf(item)->search->slot17(0x12000001, *(void**)((char*)item + 0x60))) {
  gfTask* task = gfTask::getTask(taskId);
  StageObject* obj = task ? (StageObject*)__dynamic_cast(task, 0x3c, lbl_27_data_248, __RTTI__6gfTask, 0) : 0;
  if (obj) {
   Vec3f tp = soExternalValueAccesser::getPos(obj);
   Vec3f ip = fn_27_290060(item);
   float rate;
   float b = ip.m_x;
   if (tp.m_x >= b) rate = k[0]; else rate = k[4];
   modOf(item)->anim->slot10(rate);
   modOf(item)->anim->slot19();
   Vec3f np;
   np.m_x = k[5]; np.m_y = k[5]; np.m_z = k[30] * rate;
   modOf(item)->anim->slot15(&np, 0);
  }
 }
 if ((u8)sendTouchMessage__8BaseItemFiP5Vec3ff(item, taskId, pos, item->getParamFloat(0x1ac3))) {
  s32 mode = 8;
  if (!modOf(item)->link->slot3()) mode = 11;
  modOf(item)->mode->slot3(mode, *(void**)((char*)item + 0x60));
 }
 return 0;
}
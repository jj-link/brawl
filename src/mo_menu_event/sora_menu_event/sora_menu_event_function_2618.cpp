#include <types.h>
#include <gf/gf_pad_status.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_scene.h>
#include <mu/mu_object.h>
#include <snd/snd_system.h>
#pragma force_active on
extern "C" {
extern float lbl_9_rodata_0[];
extern char lbl_9_data_268[];
extern char lbl_9_data_298[];
void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_800BA364(void*, u32);
void fn_9_1BE0(char*, unsigned int, unsigned int);
void fn_9_1F94(char*, unsigned int, unsigned int);
}
class Anim {
public:
 virtual void v0();
 virtual void v1();
 virtual void v2();
 virtual void v3();
 virtual void v4();
 virtual void v5();
 virtual float getFrame();
 virtual void v7();
 virtual void setFrame(float);
};
struct Tmp {
 u32 a, b, c, d, e, f, g, h;
 u8 i;
};
extern "C" Tmp fn_9_23A4(void*);
static inline void confirmSelection(char* self) {
  Tmp t = fn_9_23A4(self);
  char* m = (char*)__dynamic_cast(
   gfSceneManager::getInstance()->m_currentScene,
   4, lbl_9_data_268, lbl_9_data_298, 0);
  *(s32*)(m + 0x360) = t.a;
  *(s32*)(m + 0x364) = t.b;
  *(s32*)(m + 0x368) = t.c;
  *(s32*)(m + 0x36C) = t.d;
  *(s32*)(m + 0x370) = t.e;
  *(s32*)(m + 0x374) = t.f;
  *(s32*)(m + 0x378) = t.g;
  *(s32*)(m + 0x37C) = t.h;
  *(u8*)(m + 0x380) = (u8)t.i;
  g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
  __dynamic_cast(gfSceneManager::getInstance()->m_currentScene,
   4, lbl_9_data_268, lbl_9_data_298, 0);
  gfSceneManager* mgr = gfSceneManager::getInstance();
  mgr->unk1 = 0;
  mgr->processStep = 2;
}
static inline void setNodeFrame(MuObject* obj, float* base, int index) {
 int offset = index * 4;
 float* frames = base + 62;
 obj->setFrameNode(*(float*)((char*)frames + offset));
}
static inline gfPadStatus getMergedPad(char* self) {
 char* p = self;
 gfPadStatus bufs[2];
 gfPadStatus* dst = bufs;
 int n = (*(s32*)(self + 0x17BC) == 1) + 1;
 for (int i = 0; i < n; i++) {
  g_gfPadSystem->getSysPadStatus(*(s32*)(p + 0x17D8), dst);
  dst++;
  p += 4;
 }
 gfPadStatus ret;
 gfPadSystem::merge(bufs, n, &ret);
 return ret;
}
static inline int advanceSelection(char* self, int count) {
 s32 idx = *(s32*)(self + 0x17B8);
 if (idx < count - 1) {
  *(s32*)(self + 0x17B8) = idx + 1;
  return 1;
 }
 *(s32*)(self + 0x17B8) = 0;
 return 0;
}
#pragma opt_propagation off
extern "C" s32 fn_9_2618(char* self) {
 float* base = lbl_9_rodata_0;
 s32 row = *(s32*)(self + 0x17BC);
 u8 count = *(u8*)(self + row * 0x404 + 0x13B0);
 u32 flags = *(u32*)(self + 0x1C8);
 s32 var = 3;
 if (flags & 2) {
  var = advanceSelection(self, count);
  if (*(s32*)(self + 0x17B8) == (s32)((u32)count - 1)) {
   fn_800BA364(self + 0x1B8, 2);
  }
 }
 if (flags & 1) {
  s32 idx = *(s32*)(self + 0x17B8);
  if (idx > 0) {
   var = 2;
   *(s32*)(self + 0x17B8) = idx - 1;
  } else {
   var = 0;
   *(s32*)(self + 0x17B8) = count - 1;
  }
  if (*(s32*)(self + 0x17B8) == 0) {
   fn_800BA364(self + 0x1B8, 1);
  }
 }
 if (flags & 4) {
  s32 idx = *(s32*)(self + 0x17B8);
  if (idx < count - 20) {
   var = 0;
   *(s32*)(self + 0x17B8) = idx + 20;
  } else if (idx >= 20) {
   while (*(s32*)(self + 0x17B8) >= 20) {
    *(s32*)(self + 0x17B8) = *(s32*)(self + 0x17B8) - 20;
   }
   var = 0;
  }
  fn_800BA364(self + 0x1B8, 4);
 }
 if (flags & 8) {
  s32 idx = *(s32*)(self + 0x17B8);
  if (idx >= 20) {
   var = 0;
   *(s32*)(self + 0x17B8) = idx - 20;
  } else if (idx + 20 < count) {
   while (*(s32*)(self + 0x17B8) + 20 < count) {
    *(s32*)(self + 0x17B8) = *(s32*)(self + 0x17B8) + 20;
   }
   var = 0;
  }
  fn_800BA364(self + 0x1B8, 8);
 }
 if (var != 3) {
  fn_9_1F94(self, *(u32*)(self + 0x17B8), *(u32*)(self + 0x17BC));
  MuObject* obj = *(MuObject**)(self + 0x48);
  setNodeFrame(obj, base, var);
  Anim* anim = *(Anim**)((char*)obj->m_modelAnim + 0xC);
  anim->setFrame(var == 0 ? base[0x25] : base[0x24]);
  *(s32*)(self + 0x17C4) = var;
  fn_9_1BE0(self, *(u32*)(self + 0x17B8), *(u32*)(self + 0x17BC));
  g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
 }
 if (getMergedPad(self).m_buttonsPressedThisFrame.bits & 0x1100) {
  g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
  return 3;
 }
 if (getMergedPad(self).m_buttonsPressedThisFrame.bits & 0x200) {
  confirmSelection(self);
 }
 return (s32)*(void**)(self + 0x1A0);
}

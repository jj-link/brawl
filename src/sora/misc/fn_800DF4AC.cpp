#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <stdio.h>
#pragma force_active on
extern "C" void fn_800B22B8(void*);
extern "C" void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
extern char lbl_8059E228[8];
extern const float lbl_805A2374;
class SceneModelVTable {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(int); virtual void slot13();
 char pad[0xe0]; int count;
};
class ParentVTable {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(int, SceneModelVTable*);
 virtual void slot12(); virtual void slot13(SceneModelVTable*);
 char pad[0xe0]; int count;
};
class RateVTable {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void setRate(float);
};
struct Self {
 char pad0[8]; ParentVTable* parent; char pad1[0x130];
 MuObject* node; MuObject* digits[4]; char pad2[0x10]; SceneModelVTable* scene;
};
inline int minValue(int a, int b) { return a < b ? a : b; }
inline int clampValue(int value) {
 return minValue(value & ((-value & ~value) >> 31), 9999);
}
extern "C" void fn_800DF4AC(Self* self, int value) {
 SceneModelVTable* scene = self->scene;
 while (scene->count != 0) {
  if (scene->count != 0) scene->slot12(scene->count - 1);
 }
 self->parent->slot13(scene);
 value = clampValue(value);
 int digitCount = 0;
 while (digitCount < 4 && (value > 0 || digitCount == 0)) {
  MuObject* object = self->digits[digitCount];
  object->setFrameTex((float)(value % 10));
  RateVTable* rate = *(RateVTable**)(*(char**)((char*)object + 0x14) + 0x10);
  rate->setRate(lbl_805A2374);
  fn_800B22B8(object);
  char name[8];
  sprintf(name, lbl_8059E228, digitCount);
  Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(scene, object->m_sceneModel, name);
  ++digitCount;
  value /= 10;
 }
 MuObject* node = self->node;
 node->setFrameNode((float)digitCount);
 RateVTable* rate = *(RateVTable**)(*(char**)((char*)node + 0x14) + 0xc);
 rate->setRate(lbl_805A2374);

 ParentVTable* parent = self->parent;
 parent->slot11(parent->count, scene);
}
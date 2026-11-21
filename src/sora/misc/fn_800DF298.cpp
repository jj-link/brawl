#include <types.h>
#include <mu/menu.h>
#include <mu/mu_object.h>
#include <stdio.h>
#pragma force_active on

class Scene {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(int); virtual void slot13();
 char pad[0xe0]; int count;
};
class Parent {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(int, Scene*);
 virtual void slot12(); virtual void slot13(Scene*);
 char pad[0xe0]; int count;
};
struct Self {
 char pad0[8]; Parent* parent; char pad1[0x68]; MuObject* objects[50];
 char pad2[0x20]; Scene* scene;
};
struct Entry { int kind; u8 color; };
extern "C" {
 int fn_800AF904(int);
 void fn_800B7224(void*, u32, const char*, void*);
 void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
}
extern char lbl_80459FE8[];
extern char lbl_80459FF4[];
extern char lbl_8059E228[8];

inline void removeChild(Scene* scene) {
 if (scene->count != 0) scene->slot12(scene->count - 1);
}

extern "C" void fn_800DF298(Self* self, Entry* entries, int count, void* tex) {
 int kind;
 Self* current;
 Scene* scene = self->scene;
 int i;
 while (scene->count != 0) {
  removeChild(scene);
 }
 self->parent->slot13(scene);
 current = self;
 for (i = 0; i < count && i < 50; ++entries, current = (Self*)((char*)current + 4), ++i) {
  kind = entries->kind;
  int base = (int)(float)(muMenu::exchangeGmCharacterKind2Something(kind) * 10 + 1);
  int maxColor = fn_800AF904(kind);
  int color = entries->color;
  if (color >= maxColor) color = 0;
  char buf1[16];
  sprintf((base += color, buf1), lbl_80459FE8, base);
  MuObject* object = current->objects[0];
  nw4r::g3d::ResMat mat = object->m_resMdl.GetResMat(lbl_80459FF4);
  fn_800B7224(object, mat.ptr()->m_id, buf1, tex);
  char buf2[8];
  sprintf(buf2, lbl_8059E228, i);
  Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(scene, object->m_sceneModel, buf2);
 }
 self->parent->slot11(self->parent->count, scene);
}
#include <mu/mu_msg.h>
#pragma force_active on
class Scene {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10();
 virtual void add(void*, void*); virtual void v14(); virtual void remove(void*);
 char pad[0xe0]; void* group;
};
class Anim {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void frame(float);
};
struct Entry { int type; char pad[8]; unsigned char flag; char pad2[3]; unsigned int image; char pad3[12]; char name[1]; };
struct Item { int a; int b; int index; };
struct Self { char pad0[0x50]; Scene* scene; char pad1[0x2c]; MuObject* object; char pad2[0x208]; Item items[1]; };
extern "C" Entry* fn_11_8134(void*, int);
extern "C" void fn_8006BCA8(char*, const void*);
extern "C" void fn_801F28F0(void*, unsigned int, unsigned short, unsigned short, unsigned int, unsigned int, unsigned int, unsigned char);
extern "C" void fn_800B70D0(void*, const char*, void*);
extern void* lbl_11_bss_8;
extern const char* lbl_11_data_414;
extern const float lbl_11_rodata_0[];
inline void setVis(MuObject* obj, Entry* entry, const float* rodata) {
 obj->setFrameVisible(entry->flag ? rodata[70] : rodata[69]);
}
extern "C" void fn_11_6384(Self* self, int index) {
 const float* rodata = lbl_11_rodata_0;
 char name[0x50];
 char texture[0x20];
 self->scene->remove(self->object->m_sceneModel);
 Item* item = &self->items[index];
 int kind;
 if (item->index >= 0) {
  switch (fn_11_8134(lbl_11_bss_8, item->index)->type) {
  case 3: kind = 0; break;
  case 4: kind = 2; break;
  default: kind = 1; break;
  }
 } else { kind = 1; }
 if (kind == 0) {
  fn_8006BCA8(name, fn_11_8134(lbl_11_bss_8, item->index)->name);
  (*(MuMsg**)((char*)self + 0x6064))->printf(0, name);
  MuObject* obj = self->object;
  fn_801F28F0(texture, fn_11_8134(lbl_11_bss_8, item->index)->image, 0xa0, 0x78, 6, 0, 0, 0);
  fn_800B70D0(obj, lbl_11_data_414, texture);
  setVis(obj, fn_11_8134(lbl_11_bss_8, item->index), rodata);
  (*(Anim**)((char*)obj->m_modelAnim + 8))->frame(rodata[0]);
  self->scene->add(self->scene->group, obj->m_sceneModel);
 }
}
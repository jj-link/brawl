#include <mu/mu_object.h>
#pragma force_active on
class Group {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10();
 virtual void insert(int, nw4r::g3d::ScnMdl*);
 virtual void v12();
 virtual void remove(nw4r::g3d::ScnMdl*);
 char pad[0xe0];
 int count;
};
struct Menu {
 char pad[0x50]; Group* group; char pad54[0xc]; MuObject* obj60; MuObject* obj64;
 char pad68[0x60e8]; unsigned char flag;
};
struct Global { char pad[0x10]; unsigned char* a; char pad14[8]; unsigned char* b; };
inline bool inRange(int mode) { if (mode >= 4 && mode < 12) return true; return false; }
extern "C" {
extern Global* g_GameGlobal;
extern const float lbl_11_rodata_0[];
extern const float lbl_11_rodata_164[];
int fn_11_2320(Menu*);
void fn_11_23F4(Menu*, int);
void fn_11_25A0(Menu*, int, int, int, int, int, int);
void fn_11_E4C(Menu* self) {
 unsigned char* a = g_GameGlobal->a;
 unsigned char* b = g_GameGlobal->b;
 int frame = fn_11_2320(self);
 if (frame != 0) {
  MuObject* obj = self->obj60;
  self->group->remove(obj->m_sceneModel);
  obj->m_modelAnim->setUpdateRate(lbl_11_rodata_0[0]);
  obj->setFrameTex((float)frame);
  self->group->insert(self->group->count, obj->m_sceneModel);
  int mode = a[4];
  bool special = inRange(mode);
  if (!special && ((unsigned char)mode != 3 || !self->flag)) {
   MuObject* obj2 = self->obj64;
   int kind = b[2];
   self->group->remove(obj2->m_sceneModel);
   obj2->m_modelAnim->setUpdateRate(lbl_11_rodata_0[0]);
   obj2->setFrameTex(lbl_11_rodata_164[kind]);
   self->group->insert(self->group->count, obj2->m_sceneModel);
   int value;
   if (b[2] != 1) {
    value = b[3];
    if (value <= 0) value = -1;
   } else value = b[4];
   fn_11_23F4(self, value);
   unsigned char* p = a;
   unsigned char* q = a;
   for (int i = 0; i < 4; ++i, p += 0x5c, q += 4) {
    fn_11_25A0(self, i, p[0xb9], q[0xa], p[0xbd], a[0x33], p[0xc3]);
   }
  }
 }
}
}
#include <types.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scngroup.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <stdio.h>
#pragma force_active on
extern "C" int fn_800B61C0(void*);
extern "C" void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
extern const float lbl_15_rodata_0[];
extern const char lbl_15_data_150[];
struct MenuWatch {
 char pad0[0x4c]; void* m4c;
 char pad1[0x74 - 0x50]; MuObject* m74;
 char pad2[0x194 - 0x78]; nw4r::g3d::ScnGroup* m194;
 char pad3[0x4ec - 0x198]; int m4ec;
 char pad4[0x504 - 0x4f0]; int m504;
 char pad5[0x514 - 0x508]; int m514;
};
extern "C" int fn_15_27EC(MenuWatch* self) {
 const float* c = lbl_15_rodata_0;
 int idx;
 MuObject* obj;
 nw4r::g3d::ScnGroup* mdl;
 int ret = self->m504;
 if (fn_800B61C0(self->m4c)) {
  switch (self->m4ec) {
  case 0: break;
  case 1: case 2: case 5: ret = 1; break;
  case 4: ret = 9; break;
  case 3: ret = 2; break;
  }
  idx = self->m514;
  obj = self->m74;
  mdl = self->m194;
  float f;
  switch (idx) {
  case 0: f = c[0]; break;
  case 1: case 2: case 3: case 4: f = c[1]; break;
  case 5: case 6: f = c[0x3a]; break;
  }
  obj->setFrameVisible(f);
  mdl->Remove(obj->m_sceneModel);
  char buf[16];
  sprintf(buf, lbl_15_data_150, idx);
  Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(mdl, obj->m_sceneModel, buf);
 }
 return ret;
}
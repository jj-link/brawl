#include <nw4r/math/math_arithmetic.h>
#include <nw4r/g3d/g3d_resmdl.h>
#include <types.h>
#pragma force_active on
extern const float lbl_50_rodata_5C;
struct ResObj { char pad[0xE8]; void* fe8; };
struct Obj {
 char pad0[0x44]; ResObj** f44;
 char padA[0xC4-0x48]; u32 fc4;
 char padB[0x158-0xC8]; f32 f158, f15c, f160;
};
extern "C" void fn_50_20F4(Obj* self) {
 s32 r5 = 0;
 s32 r0 = 0;
 if ((float)(double)nw4r::math::FAbs(self->f158) < lbl_50_rodata_5C) r0 = 1;
 if (r0 != 0) {
  r0 = 0;
  if ((float)(double)nw4r::math::FAbs(self->f15c) < lbl_50_rodata_5C) r0 = 1;
  if (r0 != 0) {
   r0 = 0;
   if ((float)(double)nw4r::math::FAbs(self->f160) < lbl_50_rodata_5C) r0 = 1;
   if (r0 != 0) r5 = 1;
  }
 }
 if (r5 != 0) {
  nw4r::g3d::ResMdl mdl;
  ResObj* p = *self->f44;
  if (p != 0) {
   mdl = nw4r::g3d::ResMdl(p->fe8);
   if (mdl.IsValid()) {
    nw4r::g3d::ResNode node = mdl.GetResNode(self->fc4);
    if (node.IsValid()) {
     self->f158 = node.ref().m_scale.m_x;
     self->f15c = node.ref().m_scale.m_y;
     self->f160 = node.ref().m_scale.m_z;
    }
   }
  }
 }
}
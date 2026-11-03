#include <nw4r/math/math_arithmetic.h>
#include <mt/mt_vector.h>
#include <ai/ai_mgr.h>
#pragma force_active on
inline float clamp(float t, float lo, float hi) {
 float a = nw4r::math::FSelect(t - lo, t, lo);
 return nw4r::math::FSelect(a - hi, hi, a);
}
extern "C" {
extern const float lbl_51_rodata_0[];
int setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(aiMgr*, Vec2f*, Vec2f*, int, bool, bool);
struct Stage {
 char pad[0x1D8]; float left; float bottom; float z0; float right; float top; float z1;
 char pad2[0x460 - 0x1F0]; float time; char pad3[8]; int danger;
};
void fn_51_1CBC(void* arg0) {
 Stage* self = (Stage*)arg0;
 const float* const c = lbl_51_rodata_0;
 Vec2f second, first;
 if (self->time >= c[6]) {
  first.m_y = self->top - c[7] * (self->top - self->bottom);
 } else if (self->time >= c[8]) {
  float num = self->time - c[8];
  float t = num / c[9];
  float b = clamp(t, c[0], c[10]);
  first.m_y = self->top - (c[11] - c[12] * b) * (self->top - self->bottom);
 } else if (self->time >= c[13]) {
  float num = self->time - c[13];
  float t = num / c[14];
  t = clamp(t, c[0], c[10]);
  first.m_y = self->top - (c[7] + c[12] * t) * (self->top - self->bottom);
 } else {
  first.m_y = self->top - c[7] * (self->top - self->bottom);
 }
 first.m_x = self->left;
 second.m_y -= c[2];
 second.m_x = self->right;
 second.m_y = self->top;
 self->danger = setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(g_aiMgr, &first, &second, self->danger, false, false);
}
}
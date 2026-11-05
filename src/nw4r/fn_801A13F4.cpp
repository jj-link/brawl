#include <types.h>
#pragma force_active on
struct V { float x, y, z; V(float a, float b, float c) : x(a), y(b), z(c) {} };
struct M { float m[3][4]; };
struct S { char pad[4]; char active[3]; char pad2; M m[3]; };
extern const float lbl_805A332C;
extern const float lbl_805A3328;
extern const float lbl_805A331C;
extern "C" void fn_80162894(M*);
extern "C" void fn_801EC1B8(M*, M*, M*);
extern "C" void fn_801ED008(const V*, V*);
extern "C" void fn_801A13F4(S* self, int index, const V* v, M* matrix, int mode) {
 if (index >= 1 && index <= 3 && mode != 0) {
  int i = index - 1;
  self->active[i] = 1;
  if (v) {
   self->m[i].m[0][0] = lbl_805A332C * -v->x;
   M* m = &self->m[i];
   m->m[0][1] = lbl_805A332C * -v->y;
   m->m[0][2] = lbl_805A332C * -v->z;
   if (mode == 2) {
    V tmp(v->x, v->y, v->z - lbl_805A3328);
    fn_801ED008(&tmp, &tmp);
    self->m[i].m[1][0] = lbl_805A332C * -tmp.x;
    self->m[i].m[1][1] = lbl_805A332C * -tmp.y;
    self->m[i].m[1][2] = lbl_805A332C * -tmp.z;
   } else {
    self->m[i].m[1][0] = self->m[i].m[1][1] = self->m[i].m[1][2] = lbl_805A331C;
   }
   fn_801EC1B8(&((S*)((M*)self + i))->m[0], matrix, m);
  } else {
   fn_80162894(&self->m[i]);
  }
 }
}
#include <gf/gf_camera.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on
struct Obj {
 char pad0[0x44]; float x; float y; char pad4c[0x48]; void* ptr; char pad98[0x18];
 union {
  struct { signed int mode : 4; signed int type : 4; unsigned int rest : 24; };
  struct { unsigned char padb0; unsigned char wide : 1; unsigned char padbits : 2; unsigned char active : 1; unsigned char fade : 1; unsigned char remaining : 3; unsigned char padb2[2]; };
 };
 char padb4[4]; signed char state; char padb9[3]; unsigned int tick; unsigned char alpha;
};
struct Render { char pad[0x24]; int a; int b; char pad2[8]; unsigned short w; unsigned short h; };
extern "C" {
void fn_801F47D8(int, int);
void fn_801F5500(int, int, int, int);
void fn_801F5484(float, float, float, float, float, float);
void fn_801F4880(int);
void fn_801ECF4C(void*, float, float, float, float, float, float);
void fn_801F50EC(void*, int);
void fn_8026F708();
void fn_80036270(void*, unsigned char, int);
void fn_801F1D10(int);
}
extern "C" void fn_800374DC(Obj* self, Render* r) {
 float matrix[16];
 if (self->type == 1) {
  unsigned int wide = *(float*)((char*)gfCameraManager::getManager() + 0x738) > 1.3333334f;
  if (wide != self->wide) {
   self->wide = wide;
   if (!self->wide) { self->x = 1.0f; self->y = 1.0f; }
   else { self->x = 1.3684211f; self->y = 1.0f; }
  }
  if ((self->active && self->mode == 2) || self->fade) {
   fn_801F47D8(r->a, r->b);
   fn_801F5500(0, 0, r->w, r->h);
   fn_801F5484(0.0f, 0.0f, (float)r->w, (float)r->h, 0.0f, 1.0f);
   fn_801F4880(0);
   if (self->active && self->mode == 2) {
    if (!self->wide) fn_801ECF4C(matrix, 228.0f, -228.0f, -304.0f, 304.0f, 0.0f, 500.0f);
    else fn_801ECF4C(matrix, 228.0f, -228.0f, -416.0f, 416.0f, 0.0f, 500.0f);
    fn_801F50EC(matrix, 1); fn_8026F708();
   } else if (self->fade) {
    float elapsed = (float)((OSGetTick() - self->tick) / ((*(unsigned int*)0x800000F8 >> 2) / 1000));
    switch (self->state) {
    case 0:
     self->alpha = (unsigned char)(255.9f * (elapsed / 250.0f));
     if (elapsed >= 250.0f) { self->tick = OSGetTick(); self->state = 1; self->alpha = 255; }
     break;
    case 1:
     if (elapsed >= 1000.0f) { self->tick = OSGetTick(); self->state = 2; }
     break;
    case 2:
     self->alpha = (unsigned char)(255.9f * ((250.0f - elapsed) / 250.0f));
     if (elapsed >= 250.0f) { self->alpha = 0; self->fade = 0; }
     break;
    }
    fn_80036270(self->ptr, self->alpha, self->wide);
   }
   fn_801F1D10(0);
  }
 }
}
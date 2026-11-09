#include <types.h>
#pragma force_active on
extern "C" void* fn_80158BE0();
extern "C" void fn_80159690(void*);
extern "C" u32 fn_8015A41C(void*);
struct Elem { s32 type; u32 data; u8 count; };
extern "C" Elem* fn_8015A424(void*, u32);
extern void* g_GameGlobal;
struct Obj {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void call(s32);
};
struct Self {
 u8 pad0[0x10]; u32 f10; u32 f14; u32 f18; u8 pad1c[4];
 Obj o20; u8 pad24[0x10]; Obj o34; u8 pad38[0x10]; Obj o48;
};
extern "C" void fn_1_305DC(void* unused, Self* self) {
 u8* base = *(u8**)((u8*)g_GameGlobal + 0x30);
 fn_80159690(fn_80158BE0());
 for (u32 idx = 0; idx < fn_8015A41C(fn_80158BE0()); idx++) {
  u32 j; u8 n; s32 d;
  Elem* e = fn_8015A424(fn_80158BE0(), idx);
  if (e->type == 0x17) {
   j = 0; n = e->count; d = e->data;
   for (; j < n; j++) self->o20.call(d);
  }
  if (e->type == 0x33) {
   j = 0; n = e->count; d = e->data;
   for (; j < n; j++) self->o34.call(d);
  }
  if (e->type == 0xB) {
   j = 0; n = e->count; s32 d2 = e->data;
   for (; j < n; j++) self->o48.call(d2);
  }
 }
 self->f10 = *(u16*)(base + 0x4920);
 self->f14 = *(u32*)(base + 0x4910);
 self->f18 = *(u32*)(base + 0x60c);
}
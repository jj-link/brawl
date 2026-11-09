#include <types.h>
#pragma force_active on
struct Bits { u8 hi : 1; u8 rest : 7; };
struct Local { void* a; void* b; void* c; u8 byte; Bits bits; };
struct Obj { u8 pad[0x458]; u16 f458; u16 f45A; };
struct PA { u8 pad[0xF]; u8 flags; };
struct PB { u8 pad[0x54]; u8 flags; };
struct PC { u8 pad[0x2C]; u8 flags; };
extern "C" void fn_80113DF8(s32, void*);
extern "C" void fn_80113EC0(s32, void*);
extern "C" void fn_80130B90(void*, s32, s32);
extern "C" void fn_80131000(void*, s32, s32);
extern "C" s32 fn_8013099C(Obj* arg0, s32 arg1, s32 arg2) {
 Local l1; Local l2; s32 ok; s32 en; s32 t;
 if (!(arg0->f458 & 6)) {
  ok = 0; l1.a = 0; l1.b = 0; l1.c = 0; l1.byte = 0; l1.bits.hi = 0;
  fn_80113DF8(arg1, &l1);
  if (l1.a != 0 && l1.b != 0 && l1.c != 0) ok = 1;
  if (ok != 0 && ((((PB*)l1.b)->flags >> 4) & 1) && ((((PC*)l1.c)->flags >> 7) & 1)) en = 1; else en = 0;
  Local& r = l1;
  if (en != 0 && (((PA*)r.a)->flags & 1)) {
   t = arg0->f45A & 5;
   if (t != 5 && t == 0) fn_80130B90(arg0, arg1, arg2);
  }
 }
 if (!(arg0->f458 & 5)) {
  ok = 0; l2.a = 0; l2.b = 0; l2.c = 0; l2.byte = 0; l2.bits.hi = 0;
  fn_80113EC0(arg1, &l2);
  if (l2.a != 0 && l2.b != 0 && l2.c != 0) ok = 1;
  if (ok != 0 && ((((PB*)l2.b)->flags >> 4) & 1) && ((((PC*)l2.c)->flags >> 7) & 1)) en = 1; else en = 0;
  Local& r = l2;
  if (en != 0 && (((PA*)r.a)->flags & 1)) {
   t = arg0->f45A & 9;
   if (t != 9 && t == 0) fn_80131000(arg0, arg1, arg2);
  }
 }
 return 1;
}
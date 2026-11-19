#include <types.h>
#include <gr/collision/gr_collision_line.h>
#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

struct Info { char pad[8]; s32 kind; char pad2[0x67]; u8 flags; };
struct Self { char pad[0x18]; Info* info; char pad2[0x354]; Vec2f start; char pad3[0x34]; Vec2f end; char pad4[0xc8]; u8 enabled; };
struct B { char pad[0x54]; u8 flags; };
struct C { char pad[0x2c]; u8 flags; };
struct Arg { grCollisionLine* a; char pad[8]; u8 flags; };
struct Rec {
 grCollisionLine* a; B* b; C* c; u8 d; u8 flag:1;
 Rec() : a(0), b(0), c(0), d(0), flag(0) {}
 Rec(const Rec& other) : a(other.a), b(other.b), c(other.c), d(static_cast<u8>(reinterpret_cast<u32>(other.a))), flag(0) {}
};
inline u8 lineFlags(const grCollisionLine* line) {
 return reinterpret_cast<const u8*>(line)[0xf];
}
extern const f32 lbl_805A29F0;
extern "C" s32 fn_80113DF8(const Arg*, Rec*);
extern "C" s32 fn_80113EC0(const Arg*, Rec*);
extern "C" s32 fn_8012CFA0(Self*, const Arg*, f32*);
extern "C" s32 fn_8012D1A8(Self*, const Arg*, f32*);
extern "C" s32 fn_8012E474(Self*, const Arg*, f32*);
extern "C" s32 fn_8012ED7C(Self*, const Arg*, f32*);
extern "C" s32 fn_8012F6AC(Self*, const Arg*, f32*);
extern "C" s32 fn_8012F8B4(Self*, const Arg*, f32*);
extern "C" s32 fn_8013099C(Self*, const Arg*, f32*);
extern "C" s32 fn_80131498(Self*, const Arg*, f32*);

extern "C" s32 fn_8012CADC(Self* self, const Arg* arg, f32* n) {
 bool found;
 u8 active=0;
 bool result=false;
 if ((self->info->kind >> 24) != 1) active=self->enabled;
 if (active) {
  found=false;
  Rec r1, r2;
  u8 flags=lineFlags(arg->a);
  if ((flags >> 3) & 1) {
   Rec r(r1);
   fn_80113DF8(arg,&r);
   if (*reinterpret_cast<const u32*>(&r.a) && r.b && r.c) found=true;
   bool ok;
   if (found && ((r.b->flags >> 4) & 1) && ((r.c->flags >> 7) & 1)) ok=true;
   else ok=false;
   if (ok && (lineFlags(r.a) & 1)) result=true;
   else {
    fn_80113EC0(arg,&r2);
    bool found2=false;
    if (*reinterpret_cast<const u32*>(&r2.a) && r2.b && r2.c) found2=true;
    if (found2 && ((r2.b->flags >> 4) & 1) && ((r2.c->flags >> 7) & 1)) ok=true;
    else ok=false;
    if (ok && ((lineFlags(r2.a) >> 1) & 1)) result=true;
   }
  } else if ((flags >> 2) & 1) {
   Rec r(r1);
   fn_80113EC0(arg,&r);
   if (*reinterpret_cast<const u32*>(&r.a) && r.b && r.c) found=true;
   bool ok;
   if (found && ((r.b->flags >> 4) & 1) && ((r.c->flags >> 7) & 1)) ok=true;
   else ok=false;
   if (ok && (lineFlags(r.a) & 1)) result=true;
   else {
    fn_80113DF8(arg,&r1);
    bool found2=false;
    if (*reinterpret_cast<const u32*>(&r1.a) && r1.b && r1.c) found2=true;
    if (found2 && ((r1.b->flags >> 4) & 1) && ((r1.c->flags >> 7) & 1)) ok=true;
    else ok=false;
    if (ok && ((lineFlags(r1.a) >> 1) & 1)) result=true;
   }
  } else {
   if ((self->info->flags >> 4) & 1) {
    Vec2f v;
    Vec2f::copy(v, self->end - self->start);
    if (((flags & 1) || ((flags >> 1) & 1)) && v.m_y > lbl_805A29F0 && v.m_y > static_cast<f32>(static_cast<double>(nw4r::ut::Abs(v.m_x)))) {
     result=false;
     goto dispatch;
    }
   }
   result=true;
  }
 }
dispatch:
 if (result) {
  u8 f=lineFlags(arg->a);
  if ((f >> 3) & 1) { if (!(arg->flags & 2)) fn_8012CFA0(self,arg,n); }
  else if ((f >> 2) & 1) { if (!(arg->flags & 1)) fn_8012D1A8(self,arg,n); }
  else if ((f >> 1) & 1) fn_8012E474(self,arg,n);
  else if (f & 1) fn_8012ED7C(self,arg,n);
 } else {
  u8 f=lineFlags(arg->a);
  if ((f >> 3) & 1) { if (!(arg->flags & 2)) fn_8012F6AC(self,arg,n); }
  else if ((f >> 2) & 1) { if (!(arg->flags & 1)) fn_8012F8B4(self,arg,n); }
  else if ((f >> 1) & 1) fn_8013099C(self,arg,n);
  else if (f & 1) fn_80131498(self,arg,n);
 }
 return 1;
}
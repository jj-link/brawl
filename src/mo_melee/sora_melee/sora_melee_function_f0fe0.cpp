#pragma force_active on
#include <types.h>
struct Entry { char pad[0xA]; s16 unkA; };
struct Sub {
 virtual void v04(); virtual void v08(); virtual Entry* v10(s32);
 virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20();
 virtual void v24(); virtual void v28(); virtual void v2c(); virtual void v30();
 virtual void v34(s32, void*); virtual void v38(); virtual void v3c(); virtual u32 v40();
};
struct Outer {
 virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
 virtual s32 v18(); virtual void v1c(); virtual u32 v20(s32);
 char pad4[0xC]; Sub sub; char pad14[0x20]; u8 unk34;
 inline s32 find(s32 limit) {
  if (limit <= -1) return v18();
  s32 count = v18();
  for (s32 i = 0; i < count; i++) {
   s16 t = sub.v10(i)->unkA;
   if (t <= -1) return i;
   if (t > limit) return i;
  }
  return count;
 }
};
extern "C" s32 fn_27_F17E8(Outer*);
extern "C" void fn_27_FE00C(void*, u32, s32, s16*, s32);
extern "C" s32 fn_27_F0FE0(Outer* self, u32 arg1, s32 arg2, s16* arg3, s32 arg4) {
 s16 sp8;
 u32 spC[3];
 if (self->sub.v40() == 1U) return -1;
 if ((self->unk34 == 0 || arg2 > -1) && self->v20(arg2) == 1U) return -1;
 if (self->unk34 == 0 && arg2 <= -1) {
  arg2 = fn_27_F17E8(self);
  if (arg2 <= -1) return -1;
 }
 s32 i = self->find(arg4);
 if (i < 0) return -1;
 sp8 = *arg3;
 fn_27_FE00C(&spC, arg1, arg2, &sp8, arg4);
 self->sub.v34(i, &spC);
 return arg2;
}
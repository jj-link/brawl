#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
struct FnDst { u32 a; u32 b; s16 c; s16 d; };
struct Inner {
 virtual void v08(); virtual void v0c(); virtual void* v10(s32);
 virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20();
 virtual void v24(); virtual void v28(); virtual void v2c(); virtual void v30();
 virtual void v34(s32, FnDst*); virtual void v38(); virtual void v3c(); virtual unsigned int v40();
};
struct Outer {
 virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
 virtual s32 v18(); virtual unsigned int v1c(); virtual unsigned int v20(s32);
 char pad04[0xC]; Inner inner; char pad14[0x98]; u8 flag;
 inline s32 find(s32 limit) {
  if (limit <= -1) return v18();
  s32 n = v18();
  for (s32 i = 0; i < n; i++) {
   s16 val = *(s16*)((u8*)inner.v10(i) + 0xA);
   if (val <= -1) return i;
   if (val > limit) return i;
  }
  return n;
 }
};
extern "C" s32 fn_27_F987C(Outer*);
extern "C" void fn_27_FE14C(FnDst*, u32*, s32, s16*, s32);
extern "C" s32 fn_27_F9074(Outer* self, void* arg1, s32 arg2, s16* arg3, s32 arg4) {
 if (self->inner.v40() == 1U) return -1;
 if (self->flag == 0 || arg2 > -1) {
  if (self->v20(arg2) == 1U) return -1;
 }
 if (self->flag == 0 && arg2 <= -1) {
  s32 result = fn_27_F987C(self);
  arg2 = result;
  if (result <= -1) return -1;
 }
 s32 idx = self->find(arg4);
 if (idx < 0) return -1;
 s16 sp8 = *arg3;
 FnDst spC;
 fn_27_FE14C(&spC, (u32*)arg1, arg2, &sp8, arg4);
 self->inner.v34(idx, &spC);
 return arg2;
}
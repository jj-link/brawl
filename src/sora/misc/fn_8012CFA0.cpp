#include <types.h>
#pragma force_active on
struct Obj { u8 pad[0x458]; u16 f458; u16 f45a; };
struct Arg { void* p0; u8 pad[4]; void* p8; void* getFirst() const { return p0; } };
extern "C" void fn_80111968(void*, void*, void*, s32);
extern "C" void fn_80113EC0(void*, void*);
extern "C" void fn_80113DF8(void*, void*);
extern "C" void fn_8012D39C(void*, void*, s32);
extern "C" void fn_8012D7D8(void*, void*, s32);
struct Output {
 u8 data[24];
 Output(void* second, void* first) { fn_80111968(second, this, first, 0); }
};
struct Bits { u8 hi : 1; u8 rest : 7; };
struct Rec {
 void* a; void* b; void* c; u8 x; Bits bits;
 void clear() { a=0; b=0; c=0; x=0; bits.hi=0; }
};
extern "C" s32 fn_8012CFA0(Obj& self, const Arg& arg1, s32 arg2) {
 Output out(arg1.p8, arg1.getFirst());
 Rec r2; Rec r1;
 int f=0; int v;
 r2.clear(); r1.clear();
 fn_80113EC0((void*)&arg1,&r2);
 fn_80113DF8((void*)&arg1,&r1);
 if (!(self.f458 & 10)) {
  if (r1.a != 0 && r1.b != 0 && r1.c != 0) f=1;
  if (f != 0 && ((((u8*)r1.b)[0x54]>>4)&1) && ((((u8*)r1.c)[0x2c]>>7)&1)) v=1; else v=0;
  Rec& rr1=r1;
  if (v != 0 && (((u8*)rr1.a)[0xf]&1)) {
   int t=self.f45a & 6;
   if (t != 6 && t == 0) fn_8012D39C(&self,(void*)&arg1,arg2);
  }
 }
 if (!(self.f458 & 6)) {
  int g=0;
  if (r2.a != 0 && r2.b != 0 && r2.c != 0) g=1;
  if (g != 0 && ((((u8*)r2.b)[0x54]>>4)&1) && ((((u8*)r2.c)[0x2c]>>7)&1)) v=1; else v=0;
  Rec& rr2=r2;
  if (v != 0 && ((((u8*)rr2.a)[0xf]>>1)&1)) {
   int t=self.f45a & 5;
   if (t != 5 && t == 0) fn_8012D7D8(&self,(void*)&arg1,arg2);
  }
 }
 return 1;
}
#include <types.h>
#pragma force_active on
struct Bits { u8 hi : 1; u8 rest : 7; };
struct Rec { void* a; void* b; void* c; u8 x; Bits y; };
extern "C" void fn_80113EC0(void*, void*, void*, u8);
extern "C" void fn_80113DF8(void*, void*);
extern "C" void fn_8012DC08(void*, void*, void*);
extern "C" void fn_8012E044(void*, void*, void*);
extern "C" int fn_8012D1A8(char* self, void* arg1, void* arg2) {
 Rec r2; Rec r1; int f = 0; int v;
 r2.a=0; r2.b=0; r2.c=0; r2.x=0; r2.y.hi=0;
 r1.a=0; r1.b=0; r1.c=0; r1.x=0; r1.y.hi=0;
 fn_80113EC0(arg1,&r2.a,arg2,*(u8*)&r2.y);
 fn_80113DF8(arg1,&r1.a);
 if (!(*(u16*)(self+0x458)&9)) {
  if (r2.a != 0 && r2.b != 0 && r2.c != 0) f=1;
  if (f != 0 && ((((u8*)r2.b)[0x54]>>4)&1) && ((((u8*)r2.c)[0x2c]>>7)&1)) v=1; else v=0;
  Rec* p = &r2;
  if (v != 0 && (((u8*)p->a)[0xf]&1)) {
   int t=*(u16*)(self+0x45a)&0xa;
   if (t != 0xa && t == 0) fn_8012DC08(self,arg1,arg2);
  }
 }
 if (!(*(u16*)(self+0x458)&5)) {
  int g=0;
  if (r1.a != 0 && r1.b != 0 && r1.c != 0) g=1;
  if (g != 0 && ((((u8*)r1.b)[0x54]>>4)&1) && ((((u8*)r1.c)[0x2c]>>7)&1)) v=1; else v=0;
  Rec* p = &r1;
  if (v != 0 && ((((u8*)p->a)[0xf]>>1)&1)) {
   int t=*(u16*)(self+0x45a)&9;
   if (t != 9 && t == 0) fn_8012E044(self,arg1,arg2);
  }
 }
 return 1;
}
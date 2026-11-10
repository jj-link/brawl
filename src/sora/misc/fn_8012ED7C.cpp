#include <types.h>
#pragma force_active on
struct Obj { u8 pad[0x458]; u16 f458; u16 f45a; };
struct Arg { void* f0; void* pad; void* f8; void* getFirst() const { return f0; } };
struct Bits { u8 hi:1; u8 rest:7; };
struct Rec { void* a; void* b; void* c; u8 d; Bits bits; void clear() { a=0; b=0; c=0; d=0; bits.hi=0; } };
extern "C" void fn_80111968(void*,void*,void*,int);
extern "C" void fn_80113EC0(void*,void*);
extern "C" void fn_80113DF8(void*,void*);
extern "C" void fn_8012EF84(void*,void*,int);
extern "C" void fn_8012F32C(void*,void*,int);
struct Output { u8 data[24]; Output(void* const& second, void* first) { fn_80111968(second,this,first,0); } };
extern "C" int fn_8012ED7C(Obj& self,const Arg& arg1,int arg2) {
 Output out(arg1.f8,arg1.getFirst());
 Rec b; Rec a;
 int valid1=0; int enabled;
 b.clear(); a.clear();
 fn_80113EC0((void*)&arg1,&b);
 fn_80113DF8((void*)&arg1,&a);
 if (!(self.f458 & 8)) {
  if (b.a && b.b && b.c) valid1=1;
  if (valid1 && ((((u8*)b.b)[0x54]>>4)&1) && ((((u8*)b.c)[0x2c]>>7)&1)) enabled=1; else enabled=0;
  Rec& r=b;
  if (enabled && ((((u8*)r.a)[0xf]>>1)&1)) {
   int t=self.f45a & 6;
   if (t!=6 && t==0) fn_8012EF84(&self,(void*)&arg1,arg2);
  }
 }
 if (!(self.f458 & 8)) {
  int valid2=0;
  if (a.a && a.b && a.c) valid2=1;
  if (valid2 && ((((u8*)a.b)[0x54]>>4)&1) && ((((u8*)a.c)[0x2c]>>7)&1)) enabled=1; else enabled=0;
  Rec& r=a;
  if (enabled && ((((u8*)r.a)[0xf]>>1)&1)) {
   int t=self.f45a & 9;
   if (t!=9 && t==0) fn_8012F32C(&self,(void*)&arg1,arg2);
  }
 }
 return 1;
}
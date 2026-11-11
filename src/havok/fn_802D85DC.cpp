#include <types.h>
#pragma force_active on
extern "C" int __cntlzw(unsigned int);
struct Ctx { int a,b; int pad; int c,d; float e,f; int g,h; };
struct Inner { char pad[8]; int unk8; char pad2[0xA8-0xC]; u8 unkA8; char pad3[0x1B8-0xA9]; int unk1B8; };
struct Arg { int unk0; Inner* unk4; Inner* unk8; float unkC; };
extern "C" void fn_802F4358(int, Ctx*);
extern "C" void fn_802E4044(Inner*, Ctx*);
extern "C" float fn_80328E50(int, Arg*, int);
extern "C" float fn_802D85DC(int unused, Arg* p, int arg2, float f) {
 Ctx c;
 int x=p->unk4->unk8;
 int b=(int)p->unk8+0x1c;
 int a=(int)p->unk4+0x1c;
 float u=p->unkC;
 c.a=a; c.b=b; c.c=(int)p+0x20; c.d=(int)p+0x10; c.e=f; c.f=u; c.g=0; c.h=0;
 fn_802F4358(x,&c);
 if(p->unk4->unk1B8) fn_802E4044(p->unk4,&c);
 if(p->unk8->unk1B8) fn_802E4044(p->unk8,&c);
 int doCall=1;
 float ret=c.e;
 int r5=1;
 u8 state=p->unk4->unkA8;
 Inner* second=p->unk8;
 s8 eq7=(s8)((u32)__cntlzw((u32)(state-7)) >> 5);
 if(eq7==0) {
     s8 eq6=(s8)((u32)__cntlzw((u32)(state-6)) >> 5);
     if(eq6==0) r5=0;
 }
 if(r5) {
     int r3=1;
     u8 state2=second->unkA8;
     s8 eq7b=(s8)((u32)__cntlzw((u32)(state2-7)) >> 5);
     if(eq7b==0) {
         s8 eq6b=(s8)((u32)__cntlzw((u32)(state2-6)) >> 5);
         if(eq6b==0) r3=0;
     }
     if(r3) doCall=0;
 }
 if(doCall) ret=fn_80328E50(x,p,arg2);
 return ret;
}
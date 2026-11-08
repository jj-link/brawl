#pragma force_active on
typedef unsigned int u32; typedef int s32; typedef unsigned char u8;
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void wnemReport__FPCce(const char*, ...);
int fn_41_31E7C(void*, u32, int);
u32 getFrameCounter__10wnemSimpleFl(void*, s32);
extern char lbl_41_data_11F0[], lbl_41_data_12A4[], lbl_41_data_4018[];
extern float lbl_41_rodata_E28;
}
#define S10(a,b,c,d,e,f,g,h,i,j) virtual void s##a(); virtual void s##b(); virtual void s##c(); virtual void s##d(); virtual void s##e(); virtual void s##f(); virtual void s##g(); virtual void s##h(); virtual void s##i(); virtual void s##j();
struct Base8 { int a; int b; };
struct CastObj : Base8 {
S10(0,1,2,3,4,5,6,7,8,9) S10(10,11,12,13,14,15,16,17,18,19) S10(20,21,22,23,24,25,26,27,28,29) S10(30,31,32,33,34,35,36,37,38,39) S10(40,41,42,43,44,45,46,47,48,49)
virtual void s50(); virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54(); virtual u32 v55(int,int);
};
struct SecPad { char pad[0x3c]; };
struct SecObj : SecPad {
S10(0,1,2,3,4,5,6,7,8,9) S10(10,11,12,13,14,15,16,17,18,19) S10(20,21,22,23,24,25,26,27,28,29) S10(30,31,32,33,34,35,36,37,38,39) S10(40,41,42,43,44,45,46,47,48,49) S10(50,51,52,53,54,55,56,57,58,59) S10(60,61,62,63,64,65,66,67,68,69) S10(70,71,72,73,74,75,76,77,78,79)
S10(80,81,82,83,84,85,86,87,88,89) S10(90,91,92,93,94,95,96,97,98,99) S10(100,101,102,103,104,105,106,107,108,109) S10(110,111,112,113,114,115,116,117,118,119) S10(120,121,122,123,124,125,126,127,128,129)
virtual void v130(); virtual void v131(); virtual void v132(); virtual void v133(); virtual void v134(); virtual void v135(); virtual void v136(); virtual void v137(); virtual void v138(int);
};
extern "C" void fn_41_322F0(void* self_p) {
 char* base; float* rodata; int flag; CastObj* c; char* self=(char*)self_p;
 rodata=&lbl_41_rodata_E28; base=lbl_41_data_4018; flag=0;
 char* p1=*(char**)(self+0x6c); char* p2=*(char**)(p1+0xd8); void* obj=*(void**)(p2+0x10);
 c=(CastObj*)__dynamic_cast(obj,8,lbl_41_data_11F0,lbl_41_data_12A4,1);
 if(c->v55(1,0)==1 || c->v55(8,0)==1) { flag=1; wnemReport__FPCce(base+0x7e8); }
 else {
  float angle=*(float*)(self+0x21f8);
  if(angle>=rodata[9]) { if(c->v55(0xa4,0)==1) { wnemReport__FPCce(base+0x820); flag=1; } }
  else if(angle<=rodata[10]) { if(c->v55(0x52,0)==1) { wnemReport__FPCce(base+0x856); flag=1; } }
 }
 if(flag!=0) {
  if(*(s32*)(self+0x21c4)==0) {
   if(*(u8*)(self+0x21bb)!=0) {
    wnemReport__FPCce(base+0x88b);
    float zero=rodata[0]; *(float*)(self+0x21fc)=zero; *(float*)(self+0x21f8)=zero;
    ((SecObj*)(self+0xc))->v138(0); return;
   }
  } else {
   wnemReport__FPCce(base+0x8cd); fn_41_31E7C(self,*(u32*)(self+0x21c4),1);
   if(*(s32*)(self+0x21dc)==1) { wnemReport__FPCce(base+0x923); float zero=rodata[0]; *(float*)(self+0x21fc)=zero; *(float*)(self+0x21f8)=zero; }
  }
 }
 void(*fp)(void*,void*)=*(void(**)(void*,void*))(self+0x220c);
 if(fp!=0) {
  fp(self,*(void**)(self+0x6c));
  if(*(u8*)(self+0x2219)!=0) { wnemReport__FPCce(base+0x96d); ((SecObj*)(self+0xc))->v138(0); return; }
 }
 if(*(u8*)(self+0x21b9)!=0) {
  u32 fc=getFrameCounter__10wnemSimpleFl(self,0); u32 limit=*(u32*)(self+0x21d0);
  if(fc>=limit) {
   if(*(s32*)(self+0x21c0)==0) { wnemReport__FPCce(base+0x9ad,fc,limit); ((SecObj*)(self+0xc))->v138(0); return; }
   else { wnemReport__FPCce(base+0x9e1,fc,limit); fn_41_31E7C(self,*(u32*)(self+0x21c0),1); }
  }
 }
}
#include <types.h>
#pragma force_active on
#pragma fp_contract on
class Allocator {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void* alloc(u32,s32);
};
class Ref {
public:
 virtual void destroy(int);
 u16 active;
 s16 refs;
};
struct Ref18 {
 void* vt;
 u16 active;
 s16 refs;
 void* a;
 void* b;
 void* c;
 void* d;
};
struct Arr {
 void** data;
 int size;
 int capacity;
 int getCapacity() const { return capacity & 0x3fffffff; }
};
struct BF26 { u8 rest:6; u8 lo:2; };
struct BF27 { u8 hi:2; u8 rest:6; };
class Class_802F0BEC {
public:
 virtual ~Class_802F0BEC();
 virtual void fn_80080A64();
 virtual void fn_802F12D8(void*);
 virtual void fn_802F0C48();
 virtual void fn_802F0DAC();
};
class Reporter {
public:
 virtual void v0(); virtual void v1();
 virtual void report(int,int,char*,const char*,int);
};
class Class_8028096C { public: char data[12]; };
extern Allocator* lbl_805A0EB8;
extern Reporter* lbl_805A0EB0;
extern void* lbl_805A0EC8;
extern u8 lbl_805A0F20;
extern void* (*lbl_8059F030)(void*,void*,int);
extern const float lbl_805A4430,lbl_805A4434,lbl_805A4438,lbl_805A443C;
extern const float lbl_805A4440,lbl_805A4444,lbl_805A4448,lbl_805A444C;
extern const float lbl_805A4450,lbl_805A4454,lbl_805A4458,lbl_805A445C;
extern const float lbl_805A4460,lbl_805A4464,lbl_805A4468,lbl_805A446C;
extern const float lbl_805A4470,lbl_805A4474,lbl_805A4478;
extern "C" {
extern char lbl_80488320[],lbl_80488290[],lbl_80488690[];
extern char lbl_80413438[],lbl_80487320[];
void __ct__14Class_8028096CFiiii(Class_8028096C*,char*,int,char*);
void __dt__14Class_8028096CFv(Class_8028096C*,int);
void* fn_8027EA20(void*,u32,int);
void* fn_802F5D5C(void*,void*);
Class_8028096C* fn_80280A74(Class_8028096C*,const char*);
Class_8028096C* fn_80280AA8(Class_8028096C*,int);
Class_8028096C* fn_80280B00(Class_8028096C*,u32);
void fn_80281ED8(void*);
void* fn_802CAD5C(void*);
void* fn_802F3420(void*,void*);
void* fn_802D92B0(void*,void*);
void fn_802C05BC();
void* __ct__14Class_802CB910Fii(void*,void(*)(),void*);
void* __ct__14Class_802F0BECFi(void*,void*);
void* __ct__14Class_80325FDCFv(void*,void*);
void fn_802EB1A0(void*,void*);
void fn_802CCB1C(void*,void*);
void* fn_802E9BFC(void*,void*);
void fn_8027CE3C(void*,int);
void fn_802E3604(void*);
void* fn_802E2840(void*,void*);
void fn_802EC1C0(void*,void*,int);
void fn_802F0668(void*);
void* fn_802E911C(void*,void*,int);
void* fn_802F0714(void*);
double __frsqrte(double);
}
struct Next {
 static void* operator new(unsigned long n) { return lbl_805A0EB8->alloc(n,0x1D); }
 Next() {}
 void* f0;
 void* f4;
 float f8;
 u8 fc;
 u8 pad[0x30-0xD];
};
struct Flag {
 static void* operator new(unsigned long n) { return lbl_805A0EB8->alloc(n,0x13); }
 Flag() {}
 u8 v;
};
#define U8(p,o) (*(u8*)((u8*)(p)+(o)))
#define S8(p,o) (*(s8*)((u8*)(p)+(o)))
#define U16(p,o) (*(u16*)((u8*)(p)+(o)))
#define S16(p,o) (*(s16*)((u8*)(p)+(o)))
#define U32(p,o) (*(u32*)((u8*)(p)+(o)))
#define S32(p,o) (*(s32*)((u8*)(p)+(o)))
#define F32(p,o) (*(float*)((u8*)(p)+(o)))
#define PTR(p,o) (*(void**)((u8*)(p)+(o)))
inline unsigned int nz(int x) { return (unsigned int)(-x|x)>>31; }
inline s8 ne(int a,int b) { return (unsigned int)((a-b)|(b-a))>>31; }
struct Block { char data[0xC0]; };
inline void lengthTo(float y,float x,float z,float& s) {
 float a=y*y;
 x=x*x+a;
 x=z*z+x;
 float r;
 if(x<=lbl_805A4430) {
  u32 inf=0x7F800000;
  r=*(float*)&inf;
 } else {
  double estimate=__frsqrte(x);
  float q=(float)estimate;
  float c;
  float b=x*q;
  c=lbl_805A4434*q;
  r=c*(lbl_805A443C-q*b);
 }
 s=lbl_805A4438/r;
 if(lbl_805A4430==s) s=lbl_805A4440;
}
inline float length3(const float* v) {
 float d=v[0]*v[0]+v[1]*v[1]+v[2]*v[2];
 float r;
 if(d<=lbl_805A4430) {
  u32 inf=0x7F800000;
  r=*(float*)&inf;
 } else {
  double estimate=__frsqrte(d);
  float q=(float)estimate;
  r=lbl_805A4434*q*(lbl_805A443C-q*(d*q));
 }
 float s=lbl_805A4438/r;
 if(lbl_805A4430==s) s=lbl_805A4440;
 return s;
}
#define ARR ((Arr*)(obj+0x28))
extern "C" void* fn_802EEF18(void* self,void* params,u32 size) {
 __declspec(align(16)) Block block;
 __declspec(align(16)) char buffer[512];
 u8* obj=(u8*)self;
 u8* p=(u8*)params;
 U16(obj,6)=1;
 PTR(obj,0)=lbl_80488320;
 U32(obj,0x28)=0; U32(obj,0x2C)=0; U32(obj,0x30)=0x80000000;
 U32(obj,0x34)=0; U32(obj,0x38)=0; U32(obj,0x3C)=0x80000000;
 U32(obj,0x40)=0; U32(obj,0x44)=0; U32(obj,0x48)=0x80000000;
 S32(obj,0x90)=-47; U16(obj,0x94)=0;
 U32(obj,0xA8)=0; U32(obj,0xAC)=0; U32(obj,0xB0)=0x80000000;
 U32(obj,0xcc)=0; U32(obj,0xd0)=0; U32(obj,0xd4)=0x80000000;
 U32(obj,0xd8)=0; U32(obj,0xdc)=0; U32(obj,0xe0)=0x80000000;
 U32(obj,0xe4)=0; U32(obj,0xe8)=0; U32(obj,0xec)=0x80000000;
 U32(obj,0xf0)=0; U32(obj,0xf4)=0; U32(obj,0xf8)=0x80000000;
 U32(obj,0xfc)=0; U32(obj,0x100)=0; U32(obj,0x104)=0x80000000;
 U32(obj,0x108)=0; U32(obj,0x10c)=0; U32(obj,0x110)=0x80000000;
 U32(obj,0x114)=0; U32(obj,0x118)=0; U32(obj,0x11c)=0x80000000;
 U32(obj,0x120)=0; U32(obj,0x124)=0; U32(obj,0x128)=0x80000000;
 U32(obj,0x12c)=0; U32(obj,0x130)=0; U32(obj,0x134)=0x80000000;
 U32(obj,0x138)=0; U32(obj,0x13c)=0; U32(obj,0x140)=0x80000000;
 U32(obj,0x144)=0; U32(obj,0x148)=0; U32(obj,0x14c)=0x80000000;
 U32(obj,0x150)=0; U32(obj,0x154)=0; U32(obj,0x158)=0x80000000;
 U32(obj,0x15c)=0; U32(obj,0x160)=0; U32(obj,0x164)=0x80000000;
 u8* cur=obj+0x2C0;
 do { cur+=0x10; } while(cur<obj+0x2E0);
 S32(obj,0xC8)=-1;
 void* initial=fn_8027EA20(lbl_805A0EC8,0x20,0x2D);
 if(initial) initial=fn_802F5D5C(initial,obj);
 PTR(obj,0x74)=initial;
 void* r;
 U32(obj,0x88)=0; U32(obj,0x78)=0; U32(obj,0x7C)=0; U32(obj,0x80)=0;
 U8(obj,0x84)=0; U8(obj,0x85)=1;
 U32(obj,0x9C)=0; U32(obj,0xA4)=0; U32(obj,0xA0)=0; U32(obj,0x8C)=1;
 F32(obj,0x2C0)=F32(p,0x30); F32(obj,0x2C4)=F32(p,0x34);
 F32(obj,0x2C8)=F32(p,0x38); F32(obj,0x2CC)=F32(p,0x3C);
 F32(obj,0x2D0)=F32(p,0x40); F32(obj,0x2D4)=F32(p,0x44);
 F32(obj,0x2D8)=F32(p,0x48); F32(obj,0x2DC)=F32(p,0x4C);
 S32(obj,0x2E0)=S32(p,0x64);
 PTR(obj,0x54)=lbl_8059F030(obj+0x2C0,obj+0x2D0,S32(p,0x64));
 int count=S32(p,0x20);
 S32(obj,0x2E4)=count;
 S32(obj,0x2E8)=count/2;
 if(size!=40000) {
  char flag=1;
  char* flagPtr=&flag;
  Class_8028096C tmp;
  __ct__14Class_8028096CFiiii(&tmp,buffer,512,flagPtr);
  fn_80280A74(fn_80280B00(fn_80280A74(fn_80280AA8(fn_80280A74(&tmp,lbl_80413438+0x26A),40000),lbl_80413438+0x28D),size),lbl_80413438+0x2AC);
  lbl_805A0EB0->report(3,0x53C94B42,buffer,lbl_80413438+0x2B2,0x942);
  __dt__14Class_8028096CFv(&tmp,-1);
 }
 float a,ratio,half,halfConst,one,b;
 U32(obj,0xC4)=0;
 int offset;
 u8* q;
 u8* base=obj+0x180;
 int i;
 one=lbl_805A4438;
 U32(obj,8)=0;
 halfConst=lbl_805A4434;
 F32(obj,0x10)=F32(p,0x10); F32(obj,0x14)=F32(p,0x14);
 F32(obj,0x18)=F32(p,0x18); F32(obj,0x1C)=F32(p,0x1C);
 U8(obj,0xB6)=U8(p,0x8C); F32(obj,0xC0)=F32(p,0x90);
 F32(obj,0xB8)=F32(p,0x84); F32(obj,0xBC)=F32(p,0x88);
 F32(base,0)=one;
 a=F32(p,0x6C); b=F32(p,0x70);
 half=halfConst*a;
 ratio=b/a;
 F32(base,4)=a; F32(base,0xC)=half; F32(base,8)=b;
 float inverse=a/b;
 F32(base,0x50)=ratio; F32(base,0x40)=ratio; F32(base,0x44)=ratio;
 F32(base,0x48)=ratio; F32(base,0x4C)=ratio;
 float ratio2=b/half;
 F32(base,0x54)=inverse; F32(base,0x30)=inverse; F32(base,0x34)=inverse;
 F32(base,0x38)=inverse; F32(base,0x3C)=inverse;
 float inverse2=half/b;
 F32(base,0x58)=ratio2; F32(base,0x5C)=inverse2;
 F32(base,0x60)=F32(p,0x24);
 S32(obj,0x2AC)=S32(p,0x74);
 F32(obj,0x2B8)=lbl_805A4438/(float)S32(p,0x74);
 S32(obj,0x2B0)=S32(p,0x78);
 F32(obj,0x2B4)=lbl_805A4438/(float)S32(p,0x78);
 float scale;
 float mul;
 float x,y,z,aa,c;
 lengthTo(F32(p,0x14),F32(p,0x10),F32(p,0x18),scale);
 mul=lbl_805A4444*scale;
 for(i=0;i<6;++i) {
  switch(i) {
  case 0: case 1: x=lbl_805A4448; y=lbl_805A4430; z=lbl_805A444C; break;
  case 2: x=lbl_805A4450; y=lbl_805A4454; z=lbl_805A4444; break;
  case 3: x=lbl_805A4458; y=lbl_805A445C; z=lbl_805A4444; break;
  case 4: x=lbl_805A4460; y=lbl_805A4464; z=lbl_805A4444; break;
  case 5: default: x=lbl_805A4468; y=lbl_805A446C; z=lbl_805A4470; break;
  }
  q=base+i*0x20;
  aa=scale*x;
  S32(q,0x74)=(int)(z*(float)S32(base,0x12C)/lbl_805A4474);
  c=(scale*y)/aa;
  F32(q,0x6C)=lbl_805A4438-c*(lbl_805A4474*F32(base,0x138));
  F32(q,0x64)=lbl_805A4438/aa;
  F32(q,0x68)=lbl_805A4438/(mul*aa);
  if(y>lbl_805A4430) F32(q,0x70)=lbl_805A4474*F32(base,0x138)/y;
  else F32(q,0x70)=lbl_805A4478;
 }
 Ref* shared=(Ref*)PTR(p,0x60);
 PTR(obj,0x50)=shared;
 if(shared&&shared->active) shared->refs++;
 U8(obj,0xB4)=U8(p,0x96); U8(obj,0xB5)=U8(p,0x94);
 if(!nz(S8(obj,0xB4))&&nz(S8(obj,0xB5))) U8(obj,0xB5)=0;
 U8(obj,0x98)=U8(p,0x97);
 {
  void* t=lbl_805A0EB8->alloc(0x104,0x25);
  if(t) t=fn_802CAD5C(t);
  PTR(obj,0x58)=t;
 }
 {
  void* t=lbl_805A0EB8->alloc(8,0x1F); U16(t,4)=8;
  if(t) { U16(t,6)=1; PTR(t,0)=lbl_80488290; }
  PTR(obj,0x5C)=t;
 }
 {
  void* t=lbl_805A0EB8->alloc(12,0x1F); U16(t,4)=12;
  if(t) t=fn_802F3420(t,obj);
  PTR(obj,0x60)=t;
 }
 {
  void* t=lbl_805A0EB8->alloc(8,0x1F); U16(t,4)=8;
  if(t) { U16(t,6)=1; PTR(t,0)=lbl_80488690; }
  PTR(obj,0x64)=t;
 }
 PTR(PTR(obj,0x58),0x28)=PTR(obj,0x5C);
 PTR(PTR(obj,0x58),0x44)=PTR(obj,0x5C);
 PTR(PTR(obj,0x58),0x48)=PTR(obj,0x5C);
 PTR(PTR(obj,0x58),0x24)=PTR(obj,0x60);
 PTR(PTR(obj,0x58),0x2C)=PTR(obj,0x64);
 PTR(PTR(obj,0x58),0x64)=PTR(obj,0x64);
 PTR(PTR(obj,0x58),0x4C)=PTR(obj,0x64);
 PTR(PTR(obj,0x58),0x68)=PTR(obj,0x64);
 PTR(PTR(obj,0x58),0x6C)=PTR(obj,0x64);
 Ref* owner=(Ref*)lbl_805A0EB8->alloc(12,0x20);
 owner->active=12;
 if(owner) owner=(Ref*)fn_802D92B0(owner,obj);
 {
  void* t=lbl_805A0EB8->alloc(0x1C3C,0x25); U16(t,4)=0x1C3C;
  if(t) t=__ct__14Class_802CB910Fii(t,fn_802C05BC,owner);
  PTR(obj,0x70)=t;
 }
 if(owner->active) {
  if(--owner->refs==0&&owner!=0) owner->destroy(1);
 }
 shared=(Ref*)PTR(p,0x54);
 if(!shared) {
  Ref18* t=(Ref18*)lbl_805A0EB8->alloc(0x18,0x25);
  t->active=0x18;
  if(t) {
   t->refs=1;
   void* tablePart;
   void* tableC;
   void* tableB;
   char* table=lbl_80487320;
   tablePart=table+0x10;
   t->vt=table;
   tableB=table+0x20;
   tableC=table+0x30;
   t->a=tablePart;
   tablePart=table+0x40;
   t->b=tableB;
   t->c=tableC;
   t->d=tablePart;
  }
  PTR(obj,0x6C)=t;
 } else {
  PTR(obj,0x6C)=shared;
  if(shared->active) shared->refs++;
 }
 Next* next=new Next;
 PTR(obj,0x68)=next;
 next->f0=PTR(obj,0x70); next->f8=F32(p,0x50);
 void* child=PTR(obj,0x6C);
 if(child) child=(u8*)child+0xC;
 next->f4=child;
 {
  void* t=lbl_805A0EB8->alloc(8,0x1D);
  if(t) { F32(t,0)=lbl_805A4450; U32(t,4)=20; }
  PTR(next,0x20)=t;
 }
 U8(obj,0x2EC)=U8(p,0x68);
 F32(PTR(next,0x20),0)=F32(p,0x7C);
 U32(PTR(next,0x20),4)=U32(p,0x80);
 next->fc=0; PTR(next,0x28)=(u8*)next->f0+0x1A64;
 fn_802EB1A0(obj,PTR(obj,0x70));
 if(nz((s8)lbl_805A0F20)) U8(p,0x95)=3;
 int curType=S32(obj,0xC4);
 if(nz(ne((s8)curType,(s8)U8(p,0x95)))) {
  Class_802F0BEC* old=(Class_802F0BEC*)PTR(obj,8);
  if(old) delete old;
  S32(obj,0xC4)=S8(p,0x95);
  switch(S32(obj,0xC4)) {
  case 1: {
   void* t=lbl_805A0EB8->alloc(0x28,0x13); U16(t,4)=0x28;
   if(t) t=__ct__14Class_802F0BECFi(t,obj);
   PTR(obj,8)=t; break;
  }
  case 2: {
   void* t=lbl_805A0EB8->alloc(0x3C,0x13); U16(t,4)=0x3C;
   if(t) t=__ct__14Class_80325FDCFv(t,obj);
   PTR(obj,8)=t; break;
  }
  }
  PTR(obj,0xA0)=new Flag;
  F32(PTR(obj,8),0x20)=F32(p,0x98);
 }
 int secondIndex;
 int mode;
 float data[7];
 data[0]=length3((float*)(obj+0x10));
 data[1]=F32(PTR(obj,0x68),8);
 data[2]=F32(p,0x5C); data[3]=F32(p,0x58);
 secondIndex=2;
 U8(data,0x18)=(s8)U8(p,0x95)>=secondIndex;
 U8(data,0x19)=S8(p,0x68)==2;
 mode=S8(p,0x68);
 U8(data,0x1A)=mode>=1;
 U16(data,0x10)=1; U16(data,0x12)=secondIndex;
 U16(data,0x14)=3; U16(data,0x16)=4;
 fn_802CCB1C(PTR(obj,0x70),data);
 PTR(PTR(obj,0x68),0x28)=(u8*)PTR(obj,0x70)+0x1A64;
 {
  void* t=lbl_805A0EB8->alloc(0x70,0x30); U16(t,4)=0x70;
  if(t) t=fn_802E9BFC(t,obj);
  PTR(obj,0x20)=t;
  U16(t,0x20)=0xFFFF;
 }
 ((BF27*)((u8*)PTR(obj,0x20)+0x27))->hi=0;
 ((BF26*)((u8*)PTR(obj,0x20)+0x26))->lo=0;
 if(!nz((s8)U8(obj,0xB4))) {
  void* item=lbl_805A0EB8->alloc(0x70,0x30); U16(item,4)=0x70;
  if(item) item=fn_802E9BFC(item,obj);
  if(ARR->size==ARR->getCapacity()) fn_8027CE3C(ARR,4);
  ARR->data[ARR->size++]=item;
  U16(item,0x20)=0;
 }
 fn_802E3604(&block);
 U8(&block,0xB0)=7; F32(&block,0x90)=lbl_805A4430;
 r=lbl_805A0EB8->alloc(0x1F0,0x2B); U16(r,4)=0x1F0;
 if(r) r=fn_802E2840(r,&block);
 PTR(obj,0x24)=r;
 fn_802EC1C0(obj,r,1); fn_802F0668(PTR(obj,0x24));
 F32(obj,0x178)=lbl_805A4430; PTR(PTR(obj,0x68),0x24)=obj+0x170;
 if(nz(ne(3,(s8)U8(p,0x28)))) {
  void* t=lbl_805A0EB8->alloc(0x30,0xC); U16(t,4)=0x30;
  if(t) t=fn_802E911C(t,obj,(s8)U8(p,0x28));
  PTR(obj,0x168)=t;
 } else U32(obj,0x168)=0;
 {
  void* t=lbl_805A0EB8->alloc(0x10,0x13); U16(t,4)=0x10;
  if(t) t=fn_802F0714(t);
  PTR(obj,0x4C)=t;
  ((Class_802F0BEC*)t)->fn_802F12D8(obj);
 }
 if(nz(ne(3,(s8)U8(p,0x95)))) fn_80281ED8(obj+0x90);
 return self;
}

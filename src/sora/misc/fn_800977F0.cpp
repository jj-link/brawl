#include <types.h>
#pragma force_active on
struct S {
 int a; short b,c,d,e;
 float f0 __attribute__((aligned(16)));
 float f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19;
 S() {}
 S(const S& o) { *this=o; }
 S& operator=(const S& o) {
 a=o.a;b=o.b;c=o.c;d=o.d;e=o.e;
 f0=o.f0;f1=o.f1;f2=o.f2;f3=o.f3;f4=o.f4;f5=o.f5;f6=o.f6;f7=o.f7;f8=o.f8;f9=o.f9;
 f10=o.f10;f11=o.f11;f12=o.f12;f13=o.f13;f14=o.f14;f15=o.f15;f16=o.f16;f17=o.f17;f18=o.f18;f19=o.f19;
 return *this;
 }
};
struct Obj { u8 flags[2]; char pad[14]; S s; char pad2[0xA0]; float out; };
struct Entry { short id; short pad; int pos; };
struct Mgr { char pad[8]; Obj** objs; int count; int pad2; Entry* entries; int n; };
struct Mat {
 float a,b,c,d,e,f,g,h,i,j,k,l;
 Mat& operator=(const Mat& o) { a=o.a;b=o.b;c=o.c;d=o.d;e=o.e;f=o.f;g=o.g;h=o.h;i=o.i;j=o.j;k=o.k;l=o.l;return *this; }
};
struct V { float x,y,z; V() {} V(const V& o) {x=o.x;y=o.y;z=o.z;} V& operator=(const V& o) {x=o.x;y=o.y;z=o.z;return *this;} };
extern "C" Mat** fn_8032EF00(void*);
extern "C" int fn_800997D0(void*,s32);
extern "C" void fn_80283CD0(float*,float*);
extern "C" void fn_80284F2C(Mat*,float*);
extern "C" void fn_8003E388(const Mat*,Mat*);
extern "C" void fn_8003E6DC(const Mat*,V*);
static inline V getScale(const Mat* m) { V v; fn_8003E6DC(m,&v); return v; }
extern Mat lbl_804864C0;
extern float lbl_805A1D28,lbl_805A1D2C;
static inline Obj* find(Mgr* m,int id) {
 for(int i=0;i<m->count;++i) {
  Obj* o=m->objs[i];
  if(o && fn_800997D0(o,id)) return o;
 }
 return 0;
}
static inline bool contains(Mgr* m,int id) {
 for(int i=0;i<m->count;++i) {
  S s=m->objs[i]->s;
  if(s.b==id || s.c==id || s.d==id || s.e==id) return true;
 }
 return false;
}
struct Row {
 float x,y,z,w;
 Row(float a,float b,float c,float d) {x=a;y=b;z=c;w=d;}
} __attribute__((aligned(16)));
struct Mat4 {
 float in[16];
 void set(const Row& a,const Row& b,const Row& c,const Row& d) {
 in[0]=a.x;in[1]=b.x;in[2]=c.x;in[3]=d.x;
 in[4]=a.y;in[5]=b.y;in[6]=c.y;in[7]=d.y;
 in[8]=a.z;in[9]=b.z;in[10]=c.z;in[11]=d.z;
 in[12]=a.w;in[13]=b.w;in[14]=c.w;in[15]=d.w;
 }
} __attribute__((aligned(16)));
extern "C" void fn_800977F0(Mgr* self,Mat* matrices,void* arg) {
 Mat** result=fn_8032EF00(arg);
 Mat converted;
 float out[16];
 Mat4 in;
 Mat copy;
 V v2;
 V v1;
 V v;
 Mat4* inPtr=&in;
 float one,zero;
 zero=lbl_805A1D28;
 one=lbl_805A1D2C;
 for(int i=0;i<self->n;++i) {
  Entry* entry=&self->entries[i];
  int id=entry->id;
  int pos=entry->pos;
  Obj* found=find(self,id);
  if(found && contains(self,id) && found->flags[1]) {
   Mat* src=&matrices[pos];
   const Row& a=Row(src->a,src->b,src->c,src->d);
   const Row& b=Row(src->e,src->f,src->g,src->h);
   const Row& c=Row(src->i,src->j,src->k,src->l);
   const Row& d=Row(zero,zero,zero,one);
   inPtr->set(a,b,c,d);
   fn_80283CD0(inPtr->in,out);
   fn_80284F2C(&converted,out);
   (*result)[id]=converted;
   fn_8003E388(&matrices[pos],&copy);
   v1=getScale(&copy);
   v2=v1;
   found->out=v2.y;
  } else {
   (*result)[id]=lbl_804864C0;
  }
 }
}

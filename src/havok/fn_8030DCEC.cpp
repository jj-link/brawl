#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on
extern "C" int __cntlzw(unsigned int);
struct Vec4 {
 float x,y,z,w;
 inline void set(float f) { w=f; z=f; y=f; x=f; }
 inline void add(const Vec4& a,const Vec4& b) { x=a.x+b.x; y=a.y+b.y; z=a.z+b.z; w=a.w+b.w; }
 inline void mul(const Vec4& b) { x*=b.x; y*=b.y; z*=b.z; w*=b.w; }
};
struct Entry { u16 key,id; };
struct Axis {
 Entry* data; int size; u32 raw;
 inline Entry* last() { return data+size; }
};
struct Node {
 union { u32 lo; u16 lo16[2]; };
 union { u32 hi; u16 hi16[2]; };
 u16 xmin,xmax; u32 flags;
};
struct Marker { u16 id,pad; u16* list; int count; u32 raw; };
struct Pair { u32 zero,flags; };
struct PairArray { Pair* data; int size; u32 raw; };
class Class_804888F8 {
public:
 virtual void fn_8030A578();
 virtual void fn_80312920();
 virtual void fn_8030B884();
 virtual void fn_8030C454();
 virtual void fn_8030BFB8();
 char pad04[0x3c];
 Vec4 minOffset,maxOffset,scale;
 Node* nodes;
 int count;
 u32 field78;
 Axis axes[3];
 int markerCount,markerShift;
 Marker* markers;
};
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void* slot3(int);
 virtual void slot4(void*);
 char pad04[0xc];
 char* cursor;
 u32 field14;
 char* base;
 char* end;
};
extern Object_vptr_0* lbl_805A0EC8;
extern "C" Entry* fn_8030D76C(void*,Entry*,Entry*,u32);
extern "C" void fn_8030FBA0(void*,void*,void*);
extern "C" void fn_8027CE3C(int,int);
extern "C" void fn_8027EABC(void*,void*,u32,int);
inline void* allocate(int size) {
 Object_vptr_0* a=lbl_805A0EC8;
 char* p=a->cursor;
 char* next=p+size;
 if(next<=a->end) a->cursor=next;
 else p=(char*)a->slot3(size);
 return p;
}
inline void release(void* p) {
 Object_vptr_0* a=lbl_805A0EC8;
 a->cursor=(char*)p;
 if(p==a->base) a->slot4(p);
}
class Class_8030F90C {
public:
 Node** data; int size; int raw;
 Class_8030F90C():data(0),size(0),raw(0x80000000) {}
 inline int capacity() const { return raw&0x3fffffff; }
 ~Class_8030F90C() {
  if((raw&0x80000000)==0) fn_8027EABC(lbl_805A0EC8,data,capacity()*sizeof(Node*),0x15);
 }
 inline void push(Node* p) { data[size++]=p; }
};
class Class_8030F998 : public Class_8030F90C {
public:
 void* saved;
 Class_8030F998(int count) {
  data=(Node**)allocate((count*4+16)&~15);
  raw=count|0x80000000;
  saved=data;
 }
 ~Class_8030F998() { release(saved); }
};
struct TimerEntry { const char* name; u32 time,unused; };
struct Timer { u32 unused0; TimerEntry* current; u32 unused8; TimerEntry* end; u32 unused10[2]; };
extern Timer lbl_80532448;
extern char lbl_80488970[],lbl_80488964[],lbl_80488958[],lbl_80488948[];
extern char lbl_8059F034[3];
extern float lbl_805A4610;
extern Vec4 lbl_804888E0,lbl_80414340,lbl_80414330;
#define BEGIN_TIMER(output_,temporary_) { \
 TimerEntry* timerEnd=lbl_80532448.end; \
 (output_)=0; \
 TimerEntry* e=lbl_80532448.current; \
 (temporary_)=0; \
 Timer* t=&lbl_80532448; \
 s8 c=(s8)(((u32)timerEnd << __cntlzw((u32)timerEnd^(u32)e))>>31); \
 if(((u32)(-c|c)>>31)!=0) { \
  e->name=lbl_80488970; \
  ((const char**)e)[3]=lbl_80488964; \
  register u32 time; asm { mftb time } \
  e->time=time; \
  t->current=(TimerEntry*)((char*)e+16); \
 } \
}
#define RECORD(name_) { \
 TimerEntry* end=lbl_80532448.end; \
 TimerEntry* e=lbl_80532448.current; \
 Timer* t=&lbl_80532448; \
 s8 c=(s8)(((u32)end << __cntlzw((u32)end^(u32)e))>>31); \
 if(((u32)(-c|c)>>31)!=0) { \
  e->name=(name_); \
  register u32 time; asm { mftb time } \
  e->time=time; t->current=e+1; \
 } \
}
#define RECORD_END(name_,end_) { \
 Timer* t=&lbl_80532448; \
 end_=t->end; \
 TimerEntry* e=t->current; \
 s8 c=(s8)(((u32)end_ << __cntlzw((u32)end_^(u32)e))>>31); \
 if(((u32)(-c|c)>>31)!=0) { \
  e->name=(name_); \
  register u32 time; asm { mftb time } \
  e->time=time; t->current=e+1; \
 } \
}
inline float minf(const float& a,const float& b) { return a<b?a:b; }
inline float maxf(const float& a,const float& b) { return a>b?a:b; }
inline void clamp(Vec4& v) {
 v.x=minf(v.x,lbl_804888E0.x); v.y=minf(v.y,lbl_804888E0.y);
 v.z=minf(v.z,lbl_804888E0.z); v.w=minf(v.w,lbl_804888E0.w);
 v.x=maxf(v.x,lbl_80414340.x); v.y=maxf(v.y,lbl_80414340.y);
 v.z=maxf(v.z,lbl_80414340.z); v.w=maxf(v.w,lbl_80414340.w);
}
struct Quantized { union { s16 i[4]; u16 v[4]; }; u16 padding[4]; };
inline void quantize(Quantized& q,Vec4& v,Vec4& a) {
 a.add(v,lbl_80414330);
 v=a;
 q.i[0]=(s16)(*(u32*)&a.x>>7);
 q.i[1]=(s16)(*(u32*)&a.y>>7);
 q.i[2]=(s16)(*(u32*)&a.z>>7);
 q.i[3]=(s16)(*(u32*)&a.w>>7);
}
inline void toggle(u32* bits,int id) { u32 bit=1<<(id&31); bits[id>>5]^=bit; }
inline void clear(u32* bits,int id) { u32 bit=1<<(id&31); bits[id>>5]&=~bit; }
struct KeyBounds { int lo[4],hi[4]; };
inline void collect(Node* n,Node* base,int index,Class_8030F998* temp,Pair& pair,PairArray* out,int useTemp) {
 if(!useTemp) {
  pair.flags=base[index].flags;
  int capacity=out->raw&0x3fffffff;
  if(out->size==capacity) fn_8027CE3C((int)out,8);
  out->data[out->size++]=pair;
 } else temp->push(n);
}
inline void initializePair(Pair& pair,int firstHandle) { pair.zero=firstHandle; }
extern "C" void fn_8030DCEC(Class_804888F8* self,const Vec4* bounds,PairArray* output) {
 int useTemp;
 PairArray* out=output;
 Class_8030F998* local0;
 Node* block;
 u32* end;
 u32 mask;
 Node* node;
 u32* word;
 u32* bits;
 TimerEntry* lastEnd;
 BEGIN_TIMER(local0,useTemp);
 int count=self->count;
 int firstHandle=0;
 Object_vptr_0* allocator=lbl_805A0EC8;
 bits=(u32*)allocator->cursor;
 int bytes=(((count>>5)+8)*4+16)&~15;
 char* next=(char*)bits+bytes;
 if(next<=allocator->end) allocator->cursor=next;
 else bits=(u32*)allocator->slot3(bytes);
 Quantized qlo __attribute__((aligned(16)));
 Quantized qhi __attribute__((aligned(16)));
 Vec4 loTemp __attribute__((aligned(16)));
 Vec4 lo __attribute__((aligned(16)));
 Vec4 hiTemp __attribute__((aligned(16)));
 Vec4 hi __attribute__((aligned(16)));
 Vec4 zero __attribute__((aligned(16)));
 zero.set(lbl_805A4610);
 Vec4* p=(Vec4*)bits;
 for(int i=count>>7;i>=0;--i,++p) { *p=zero; }
 lo.add(bounds[0],self->minOffset);
 lo.mul(self->scale);
 clamp(lo);
 quantize(qlo,lo,loTemp);
 hi.add(bounds[1],self->maxOffset);
 hi.mul(self->scale);
 clamp(hi);
 quantize(qhi,hi,hiTemp);
 KeyBounds keys;
 keys.lo[0]=qlo.v[0]&0xfffe;
 keys.lo[1]=qlo.v[1]&0xfffe;
 keys.lo[2]=qlo.v[2]&0xfffe;
 keys.hi[0]=qhi.v[0]|1;
 keys.hi[1]=qhi.v[1]|1;
 keys.hi[2]=qhi.v[2]|1;
 int numMarkers=self->markerCount;
 Entry* walk=self->axes[0].data+1;
 if(numMarkers) {
  int idx=keys.lo[0]>>(16-self->markerShift);
  if(idx>0) {
   u16* ids;
   Marker* marker=self->markers+(idx-1);
   toggle(bits,marker->id);
   ids=marker->list;
   for(int k=marker->count-1;k>=0;--k) toggle(bits,*ids++);
   Node* mnode=self->nodes+marker->id;
   walk=self->axes[0].data+(mnode->xmin+1);
   Entry* aend=self->axes[0].data+mnode->xmax;
   for(;walk<aend;++walk) if(!(walk->key&1)) clear(bits,walk->id);
   walk=self->axes[0].data;
   walk+=mnode->xmin+1;
  }
 }
 while(walk->key<(u32)keys.lo[0]) { toggle(bits,walk->id); ++walk; }
 while(walk->key<(u32)keys.hi[0]) {
  if(!(walk->key&1)) toggle(bits,walk->id);
  ++walk;
 }
 RECORD(lbl_80488958);
 Node range;
 Axis* axis=&self->axes[1];
 Entry* base=axis->data;
 range.lo16[0]=fn_8030D76C(axis,base+1,axis->last()-2,(u16)keys.lo[1])-base;
 range.hi16[0]=fn_8030D76C(axis,base+1,axis->last()-2,(u16)keys.hi[1])-(base+1);
 axis=&self->axes[2];
 base=axis->data;
 range.lo16[1]=fn_8030D76C(axis,base+1,axis->last()-2,(u16)keys.lo[2])-base;
 range.hi16[1]=fn_8030D76C(axis,base+1,axis->last()-2,(u16)keys.hi[2])-(base+1);
 RECORD(lbl_80488948);
 Pair pair;
 initializePair(pair,firstHandle);
 block=self->nodes;
 word=bits;
 end=bits+(self->count>>5)+1;
 for(;word<end;block+=32,++word) {
  mask=*word;
  if(mask) {
   node=block;
   do {
    if(mask&15) {
     if(mask&1) {
      u32 bMax; u32 aMax; u32 bMin; Node* n; u32 aMin;
      n=node;
      aMin=n->lo;
      bMax=range.hi;
      bMin=range.lo;
      aMax=n->hi;
      bMax-=aMin;
      aMax-=bMin;
      aMax|=bMax;
      if(!(aMax&0x80008000))
       if(!(n->flags&1)) collect(n,node,0,local0,pair,out,useTemp);
     }
#define TAKE(bit,index) \
     if(mask&(bit)) { \
      u32 bMax; u32 aMax; u32 bMin; Node* n; u32 aMin; \
      bMin=range.lo; \
      n=node+(index); \
      aMax=n->hi; \
      aMin=n->lo; \
      bMax=range.hi; \
      aMax-=bMin; \
      bMax-=aMin; \
      aMax|=bMax; \
      if(!(aMax&0x80008000)) \
       if(!(n->flags&1)) collect(n,node,index,local0,pair,out,useTemp); \
     }
     TAKE(2,1)
     TAKE(4,2)
     TAKE(8,3)
#undef TAKE
    }
    mask>>=4; node+=4;
   } while(mask);
  }
 }
 release(bits);
 RECORD_END(lbl_8059F034,lastEnd);

}
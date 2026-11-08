#include <types.h>
#pragma force_active on
#pragma fp_contract on
extern "C" int __cntlzw(unsigned int);
struct Vec4 { float x,y,z,w; };
struct Mtx { float m[16]; };
struct Sub { char pad[12]; float f; };
struct Node { Sub* unk0; int unk4; Mtx* unk8; };
class Class_80487134 { public: virtual void fn_802C711C(); virtual void fn_80080A64(void*,void*); };
class Object_vptr_0 { public: virtual void slot0(); virtual void slot1(); };
struct TimerEntry { char* name; u32 time,unused; };
struct Timer { u32 unused0; TimerEntry* current; u32 unused8; TimerEntry* end; u32 unused10[2]; };
extern Timer lbl_80532448;
extern char lbl_8040FF90[];
extern float lbl_805A3FE8;
extern "C" void fn_8032561C(Vec4*,void*,void*,void*);
inline void record(int offset) {
 Timer* timer=&lbl_80532448;
 TimerEntry* entry=timer->current;
 if ((signed char)(((u32)timer->end << __cntlzw((u32)timer->end ^ (u32)entry)) >> 31)) {
 entry->name=lbl_8040FF90+offset;
 register u32 t; asm { mftb t }
 entry->time=t;
 timer->current=entry+1;
 }
}
inline void transform(Vec4& v,Mtx* A,Mtx* B) { float dy=A->m[13]-B->m[13];
 float dx=A->m[12]-B->m[12];
 float dz=A->m[14]-B->m[14];
 v.x=dz*B->m[2]+(dx*B->m[0]+dy*B->m[1]);
 v.y=dz*B->m[6]+(dx*B->m[4]+dy*B->m[5]);
 v.z=dz*B->m[10]+(dx*B->m[8]+dy*B->m[9]);
 v.w=lbl_805A3FE8;
}
extern "C" void fn_802C7B54(char* a0,Node* a1,Node* a2,void* a3,Class_80487134* a4) {
 record(0);
 Vec4 v __attribute__((aligned(16)));
 float out[8];
 Mtx* A=a1->unk8;
 Mtx* B=a2->unk8;
 Sub* s1=a1->unk0;
 Sub* s2=a2->unk0;
 transform(v,A,B);
 fn_8032561C(&v,(char*)s2+16,a0+16,out);
 float radius2=s2->f;
 float radius1=s1->f;
 float sum=radius1+radius2;
 if(out[4]<sum) a4->fn_80080A64(a1,a2);
 record(12);
}

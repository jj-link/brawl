#include <types.h>
#include <sr/sr_common.h>
#pragma force_active on
struct Vec3 { f32 x,y,z; };
struct Object_vptr_30_base { char pad[0x30]; };
class Object_vptr_30 : public Object_vptr_30_base {
public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual Vec3 slot4();
};
class Object_vptr_0 {
public:
virtual void slot0();
virtual void* slot1(int);
virtual u8 slot2();
virtual int slot3();
};
struct Owner { s32 m0; Object_vptr_0* m4; Object_vptr_0* m8; u32 mC; u8 m10; u8 pad11; u8 m12; };
struct Target { s32 m0; u8 pad4[4]; Object_vptr_0* m8; u32 mC; };
struct Entry : Object_vptr_0 { u8 pad4[0x14]; s32 m18; u16 m1c; u8 m1e; u8 m1f; };
struct Node74 { u8 pad0[0x18]; s32 m18; u8 pad1[0x74-0x1c]; u8 m74; };
struct New { u8 pad0[8]; s32 m8; u32 mC; f32 m10,m14,m18; u16 m1c,m1e; u8 m20,m21,m22,m23,m24,m25,m26,m27,m28,m29,m2a; };
extern "C" {
void* fn_27_4FAB4(void*);
void* fn_27_500B8(void*);
void* fn_8015C1B0(void*,void*);
void* fn_8015C1EC(void*,u16);
void fn_27_381F0(void*,void*,int);
extern int lbl_27_bss_B8;
}
inline Vec3 getPosition(Entry* e, Target* target, u8 kind) {
void* inner = target->m8->slot1(e->m1c);
Object_vptr_30* q=(Object_vptr_30*)fn_8015C1EC((u8*)inner+0x1c,kind);
return q->slot4();
}
inline void body(Owner* a0,Target* a1) {
u8* base;
Entry* e;
long i;
if(a0->m12==1) {
for(i=0;i<a0->m8->slot3();i++) {
e=0;
base=(u8*)a0->m8->slot1(i)+0x40;
while((e=(Entry*)fn_8015C1B0(base,e))) {
if(*(u32*)e==a1->mC && e->m18==a1->m0) {
const Vec3& v=getPosition(e,a1,e->m1e);
if(lbl_27_bss_B8==0) {
void* n=operator new(0x1508,(Heaps::HeapType)2);
if(n!=0) n=fn_27_4FAB4(n);
lbl_27_bss_B8=(int)n;
}
New* node=(New*)fn_27_500B8((void*)lbl_27_bss_B8);
u8 r17=((Node74*)a0->m8->slot1(i))->m74;
u8 r18=e->m1e;
u8 r19=e->m1f;
s32 r20=a0->m0;
u8 r24=a0->m4->slot2();
u8 r21=a0->m10;
u32 r22=a0->mC;
s32 m18=((Node74*)a0->m8->slot1(i))->m18;
node->m8=m18;
node->mC=r22;
node->m22=r21;
node->m20=r24;
node->m21=(u8)r20;
node->m23=(u8)i;
node->m1c=0;
node->m24=r19;
node->m25=r18;
node->m1e=0;
node->m26=0;
node->m10=v.x;
node->m14=v.y;
node->m18=v.z;
node->m27=1;
node->m28=0;
node->m29=0;
node->m2a=r17;
fn_27_381F0(a1->m8->slot1(e->m1c),node,0);
}
}
}
}
}
extern "C" void fn_27_36DC0(Owner* a0,Target* a1) { body(a0,a1); }

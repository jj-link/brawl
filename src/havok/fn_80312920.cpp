#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on
extern char lbl_80414360[];
class Object_vptr_0 {
public:
virtual void slot0();
virtual void slot1(const char*, int, void*);
virtual void slot2(const char*, int, void*, u32, u32);
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
};
class Class_804888F8 {
public:
virtual void fn_8030A578();
virtual void fn_80312920();
virtual void fn_8030B884();
virtual void fn_8030C454();
virtual void fn_8030BFB8();
virtual void fn_8030D044();
virtual void fn_8030D69C();
};
struct Ent { char pad[4]; void* ptr; u32 count; u32 flags; };
struct Self {
char pad0[0x70];
void* p70; u32 c74; u32 f78;
void* p7c; u32 c80; u32 f84;
void* p88; u32 c8c; u32 f90;
void* p94; u32 c98; u32 f9c;
u32 fa0; char padA4[4]; Ent* paa8;
};
inline void start(Self* self, Object_vptr_0* r, char* name, int size) {
r->slot1(name,size,self);
}
extern "C" void fn_80312920(Self* self,Object_vptr_0* r) {
char* base=lbl_80414360;
start(self,r,base+0x3D,4);
char* s48=base+0x48;
if (!(self->f78 & 0x80000000)) r->slot2(s48,4,self->p70,self->c74*16,self->f78*16);
char* s4e=lbl_80414360+0x4E;
if (!(self->f84 & 0x80000000)) r->slot2(s4e,4,self->p7c,self->c80*4,self->f84*4);
s4e=lbl_80414360+0x4E;
if (!(self->f90 & 0x80000000)) r->slot2(s4e,4,self->p88,self->c8c*4,self->f90*4);
s4e=lbl_80414360+0x4E;
if (!(self->f9c & 0x80000000)) r->slot2(s4e,4,self->p94,self->c98*4,self->f9c*4);
if(self->fa0!=0) r->slot2(lbl_80414360+0x53,4,self->paa8,self->fa0*16,0);
char* p53;
int off;
int i=0;
if((int)self->fa0>0) {
off=0;
p53=lbl_80414360+0x53;
for(;i<(int)self->fa0;off+=16,i++) {
Ent* e=(Ent*)((char*)self->paa8+off);
if(!(e->flags&0x80000000)) r->slot2(p53,8,e->ptr,e->count*2,(e->flags&0x3FFFFFFF)*2);
}
}
r->slot6();
}

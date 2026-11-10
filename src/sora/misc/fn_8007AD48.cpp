#include <types.h>
#include <gf/gf_task.h>
#include <sr/sr_common.h>
#pragma force_active on
struct TaskView {
char pad0[0x3C]; void* unk3C; char pad40[4];
void *unk44,*unk48,*unk4C,*unk50,*unk54;
u8 unk58; char pad59; s16 ids[32]; char pad9A[2]; s32 unk9C;
};
struct sndSystemView { char pad[0x70C]; f32 unk70C; };
extern "C" {
void __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, gfTask::Category, int, int, bool);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
void* fn_801C0CA0(void*);
void fn_801C0D44(void*, unsigned long);
void* fn_801C8754(void*);
unsigned long fn_801C8D38(void*, void*);
void fn_801C8B3C(void*, void*, void*, unsigned long, void*, unsigned long);
void* fn_803EEFCC(void*);
s32 fn_803EF174(void);
void fn_803EF108(void*, void*);
f32 fn_80077054(void*);
void fn_803EF478(void*, f32);
extern char lbl_80454618[];
extern char lbl_8045462C[];
extern f32 lbl_805A1B10;
}
extern sndSystemView* g_sndSystem;
extern "C" TaskView* fn_8007AD48(TaskView* self, unsigned long arg1, int heapType) {
void* p; unsigned long sz; void* q; f32 f31;
__ct__6gfTaskFPCcQ26gfTask8Categoryiib(self,lbl_80454618,gfTask::Category_None,0xE,6,true);
self->unk3C=lbl_8045462C; self->unk54=0; self->unk58=1;
p=__nw__FUlQ25Heaps8HeapType(0x150,heapType);
if(p) p=fn_801C0CA0(p);
self->unk44=p;
q=__nw__FUlQ25Heaps8HeapType(0xE0,heapType);
if(q) q=fn_801C8754(q);
self->unk48=q;
fn_801C0D44(self->unk44,arg1);
sz=fn_801C8D38(self->unk48,self->unk44);
self->unk4C=alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(heapType,sz);
self->unk50=alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(heapType,0x20);
fn_801C8B3C(self->unk48,self->unk44,self->unk4C,sz,self->unk50,0x20);
q=__nw__FUlQ25Heaps8HeapType(0xC8,heapType);
if(q) q=fn_803EEFCC(q);
self->unk54=q;
if(fn_803EF174()==0) fn_803EF108(self->unk54,self->unk48);
f31=g_sndSystem->unk70C;
fn_803EF478(self->unk54,lbl_805A1B10*(f31*fn_80077054(g_sndSystem)));
self->unk9C=0;
for(int i=0;i<32;++i) self->ids[i]=0xD3;
return self;
}
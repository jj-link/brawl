#include <types.h>
#include <gf/gf_task_scheduler.h>
#pragma force_active on
#define V(n) virtual void slot##n();
struct Module {
 V(0) V(1) V(2) V(3) virtual int slot4(u32);
 V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12)
 virtual u64 slot13(s16*);
 V(14) V(15) virtual int slot16(); virtual u32 slot17(u32);
};
struct FighterBase { char pad[0x3c]; };
struct Fighter : FighterBase {
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
 V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
 V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
 V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
 virtual u32 slot40();
};
#undef V
struct Owner { char pad[0x64]; Module* a; char pad2[8]; Module* b; char pad3[8]; Module* c; };
struct Self { char pad[8]; Fighter* fighter; char pad2[0xcc]; Owner* owner; };
extern "C" u32* fn_27_14554C(void*,u32,u32);
extern "C" int fn_27_8CC84(void*);
extern "C" void* __dynamic_cast(void*,long,const void*,const void*,short);
extern char g_ftCommonDataAccesser[];
extern char lbl_27_data_248[];
extern "C" char __RTTI__6gfTask[];
extern const f32 lbl_27_rodata_26B0;
inline bool compare(f32 x) { return x >= lbl_27_rodata_26B0; }
extern "C" int fn_27_194520(Self* input,u32 flag) {
 u32 savedFlag;
 int id;
 int kind;
 Self* s;
 s=input;
 savedFlag=flag;
 id=s->owner->a->slot4(0x10000007);
 if(id!=-1) {
 kind=s->owner->b->slot16();
 if(kind==0x6d || ((fn_27_14554C(g_ftCommonDataAccesser,s->fighter->slot40(),kind)[0]>>3)&1)) return 0;
 if(savedFlag==0) {
 if(s->owner->a->slot17(0x12000005)==1) return 0;
 } else {
 if(s->owner->a->slot17(0x12000005)==0) return 0;
 s16 index=1;
 union { u64 value; f32 f[2]; } result;
 result.value=s->owner->c->slot13(&index);
 if(compare(result.f[1])) return 0;
 }
 int category=s->owner->a->slot4(0x10000008);
 gfTask* task=gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)category,id);
 if(task) {
 void* object=__dynamic_cast(task,0x3c,lbl_27_data_248,__RTTI__6gfTask,0);
 if(object && fn_27_8CC84(object)) return 1;
 }
 }
 return 0;
}
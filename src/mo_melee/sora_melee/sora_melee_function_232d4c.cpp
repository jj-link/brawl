#include <ut/ut_list.h>
#include <st/st_trigger_observe.h>
#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" int lbl_27_data_4BEC8;
struct Trigger : utListNode {
 int kind; int id; unsigned char keep; char pad[3];
 int a,b,c,d,e,f; unsigned char flag,flag2,flag3,flag4; void* vtable;
};
struct Manager { char pad[0x40]; utList list; };
struct InputBytes { unsigned short id; unsigned char valid,keep; };
inline Trigger* findTrigger(utList* list, int id, unsigned char keep) {
 Trigger* p=(Trigger*)*(utListNode**)list;
 while(p) { if(p->id==id && p->keep==keep) return p; p=(Trigger*)p->m_next; }
 return 0;
}
inline void enableTrigger(Trigger* t) { if(t->flag4==0) t->flag=1; }
inline Trigger* createTrigger(Manager* mgr, stTriggerData* data) {
 int id=data->m_triggerId; Trigger* trigger=0;
 if(id!=-1) trigger=findTrigger(&mgr->list,id,((InputBytes*)data)->keep);
 if(!trigger) {
 Trigger* p=(Trigger*)__nw__FUlQ25Heaps8HeapType(0x34,15);
 if(p) {
 p->vtable=&lbl_27_data_4BEC8; p->kind=0; p->id=-1; p->keep=0;
 p->a=0;p->b=0;p->c=0;p->d=0;p->e=0;p->f=0;
 p->flag=0;p->flag2=0;p->flag3=0;p->flag4=0;
 }
 unsigned char keep=((InputBytes*)data)->keep;
 trigger=p;p->id=id;p->keep=keep;
 utListNode* node=*(utListNode**)&mgr->list;
 while(node) node=node->m_next;
 mgr->list.addTail(p);
 }
 if(id==0) enableTrigger(trigger);
 return trigger;
}
extern "C" void setTriggerFlag__12stTriggerMngFP13stTriggerData(Manager* mgr,stTriggerData* data) {
 Trigger* trigger=0;
 if(*(unsigned short*)data!=0) {
 trigger=findTrigger(&mgr->list,*(unsigned short*)data,((unsigned char*)data)[3]);
 if(!trigger) {
 if((unsigned char)(((unsigned char*)data)[3]+0xFF)<=1)
 trigger=createTrigger(mgr,data);
 else return;
 }
 if(((unsigned char*)data)[2]&1) { if(trigger->flag4==0) trigger->flag=1; }
 else if(trigger->flag4==0) trigger->flag=0;
 }
}

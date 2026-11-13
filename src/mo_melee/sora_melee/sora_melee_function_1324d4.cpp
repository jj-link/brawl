#include <types.h>
#include <ft/fighter.h>
#include <ft/ft_common_data_accesser.h>
#include <it/item.h>
#include <so/so_value_accesser.h>
#include <gf/gf_task_scheduler.h>
#pragma force_active on
struct Accesser;
struct Event {
 int kind; u8 field4, field5, field6, pad7;
 int field8, fieldC, field10, field14, field18;
 u8 field1C;
};
struct ModuleBase { char pad[8]; };
class StatusModule {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3(int, Accesser*);
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual int slot16();
};
class WorkModule {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual int slot4(int);
 virtual void slot5(int,int);
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual float slot12(int);
 virtual void slot13(float,int);
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual int slot17(int);
 virtual void slot18(int);
 virtual void slot19(int);
};
class Module3C {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9(int,int);
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14(int);
};
class Module40 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual u32 slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19(int);
};
class Module14 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual int slot3();
};
class Module20 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19(int,int);
};
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4(int,int);
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22();
 virtual void slot23();
 virtual void slot24();
 virtual void slot25();
 virtual void slot26();
 virtual void slot27();
 virtual void slot28();
 virtual void slot29();
 virtual void slot30();
 virtual void slot31();
 virtual void slot32();
 virtual void slot33();
 virtual void slot34();
 virtual void slot35();
 virtual void slot36();
 virtual void slot37();
 virtual void slot38();
 virtual void slot39();
 virtual void slot40();
 virtual void slot41();
 virtual u32 slot42(int);
 virtual void slot43();
 virtual void slot44();
 virtual void slot45();
 virtual void slot46();
 virtual void slot47();
 virtual void slot48();
 virtual void slot49();
 virtual void slot50();
 virtual void slot51();
 virtual void slot52();
 virtual void slot53();
 virtual void slot54();
 virtual void slot55();
 virtual void slot56();
 virtual void slot57();
 virtual void slot58();
 virtual void slot59();
 virtual void slot60();
 virtual void slot61();
 virtual void slot62();
 virtual void slot63();
 virtual void slot64();
 virtual void slot65();
 virtual void slot66();
 virtual void slot67();
 virtual void slot68();
 virtual void slot69();
 virtual void slot70();
 virtual void slot71();
 virtual void slot72();
 virtual void slot73();
 virtual void slot74();
 virtual void slot75();
 virtual void slot76(int,int,void*,int,int);
 virtual void slot77();
 virtual void slot78();
 virtual void slot79();
 virtual void slot80();
 virtual void slot81();
 virtual void slot82();
 virtual void slot83();
 virtual void slot84();
 virtual void slot85();
 virtual void slot86();
 virtual void slot87();
 virtual int slot88();
 virtual void slot89();
 virtual void slot90();
 virtual void slot91();
 virtual void slot92();
 virtual void slot93();
 virtual void slot94();
 virtual void slot95();
 virtual void slot96();
 virtual void slot97();
 virtual void slot98();
 virtual void slot99(int,int,int);
};
class Module58 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7(int);
};
class Module88 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22();
 virtual void slot23();
 virtual void slot24();
 virtual void slot25();
 virtual void slot26();
 virtual void slot27();
 virtual void slot28();
 virtual void slot29();
 virtual void slot30();
 virtual void slot31();
 virtual void slot32();
 virtual void slot33(int);
 virtual void slot34();
 virtual void slot35();
 virtual void slot36();
 virtual void slot37();
 virtual void slot38();
 virtual void slot39();
 virtual void slot40();
 virtual void slot41();
 virtual void slot42();
 virtual void slot43(int);
 virtual void slot44(int);
};
class Module5C {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22();
 virtual void slot23();
 virtual void slot24();
 virtual void slot25();
 virtual void slot26();
 virtual void slot27();
 virtual void slot28();
 virtual void slot29();
 virtual void slot30();
 virtual void slot31();
 virtual void slot32();
 virtual void slot33();
 virtual void slot34();
 virtual void slot35();
 virtual void slot36();
 virtual void slot37();
 virtual void slot38();
 virtual void slot39();
 virtual void slot40();
 virtual void slot41();
 virtual void slot42();
 virtual void slot43();
 virtual void slot44();
 virtual void slot45();
 virtual void slot46();
 virtual void slot47();
 virtual void slot48(float,float,float,int,int,int,int);
 virtual void slot49();
 virtual void slot50();
 virtual void slot51();
 virtual void slot52();
 virtual void slot53();
 virtual void slot54();
 virtual void slot55(int,int,int,int);
};
class Module38 : public ModuleBase {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14(void*,void*,int,int,int,int);
 virtual void slot15();
 virtual void slot16();
 virtual void slot17(float,int);
 virtual void slot18();
 virtual void slot19();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22(float,float,int);
};
class Module4 : public ModuleBase {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22();
 virtual void slot23();
 virtual void slot24();
 virtual void slot25();
 virtual void slot26();
 virtual void slot27();
 virtual void slot28();
 virtual void slot29();
 virtual void slot30();
 virtual void slot31();
 virtual void slot32();
 virtual int slot33(int);
};
class Module8 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7(float);
};
class ModuleC {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual float slot9();
};
class Module10 : public ModuleBase {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19(int,int);
 virtual void slot20();
 virtual void slot21();
 virtual void slot22();
 virtual void slot23();
 virtual void slot24();
 virtual void slot25();
 virtual void slot26();
 virtual void slot27();
 virtual void slot28();
 virtual void slot29();
 virtual void slot30();
 virtual void slot31();
 virtual void slot32();
 virtual void slot33();
 virtual int slot34(int);
 virtual void slot35();
 virtual void slot36();
 virtual void slot37();
 virtual void slot38();
 virtual Vec3f slot39(int);
};
class Module60 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13(int,int);
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22();
};
class ModuleB8 : public ModuleBase {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
};

struct Modules {
 int pad0; Module4* m4; Module8* m8; ModuleC* mC;
 Module10* m10; Module14* m14; char pad18[8]; Module20* m20;
 char pad24[0x14]; Module38* m38; Module3C* m3C; Module40* m40;
 char pad44[0x10]; Object_vptr_0* m54; Module58* m58; Module5C* m5C;
 Module60* m60; WorkModule* work; char pad68[8]; StatusModule* status;
 char pad74[0x14]; Module88* m88; char pad8C[0x2C]; ModuleB8* mB8;
};
struct Accesser { char pad[0xD8]; Modules* modules; };
struct CommonData { char pad[0x48]; int** values; };
struct Bits { unsigned char high:7; unsigned char low:1; };
extern "C" {
extern int lbl_27_bss_4ABC;
extern char lbl_27_data_248[];
extern char __RTTI__6gfTask[];
extern char lbl_27_data_292B4[];
extern const float lbl_27_rodata_1018[];
unsigned int* fn_27_14554C(void*,unsigned int,unsigned int);
CommonData* fn_27_145534(void*,int);
void fn_27_171280(void*,Accesser*);
void fn_27_6650(Fighter*,Event*,Accesser*,StageObject*,int);
void fn_27_188BD0(Event*,Accesser*,StageObject*,int);
void fn_27_18FB48(Event*,Accesser*,StageObject*,int);
void fn_27_190F50(Event*,Accesser*,StageObject*,int);
void fn_27_1392D4(Fighter*,float,float,int,int,int);
void fn_27_138CBC(Fighter*,int,int);
void fn_27_138458(Fighter*,int,int,int,int);
void* __dynamic_cast(void*,long,const void*,const void*,short);
}
inline Accesser* own(Fighter* f) { return (Accesser*)f->m_moduleAccesser; }
inline int kind(Fighter* f) { return *(int*)((char*)f+0x110); }
inline void init(Fighter* f,Event* e) {
 e->fieldC=0;
 e->field10=(*fn_27_145534(&g_ftCommonDataAccesser,kind(f))->values)[1];
}
inline float constant(Accesser* a,u32 id) {
 return soValueAccesser::getConstantFloat((soModuleAccesser*)a,id,0);
}
extern "C" void fn_27_1324D4(Fighter* self, Event* event, Accesser* accesser, StageObject* sender,int arg) {
 const float* rd=lbl_27_rodata_1018;
 switch(event->kind) {
 case 6: {
  int status=accesser->modules->status->slot16();
  int bits=(*fn_27_14554C(&g_ftCommonDataAccesser,self->getFtKind(),status)>>29)&3;
  event->field4=1;
  event->field6=1;
  if(bits==1) event->field5=0;
  else {
   event->field5=1;
   event->field8=accesser->modules->m4->slot33(0x12C);
   switch(accesser->modules->m14->slot3()) {
   case 0: accesser->modules->status->slot3(0x6E,accesser); break;
   case 1: case 2: accesser->modules->status->slot3(0x70,accesser); break;
   }
  }
  break;
 }
 case 7:
  if(accesser->modules->status->slot16()==0x6D)
   fn_27_171280(&lbl_27_bss_4ABC,accesser);
  break;
 case 8: {
  int status=accesser->modules->status->slot16();
  switch(status) {
  case 0x34: case 0x36: case 0x38:
   event->field8=accesser->modules->m4->slot33(0x12C);
   event->field4=1;
   event->field18=accesser->modules->work->slot4(0x10000033);
   accesser->modules->status->slot3(status==0x36?0x37:0x35,accesser);
   break;
  }
  break;
 }
 case 9:
  accesser->modules->m3C->slot14(0);
  accesser->modules->status->slot3(0x3B,accesser);
  break;
 case 0xA:
  accesser->modules->m40->slot19(0);
  accesser->modules->status->slot3(0x40,accesser);
  break;
 case 0xB: {
  accesser->modules->work->slot5(event->field8,0x20000000);
  accesser->modules->status->slot3(0x42,accesser);
  if((event->field14==5 || event->field14==0x16) && event->field8==0x78) {
   accesser->modules->m60->slot13(0,-1);
   accesser->modules->work->slot18(0x12000029);
   accesser->modules->work->slot19(0x1200001A);
  }
  if(!event->field1C) {
   float rate=constant(accesser,0xCC8);
   float scale=*(float*)((char*)g_ftCommonDataAccesser.getParam((ftKind)kind(self))+0xB0);
   scale*=rate;
   rate=rd[13]/scale;
   if(rate>constant(accesser,0xCC9)) rate=constant(accesser,0xCC9);
   else if(rate<constant(accesser,0xCCA)) rate=constant(accesser,0xCCA);
   *(float*)&event->field18=rate;
   accesser->modules->m8->slot7((float)(double)rate);
  }
  init(self,event);
  break;
 }
 case 0xC: {
  accesser->modules->m40->slot19(0);
  u32 id=accesser->modules->m54->slot42(0);
  gfTask* task=gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)0xA,id);
  accesser->modules->work->slot18(0x22000014);
  void* obj=__dynamic_cast(task,0x3C,lbl_27_data_248,__RTTI__6gfTask,1);
  accesser->modules->m38->slot14(obj,&event->fieldC,event->field8,event->field18,1,1);
  break;
 }
 case 0xE:
  accesser->modules->m3C->slot14(0);
  accesser->modules->m3C->slot9(0,0);
  if(!event->field5) accesser->modules->status->slot3(0x3B,accesser);
  break;
 case 0x10:
  accesser->modules->status->slot3(0xCE,accesser);
  init(self,event); break;
 case 0x11: event->field8=accesser->modules->m4->slot33(0x12E); break;
 case 0x12: break;
 case 0x16: accesser->modules->work->slot18(0x22000011); break;
 case 0x17:
  accesser->modules->work->slot5(event->fieldC,0x20000002);
  if(*(u8*)&event->field10) accesser->modules->work->slot18(0x22000010);
  accesser->modules->status->slot3(0xD3,accesser); break;
 case 0x1A: accesser->modules->status->slot3(0xD4,accesser); break;
 case 0x36:
  accesser->modules->m58->slot7(0);
  accesser->modules->m88->slot33(0); break;
 case 0x1B: accesser->modules->status->slot3(0xD9,accesser); break;
 case 0x1C:
  accesser->modules->work->slot5(event->field8,0x20000000);
  accesser->modules->status->slot3(0xDB,accesser);
  init(self,event); break;
 case 0x1D:
  accesser->modules->m58->slot7(0);
  accesser->modules->m20->slot19(2,0);
  accesser->modules->m10->slot19(0,0);
  if(accesser->modules->m54->slot88()==0) {
   Object_vptr_0* module=accesser->modules->m54;
   int value=accesser->modules->m4->slot33(0x12E);
   module->slot76(0,value,lbl_27_data_292B4,1,0);
  }
  accesser->modules->work->slot18(0x1200003B); break;
 case 0x1E:
  accesser->modules->status->slot3(0xEC,accesser);
  init(self,event); break;
 case 0x1F: event->field8=accesser->modules->m4->slot33(0x130); break;
 case 0x837:
  if(accesser->modules->status->slot16()==0xEC && sender->soGetKind()==2 && sender->soGetSubKind()==0x3C)
   accesser->modules->status->slot3(0xE,accesser);
  break;
 case 0x452:
  accesser->modules->status->slot3(0x108,accesser);
  accesser->modules->work->slot18(0x1200003B); break;
 case 0x21:
  switch(event->field8) {
  case 0x1B2: break;
  case 0x1B3: accesser->modules->status->slot3(0xE9,accesser); break;
  case 0x1B4:
   accesser->modules->work->slot5(event->field8,0x20000000);
   accesser->modules->status->slot3(0xEA,accesser); break;
  }
  init(self,event); break;
 case 0x22:
  accesser->modules->work->slot5(event->field8,0x20000000);
  accesser->modules->status->slot3(0xD7,accesser); break;
 case 0x23:
  accesser->modules->status->slot3(0xD8,accesser);
  init(self,event); break;
 case 0x24: case 0x3B: case 0x3C: break;
 case 0x25: fn_27_188BD0(event,accesser,sender,arg); break;
 case 0x3E:
  if(!accesser->modules->work->slot17(0x12000018))
   self->touchItem((soLinkTouchItemEventArgs*)event);
  break;
 case 0x3F: accesser->modules->m5C->slot55(15,0,0,-1); break;
 case 0x26:
  if(event->field8==-1) accesser->modules->status->slot3(0xE,accesser);
  else {
   accesser->modules->work->slot5(event->field8,0x20000000);
   init(self,event);
  } break;
 case 0x44D: accesser->modules->status->slot3(0xEF,accesser); break;
 case 0x44E:
  accesser->modules->m20->slot19(0,0);
  accesser->modules->work->slot18(0x22000010); break;
 case 0x28:
  if(event->fieldC==0xF7) {
   accesser->modules->m54->slot4(4,event->field10);
   accesser->modules->m54->slot99(4,0,1);
   accesser->modules->status->slot3(event->fieldC,accesser);
  } else if(accesser->modules->status->slot16()==0xF7 || accesser->modules->status->slot16()==0xF8) {
   accesser->modules->work->slot5(event->field8,0x20000001);
   accesser->modules->status->slot3(event->fieldC,accesser);
  } break;
 case 0x2A:
  if(accesser->modules->status->slot16()==0xF9) {
   accesser->modules->m38->slot22(rd[16],rd[16],0);
   accesser->modules->work->slot18(0x22000010);
  } break;
 case 0x2B:
  if(accesser->modules->m14->slot3()==0) accesser->modules->status->slot3(0,accesser);
  else accesser->modules->status->slot3(0xE,accesser);
  break;
 case 0x836:
  if(accesser->modules->m10->slot34(0)) {
   Vec3f pos=accesser->modules->m10->slot39(0);
   *(float*)&event->field8=pos.m_x;
   *(float*)&event->fieldC=pos.m_y;
   *(float*)&event->field10=pos.m_z;
   float x=accesser->modules->mC->slot9();
   event->field4=1;
   *(float*)&event->field8-=x;
  } else if(accesser->modules->status->slot16()==0x80) {
   *(float*)&event->field8=accesser->modules->work->slot12(0x21000005);
   *(float*)&event->fieldC=accesser->modules->work->slot12(0x21000006);
   *(float*)&event->field10=rd[12];
   *(float*)&event->field8-=accesser->modules->mC->slot9();
  } break;
 case 0x44F:
  switch(event->field8) {
  case 8: {
   int index=event->fieldC;
   event->fieldC=(*fn_27_145534(&g_ftCommonDataAccesser,kind(self))->values)[index]; break;
  }
  case 9: {
   self->setMetal(false,rd[16],-1);
   fn_27_1392D4(self,rd[12],rd[12],0,0,0);
   self->setCurry(false,-1);
   fn_27_138CBC(self,0,0);
   self->setSuperStar(false,-1,false);
   u8* flags=(u8*)self+0x138;
   if((*flags&1)==1U) {
    ((Bits*)flags)->low=0;
    own(self)->modules->m60->slot22();
   }
   fn_27_138458(self,0,1,0,0);
   Accesser* a=own(self);
   if(a->modules->work->slot17(0x12000028)==1U) {
    a->modules->m88->slot44(8);
    a->modules->m88->slot43(9);
    a->modules->work->slot19(0x12000028);
    a->modules->mB8->slot16();
   }
   break;
  }
  default: fn_27_18FB48(event,accesser,sender,arg); break;
  } break;
 case 0x450: fn_27_190F50(event,accesser,sender,arg); break;
 case 0x2C:
  accesser->modules->m54->slot4(4,event->field8);
  accesser->modules->m54->slot4(5,event->fieldC);
  accesser->modules->status->slot3(0x100,accesser); break;
 case 0x2D: accesser->modules->m38->slot17(*(float*)&event->fieldC,0); break;
 case 0x32:
  if(own(self)->modules->m14->slot3()==0) accesser->modules->status->slot3(0,accesser);
  else accesser->modules->status->slot3(0xE,accesser);
  break;
 case 0x34: {
  BaseItem* item=(BaseItem*)sender;
  float first=item->getParamFloat(0x2487);
  float second=item->getParamFloat(0x2488);
  float third=item->getParamFloat(8);
  accesser->modules->work->slot13(first*third,0x21000004);
  accesser->modules->work->slot13(second,0x21000005);
  accesser->modules->m40->slot19(0);
  accesser->modules->status->slot3(0x103,accesser); break;
 }
 case 0x35:
  accesser->modules->m5C->slot48(*(float*)&event->field8,*(float*)&event->fieldC,*(float*)&event->field10,0,-1,0,0); break;
 case 0x451: accesser->modules->work->slot19(0x12000001); break;
 case 2:
  if((own(self)->modules->status->slot16()==0xD1 || own(self)->modules->status->slot16()==0xD2 || own(self)->modules->status->slot16()==0xD0) && arg==0) {
   u32 id=*(u32*)((char*)sender+0x28);
   if(id==own(self)->modules->m40->slot6()) self->toDead((Fighter::Dead::Reason)event->field8);
  } break;
 case 0x13:
  if(own(self)->modules->status->slot16()==0xD1) accesser->modules->status->slot3(0xD2,accesser);
  break;
 default: break;
 }
 fn_27_6650(self,event,accesser,sender,arg);
}

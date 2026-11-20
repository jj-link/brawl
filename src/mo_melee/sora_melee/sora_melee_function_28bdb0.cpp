#include <types.h>
#include <so/link/so_link_module_impl.h>
#pragma force_active on

struct Event { int kind; unsigned char b4,b5,b6,b7; float f8; };
struct Arg3 { char pad[0x28]; unsigned int v28; };
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual unsigned int slot4(unsigned int);
 virtual void slot5(int, unsigned int);
};
struct ModBase { char pad[8]; };
class Mod : public ModBase {
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
 virtual void call(void*, Event*, void*, Arg3*, int);
};
struct SelfBase { char pad[0x3c]; };
class Self : public SelfBase {
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
 virtual void slot76();
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
 virtual void slot88();
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
 virtual void slot99();
 virtual void slot100();
 virtual void slot101();
 virtual void slot102();
 virtual void slot103();
 virtual void slot104();
 virtual void slot105();
 virtual void slot106();
 virtual void slot107();
 virtual void slot108();
 virtual void slot109();
 virtual void slot110();
 virtual void slot111();
 virtual void slot112();
 virtual void slot113();
 virtual void slot114();
 virtual void slot115();
 virtual void slot116();
 virtual void slot117();
 virtual void slot118();
 virtual void slot119();
 virtual void slot120();
 virtual void slot121();
 virtual void slot122();
 virtual void slot123();
 virtual void slot124();
 virtual void onHave();
 virtual void gap0();
 virtual void gap1();
 virtual void gap2();
 virtual void gap3();
 virtual void gap4();
 virtual void gap5();
 virtual void gap6();
 virtual void gap7();
 virtual void gap8();
 virtual void setVisibility(int);
 char padding[0x27a8-0x40];
 char link[4];
};
extern "C" void fn_27_6650(void*, void*, void*, void*, int);
extern "C" void fn_27_28E48C(void*, float*, float);
extern const float lbl_27_rodata_4610;

inline void helper(Self* self, Event* event, int arg4, Arg3* arg3, void* arg2) {
 fn_27_6650(self,event,arg2,arg3,arg4);
 (*(Mod**)((char*)self+0x8d0))->call(self,event,arg2,arg3,arg4);
 switch(event->kind) {
 case 2: {
  Object_vptr_0* work=(Object_vptr_0*)((char*)self+0x2aac);
  if(arg4==4) {
   unsigned int v=arg3->v28;
   if(v==work->slot4(0x10000013)) work->slot5(-1,0x10000013);
   if(((soLinkModule*)self->link)->isLink(4))
     ((soLinkModule*)self->link)->unlink(4);
  } else if(arg4==3) {
   ((soLinkModule*)self->link)->removeModelConstraint(true);
   if(((soLinkModule*)self->link)->isLink(3))
     ((soLinkModule*)self->link)->unlink(3);
   self->onHave();
  }
  break;
 }
 case 0x37:
  if(arg4==3) {
   int k=*(int*)((char*)self+0x8c0);
   if(k==12||k==56) self->setVisibility(event->b5);
  }
  break;
 case 0x38:
  if(arg4==3) {
   int k=*(int*)((char*)self+0x8c0);
   if(k==12||k==56) {
    float v[3]; v[0]=lbl_27_rodata_4610; v[1]=lbl_27_rodata_4610; v[2]=lbl_27_rodata_4610;
    fn_27_28E48C(self,v,event->f8);
   }
  }
  break;
 case 0x3d:
  if(arg4==4) ((Object_vptr_0*)((char*)self+0x2aac))->slot5(-1,0x10000013);
  else if(arg4==7) *(int*)((char*)self+0x8c8)=-1;
  break;
 }
}
extern "C" void fn_27_28BDB0(Self* self, Event* event, void* arg2, Arg3* arg3, int arg4) { helper(self,event,arg4,arg3,arg2); }

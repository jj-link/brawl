#include <ft/fighter.h>
#include <so/so_external_value_accesser.h>
#pragma force_active on
extern "C" void fn_27_12BAF8(void*, int);
struct Event { unsigned int id; unsigned char flag; };
class Class_8AD0 {
public:
 virtual void fn_105_8130();
 virtual void fn_105_17CBC();
 virtual void fn_105_18340();
 virtual void fn_105_1833C();
 virtual void fn_105_18338();
 virtual void fn_105_18334(int, unsigned int);
 virtual void fn_105_1832C();
 virtual void fn_105_18374();
 virtual void fn_105_1836C();
 virtual void fn_105_18364();
 virtual void fn_105_1835C();
 virtual void fn_105_18354();
 virtual void fn_105_182EC();
 virtual void fn_105_18320(float, unsigned int);
 virtual void fn_105_18314();
 virtual void fn_105_1830C();
 virtual void fn_105_18300();
};
class Class_8CA8 {
public:
 virtual void fn_105_8130();
 virtual void fn_105_17C60();
 virtual void fn_105_1852C();
 virtual void fn_105_18524();
 virtual void fn_105_1851C();
 virtual void fn_105_18514();
 virtual void fn_105_1850C();
 virtual void fn_105_18504();
 virtual void fn_105_184FC();
 virtual unsigned int fn_105_184F4(int);
 virtual void fn_105_184EC();
 virtual void fn_105_184E4();
 virtual void fn_105_184DC();
 virtual void fn_105_184D4();
 virtual void fn_105_18484();
 virtual void fn_105_184CC();
 virtual void fn_105_184BC(int, Event*, int);
};
#define MODULES(a) (*(unsigned char**)(*(unsigned char**)((unsigned char*)(a)+0x60)+0xd8))
#define WORK(a) (*(Class_8AD0**)(MODULES(a)+0x64))
#define LINK(a) (*(Class_8CA8**)(MODULES(a)+0x54))
#define FLAG(a) (*(unsigned char*)((unsigned char*)(a)+0x1fe4c))
extern "C" void fn_105_CD5C(Fighter* self, int status) {
 fn_27_12BAF8(self,status);
 switch(status) {
 case 0: case 1: case 2: case 3: case 8:
  if (FLAG(self)==1) {
   Class_8AD0* work;
   Fighter* partner=self->getPartner();
   Vec3f pos=soExternalValueAccesser::getPos(partner);
   float lr=soExternalValueAccesser::getLr(partner);
   work=WORK(self);
   work->fn_105_18334(0,0x10000040);
   work->fn_105_18320(pos.m_x,0x11000013);
   work->fn_105_18320(pos.m_x,0x11000014);
   work->fn_105_18320(pos.m_x,0x11000015);
   work->fn_105_18320(pos.m_x,0x11000016);
   work->fn_105_18320(pos.m_x,0x11000017);
   work->fn_105_18320(pos.m_y,0x11000018);
   work->fn_105_18320(pos.m_y,0x11000019);
   work->fn_105_18320(pos.m_y,0x1100001a);
   work->fn_105_18320(pos.m_y,0x1100001b);
   work->fn_105_18320(pos.m_y,0x1100001c);
   work->fn_105_18320(lr,0x1100001d);
   work->fn_105_18320(lr,0x1100001e);
   work->fn_105_18320(lr,0x1100001f);
   work->fn_105_18320(lr,0x11000020);
   work->fn_105_18320(lr,0x11000021);
  }
  break;
 }
 switch(status) {
 case 8: {
  Fighter* partner=self->getPartner();
  if (partner && FLAG(self)==0 && soExternalValueAccesser::getStatusKind(partner)!=0x10b) {
   if (LINK(self)->fn_105_184F4(6)==1U) {
    Event event;
    event.id=0x45e;
    event.flag=0;
    LINK(self)->fn_105_184BC(6,&event,0);
   }
  }
  break;
 }
 case 4:
  if (FLAG(self)==1) {
   Fighter* partner=self->getPartner();
   if (partner) {
    int value=soExternalValueAccesser::getWorkInt(partner,0x20000000);
    WORK(self)->fn_105_18334(value,0x20000000);
   }
  }
  break;
 }
}

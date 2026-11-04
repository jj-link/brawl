#include <mu/mu_msg.h>
#pragma force_active on
struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void processPreCollision();
 virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void processGameProc(); virtual void processEnd();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
 virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
 virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
 virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35(int);
};
struct Obj : gfTask {
 char pad40[0xa8];
 MuMsg* msg;
 unsigned char delay;
 char paded[3];
 int index;
 int state;
 unsigned char flag;
 char padf9[3];
 int value;
 int defaultValue;
};
extern "C" int fn_8004D9E8(void*);
extern "C" const char* getMsgData__5MuMsgFUlPPv(MuMsg*, unsigned long, void**);
extern "C" void fn_800B932C(MuMsg*, int);
extern "C" void* g_GameGlobal;
extern "C" char lbl_8059E3F0;
extern "C" const float lbl_805A2610;
extern "C" const float lbl_805A2624;
extern "C" void fn_800F57F0(Obj* self, int index, int state, int a, int b, int value) {
 void* length;
 if (self->msg) {
  if (!a) a = 3;
  if (!b) b = 10;
  if (!value) value = self->defaultValue;
  self->value = value;
  if (!fn_8004D9E8(g_GameGlobal)) {
   a = (int)((float)a * lbl_805A2624);
   b = (int)((float)b * lbl_805A2624);
  }
  self->index = index;
  self->flag = 0;
  if (self->state != state) {
   self->slot35(state);
   self->state = state;
  }
  if (self->index >= 0) {
   if (self->delay) self->msg->setDelayPrint(0, (float)a, (float)b, lbl_805A2610, lbl_805A2610);
   else getMsgData__5MuMsgFUlPPv(self->msg, index, &length);
   self->msg->printIndex(0, index, 0);
   fn_800B932C(self->msg, 0);
  } else {
   self->msg->printf(0, &lbl_8059E3F0);
   fn_800B932C(self->msg, 0);
  }
 }
}
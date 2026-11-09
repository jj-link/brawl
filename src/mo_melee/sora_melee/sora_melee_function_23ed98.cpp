#pragma force_active on
#include <if/if_mngr.h>
struct CallbackData {
 unsigned char bytes[0x1B];
 unsigned char f1B_0 : 1;
 unsigned char f1B_1 : 1;
 unsigned char f1B_2 : 1;
 unsigned char f1B_3 : 1;
 unsigned char f1B_4 : 1;
 unsigned char f1B_5 : 1;
 unsigned char f1B_6 : 1;
 unsigned char f1B_7 : 1;
 unsigned char f1C_0 : 1;
 unsigned char f1C_1 : 7;
 unsigned char pad1D[5];
 unsigned short h22;
 unsigned short h24;
};
struct Event {
 int enabled, field1, field0;
 char padding14, field5, field16, padding17;
 int mode, value;
 unsigned char valueIs24, padding21[3];
 int field24, field28;
 unsigned char field2C, field2D, padding2E[2];
 int field30, field34, field38, field3C, field40;
 char field44;
 unsigned char padding45[3];
 int field48;
};
struct ObjectBase { unsigned char padding[0x3C]; };
struct Object : ObjectBase {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void processCamera();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void renderOpa(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void init(); virtual void slot22(); virtual void slot23();
 virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
 virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
 virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
 virtual void slot36(); virtual CallbackData* slot37();
 unsigned char padding40[8]; int index; unsigned char padding4C[0x18]; unsigned char enabled;
};
extern "C" void fn_800E08A0(void*, Event*, unsigned char);
extern "C" void fn_27_23ED98(Object* self) {
 if (self->enabled != 0) {
  CallbackData* data = self->slot37();
  Event event;
  event.enabled = 0;
  event.field1 = 0;
  event.field0 = 0;
  event.padding14 = 0;
  event.field5 = 0;
  event.field16 = -1;
  event.mode = 0;
  event.value = 0;
  event.valueIs24 = 0;
  event.field24 = 3;
  event.field28 = 0;
  event.field2C = 0;
  event.field2D = 0;
  event.field30 = 0;
  event.field44 = 1;
  event.field48 = 0;
  event.field34 = 0;
  event.field38 = 0;
  event.field3C = 0;
  event.field40 = 0;
  event.field1 = data->bytes[1];
  event.field0 = data->bytes[0];
  event.field5 = data->bytes[5];
  if (data->f1B_4) event.mode = 2;
  else if (data->f1B_3) event.mode = 1;
  else event.mode = 0;
  if (data->f1C_0) {
   event.value = data->h24;
   event.valueIs24 = 1;
  } else {
   event.value = data->h22;
   event.valueIs24 = 0;
  }
  event.field24 = 0;
  event.field28 = data->bytes[0x0B];
  event.enabled = 1;
  IfMngr* manager = g_IfMngr;
  if (manager != 0) {
   unsigned char managerFlag = ((unsigned char*)manager)[0xA8];
   fn_800E08A0(manager->m_ifPlayers[self->index], &event, managerFlag);
  }
 }
}

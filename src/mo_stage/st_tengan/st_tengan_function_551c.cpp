#include <gr/gr_tengan_event.h>
#include <gr/gr_madein.h>
#include <st/stage.h>
#pragma force_active on
struct Param { char pad[0x100]; float a; char pad2[4]; float b; };
struct Tengan {
 char pad[0x9c]; Param* param; char pad2[0x218-0xa0]; int choice;
 char pad3[0x2c8-0x21c]; grTenganEvent event;
 char pad4[0xc30-0x374]; grTenganEvent eventA;
 char pad5[0xd88-0xcdc]; grTenganEvent eventB;
 char pad6[0xe54-0xe34]; unsigned char flag;
 char pad7[0xee8-0xe55]; int value; float time;
};
extern "C" float lbl_60_rodata_38;
extern "C" int randi__Fl(long);
extern "C" void fn_60_551C(Tengan* self) {
 Param* p = self->param;
 if (p) {
  float scale = lbl_60_rodata_38;
  int choice = 0;
  int r = randi__Fl((int)(p->b * scale + p->a * scale) + 1);
  int sum = 0;
  unsigned int done = 0;
  do {
   switch (choice) {
    case 0: sum += (int)(p->b * scale); break;
    case 1: sum += (int)(p->a * scale); break;
    case 2: sum = r; break;
   }
   if (sum >= r) done = 1;
   if (sum < r) choice++;
  } while (done != 1);
  bool started = false;
  if (self->choice != choice) {
   if (choice != 1) started = self->eventA.start();
   else started = self->eventB.start();
  }
  if (started == 1) {
   self->choice = choice;
   self->flag = 1;
   ((grMadein*)((Stage*)self)->getGround(0x13))->setMotion(1);
   ((grMadein*)((Stage*)self)->getGround(0x13))->startEntity();
   self->event.end();
   self->event.start();
   float temp = lbl_60_rodata_38;
   self->value = 0x1c5f;
   self->time = temp;
  }
 }
}
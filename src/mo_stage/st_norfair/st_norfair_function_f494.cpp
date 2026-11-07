#pragma force_active on
#pragma fp_contract off
#include <snd/snd_system.h>
#include <mt/mt_prng.h>
#include <nw4r/ut/ut_algorithm.h>
extern "C" const float lbl_54_rodata_198;
extern "C" const float lbl_54_rodata_1A4;
struct Params { char pad[8]; float range, accel, limit; };
struct Entry { float value, low, high; };
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual Entry* slot3(int);
};
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
 virtual void processDefault();
 virtual void processBegin();
 virtual void fn_54_F1F0();
 virtual void processUpdate();
 virtual void processPreMapCorrection();
 virtual void processMapCorrection();
 virtual void processFixPosition();
 virtual void processPreCollision();
 virtual void processCollision();
 virtual void processCatch();
 virtual void processHit();
 virtual void processCamera();
 virtual void processFixCamera();
 virtual void processEffect();
 virtual void processGameProc();
 virtual void processEnd();
 virtual void renderPre();
 virtual void renderOpa();
 virtual void renderXlu();
 virtual void processDebug();
 virtual void renderDebug();
 virtual void init();
 virtual void fn_54_F16C();
 virtual void fn_54_F244();
 virtual void loadGroundData();
 virtual void bindData();
 virtual void setupMelee();
 virtual void setVisibility();
 virtual void setVisibilityByClipping();
 virtual void setVisibilityAttachedEffect();
 virtual void receiveCollMsg();
 virtual void receiveCollMsg_Landing();
 virtual void receiveCollMsg_Heading();
 virtual void receiveCollMsg_Wall();
 virtual void receiveCollMsg_Attack();
 virtual void unloadData();
 virtual void fn_54_338C();
 virtual void startup();
 virtual void fn_54_F890();
 virtual void fn_54_1310();
 virtual Params* fn_54_3150();
};
struct Self : Ground {
 char pad40[0x110];
 unsigned char state;
 char pad151[3];
 float timer;
 unsigned char* mode;
 unsigned char index;
 char pad15d[3];
 float speed;
 float previous;
 float offset;
 float target;
 char pad170[4];
 float position;
 char pad178[4];
 Object_vptr_0* entries;
};
extern "C" void fn_54_F494(Self* self, float delta) {
 Params* p = self->fn_54_3150();
 if (p) {
  self->timer -= delta;
  if (self->timer < lbl_54_rodata_198) self->timer = lbl_54_rodata_198;
  Entry* e = self->entries->slot3(self->index);
  if (!e) { self->index = 1; return; }
  if (*self->mode == 4) {
   self->timer = lbl_54_rodata_198;
   if (self->index != 0) self->state = 1;
  }
  switch (self->state) {
  case 0:
   self->position = e->value;
   self->timer = e->low + (e->high - e->low) * randf();
   self->state = 1;
   break;
  case 1:
   if (lbl_54_rodata_198 == self->timer) {
    if (*self->mode == 4) self->index = 0;
    else { self->index++; self->offset = p->range * randf(); }
    if (e->value + self->offset > self->position)
     g_sndSystem->playSE((SndID)0x1bc4, 0, 0, 0, -1);
    if (e->value + self->offset < self->position)
     g_sndSystem->playSE((SndID)0x1bc5, 0, 0, 0, -1);
    self->state = 2;
    self->speed = lbl_54_rodata_198;
    self->previous = lbl_54_rodata_198;
   }
   break;
  case 2:
   self->target = e->value + self->offset;
   if (self->target > self->position) self->speed += p->accel * delta;
   if (self->target < self->position) self->speed -= p->accel * delta;
   if (nw4r::ut::Abs(self->speed) > p->limit) {
    if (self->target > self->position) self->speed = p->limit * delta;
    if (self->target < self->position) self->speed = lbl_54_rodata_1A4 * (p->limit * delta);
   }
   self->position += self->speed * delta;
   if (lbl_54_rodata_198 != self->previous) {
    unsigned int changed = 0;
    if (self->previous > lbl_54_rodata_198 && self->speed < lbl_54_rodata_198) changed = 1;
    if (self->previous < lbl_54_rodata_198 && self->speed > lbl_54_rodata_198) changed = 1;
    if (lbl_54_rodata_198 == self->speed) changed = 1;
    if (changed == 1) {
     self->timer = e->low + (e->high - e->low) * randf();
     self->state = 1;
    }
   }
   self->previous = self->speed;
   break;
  }
 }
}

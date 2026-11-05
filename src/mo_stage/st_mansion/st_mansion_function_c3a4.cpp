#pragma force_active on
#pragma fp_contract off
extern "C" float randf__Fv();
extern "C" const float lbl_47_rodata_110[];
struct Params { char pad[0x3C]; float accel; float maxSpeed; };
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
 virtual void processDefault();
 virtual void processBegin();
 virtual void processAnim();
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
 virtual void fn_47_BA84();
 virtual void fn_47_BADC();
 virtual void loadGroundData();
 virtual void bindData();
 virtual void setupMelee();
 virtual void setVisibility();
 virtual void setVisibilityByClipping();
 virtual void setVisibilityAttachedEffect();
 virtual void receiveCollMsg();
 virtual void fn_47_CB54();
 virtual void receiveCollMsg_Heading();
 virtual void receiveCollMsg_Wall();
 virtual void receiveCollMsg_Attack();
 virtual void unloadData();
 virtual void fn_47_1A28();
 virtual void startup();
 virtual void setNode();
 virtual void fn_47_5A0();
 virtual Params* fn_47_1A20();
};
struct Ptr { char pad[4]; float pos; };
struct Self : Ground {
 char pad40[0x119];
 unsigned char state;
 char pad15A[6];
 float timer;
 char pad164[4];
 Ptr* ptr;
 char pad16C[4];
 float limit;
 char pad174[0x14];
 float speed;
};
extern "C" void fn_47_C3A4(Self* self, float delta) {
 const float* c = lbl_47_rodata_110;
 Params* p = self->fn_47_1A20();
 if (p == 0) return;
 self->timer = self->timer - delta;
 if (self->timer < c[0]) self->timer = c[0];
 switch (self->state) {
 case 0:
  self->state = 2;
  self->timer = c[6];
  break;
 case 2:
  if (c[0] == self->timer) {
   float r = randf__Fv();
   self->state = 11;
   self->timer = c[7] + c[4] * r;
  }
  break;
 case 11:
  if (c[0] == self->timer || self->ptr->pos > c[3] + self->limit) {
   float r = randf__Fv();
   self->state = 12;
   self->timer = c[8] + c[4] * r;
  } else {
   self->speed += p->accel * delta;
   if (self->speed > p->maxSpeed) self->speed = p->maxSpeed;
   self->ptr->pos += self->speed * delta;
  }
  break;
 case 12:
  if (c[0] == self->timer || self->ptr->pos < self->limit) {
   float r = randf__Fv();
   self->state = 11;
   self->timer = c[4] + c[4] * r;
  } else {
   self->speed -= p->accel * delta;
   if (self->speed < -p->maxSpeed) self->speed = -p->maxSpeed;
   self->ptr->pos += self->speed * delta;
  }
  break;
 }
}
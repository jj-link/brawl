#pragma force_active on
class Class_3138 {
public:
 virtual void fn_63_D57C();
 virtual void fn_63_CA44();
 virtual void fn_63_CA54();
 virtual unsigned char* fn_63_AF3C(unsigned char);
};
class Class_34E0 {
public:
 virtual void fn_63_EF70();
 virtual void fn_63_E390();
 virtual void fn_63_E3A0();
 virtual unsigned char* fn_63_B09C(unsigned char);
};
class Class_47D8 {
public:
 virtual void fn_63_EF70();
 virtual void fn_63_E390();
 virtual void fn_63_E3A0();
 virtual unsigned char* fn_63_10B3C(unsigned char);
};
class Class_4D30 {
public:
 virtual void fn_63_D57C();
 virtual void fn_63_CA44();
 virtual void fn_63_CA54();
 virtual unsigned char* fn_63_11FB4(unsigned char);
};
struct Ground_base { char pad[0x3c]; };
struct Item { char pad[0x54]; unsigned char b0:1; unsigned char b1:1; unsigned char b2:1; unsigned char b3:1; unsigned char rest:4; };
class Ground : public Ground_base {
public:
 virtual void processDefault();
 virtual void processBegin();
 virtual void fn_63_3C84();
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
 virtual void fn_63_3BE4();
 virtual void fn_63_3D84();
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
 virtual void fn_63_3378();
 virtual void startup();
 virtual void setNode();
 virtual void fn_63_59C();
 virtual int fn_63_3370();
 char pad2[0x144];
 unsigned char* state;
 char pad3[8];
 Class_3138* data;
 char pad4[0x10];
 Item** items;
};
extern "C" void fn_63_484C(Ground* self) {
 if (self->items && self->state && self->data && self->fn_63_3370()) {
  unsigned char* values = self->data->fn_63_AF3C(*self->state);
  if (values || (*self->state = 0, values = self->data->fn_63_AF3C(*self->state))) {
   for (int i = 0; i < 20; i++) {
    switch (values[i]) { case 1: {
     Item* item = self->items[i];
     item->b3 = 1;
     item->b1 = item->b3;
     break;
    } default: {
     Item* item = self->items[i];
     item->b0 = 0;
     item->b3 = item->b0;
     item->b1 = item->b3;
     break;
    }}
   }
  }
 }
}
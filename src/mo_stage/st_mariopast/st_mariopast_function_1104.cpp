#include <gf/gf_archive.h>
#pragma force_active on
struct Stage {
 char pad0[0x9c]; void* data; char padA0[0x100]; gfArchive* archive;
 char pad1a4[0x48]; char field1ec[0x24]; char field210[0xb4];
 unsigned char mode; char pad2c5[3]; char field2c8[8];
 int field2d0[2]; int field2d8[2]; char field2e0[2][0x10];
};
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
 virtual void processDefault(); virtual void processBegin(); virtual void slot2();
 virtual void processUpdate(); virtual void processPreMapCorrection(); virtual void processMapCorrection();
 virtual void processFixPosition(); virtual void processPreCollision(); virtual void processCollision();
 virtual void processCatch(); virtual void processHit(); virtual void processCamera();
 virtual void processFixCamera(); virtual void processEffect(); virtual void processGameProc();
 virtual void processEnd(); virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu();
 virtual void processDebug(); virtual void renderDebug(); virtual void init();
 virtual void slot22(); virtual void slot23(); virtual void loadGroundData(); virtual void bindData();
 virtual void setupMelee(); virtual void setVisibility(); virtual void setVisibilityByClipping();
 virtual void setVisibilityAttachedEffect(); virtual void receiveCollMsg(); virtual void receiveCollMsg_Landing();
 virtual void slot32(); virtual void receiveCollMsg_Wall(); virtual void receiveCollMsg_Attack();
 virtual void unloadData(); virtual void fn_48_203C(); virtual void slot37(gfArchive*, int, int);
 virtual void slot38(); virtual void fn_48_7BC(void*);
 char pad40[0x118]; unsigned char mode, index; char pad15a[2];
 int field15c, field160; void* joint; void* field168; void* field16c;
};
extern "C" {
extern char lbl_48_data_118[];
void* fn_8018D174(void*, int);
void fn_48_1924(Stage*, void*, void**, int, float);
Ground* fn_48_78E8(int, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void __dl__FPv(void*);
void fn_48_134C(Stage*, void*, void*, Ground*, int, int);
void* create__11grCollisionFP5StagePvP6Groundi(Stage*, void*, Ground*, int);
void* getJoint__11grCollisionFUs(void*, unsigned short);
void fn_48_7DAC(Ground*);
void fn_48_7E6C(Ground*);
}
inline void* makeCollision(Stage* self, void* col, Ground* ground, int c, int b) {
 if (!col) return 0;
 if (!ground) return 0;
 void* p = __nw__FUlQ25Heaps8HeapType(0x28, 15);
 if (!p) return 0;
 fn_48_134C(self, p, col, ground, c, b);
 void* collision = create__11grCollisionFP5StagePvP6Groundi(self, p, ground, 1);
 __dl__FPv(p);
 return collision;
}
extern "C" void fn_48_1104(Stage* self) {
 char* pos;
 Stage* cursor;
 char* col;
 void* data = self->data;
 if (data) {
  void* model = 0;
  void* resource = self->archive->getData(Data_Type_Model, 1, (unsigned short)0xfffe);
  bool ok;
  if (!resource) ok = false;
  else {
   void* p = fn_8018D174(&resource, 0);
   if (!p) ok = false;
   else { model = p; ok = true; }
  }
  if (ok) {
   float f = *(float*)((char*)data + 0xc);
   switch (self->mode) {
   case 0: fn_48_1924(self, self->field2c8, &model, 0x2c, f); break;
   case 1: fn_48_1924(self, self->field2c8, &model, 0x107, f); break;
   }
   pos = self->field210;
   cursor = self;
   col = self->field2e0[0];
   for (unsigned int i = 0; i < 2; i++, pos += 0xc, cursor = (Stage*)((char*)cursor + 4), col += 0x10) {
    Ground* ground = fn_48_78E8(0x5a, lbl_48_data_118);
    if (ground) {
     addGround__5StageFP6Ground(self, ground);
     ground->mode = self->mode;
     ground->index = i;
     ground->fn_48_7BC(self->data);
     ground->field168 = pos;
     ground->field16c = self->field1ec;
     int value = cursor->field2d8[0];
     ground->field15c = cursor->field2d0[0];
     ground->field160 = value;
     ground->slot37(self->archive, 0, 0);
     void* collision = makeCollision(self, col, ground, cursor->field2d0[0], cursor->field2d8[0]);
     if (collision) {
      ground->joint = getJoint__11grCollisionFUs(collision, 0);
      fn_48_7DAC(ground);
     }
     fn_48_7E6C(ground);
    }
   }
  }
 }
}

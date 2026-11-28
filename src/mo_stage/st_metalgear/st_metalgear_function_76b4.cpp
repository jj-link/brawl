#include <gr/collision/gr_collision.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

extern "C" grCollisionJoint* getJoint__11grCollisionFUs(grCollision*, unsigned int);
extern "C" void fn_80162384(float*, float*, float);
extern "C" const float lbl_71_rodata_178[];

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
 virtual void processDefault(); virtual void processBegin(); virtual void fn_71_6D5C(); virtual void processUpdate();
 virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void processFixPosition(); virtual void processPreCollision();
 virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera();
 virtual void processFixCamera(); virtual void processEffect(); virtual void processGameProc(); virtual void processEnd();
 virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug();
 virtual void renderDebug(); virtual void init(); virtual void fn_71_6C6C(); virtual void fn_71_6E50();
 virtual void loadGroundData(); virtual void bindData(); virtual void setupMelee(); virtual void setVisibility();
 virtual void setVisibilityByClipping(); virtual void setVisibilityAttachedEffect(); virtual void receiveCollMsg(); virtual void receiveCollMsg_Landing();
 virtual void receiveCollMsg_Heading(); virtual void receiveCollMsg_Wall(); virtual void receiveCollMsg_Attack(); virtual void unloadData();
 virtual void fn_71_2B8C(); virtual void startup(); virtual void setNode(); virtual void fn_71_85C();
 virtual void fn_71_2B84(); virtual void fn_71_2B80(); virtual void fn_71_2700(); virtual void fn_71_2B78();
 virtual void fn_71_2B6C(); virtual void fn_71_2B5C(); virtual void fn_71_F04(); virtual void getNodeIndex();
 virtual void getNodePosition(); virtual void getNodePosition_2(); virtual void getNodeMatrix(); virtual void getNodeMatrix_2();
 virtual void setNodeVisibility(); virtual void setNodeVisibility_2(); virtual void setNodeVisibilityAll(); virtual void isNodeVisible();
 virtual void setNodeCollision(); virtual void setNodeCollision_2(); virtual void getNodeScale(); virtual void getNodeScale_2();
 virtual void setValid(); virtual void setValidAttachedEffect(); virtual void fn_71_2B58(); virtual void fn_71_2B54();
 virtual void fn_71_2B4C(); virtual void setMotionRatio(); virtual void setMotionFrame(); virtual float getMotionFrame(unsigned long);
 char pad40[0xc]; grCollision* collision; char pad50[0x100];
 unsigned char motion; char pad151[0x1f];
 struct Params* params; float* angle; char pad178[0x1c];
 unsigned char kind; char pad195[3];
 float x0, y0, x1, y1; char pad1a8[0xc];
 float endFrame; char pad1b8[0x20];
 grCollisionJoint* joint; int index;
};
struct Params { char pad[0x84]; float a,b,c,d,e,f; };

inline float clamp01(float t, float lo, float hi) {
 t = nw4r::math::FSelect(t - lo, t, lo);
 return nw4r::math::FSelect(t - hi, hi, t);
}

extern "C" void fn_71_76B4(Ground* self) {
 Vec2f* p;
 Vec2f* q;
 grCollision* collision;
 unsigned int i;
 unsigned int count;
 const float* data = lbl_71_rodata_178;
 grCollisionJoint* joint;
 switch (self->kind) {
 case 0:
  goto active;
 case 2:
  goto active;
 default:
  return;
 active:
  if (self->joint == 0) {
   collision = self->collision;
   if (collision == 0) return;
   i = 0;
   count = (unsigned short)collision->m_jointLen;
   for (; i != count; ++i) {
    joint = getJoint__11grCollisionFUs(collision, i);
    if (joint && joint->m_ground == self) break;
   }
   if (i == count) return;
   self->joint = joint;
   struct JointState { char pad[0x48]; unsigned int pad0:8; unsigned int mode:8; unsigned int pad1:16; };
   ((JointState*)joint)->mode = 3;
   grCollisionLine* line = joint->getLine(0);
   unsigned short n = joint->m_vtxLen;
   for (unsigned int j = 0; j != n; ++j) {
    grCollData::VtxData p;
    __memcpy(&p, &joint->m_vtxDatas[(unsigned short)(*(unsigned short*)&line->m_point0Index + j)], sizeof(p));
    if (p.m_pos.m_y > data[12]) {
     self->index = j;
     self->x0 = p.m_pos.m_x;
     self->y0 = data[13];
     Vec2f q;
     __memcpy(&q, &joint->m_vtxDatas[(unsigned short)(*(unsigned short*)&line->m_point0Index + (j + 1))].m_pos, sizeof(q));
     self->x1 = q.m_x;
     self->y1 = data[13];
     break;
    }
   }
  }
  if (self->joint && self->index != -1) {
   grCollisionLine* line = self->joint->getLine(0);
   if (!line) return;
   float a, b;
   if (self->motion == 5) {
    float t = (self->getMotionFrame(0) - data[5]) / (self->endFrame - data[5]);
    a = clamp01(t, data[0], data[4]);
    t = (self->getMotionFrame(0) - data[5]) / ((self->endFrame - data[5]) - data[14]);
    b = clamp01(t, data[0], data[4]);
   } else {
    a = data[4]; b = a;
   }
   int i = self->index;
   int next = i + 1;
   int point = *(unsigned short*)line;
   grCollData::VtxData* vertices = self->joint->m_vtxDatas;
   p = &vertices[(unsigned short)(point + i)].m_pos;
   q = &vertices[(unsigned short)(point + next)].m_pos;
   float s, c;
   switch (self->kind) {
   case 0:
    fn_80162384(&s, &c, data[15] * (data[16] - data[6] * a));
    if (self->angle) *self->angle = data[16] - data[6] * a;
    self->params->a = data[17];
    self->params->b = a; self->params->c = b;
    if (data[4] != a) fn_80162384(&s, &c, data[18]);
    p->m_x = self->x0 + data[19] * c;
    p->m_y = self->y0 + data[19] * s;
    q->m_x = self->x1 + data[19] * c;
    q->m_y = self->y1 + data[19] * s;
    break;
   case 2:
    fn_80162384(&s, &c, data[15] * (data[6] * a));
    if (self->angle) *self->angle = data[6] * a;
    self->params->d = data[20];
    self->params->e = a; self->params->f = b;
    if (data[4] != a) fn_80162384(&s, &c, data[0]);
    p->m_x = self->x0 + data[19] * c;
    p->m_y = self->y0 + data[19] * s;
    q->m_x = self->x1 + data[19] * c;
    q->m_y = self->y1 + data[19] * s;
    break;
   }
  }
  break;
 }
}
#include <gr/gr_yakumono.h>
#include <st/st_trigger.h>
#include <so/area/so_area_module_impl.h>
#pragma force_active on

struct Quad { float a,b; union { float c; float d; }; Quad(float a_, float b_, float c_, float d_) : a(d_), b(c_), c(b_) { d = a_; } };
struct Info { char pad[0x20]; float a,b,c,d; };
struct Base73 { char pad[0x3c]; };
#define V4(n) virtual void v##n##a(); virtual void v##n##b(); virtual void v##n##c(); virtual void v##n##d();
class Obj : public Base73 {
public:
 virtual void processDefault();
 virtual void processBegin();
 virtual void slot2();
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
 virtual void slot14();
 virtual void processEnd();
 virtual void renderPre();
 virtual void renderOpa();
 virtual void renderXlu();
 virtual void processDebug();
 virtual void renderDebug();
 virtual void init();
 virtual void slot22();
 virtual void slot23();
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
 virtual void fn_73_33D0();
 virtual void slot37();
 virtual void slot38();
 virtual void fn_73_8DC();
 virtual void fn_73_33C8();
 virtual void fn_73_33C4();
 virtual void fn_73_2C5C();
 virtual void fn_73_33BC();
 virtual void fn_73_33B0();
 virtual void fn_73_33A0();
 virtual void fn_73_3390();
 virtual void getNodeIndex();
 virtual void getNodePosition();
 virtual void getNodePosition_2();
 virtual void getNodeMatrix();
 virtual void getNodeMatrix_2();
 virtual void setNodeVisibility();
 virtual void setNodeVisibility_2();
 virtual void setNodeVisibilityAll();
 virtual void isNodeVisible();
 virtual void setNodeCollision();
 virtual void setNodeCollision_2();
 virtual void getNodeScale();
 virtual void getNodeScale_2();
 virtual void setValid();
 virtual void setValidAttachedEffect();
 virtual void slot62();
 virtual void fn_73_3388();
 virtual void fn_73_3380();
 virtual void setMotionRatio();
 virtual void setMotionFrame();
 virtual void getMotionFrame();
 virtual void setMotionLoop();
 virtual void setMatAlphaMul();
 virtual void setMatAlpha();
 virtual void updateG3dProcCalcWorld();
 virtual void preExit();
 virtual void fn_73_3378();
 virtual void invalidatedByCameraClipping();
 virtual void setTransparencyFlag();
 virtual void updateCallback();
 virtual void fixedPosition();
 virtual void setTgtNode();
 virtual void getTgtNode();
 virtual void fn_73_1848();
 virtual Info* fn_73_33F4();
 char pad1[0x10c];
 Yakumono* yak;
 Info* info;
 unsigned char a, b;
 short c;
 int d,e,f;
 float x,y,z,w;
 soSet<soAreaData> set;
 ykAreaData area;
 char padArea[0x1c];
 Vec3f* pos;
 char padPos[0xc];
 unsigned char flag;
};
extern float lbl_73_rodata_110;
extern "C" void fn_73_D3D8(Obj* o) {
 if (o->pos) {
  if (o->flag == 1) {
   Quad p(lbl_73_rodata_110, o->pos->m_z, o->pos->m_y, o->pos->m_x);
   ((grGimmick*)o)->setPos(o->pos);
  } else {
   Info* i = o->fn_73_33F4();
   o->info = i;
   if (i) {
    o->a = 0; o->b = 0x16; o->d = 0; o->e = 0; o->c = 0; o->f = 0;
    o->x = i->a; o->y = i->b; o->z = i->c; o->w = i->d;
    ((grYakumono*)o)->grYakumono::setAreaGimmick((soAreaData*)&o->a, &o->set, &o->area, false);
    if (o->yak) {
     stTrigger* t = g_stTriggerMng->createTrigger((Gimmick::AreaKind)0x25, -1);
     if (t) { t->setObserveYakumono(o->yak); o->flag = 1; }
    }
   }
  }
 }
}

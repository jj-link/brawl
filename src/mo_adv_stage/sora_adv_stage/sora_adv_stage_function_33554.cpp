#include <gr/gr_gimmick.h>
#include <gf/gf_model.h>
#pragma force_active on

struct grGimmickWarpZone_base { char pad[0x3c]; };
class grGimmickWarpZone : public grGimmickWarpZone_base {
public:
 virtual void processDefault(); virtual void processBegin(); virtual void processAnim(); virtual void processUpdate();
 virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void fn_40_37EA8(); virtual void processPreCollision();
 virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera();
 virtual void processFixCamera(); virtual void processEffect(); virtual void processGameProc(); virtual void processEnd();
 virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug();
 virtual void renderDebug(); virtual void init(); virtual void fn_40_37E50(); virtual void update();
 virtual void loadGroundData(); virtual void bindData(); virtual void setupMelee(); virtual void setVisibility();
 virtual void setVisibilityByClipping(); virtual void setVisibilityAttachedEffect(); virtual void receiveCollMsg(); virtual void receiveCollMsg_Landing();
 virtual void receiveCollMsg_Heading(); virtual void receiveCollMsg_Wall(); virtual void receiveCollMsg_Attack(); virtual void unloadData();
 virtual void getModelCount(); virtual void startup(); virtual void setNode(); virtual void setStageData();
 virtual void getStageData(); virtual void initStageData(); virtual void setMdlIndex(); virtual void getMdlIndex();
 virtual void isEnableCalcCollision(); virtual void enableCalcCollision(); virtual void disableCalcCollision(); virtual void getNodeIndex();
 virtual void getNodePosition(); virtual void getNodePosition_2(); virtual void getNodeMatrix(); virtual void getNodeMatrix_2();
 virtual void setNodeVisibility(); virtual void setNodeVisibility_2(); virtual void setNodeVisibilityAll(); virtual void isNodeVisible();
 virtual void setNodeCollision(); virtual void setNodeCollision_2(); virtual void getNodeScale(); virtual void getNodeScale_2();
 virtual void setValid(); virtual void setValidAttachedEffect(); virtual void setInitializeFlag(); virtual void setInitializeInfo();
 virtual void getInitializeInfo(); virtual void setMotionRatio(); virtual void setMotionFrame(); virtual void getMotionFrame();
 virtual void setMotionLoop(); virtual void setMatAlphaMul(); virtual void setMatAlpha(); virtual void updateG3dProcCalcWorld();
 virtual void preExit(); virtual void adventureEventGetItem(); virtual void invalidatedByCameraClipping(); virtual void setTransparencyFlag();
 virtual void updateCallback(unsigned long);
};

struct Data { char pad[0x1e4]; Vec3f pos; Vec3f rot; };
struct Object {
 char pad[0x44];
 nw4r::g3d::ScnMdl** model;
 gfModelAnimation** anim;
 char pad4c[0x70];
 Data* data;
 char padc0[0x94];
 Data* current;
};
extern "C" void fn_27_272E30(Object*, void*, unsigned long, unsigned long);
extern "C" void fn_40_33554(Object* self, void* archive, unsigned long a, unsigned long b) {
 fn_27_272E30(self, archive, a, b);
 unsigned int count = (*self->anim)->m_resFile.GetResAnmTexSrtNumEntries();
 if ((unsigned int)(-count | count) >> 31) {
  ((grGimmick*)self)->changeTexSrtAnim(0, 0);
 }
 if (self->anim) {
  (*self->anim)->unbindNodeAnim(*self->model);
 }
 self->current = self->data;
 ((grGimmick*)self)->makeCalcuCallback(1, (Heaps::HeapType)15);
 ((grGimmick*)self)->setCalcuCallbackRoot(3);
 Vec3f pos = self->current->pos;
 ((grGimmick*)self)->setPos(&pos);
 Vec3f rot = self->current->rot;
 ((grGimmick*)self)->setRot(&rot);
 ((grGimmickWarpZone*)self)->updateCallback(0);
 ((grGimmickWarpZone*)self)->updateG3dProcCalcWorld();
}
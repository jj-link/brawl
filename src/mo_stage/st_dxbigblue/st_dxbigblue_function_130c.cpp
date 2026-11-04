#pragma force_active on
struct gfArchive;
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
 virtual void processDefault(); virtual void processBegin(); virtual void slot2(); virtual void processUpdate();
 virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void processFixPosition(); virtual void processPreCollision();
 virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera();
 virtual void processFixCamera(); virtual void processEffect(); virtual void processGameProc(); virtual void processEnd();
 virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug();
 virtual void renderDebug(); virtual void init(); virtual void slot22(); virtual void slot23();
 virtual void loadGroundData(); virtual void bindData(); virtual void setupMelee(); virtual void setVisibility();
 virtual void setVisibilityByClipping(); virtual void setVisibilityAttachedEffect(); virtual void receiveCollMsg(); virtual void slot31();
 virtual void receiveCollMsg_Heading(); virtual void receiveCollMsg_Wall(); virtual void receiveCollMsg_Attack(); virtual void unloadData();
 virtual void getModelCount(); virtual void startup(gfArchive*, int, int); virtual void slot38(); virtual void setStageData(void*);
 virtual void getStageData(); virtual void initStageData(); virtual void setMdlIndex(); virtual void getMdlIndex();
 virtual void isEnableCalcCollision(); virtual void enableCalcCollision(); virtual void disableCalcCollision(); virtual void getNodeIndex();
 virtual void getNodePosition(); virtual void getNodePosition_2(); virtual void getNodeMatrix(); virtual void getNodeMatrix_2();
 virtual void setNodeVisibility(); virtual void setNodeVisibility_2(); virtual void setNodeVisibilityAll(); virtual void isNodeVisible();
 virtual void setNodeCollision(); virtual void setNodeCollision_2(); virtual void getNodeScale(); virtual void getNodeScale_2();
 virtual void setValid(); virtual void setValidAttachedEffect(); virtual void setInitializeFlag(); virtual void setInitializeInfo();
 virtual void getInitializeInfo(); virtual void setMotionRatio(); virtual void setMotionFrame(); virtual void getMotionFrame();
 virtual void setMotionLoop(); virtual void setMatAlphaMul(); virtual void setMatAlpha(); virtual void updateG3dProcCalcWorld();
 virtual void preExit(); virtual void adventureEventGetItem(); virtual void invalidatedByCameraClipping(); virtual void setTransparencyFlag();
 virtual void updateCallback(); virtual void fixedPosition(); virtual void setTgtNode(); virtual void getTgtNode();
 virtual void setGimmickData(); virtual void getGimmickData(); virtual void changeNodeAnim(); virtual void createFadeVisibleProduction();
 virtual void createSoundEffectVisibleProductionForExcel(); virtual void createEffectVisibleProductionForExcel();
 virtual void setSimpleEffectVisibleProduction(); virtual void dbDispInvalidatedByCameraClippingSphere();
 virtual void setTransparency(); virtual void getTransparencyFlag(); virtual void onDamage(); virtual void onInflict();
 virtual void onInflictEach(); virtual void onGimmickEvent(); virtual void enableYakumono(); virtual void disableYakumono();
 virtual void enableHit(); virtual void disableHit(); virtual void disableAttack(); virtual void enableArea();
 virtual void disableArea(); virtual void setSleepArea(); virtual void setTeamYakumonoOwnerId(); virtual void setTeamYakumono();
 virtual void getTeamYakumono(); virtual void setOffsetAttack(); virtual void setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab(); virtual void setAttackGimmick();
 virtual void setSoCollisionAttackData(); virtual void setAttackGimmickDetails(); virtual void isEnableAttackPersonAttacked(); virtual void isEnableAttackAttribute();
 virtual void slot112(); virtual void slot113(); virtual void slot114(); virtual void slot115(); virtual void slot116(); virtual void slot117();
 virtual void slot118(void*); virtual void slot119(void*); virtual void slot120(int); virtual void slot121(void*); virtual void slot122(void*); virtual void fn_81_1490(void*);
};
struct Stage {
 char pad0[0x9c]; void* f9c; char padA0[0x100]; gfArchive* f1a0;
};
extern "C" {
extern char lbl_81_data_380[];
extern char lbl_81_data_388[];
Ground* fn_81_6858(short, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
void createCollision__5StageFP9gfArchiveiP6Ground(Stage*, gfArchive*, int, Ground*);
void fn_81_130C(Stage* stage, int kind) {
 Ground* ground;
 unsigned char id = kind + 0x1e;
 ground = fn_81_6858((short)(kind + 0x82), lbl_81_data_380, lbl_81_data_388);
 if (ground) {
  addGround__5StageFP6Ground(stage, ground);
  ground->startup(stage->f1a0, 0, 0);
  ground->setStageData(stage->f9c);
  ground->slot118((char*)stage + 0x1e0);
  ground->slot119((char*)stage + 0x1fc);
  ground->slot120(kind);
  ground->slot121((char*)stage + 0xa9a);
  ground->slot122((char*)stage + 0xa7c);
  ground->fn_81_1490((char*)stage + 0x374);
  createCollision__5StageFP9gfArchiveiP6Ground(stage, stage->f1a0, id, ground);
 }
}
}
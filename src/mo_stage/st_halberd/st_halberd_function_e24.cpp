#pragma force_active on
#define D(n) virtual void n();
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
D(processDefault) D(processBegin) D(slot2) D(processUpdate)
D(processPreMapCorrection) D(processMapCorrection) D(processFixPosition) D(processPreCollision)
D(processCollision) D(processCatch) D(processHit) D(processCamera)
D(processFixCamera) D(processEffect) D(processGameProc) D(processEnd)
D(renderPre) D(renderOpa) D(renderXlu) D(processDebug)
D(renderDebug) D(init) D(slot22) D(slot23)
D(loadGroundData) D(bindData) D(setupMelee) D(setVisibility)
D(setVisibilityByClipping) D(setVisibilityAttachedEffect) D(receiveCollMsg) D(receiveCollMsg_Landing)
D(receiveCollMsg_Heading) D(receiveCollMsg_Wall) D(receiveCollMsg_Attack) D(unloadData)
D(fn_57_3A9C)
virtual void slot37(void*, int, int);
D(setNode)
virtual void fn_57_638(void*);
D(fn_57_3A94) D(fn_57_3A90) D(fn_57_3978) D(fn_57_3A88)
D(fn_57_3A7C) D(fn_57_3A6C) D(fn_57_3A5C) D(getNodeIndex)
D(getNodePosition) D(getNodePosition_2) D(getNodeMatrix) D(getNodeMatrix_2)
D(setNodeVisibility) D(setNodeVisibility_2) D(setNodeVisibilityAll) D(isNodeVisible)
D(setNodeCollision) D(setNodeCollision_2) D(getNodeScale) D(getNodeScale_2)
D(setValid) D(setValidAttachedEffect) D(fn_57_3A58) D(fn_57_3A54)
D(fn_57_3A4C) D(setMotionRatio) D(slot66) D(slot67)
D(setMotionLoop) D(setMatAlphaMul) D(setMatAlpha) D(updateG3dProcCalcWorld)
D(preExit) D(fn_57_3A44) D(invalidatedByCameraClipping) D(setTransparencyFlag)
D(updateCallback) D(fixedPosition) D(setTgtNode) D(getTgtNode)
D(fn_57_3AC8) D(fn_57_3AC0) D(changeNodeAnim) D(createFadeVisibleProduction)
D(createSoundEffectVisibleProductionForExcel) D(createEffectVisibleProductionForExcel)
D(setSimpleEffectVisibleProduction) D(dbDispInvalidatedByCameraClippingSphere)
D(setTransparency) D(fn_57_3AB8) D(onDamage) D(slot91)
D(onInflictEach) D(onGimmickEvent) D(enableYakumono) D(disableYakumono)
D(enableHit) D(disableHit) D(disableAttack) D(enableArea)
D(disableArea) D(setSleepArea) D(setTeamYakumonoOwnerId) D(setTeamYakumono)
D(getTeamYakumono) D(setOffsetAttack)
D(setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab)
D(setAttackGimmick) D(setSoCollisionAttackData) D(setAttackGimmickDetails)
D(isEnableAttackPersonAttacked) D(isEnableAttackAttribute)
virtual void fn_57_650(void*);
virtual void fn_57_658(void*);
D(slot114) D(slot115) D(slot116) D(slot117) D(slot118) D(slot119) D(slot120)
virtual void slot121(void*);
virtual void slot122(void*);
};
#undef D
struct Stage {
    char pad0[0x9c];
    void* value;
    char padA0[0x100];
    void* archive;
    char pad1A4[0x38];
    char at1DC[0xc];
    char at1E8[0x1e8];
    char at3D0[0x18];
    char at3E8[1];
};
extern "C" Ground* fn_57_EC30(int, const char*, const char*);
extern "C" void addGround__5StageFP6Ground(Stage*, Ground*);
extern char lbl_57_data_120[];
extern char lbl_57_data_12C[];
extern "C" void fn_57_E24(Stage* self, int kind) {
    Ground* ground;
    switch (kind) {
    case 8:
        ground = fn_57_EC30(8, lbl_57_data_120, lbl_57_data_12C);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        addGround__5StageFP6Ground(self, ground);
        ground->slot37(self->archive, 0, 0);
        ground->fn_57_638(self->value);
        ground->slot121(self->at1E8);
        ground->slot122(self->at3E8);
        ground->fn_57_650(self->at1DC);
        ground->fn_57_658(self->at3D0);
    }
}
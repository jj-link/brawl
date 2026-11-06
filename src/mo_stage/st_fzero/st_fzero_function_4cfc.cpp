#pragma force_active on
extern "C" const float lbl_61_rodata_50[];
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
    virtual void fn_61_3C98();
    virtual void fn_61_3CF0();
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
    virtual void fn_61_3A50();
    virtual void startup();
    virtual void fn_61_56BC();
    virtual void fn_61_6D8();
    virtual void fn_61_3504();
    virtual void fn_61_3A4C();
    virtual void fn_61_2318();
    virtual void fn_61_3A44();
    virtual void fn_61_3A38();
    virtual void fn_61_3A28();
    virtual void fn_61_3A18();
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
    virtual void fn_61_3A14();
    virtual void fn_61_3A10();
    virtual void fn_61_3A08();
    virtual void setMotionRatio();
    virtual void fn_61_5C54();
    virtual float fn_61_5CC4(unsigned long);
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_61_3A00();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_61_3A7C();
    virtual void fn_61_3A74();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_61_3A6C();
    virtual void onDamage();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit();
    virtual void disableHit();
    virtual void disableAttack();
    virtual void enableArea();
    virtual void disableArea();
    virtual void setSleepArea();
    virtual void setTeamYakumonoOwnerId();
    virtual void setTeamYakumono();
    virtual void getTeamYakumono();
    virtual void setOffsetAttack();
    virtual void setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_61_4118();
    virtual void fn_61_4218();
    virtual void fn_61_4354();
    virtual void fn_61_4CFC();
    virtual void fn_61_58E8();
    virtual void fn_61_5974();
    char pad40[0x1b4];
    unsigned char state;
    char pad1f5[0xb];
    unsigned char step;
};

extern "C" void fn_61_4CFC(Ground* self) {
    const float* c = lbl_61_rodata_50;
    switch (self->state) {
    case 0:
        switch ((int) self->step) {
        case 0:
            if (!(self->fn_61_5CC4(0) < c[6])) {
                self->fn_61_5974();
                self->step++;
            }
            break;
        case 1:
            if (!(self->fn_61_5CC4(0) < c[7])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        case 2:
            if (!(self->fn_61_5CC4(0) < c[8])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        case 3:
            if (!(self->fn_61_5CC4(0) < c[9])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        case 4:
            if (!(self->fn_61_5CC4(0) < c[10])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        case 5:
            if (!(self->fn_61_5CC4(0) < c[11])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        }
        break;
    case 1:
        switch ((int) self->step) {
        case 0:
            if (!(self->fn_61_5CC4(0) < c[12])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        }
        break;
    case 2:
        switch ((int) self->step) {
        case 0:
            if (!(self->fn_61_5CC4(0) < c[13])) {
                self->fn_61_5974();
                self->step++;
            }
            break;
        }
        break;
    case 3:
        switch ((int) self->step) {
        case 0:
            if (!(self->fn_61_5CC4(0) < c[14])) {
                self->fn_61_5974();
                self->step++;
            }
            break;
        case 1:
            if (!(self->fn_61_5CC4(0) < c[15])) {
                self->fn_61_5974();
                self->step++;
            }
            break;
        }
        break;
    case 4:
        switch (self->step) {
        case 0:
            if (!(self->fn_61_5CC4(0) < c[16])) {
                self->fn_61_5974();
                self->step++;
            }
            break;
        case 1:
            if (!(self->fn_61_5CC4(0) < c[17])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        case 2:
            if (!(self->fn_61_5CC4(0) < c[18])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        case 3:
            if (!(self->fn_61_5CC4(0) < c[19])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        case 4:
            if (!(self->fn_61_5CC4(0) < c[20])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        case 5:
            if (!(self->fn_61_5CC4(0) < c[21])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        case 6:
            if (!(self->fn_61_5CC4(0) < c[22])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        case 7:
            if (!(self->fn_61_5CC4(0) < c[23])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        }
        break;
    case 5:
        switch (self->step) {
        case 0:
            if (!(self->fn_61_5CC4(0) < c[24])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        case 1:
            if (!(self->fn_61_5CC4(0) < c[25])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        case 2:
            if (!(self->fn_61_5CC4(0) < c[26])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        case 3:
            if (!(self->fn_61_5CC4(0) < c[27])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        case 4:
            if (!(self->fn_61_5CC4(0) < c[28])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        case 5:
            if (!(self->fn_61_5CC4(0) < c[22])) {
                self->fn_61_5974();
                self->step++;
            }
            break;
        case 6:
            if (!(self->fn_61_5CC4(0) < c[29])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        case 7:
            if (!(self->fn_61_5CC4(0) < c[30])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        case 8:
            if (!(self->fn_61_5CC4(0) < c[31])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        case 9:
            if (!(self->fn_61_5CC4(0) < c[32])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        }
        break;
    case 6:
        switch ((int) self->step) {
        case 0:
            if (!(self->fn_61_5CC4(0) < c[33])) {
                self->fn_61_5974();
                self->step++;
            }
            break;
        case 1:
            if (!(self->fn_61_5CC4(0) < c[34])) {
                self->fn_61_5974();
                self->step++;
            }
            break;
        case 2:
            if (!(self->fn_61_5CC4(0) < c[35])) {
                self->fn_61_5974();
                self->step++;
            }
            break;
        case 3:
            if (!(self->fn_61_5CC4(0) < c[36])) {
                self->fn_61_58E8();
                self->step++;
            }
            break;
        }
        break;
    }
}

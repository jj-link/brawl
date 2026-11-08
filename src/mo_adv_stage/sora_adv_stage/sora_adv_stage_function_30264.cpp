#pragma force_active on
struct CameraController {
    char pad[0x48];
    int* unk48;
    static CameraController* getInstance();
};

extern "C" int fn_80019C10(int, float*, float, float, float);

class grYakumono_base { public: char pad[0x3c]; };

class grYakumono : public grYakumono_base {
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
    virtual void fn_40_3060C();
    virtual void fn_40_2FA98();
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
    virtual void getModelCount();
    virtual void fn_40_2EFC0();
    virtual void setNode();
    virtual void setStageData();
    virtual void getStageData();
    virtual void initStageData();
    virtual void setMdlIndex();
    virtual void getMdlIndex();
    virtual void isEnableCalcCollision();
    virtual void enableCalcCollision();
    virtual void disableCalcCollision();
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
    virtual void setInitializeFlag();
    virtual void fn_40_1CB5C();
    virtual void fn_40_1CC10();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void adventureEventGetItem();
    virtual void fn_40_30264();
    virtual void setTransparencyFlag(char);
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void setGimmickData();
    virtual void getGimmickData();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void fn_40_30608();
    virtual void setTransparency(unsigned long, unsigned long);
    virtual int getTransparencyFlag();
    virtual void fn_40_2FF44();
    virtual void fn_40_3001C();
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
    virtual void setAreaGimmick();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void fn_40_301B4();
    virtual void isEnableAttackAttribute();
    virtual void fn_40_1CDDC();
    virtual void fn_40_1CDF0();
    virtual void fn_40_1CE38();
    virtual void fn_40_30414();

    void setSleepAttack(bool);
    void setSleepHit(bool);

    char pad40[0xA4];
    int unkE4;
    char padE8[4];
    float unkEC;
    float unkF0;
    float unkF4;
    float unkF8;
    char padFC[0x78];
    grYakumono* unk174;
    char pad178[0x30];
    unsigned char unk1A8;
};

extern "C" void fn_40_30264(grYakumono* self) {
    CameraController* cam = CameraController::getInstance();
    int* temp = cam->unk48;
    self->fn_40_30414();
    if (temp != 0 && *temp != 0) {
        float f3 = self->unkF8;
        float f2 = self->unkF4;
        float f1 = self->unkF0;
        float f0 = self->unkEC;
        float v[4];
        v[0] = f0;
        v[1] = f1;
        v[2] = f2;
        v[3] = f3;
        if (fn_80019C10(*temp, v, f1, f2, f3) == 0) {
            if (self->getTransparencyFlag() != 0) {
                for (int i = 0; i < self->unk1A8; i++) {
                    grYakumono* o = (&self->unk174)[i];
                    o->setTransparency(0, self->unkE4);
                }
                self->setSleepAttack(true);
                self->setSleepHit(true);
                self->setTransparencyFlag(0);
            }
        } else {
            if (self->getTransparencyFlag() == 0) {
                for (int i = 0; i < self->unk1A8; i++) {
                    grYakumono* o = (&self->unk174)[i];
                    o->setTransparency(1, self->unkE4);
                }
            }
            self->setSleepAttack(false);
            self->setSleepHit(false);
            self->setTransparencyFlag(1);
        }
    }
}

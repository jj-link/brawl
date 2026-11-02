#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct Stage_base { char pad[0x3c]; };
class Ground;
class GroundSet;

class Stage : public Stage_base {
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
    virtual void fn_67_100();
    virtual void fn_67_174();
    virtual void createObjPokeTrainer();
    virtual void fn_67_1DEC();
    virtual void fn_67_1DE8();
    virtual void fn_67_1DDC();
    virtual void fn_67_1DD4();
    virtual void fn_67_1DCC();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_67_16C();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_67_1DC4();
    virtual void fn_67_1DBC();
    virtual void getZoneLightSetIndex();
    virtual void fn_67_1DA0();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_67_1D9C();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_67_1DF4();
    virtual void getPokeTrainerStartPos();
    virtual void getItemPosCount();
    virtual void getItemPos();
    virtual void getRandItemPos();
    virtual void getKirifudaPos();
    virtual void getKirifudaAngle();
    virtual void getKirifudaScale();
    virtual void getKirifudaModelType();
    virtual void getPokeTrainerPosCount();
    virtual void getPokeTrainerPos();
    virtual void getFighterDeadEffectSizeRate();
    virtual void getEnemyDeadEffectSizeRate();
    virtual void getEnableZ();
    virtual void fn_67_1D8C();
    virtual void fn_67_1D94();
    virtual void fn_67_1D84();
    virtual void fn_67_1D7C();
    virtual void fn_67_1D74();
    virtual void fn_67_1D60();
    virtual void fn_67_1D50();
    virtual void fn_67_1D44();
    virtual void fn_67_1D38();
    virtual void fn_67_1D30();
    virtual void fn_67_1D28();
    virtual void fn_67_1D20();
    virtual void fn_67_1D1C();
    virtual void isEnd();
    virtual void fn_67_1BD0();
    virtual void enableDevil();
    virtual void disableDevil();
    virtual void isDevil();
    virtual void setDevilScrool();
    virtual void getLucarioFinalTechniquePosition();
    virtual void startAppear();
    virtual void setAppearKind();
    virtual void endAppear();
    virtual void getAppearTask();
    virtual void forceStopAppear();
    virtual void getFinalTechniqColor();
    virtual void setMotionRatio();
    virtual void saveMotionRatio();
    virtual void restoreMotionRatio();
    virtual void setMotionSubRatio();
    virtual void saveMotionSubRatio();
    virtual void restoreMotionSubRatio();
    virtual void fn_67_1D14();
    virtual void fn_67_1D0C();
    virtual void fn_67_1D04();
    virtual void isAppear();
    virtual void isStartAppearTimming();
    virtual void getMadeinAiData();
    virtual void fn_67_1E04();
    virtual void getBamperVector();
    virtual void notifyEventInfoReady();
    virtual void notifyEventInfoGo();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
    virtual void fn_67_1CFC();
    virtual void fn_67_1CF4();
    virtual void fn_67_1CF0();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_67_1DFC();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_67_11D4();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();

    Ground* getGround(int index);
};

struct Ground_base { char pad[0x3c]; };

// Slots 0..119 (offsets 0x0..0x1dc) of the Ground vtable, in game order.
class GroundBase : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void slot2();
    virtual void slot3();
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
    virtual void slot22();
    virtual void slot23();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void slot31();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_67_2168();
    virtual void slot37();
    virtual void slot38();
    virtual void fn_67_880();
    virtual void fn_67_2160();
    virtual void fn_67_888();
    virtual void fn_67_2050();
    virtual void fn_67_2158();
    virtual void fn_67_214C();
    virtual void fn_67_213C();
    virtual void fn_67_212C();
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
    virtual void slot60();
    virtual void slot61();
    virtual void fn_67_2128();
    virtual void fn_67_2124();
    virtual void fn_67_211C();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void slot72();
    virtual void fn_67_2114();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_67_E10();
    virtual void fn_67_218C();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void slot88();
    virtual void fn_67_2184();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
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
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116(Vec3f* pos);
    virtual void slot117(float x, float y, float z);

    char _40[0x2c];
    u8 unk6C;
};

// Slot 120 (0x1e0) returns a value here.
class Ground : public GroundBase {
public:
    virtual u8 slot118();
    virtual void fn_67_3778();
    virtual void fn_67_381C();
    virtual void fn_67_478C();
    virtual void fn_67_D14();
    virtual void fn_67_D1C();
    virtual void fn_67_D24();
    virtual void fn_67_38B4();
    virtual void fn_67_3960();
    virtual void fn_67_8E84();
    virtual void fn_67_917C();
    virtual void fn_67_91A0(float x, float y, float z);
    virtual void fn_67_148C(Vec3f* pos);
    virtual void fn_67_91B0(Vec3f* pos);
};

// Same slot 120 (0x1e0) with a u8 argument.
class GroundSet : public GroundBase {
public:
    virtual void slot118(u8 value);
};

extern "C" void fn_67_1230(Stage* self) {
    Vec3f pos;
    Ground* g0 = self->getGround(0xF);
    if (g0 != NULL) {
        Ground* g1 = self->getGround(0xA);
        if (g1 != NULL) {
            Ground* g2 = self->getGround(0x20);
            if (g2 != NULL) {
                Ground* g3 = self->getGround(0x21);
                if (g3 != NULL) {
                    g0->slot116(&pos);
                    g1->fn_67_91A0(pos.m_x, pos.m_y, pos.m_z);
                    g2->fn_67_91A0(pos.m_x, pos.m_y, pos.m_z);
                    g3->fn_67_91A0(pos.m_x, pos.m_y, pos.m_z);
                    if ((((u32)g1->unk6C >> 7) & 1) == 1) {
                        g1->fn_67_91B0(&pos);
                        g0->slot117(pos.m_x, pos.m_y, pos.m_z);
                    }
                    if ((((u32)g2->unk6C >> 7) & 1) == 1) {
                        g1->fn_67_91B0(&pos);
                        g2->fn_67_148C(&pos);
                        g0->slot117(pos.m_x, pos.m_y, pos.m_z);
                    }
                    if ((((u32)g3->unk6C >> 7) & 1) == 1) {
                        g1->fn_67_91B0(&pos);
                        g3->fn_67_148C(&pos);
                        g0->slot117(pos.m_x, pos.m_y, pos.m_z);
                    }
                    u8 z = g1->slot118();
                    reinterpret_cast<GroundSet*>(g0)->slot118(z);
                }
            }
        }
    }
}

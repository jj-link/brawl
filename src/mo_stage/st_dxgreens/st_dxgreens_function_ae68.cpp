#include <it/it_manager.h>
#include <ec/ec_mgr.h>
#include <st/st_trigger.h>
#include <snd/snd_system.h>
#include <mt/mt_prng.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
extern const float lbl_79_rodata_60[];
extern const char lbl_79_data_2E30[];
extern const char lbl_79_data_2E38[];

void cmReqQuake__FiP5Vec3f(int, Vec3f*);
void cmRemoveQuake__Fi(int);
}

struct GreenParameters {
    char pad00[0x30];
    float waitMin;
    float waitMax;
    char pad38[0x18];
    float loopMin;
    float loopMax;
    float itemCountMin;
    float itemCountMax;
    char pad60[8];
    float itemYMin;
    float itemYMax;
};

struct Ground_base {
    char pad[0x3c];
};

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
    virtual void fn_79_ADB4();
    virtual void fn_79_AE0C();
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
    virtual void fn_79_1B64();
    virtual void startup();
    virtual void setNode();
    virtual void fn_79_624();
    virtual GreenParameters* fn_79_1B5C();
    virtual void fn_79_1B58();
    virtual void fn_79_1A5C();
    virtual void fn_79_1B50();
    virtual void fn_79_1B44();
    virtual void fn_79_1B34();
    virtual void fn_79_1B24();
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
    virtual void fn_79_1B20();
    virtual void fn_79_1B1C();
    virtual void fn_79_1B14();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual float getMotionFrame(unsigned long);
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_79_1B0C();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_79_1B90();
    virtual void fn_79_1B88();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_79_1B80();
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
    virtual void setAreaGimmick();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_79_AE68();
    virtual void fn_79_BB38(int);
    virtual void fn_79_BC90(int, int, int, float*);
    virtual void fn_79_6F4();
    virtual void fn_79_6FC();
    virtual unsigned int fn_79_C0D8();

    char pad40[4];
    nw4r::g3d::ScnMdl** model;
    char pad48[0x108];
    unsigned char eventState;
    char pad151[3];
    float timer;
    unsigned long effect;
    unsigned char motion;
    char pad15D[3];
    float previousFrame;
    float endFrame;
    unsigned char loops;
    char pad169[3];
    stTrigger* trigger;
};

extern "C" void fn_79_AE68(Ground* self, float delta)
{
    Vec3f position;
    const float* constants = lbl_79_rodata_60;
    GreenParameters* params = self->fn_79_1B5C();
    if (params == 0)
        return;

    itManager* manager = itManager::getInstance();
    if (manager == 0)
        return;

    self->timer -= delta;
    if (self->timer < constants[0])
        self->timer = constants[0];

    switch (self->motion) {
    case 0:
        if (self->getMotionFrame(0) >= self->endFrame) {
            if (randf() > constants[1])
                self->fn_79_BC90(1, 0, 1, &self->endFrame);
            else
                self->fn_79_BC90(0, 0, 1, &self->endFrame);
        }
        break;

    case 1:
        if (self->getMotionFrame(0) >= self->endFrame) {
            if (randf() > constants[1])
                self->fn_79_BC90(0, 0, 1, &self->endFrame);
            else
                self->fn_79_BC90(1, 0, 1, &self->endFrame);
        }
        break;

    case 2:
        if (self->getMotionFrame(0) >= self->endFrame) {
            self->fn_79_BC90(4, 1, 1, &self->endFrame);
            self->fn_79_BB38(1);
            self->trigger->setAreaSleep(false);
            g_ecMgr->setDrawPrio(1);
            self->effect = g_ecMgr->setEffect((EfID)0x5e0001);
            g_ecMgr->setDrawPrio(-1);
            g_ecMgr->setParent(self->effect, *self->model, lbl_79_data_2E30, true);
            Vec3f rotation(constants[0], constants[2], constants[0]);
            g_ecMgr->setRot(self->effect, &rotation);
            int sound = randf() < constants[1] ? 0x1db3 : 0x1db4;
            g_sndSystem->playSE((SndID)sound, 0, 0, 0, -1);
            self->loops = (int)(params->loopMin +
                (params->loopMax - params->loopMin) * randf());
        }
        break;

    case 3:
        if (self->getMotionFrame(0) >= self->endFrame) {
            self->fn_79_BC90(5, 1, 1, &self->endFrame);
            self->fn_79_BB38(0);
            self->trigger->setAreaSleep(false);
            g_ecMgr->setDrawPrio(1);
            self->effect = g_ecMgr->setEffect((EfID)0x5e0001);
            g_ecMgr->setDrawPrio(-1);
            g_ecMgr->setParent(self->effect, *self->model, lbl_79_data_2E30, true);
            Vec3f rotation(constants[0], constants[3], constants[0]);
            g_ecMgr->setRot(self->effect, &rotation);
            int sound = randf() < constants[1] ? 0x1db3 : 0x1db4;
            g_sndSystem->playSE((SndID)sound, 0, 0, 0, -1);
            self->loops = (int)(params->loopMin +
                (params->loopMax - params->loopMin) * randf());
        }
        break;

    case 4:
        if (self->getMotionFrame(0) < self->previousFrame) {
            if (self->loops != 0)
                --self->loops;
            if (self->loops != 0) {
                self->previousFrame = self->getMotionFrame(0);
            } else {
                self->fn_79_BC90(6, 0, 1, &self->endFrame);
                self->trigger->setAreaSleep(true);
                cmRemoveQuake__Fi(1);
                g_ecMgr->endEffect(self->effect);
            }
        } else {
            Vec3f offset(constants[0], constants[0], constants[0]);
            cmReqQuake__FiP5Vec3f(1, &offset);
            self->previousFrame = self->getMotionFrame(0);
        }
        break;

    case 5:
        if (self->getMotionFrame(0) < self->previousFrame) {
            if (self->loops != 0)
                --self->loops;
            if (self->loops != 0) {
                self->previousFrame = self->getMotionFrame(0);
            } else {
                self->fn_79_BC90(7, 0, 1, &self->endFrame);
                self->trigger->setAreaSleep(true);
                cmRemoveQuake__Fi(1);
                g_ecMgr->endEffect(self->effect);
            }
        } else {
            Vec3f offset(constants[0], constants[0], constants[0]);
            cmReqQuake__FiP5Vec3f(1, &offset);
            self->previousFrame = self->getMotionFrame(0);
        }
        break;

    case 6:
        if (self->getMotionFrame(0) >= self->endFrame) {
            if (randf() > constants[1])
                self->fn_79_BC90(1, 0, 1, &self->endFrame);
            else
                self->fn_79_BC90(0, 0, 1, &self->endFrame);
            self->timer = params->waitMin +
                (params->waitMax - params->waitMin) * randf();
        }
        break;

    case 7:
        if (self->getMotionFrame(0) >= self->endFrame) {
            if (randf() > constants[1])
                self->fn_79_BC90(0, 0, 1, &self->endFrame);
            else
                self->fn_79_BC90(1, 0, 1, &self->endFrame);
            self->timer = params->waitMin +
                (params->waitMax - params->waitMin) * randf();
        }
        break;

    case 8:
        if (self->getMotionFrame(0) < self->previousFrame) {
            if (self->loops != 0)
                --self->loops;
            if (self->loops != 0) {
                self->previousFrame = self->getMotionFrame(0);
            } else {
                if (randf() > constants[1])
                    self->fn_79_BC90(0, 0, 1, &self->endFrame);
                else
                    self->fn_79_BC90(1, 0, 1, &self->endFrame);
                self->timer = params->waitMin +
                    (params->waitMax - params->waitMin) * randf();
            }
        } else {
            self->previousFrame = self->getMotionFrame(0);
        }
        break;

    case 9:
    case 10:
        break;

    default:
        self->fn_79_BC90(0, 0, 1, &self->endFrame);
        self->timer = params->waitMin +
            (params->waitMax - params->waitMin) * randf();
        break;
    }

    switch (self->motion) {
    case 0:
    case 1:
        if (constants[0] == self->timer) {
            switch (self->eventState) {
            case 0:
                if (self->fn_79_C0D8() == 1)
                    self->fn_79_BC90(3, 0, 1, &self->endFrame);
                else
                    self->fn_79_BC90(2, 0, 1, &self->endFrame);
                g_sndSystem->playSE((SndID)0x1db2, 0, 0, 0, -1);
                self->eventState = 1;
                break;

            case 1:
                if (self->fn_79_C0D8() == 1)
                    self->fn_79_BC90(3, 0, 1, &self->endFrame);
                else
                    self->fn_79_BC90(2, 0, 1, &self->endFrame);
                g_sndSystem->playSE((SndID)0x1db2, 0, 0, 0, -1);
                self->eventState = 2;
                break;

            case 2:
                self->fn_79_BC90(8, 1, 1, &self->endFrame);
                self->loops = 2;
                g_ecMgr->setDrawPrio(1);
                {
                    unsigned long effect = g_ecMgr->setEffect((EfID)0x5e0002);
                    g_ecMgr->setDrawPrio(-1);
                    g_ecMgr->setParent(effect, *self->model, lbl_79_data_2E38, false);
                }
                g_sndSystem->playSE((SndID)0x1db5, 0, 0, 0, -1);
                if (manager->isCompItemKindArchive((itKind)0x4a, 0, true)) {
                    int i = 0;
                    int count = (int)(params->itemCountMin +
                        (params->itemCountMax - params->itemCountMin) * randf());
                    while (i != count) {
                        position.m_x = constants[0];
                        position.m_y = params->itemYMin +
                            (params->itemYMax - params->itemYMin) * randf();
                        position.m_z = constants[0];
                        manager->createItem(&position, constants[0],
                                            (itKind)0x4a, 0, -1, 0, 0,
                                            0xffff, 0, 0xffff);
                        ++i;
                    }
                    self->eventState = 3;
                }
                break;

            case 3:
                if (self->fn_79_C0D8() == 1)
                    self->fn_79_BC90(3, 0, 1, &self->endFrame);
                else
                    self->fn_79_BC90(2, 0, 1, &self->endFrame);
                g_sndSystem->playSE((SndID)0x1db2, 0, 0, 0, -1);
                self->eventState = 4;
                break;

            case 4:
                self->fn_79_BC90(8, 1, 1, &self->endFrame);
                self->loops = 2;
                g_ecMgr->setDrawPrio(1);
                {
                    unsigned long effect = g_ecMgr->setEffect((EfID)0x5e0002);
                    g_ecMgr->setDrawPrio(-1);
                    g_ecMgr->setParent(effect, *self->model, lbl_79_data_2E38, false);
                }
                g_sndSystem->playSE((SndID)0x1db5, 0, 0, 0, -1);
                self->eventState = 0;
                break;
            }
        }
        break;
    }
}

#include <snd/snd_system.h>
#include <ec/ec_mgr.h>
#pragma force_active on

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
virtual void fn_88_751C();
virtual void fn_88_7574();
virtual void loadGroundData();
virtual void bindData();
virtual void setupMelee();
virtual void setVisibility(unsigned long);
virtual void setVisibilityByClipping();
virtual void setVisibilityAttachedEffect();
virtual void receiveCollMsg();
virtual void receiveCollMsg_Landing();
virtual void receiveCollMsg_Heading();
virtual void receiveCollMsg_Wall();
virtual void receiveCollMsg_Attack();
virtual void unloadData();
virtual void fn_88_447C();
virtual void startup();
virtual void setNode();
virtual void fn_88_B1C();
virtual int fn_88_4474();
virtual void fn_88_4470();
virtual void fn_88_4360();
virtual void fn_88_4468();
virtual void fn_88_445C();
virtual void fn_88_444C();
virtual void fn_88_443C();
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
virtual void fn_88_4438();
virtual void fn_88_4434();
virtual void fn_88_442C();
virtual void setMotionRatio();
virtual void setMotionFrame();
virtual void getMotionFrame();
virtual void setMotionLoop();
virtual void setMatAlphaMul();
virtual void setMatAlpha();
virtual void updateG3dProcCalcWorld();
virtual void preExit();
virtual void fn_88_4424();
virtual void invalidatedByCameraClipping();
virtual void setTransparencyFlag();
virtual void updateCallback();
virtual void fixedPosition();
virtual void setTgtNode();
virtual const char* getTgtNode();
virtual void fn_88_44A8();
virtual void fn_88_44A0();
virtual void changeNodeAnim();
virtual void createFadeVisibleProduction();
virtual void createSoundEffectVisibleProductionForExcel();
virtual void createEffectVisibleProductionForExcel();
virtual void setSimpleEffectVisibleProduction();
virtual void dbDispInvalidatedByCameraClippingSphere();
virtual void setTransparency();
virtual void fn_88_4498();
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
virtual void fn_88_7600();
virtual void fn_88_7A54();
virtual void fn_88_7A58();
virtual void fn_88_7B00(int, int, int, float*);
    char pad40[4];
    nw4r::g3d::ScnMdl** model;
    char pad48[0x108];
    unsigned char state;
    char pad151[7];
    unsigned char* trigger;
    char pad15c[4];
    unsigned char previous;
    unsigned char next;
    char pad162[0x12];
    float timer;
};
extern const float lbl_88_rodata_158;
extern "C" void fn_88_7600(Ground* self, float delta) {
    if (self->fn_88_4474()) {
        switch (self->state) {
        case 0:
            self->fn_88_7B00(3, 0, 1, 0);
            self->setVisibility(0);
            self->state = 1;
            break;
        case 1:
            switch (*self->trigger) {
            case 1:
                self->fn_88_7B00(0, 0, 1, &self->timer);
                self->setVisibility(1);
                g_sndSystem->playSE((SndID)0x1eda, 0, 0, 0, -1);
                *self->trigger = 2;
                self->previous = *self->trigger;
                self->next = 0;
                self->state = 3;
                break;
            case 2:
                break;
            case 3:
                self->fn_88_7B00(1, 0, 1, &self->timer);
                self->setVisibility(1);
                g_sndSystem->playSE((SndID)0x1ede, 0, 0, 0, -1);
                self->previous = *self->trigger;
                self->next = 5;
                self->state = 6;
                break;
            }
            break;
        case 3:
            switch (*self->trigger) {
            case 1:
                self->fn_88_7B00(0, 0, 1, &self->timer);
                g_sndSystem->playSE((SndID)0x1eda, 0, 0, 0, -1);
                *self->trigger = 2;
                self->previous = *self->trigger;
                self->next = 0;
                break;
            case 2:
                break;
            case 3:
                self->fn_88_7B00(1, 0, 1, &self->timer);
                self->setVisibility(1);
                g_sndSystem->playSE((SndID)0x1ede, 0, 0, 0, -1);
                self->previous = *self->trigger;
                self->next = 5;
                self->state = 6;
                break;
            }
        case 6:
        case 7:
            self->timer -= delta;
            if (self->timer < lbl_88_rodata_158)
                self->timer = lbl_88_rodata_158;
            if (lbl_88_rodata_158 == self->timer) {
                *self->trigger = self->next;
                self->state = 0;
            }
            break;
        }
        switch (*self->trigger) {
        case 4:
            self->fn_88_7B00(2, 0, 1, &self->timer);
            self->setVisibility(1);
            g_sndSystem->playSE((SndID)0x1edb, 0, 0, 0, -1);
            nw4r::g3d::ScnMdl* model;
            unsigned long effect = g_ecMgr->setEffect((EfID)0x650001);
            model = *self->model;
            ecMgr* mgr = g_ecMgr;
            const char* node = self->getTgtNode();
            mgr->setParent(effect, model, node, false);
            self->previous = *self->trigger;
            self->next = 5;
            *self->trigger = 5;
            self->state = 7;
            break;
        }
    }
}

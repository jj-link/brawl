#include <gr/ground.h>
#include <ec/ec_mgr.h>
#include <mt/mt_prng.h>
#pragma force_active on

extern "C" {
extern const float lbl_52_rodata_160[];
extern const char lbl_52_data_2350[];
void fn_8011097C(void*);
}
namespace pirates {
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
virtual void fn_52_A408();
virtual void fn_52_A498();
virtual void loadGroundData();
virtual void bindData();
virtual void setupMelee();
virtual void setVisibility();
virtual void setVisibilityByClipping();
virtual void setVisibilityAttachedEffect();
virtual void receiveCollMsg();
virtual void fn_52_B8D8();
virtual void receiveCollMsg_Heading();
virtual void receiveCollMsg_Wall();
virtual void receiveCollMsg_Attack();
virtual void unloadData();
virtual void fn_52_36EC();
virtual void startup();
virtual void setNode();
virtual void fn_52_83C();
virtual float* fn_52_36E4();
virtual void fn_52_36E0();
virtual void fn_52_35C8();
virtual void fn_52_36D8();
virtual void fn_52_36CC();
virtual void fn_52_36BC();
virtual void fn_52_36AC();
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
virtual void fn_52_36A8();
virtual void fn_52_36A4();
virtual void fn_52_369C();
virtual void setMotionRatio();
virtual void setMotionFrame(float, unsigned long);
virtual float getMotionFrame(unsigned long);
virtual void setMotionLoop();
virtual void setMatAlphaMul();
virtual void setMatAlpha();
virtual void updateG3dProcCalcWorld();
virtual void preExit();
virtual void fn_52_3694();
virtual void invalidatedByCameraClipping();
virtual void setTransparencyFlag();
virtual void updateCallback();
virtual void fixedPosition();
virtual void setTgtNode();
virtual void getTgtNode();
virtual void fn_52_3718();
virtual void fn_52_3710();
virtual void changeNodeAnim();
virtual void createFadeVisibleProduction();
virtual void createSoundEffectVisibleProductionForExcel();
virtual void createEffectVisibleProductionForExcel();
virtual void setSimpleEffectVisibleProduction();
virtual void dbDispInvalidatedByCameraClippingSphere();
virtual void setTransparency();
virtual void fn_52_3708();
virtual void onDamage();
virtual void onInflict();
virtual void onInflictEach();
virtual void onGimmickEvent();
virtual void enableYakumono();
virtual void disableYakumono();
virtual void enableHit();
virtual void disableHit();
virtual void disableAttack(unsigned long);
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
virtual void fn_52_864();
virtual void fn_52_A24();
virtual void fn_52_A584();
virtual void fn_52_A5DC();
virtual void fn_52_A6B8();
virtual void fn_52_A70C();
virtual void fn_52_AA98();
virtual void fn_52_ADD4();
virtual void fn_52_AEA8();
virtual void fn_52_B3E0();
virtual void fn_52_B77C();
virtual void fn_52_AF98(int, int, bool, float*);
char pad40[4];
nw4r::g3d::ScnMdl** model;
char pad48[4];
void* collision;
char pad50[0x100];
unsigned char state;
char pad151[3];
float timer;
char pad158[0xc];
unsigned char* trigger;
unsigned char initial;
char pad169[3];
float endFrame;
char pad170[5];
unsigned char attack;
char pad176[0x12];
int step;
};
}

extern "C" void fn_52_A70C(pirates::Ground* self, float delta) {
    const float* c = lbl_52_rodata_160;
    float* p = self->fn_52_36E4();
    if (!p) return;
    self->timer -= delta;
    if (self->timer < c[0]) self->timer = c[0];
    switch (self->state) {
    case 0:
        self->fn_52_AF98(1, 0, true, &self->endFrame);
        self->setMotionFrame(self->endFrame, 0);
        ((::Ground*)self)->setEnableCollisionStatus(false);
        if (self->collision) fn_8011097C(self->collision);
        if (self->initial == 1) {
            self->timer = p[1];
            self->initial = 0;
        } else {
            self->timer = p[2] + (p[3] - p[2]) * randf();
        }
        self->state = 1;
        break;
    case 1:
        if (c[0] == self->timer) {
            switch (*self->trigger) {
            case 5: case 6: case 8: case 9:
                self->state = 0;
                return;
            }
            if (randf() < p[4]) {
                self->fn_52_AF98(0, 0, true, &self->endFrame);
                ((::Ground*)self)->setEnableCollisionStatus(true);
                self->timer = p[5] + (p[6] - p[5]) * randf();
                self->step = 0;
                self->state = 5;
            } else self->state = 0;
        }
        break;
    case 5:
        if (self->getMotionFrame(0) > c[1]) {
            unsigned long effect = g_ecMgr->setEffect((EfID)0x3a0006);
            g_ecMgr->setParent(effect, *self->model, lbl_52_data_2350, false);
            self->state = 4;
        }
        break;
    case 4:
        if (c[0] == self->timer) {
            self->fn_52_AF98(1, 0, true, &self->endFrame);
            self->step = 0;
            self->state = 10;
        }
        break;
    case 10:
        if (self->getMotionFrame(0) >= self->endFrame) {
            if (self->attack == 1) {
                self->disableAttack(0);
                self->attack = 0;
            }
            self->state = 0;
        } else if (self->getMotionFrame(0) <= c[2]) {
            self->fn_52_B77C();
        } else if (self->attack == 1) {
            self->disableAttack(0);
            self->attack = 0;
        }
        break;
    }
}

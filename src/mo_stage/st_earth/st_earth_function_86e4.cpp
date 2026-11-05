#include <gf/gf_task.h>
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#pragma force_active on

extern "C" void fn_27_26399C(void*);
extern "C" void fn_27_28ECF4(void*);
extern "C" const float lbl_66_rodata_178;

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
    virtual void fn_66_6B40();
    virtual void fn_66_6C30();
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
    virtual void fn_66_2D00();
    virtual void startup();
    virtual void setNode();
    virtual void fn_66_6BC();
    virtual void fn_66_2CF8();
    virtual void fn_66_2CF4();
    virtual void fn_66_2BF4();
    virtual void fn_66_2CEC();
    virtual void fn_66_2CE0();
    virtual void fn_66_2CD0();
    virtual void fn_66_BBC();
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
    virtual void fn_66_2CCC();
    virtual void fn_66_2CC8();
    virtual void fn_66_2CC0();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_66_2CB8();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_66_2D2C();
    virtual void fn_66_2D24();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_66_2D1C();
    virtual void fn_66_86E4();
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
    virtual void fn_66_6CBC();
    virtual void fn_66_6D14();
    virtual void fn_66_7534();
    virtual void fn_66_76BC();
    virtual void fn_66_7F10();
    virtual void fn_66_8034(int, int, void*);
    virtual void fn_66_8468();
    virtual void fn_66_8484();
    virtual void fn_66_849C(unsigned char);
    char pad40[0x14c - 0x40];
    void* object;
    char pad150[0x198 - 0x150];
    float timer;
    char pad19c[4];
    char data[0x1c];
    snd3DGenerator sound;
    int soundHandle;
};
struct HitData { char pad[4]; float value; };
struct HitSource { char pad[4]; int id; int kind; };
struct Item { char pad[0x8c0]; int kind; int value; };

extern "C" void fn_66_86E4(Ground* self, void*, const HitData* hit, HitSource* source) {
    float value = hit->value;
    fn_27_26399C(self->object);
    self->timer -= value;
    if (self->timer < lbl_66_rodata_178)
        self->timer = lbl_66_rodata_178;
    if (lbl_66_rodata_178 == self->timer) {
        self->soundHandle = self->sound.playSE((SndID)0x1ccf, 0, 0, -1);
    } else {
        if (source->kind == 4) {
            Item* item = (Item*)gfTask::getTask(source->id);
            if (item == 0)
                return;
            if (item->kind == 0x4d) {
                self->fn_66_849C((unsigned char)item->value);
                fn_27_28ECF4(item);
                return;
            }
        }
        self->fn_66_8034(3, 0, self->data);
        self->soundHandle = self->sound.playSE((SndID)0x1ccf, 0, 0, -1);
    }
}

#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
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
    virtual void fn_51_12158();
    virtual void fn_51_12248();
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
    virtual void fn_51_33B4();
    virtual void startup();
    virtual void setNode();
    virtual void fn_51_994();
    virtual void fn_51_33AC();
    virtual void fn_51_33A8();
    virtual void fn_51_2830();
    virtual void fn_51_33A0();
    virtual void fn_51_3394();
    virtual void fn_51_3384();
    virtual void fn_51_3374();
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
    virtual void fn_51_3370();
    virtual void fn_51_336C();
    virtual void fn_51_3364();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_51_335C();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_51_1918();
    virtual void fn_51_33D8();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_51_33D0();
    virtual void fn_51_12FA8();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit();
    virtual void disableHit(unsigned long, unsigned long);

    char pad40[0x10c];
    void* object;                 // 0x14c
    signed char state;            // 0x150
    char pad151[0xb];
    unsigned char* trigger;       // 0x15c
    char pad160[4];
    float timer;                  // 0x164
    char pad168[4];
    float f16c;                   // 0x16c
    char pad170[0x20];
    snd3DGenerator generator;     // 0x190
};

extern "C" {
void fn_27_26399C(void*);
void setEnableCollisionStatus__6GroundFb(Ground*, bool);
extern const float lbl_51_rodata_1E0;
extern const float lbl_51_rodata_224;
}

float randf();

extern "C" void fn_51_12FA8(Ground* self, int unused, Vec3f* p) {
    if (self->trigger != 0) {
        float dt = p->m_y;
        fn_27_26399C(self->object);
        switch (self->state) {
        case 1:
            self->timer = self->timer - dt;
            if (self->timer < lbl_51_rodata_1E0) {
                self->timer = lbl_51_rodata_1E0;
            }
            if (lbl_51_rodata_1E0 == self->timer) {
                self->setVisibility(0);
                setEnableCollisionStatus__6GroundFb(self, false);
                self->disableHit(0, 0);
                *self->trigger = 2;
                self->generator.playSE((SndID)0x1b94, 0, 0, -1);
                self->state = 9;
            } else {
                self->generator.playSE((SndID)0x1b93, 0, 0, -1);
            }
            break;
        }
        self->f16c = lbl_51_rodata_224 + lbl_51_rodata_224 * randf();
    }
}

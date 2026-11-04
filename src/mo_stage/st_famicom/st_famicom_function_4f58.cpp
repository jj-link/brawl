#pragma force_active on
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
extern "C" const float lbl_68_rodata_88;
extern "C" void cmReqQuake__FiP5Vec3f(int, Vec3f*);
struct Params { char pad[12]; float value; };
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
    virtual void fn_68_41F0();
    virtual void fn_68_434C();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(unsigned long);
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void fn_68_5094();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_68_249C();
    virtual void startup();
    virtual void fn_68_42E0();
    virtual void fn_68_97C();
    virtual Params* fn_68_2494();
    virtual void fn_68_2490();
    virtual void fn_68_2390();
    virtual void fn_68_2488();
    virtual void fn_68_247C();
    virtual void fn_68_246C();
    virtual void fn_68_B50();
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
    virtual void fn_68_2468();
    virtual void fn_68_2464();
    virtual void fn_68_245C();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_68_2454();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_68_24C8();
    virtual void fn_68_24C0();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_68_24B8();
    virtual void fn_68_5084();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit();
    virtual void disableHit(unsigned long, unsigned long);
    void setEnableCollisionStatus(bool);
    char pad40[0x110];
    unsigned char state;
    char pad151[3];
    float value;
    char pad158[8];
    unsigned char* data;
    unsigned char count;
    char pad165[0x3f];
    snd3DGenerator generator;
};
extern "C" void fn_68_4F58(Ground* self) {
    switch ((int)self->state) {
    case 2:
    if (*self->data != 8) {
        Params* params = self->fn_68_2494();
        if (params != 0) {
            *self->data = 8;
            Vec3f quake;
            quake.m_x = lbl_68_rodata_88;
            quake.m_y = lbl_68_rodata_88;
            quake.m_z = lbl_68_rodata_88;
            cmReqQuake__FiP5Vec3f(4, &quake);
            self->generator.playSE((SndID)0x1ce2, 0, 0, -1);
            self->count++;
            if (self->count >= 3) self->count = 3;
            if (self->count == 3) {
                self->value = params->value;
                self->setVisibility(0);
                self->setEnableCollisionStatus(false);
                self->disableHit(0, 0);
                self->state = 3;
            }
        }
    }
    break;
    }
}
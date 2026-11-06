// st_famicom gimmick sound/state machine
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#include <ai/ai_mgr.h>

#pragma force_active on

extern "C" const float lbl_68_rodata_1D8;
extern "C" const float lbl_68_rodata_1DC;
extern "C" void fn_27_1F299C(aiMgr*, int);

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
    virtual void fn_68_11A00();
    virtual void fn_68_11A90();
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
    virtual void fn_68_249C();
    virtual void startup();
    virtual void fn_68_120B4();
    virtual void fn_68_97C();
    virtual void fn_68_2494();
    virtual void fn_68_2490();
    virtual void fn_68_2390();
    virtual void fn_68_2488();
    virtual void fn_68_247C();
    virtual void fn_68_246C();
    virtual void fn_68_B50();
    virtual void getNodeIndex();
    virtual void getNodePosition(Vec3f*, unsigned long, unsigned long);
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
    virtual float getMotionFrame(unsigned long);
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
    virtual void onDamage();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit(unsigned long, unsigned long);
    virtual void disableHit(unsigned long, unsigned long);
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
    virtual void fn_68_11B1C();
    virtual void fn_68_11BAC();
    virtual void fn_68_11F54();
    virtual void fn_68_12108();
    virtual void fn_68_124A4();
    virtual void fn_68_125F4(int, int, int, float*);

    char pad40[0x64 - 0x40];
    float speed;
    char pad68[0x6C - 0x68];
    unsigned char flags;
    char pad6D[0x150 - 0x6D];
    unsigned char state;
    char pad151[0x15C - 0x151];
    unsigned char* event;
    unsigned char* trigger;
    float f164;
    float f168;
    unsigned int node;
    char pad170[0x174 - 0x170];
    float f174;
    char pad178;
    unsigned char unk179;
    char pad17A[0x180 - 0x17A];
    snd3DGenerator gen;
    int soundHandle;
    int aiHandle;
};

extern "C" void fn_68_11BAC(Ground* self) {
    switch (self->state) {
    case 0:
        self->fn_68_125F4(1, 0, 1, 0);
        self->setVisibility(0);
        self->disableHit(0, 0);
        self->disableAttack(0);
        self->unk179 = 0;
        self->state = 1;
        // fallthrough
    case 1:
        if (*self->event != 0xD) {
            if (*self->trigger == 1) {
                self->fn_68_125F4(0, 0, 1, &self->f174);
                if (self->speed < lbl_68_rodata_1D8) {
                    self->speed = self->speed * lbl_68_rodata_1DC;
                }
            } else {
                self->fn_68_125F4(0, 1, 1, &self->f174);
                if (self->speed > lbl_68_rodata_1D8) {
                    self->speed = self->speed * lbl_68_rodata_1DC;
                }
            }
            self->soundHandle = self->gen.playSE((SndID)0x1CE3, 0, 0, -1);
            self->state = 6;
        }
        break;
    case 6: {
        if (!((self->flags >> 7) & 1)) {
            Vec3f vec;
            self->setVisibility(1);
            self->enableHit(0, 0);
            self->getNodePosition(&vec, 0, self->node);
            self->f164 = vec.m_x;
            self->f168 = vec.m_x;
        }
        unsigned int reached = 0;
        if (*self->trigger == 1) {
            if (self->getMotionFrame(0) >= self->f174) {
                reached = 1;
            }
        } else {
            if (self->getMotionFrame(0) > self->f174) {
                reached = 1;
            } else {
                self->f174 = self->getMotionFrame(0);
            }
        }
        if (reached == 1) {
            if (self->soundHandle != -1) {
                self->gen.stopSE(self->soundHandle, 0);
            }
            self->setVisibility(0);
            self->disableHit(0, 0);
            if (self->aiHandle != -1) {
                fn_27_1F299C(g_aiMgr, self->aiHandle);
                self->aiHandle = -1;
            }
            *self->event = 0xD;
            self->state = 0;
        } else {
            Vec3f vec;
            self->getNodePosition(&vec, 0, self->node);
            float x = vec.m_x;
            self->f164 = x;
            if (x != self->f168) {
                self->fn_68_124A4();
            } else {
                self->disableAttack(0);
                self->unk179 = 0;
            }
            self->f168 = self->f164;
        }
        break;
    }
    }
}

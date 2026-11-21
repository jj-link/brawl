#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" const float lbl_81_rodata_E0;
extern "C" float randf__Fv();
extern "C" void* getInstance__16CameraControllerFv();

#define FIELD(T, p, off) (*reinterpret_cast<T*>(reinterpret_cast<char*>(p) + (off)))

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
    virtual void fn_81_69C8();
    virtual void fn_81_6A20();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_81_787C();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void getModelCount();
    virtual void startup();
    virtual void setNode();
    virtual void setStageData();
    virtual void* getStageData();
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
    virtual void setInitializeInfo();
    virtual void getInitializeInfo();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void adventureEventGetItem();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
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
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void getTransparencyFlag();
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
    virtual void fn_81_6A94();
    virtual void fn_81_6E1C();
    virtual void fn_81_7070();
    virtual void fn_81_744C();
    virtual void fn_81_7688();
    virtual unsigned int fn_81_7824(unsigned int index);
};

extern "C" void fn_81_6E1C(Ground* self, f32 dt) {
    Ground* obj = self;
    char* data = static_cast<char*>(obj->getStageData());
    if (data == 0) {
        return;
    }
    char* entry;
    unsigned int flag = 0;
    entry = FIELD(char*, obj, 0x178) + FIELD(u8*, obj, 0x174)[FIELD(u8, obj, 0x16c)] * 0x3c;

    void* cam = getInstance__16CameraControllerFv();
    Vec3f box[2] = {
        Vec3f(FIELD(f32, cam, 0x148), FIELD(f32, cam, 0x150), lbl_81_rodata_E0),
        Vec3f(FIELD(f32, cam, 0x14C), FIELD(f32, cam, 0x154), lbl_81_rodata_E0)
    };

    if (lbl_81_rodata_E0 == FIELD(f32, obj, 0x154)) {
        flag = 1;
    } else if (FIELD(u8, entry, 0x38) == 1) {
        f32 v = FIELD(f32, obj, 0x160) + FIELD(f32, data, 0x28) * dt;
        FIELD(f32, obj, 0x160) = v;
        if (v > FIELD(f32, data, 0x24)) {
            FIELD(f32, obj, 0x160) = FIELD(f32, data, 0x24);
        }
        FIELD(f32, entry, 4) = FIELD(f32, entry, 4) + FIELD(f32, obj, 0x160) * dt;
        unsigned int r27 = FIELD(u8, obj, 0x16c) + 1;
        if (r27 == 0x1e) {
            r27 = 0;
        }
        if (obj->fn_81_7824(r27) == 1) {
            f32 e4 = FIELD(f32, entry, 4);
            if (!(e4 < box[0].m_x)) {
                char* e2 = FIELD(char*, obj, 0x178) + FIELD(u8*, obj, 0x174)[r27] * 0x3c;
                f32 diff = FIELD(f32, e2, 4) - e4;
                if (diff < FIELD(f32, data, 0x20)) {
                    flag = 1;
                }
            }
        }
    } else {
        f32 v = FIELD(f32, obj, 0x160) - FIELD(f32, data, 0x28) * dt;
        FIELD(f32, obj, 0x160) = v;
        f32 lim = -FIELD(f32, data, 0x24);
        if (v < lim) {
            FIELD(f32, obj, 0x160) = lim;
        }
        unsigned int r27 = 0x1d;
        FIELD(f32, entry, 4) = FIELD(f32, entry, 4) + FIELD(f32, obj, 0x160) * dt;
        unsigned int c = FIELD(u8, obj, 0x16c);
        if (c != 0) {
            r27 = c - 1;
        }
        if (obj->fn_81_7824(r27) == 1) {
            f32 e4 = FIELD(f32, entry, 4);
            if (!(e4 > box[1].m_x)) {
                char* e2 = FIELD(char*, obj, 0x178) + FIELD(u8*, obj, 0x174)[r27] * 0x3c;
                f32 diff = e4 - FIELD(f32, e2, 4);
                if (diff < FIELD(f32, data, 0x20)) {
                    flag = 1;
                }
            }
        }
    }

    if (flag == 1) {
        f32 r = randf__Fv();
        f32 b = FIELD(f32, data, 0x60);
        f32 a = FIELD(f32, data, 0x5C);
        f32 d = b - a;
        FIELD(f32, obj, 0x154) = a + d * r;
        FIELD(u8, entry, 0) = 5;
    }
}

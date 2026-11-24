#include <types.h>
#include <gr/gr_gimmick.h>
#include <gf/gf_model.h>
#pragma force_active on

extern const double lbl_27_rodata_43B8;

extern "C" {
    void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
    void fn_801AF9F4(void*);
    void fn_27_26EA0C(void*);
    extern float lbl_27_data_547E0;
    extern const float lbl_27_rodata_43A8[];
}

struct grGimmickMotionPath_base {
    char pad[0x3c];
};

class grGimmickMotionPath : public grGimmickMotionPath_base {
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
    virtual ~grGimmickMotionPath();
    virtual void update();
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
    virtual void startup();
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
    virtual void fn_27_26E95C();
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
    virtual unsigned int isMoveEnd();

    char pad40[4];
    void** models;
    gfModelAnimation** animations;
    char pad4c[0x18];
    float motionScale;
    char pad68[4];
    u8 flags;
    char pad6d[0x3b];
    void* sounds;
    char padac[4];
    void* effects;
    char padb4[0x98];
    u8 state;
    char pad14d[3];
    float frame;
    float wait;
    float rate;
    float savedRate;
    u32 frameCount;
    grGimmickMotionPathData* pathData;
    char pad168[4];
    float waitDuration;
    float returnRate;
};

void grGimmickMotionPath::processAnim() {
    float delta = lbl_27_data_547E0;

    if (state == 0)
        return;

    void* model = *models;
    gfModelAnimation* anim = *animations;
    if (model == 0 || anim == 0)
        return;

    switch (state) {
    case 1:
        frame += rate;
        switch (*(u8*)((char*)pathData + 5)) {
        case grGimmickMotionPathData::Path_Loop:
            if (frame >= (float)frameCount) {
                if (sounds != 0) {
                    for (int i = 0; i < 3; ++i)
                        ((grGimmick*)this)->startGimmickSE(i + 8);
                }
                if (effects != 0) {
                    for (int i = 0; i < 3; ++i)
                        ((grGimmick*)this)->startGimmickEffect(i + 8);
                }
                frame -= (float)frameCount;
                if (sounds != 0) {
                    for (int i = 0; i < 5; ++i)
                        ((grGimmick*)this)->startGimmickSE(i + 3);
                }
                if (effects != 0) {
                    for (int i = 0; i < 5; ++i)
                        ((grGimmick*)this)->startGimmickEffect(i + 3);
                }
            } else if (frame <= lbl_27_rodata_43A8[0]) {
                frame += (float)frameCount;
            }
            break;

        case grGimmickMotionPathData::Path_Return:
            if (frame >= (float)frameCount || isMoveEnd() == 1) {
                if (frame > (float)frameCount)
                    frame = (float)frameCount;
                state = 2;
                rate = lbl_27_rodata_43A8[0];
                wait = waitDuration;
                if (sounds != 0) {
                    for (int i = 0; i < 3; ++i)
                        ((grGimmick*)this)->startGimmickSE(i + 8);
                }
                if (effects != 0) {
                    for (int i = 0; i < 3; ++i)
                        ((grGimmick*)this)->startGimmickEffect(i + 8);
                }
            }
            break;

        case grGimmickMotionPathData::Path_Once:
            if (frame >= (float)frameCount || isMoveEnd() == 1) {
                state = 0;
                rate = lbl_27_rodata_43A8[0];
                if (frame > (float)frameCount)
                    frame = (float)frameCount;
                if (sounds != 0) {
                    for (int i = 0; i < 3; ++i)
                        ((grGimmick*)this)->startGimmickSE(i + 8);
                }
                if (effects != 0) {
                    for (int i = 0; i < 3; ++i)
                        ((grGimmick*)this)->startGimmickEffect(i + 8);
                }
            } else if (frame <= lbl_27_rodata_43A8[0]) {
                rate = lbl_27_rodata_43A8[0];
                state = 0;
                frame = lbl_27_rodata_43A8[0];
            }
            break;
        }

        setFrame__16gfModelAnimationFd(anim, frame);
        anim->setUpdateRate(lbl_27_rodata_43A8[0]);
        fn_801AF9F4(model);
        break;

    case 2:
        wait -= delta * motionScale;
        if (wait <= lbl_27_rodata_43A8[0]) {
            float speed = returnRate;
            const float scale = lbl_27_data_547E0;
            state = 3;
            savedRate = rate = (speed * scale) * motionScale;
        }
        break;

    case 3:
        frame -= rate;
        if (frame <= lbl_27_rodata_43A8[0]) {
            rate = lbl_27_rodata_43A8[0];
            frame = lbl_27_rodata_43A8[0];
            state = 0;
        }
        setFrame__16gfModelAnimationFd(anim, frame);
        anim->setUpdateRate(lbl_27_rodata_43A8[0]);
        fn_801AF9F4(model);
        break;
    }

    flags &= ~2u;
    updateG3dProcCalcWorld();
    fn_27_26EA0C(this);
}

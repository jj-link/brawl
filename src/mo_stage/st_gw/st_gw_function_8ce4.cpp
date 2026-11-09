#include <types.h>

#pragma force_active on

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
    virtual void fn_63_65C8();
    virtual void fn_63_66AC();
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
    virtual void fn_63_3378();
    virtual void startup();
    virtual void setNode();
    virtual void fn_63_59C();
    virtual void fn_63_3370();
    virtual void fn_63_336C();
    virtual void fn_63_2B64();
    virtual void fn_63_3364();
    virtual void fn_63_3358();
    virtual void fn_63_3348();
    virtual void fn_63_3338();
    virtual void getNodeIndex();
    virtual void getNodePosition(void*, u32, u32);
    virtual void getNodePosition_2();
    virtual void getNodeMatrix();
    virtual void getNodeMatrix_2();
    virtual void setNodeVisibility(int, u32, u32, int, int);
    virtual void setNodeVisibility_2();
    virtual void setNodeVisibilityAll();
    virtual void isNodeVisible();
    virtual void setNodeCollision();
    virtual void setNodeCollision_2();
    virtual void getNodeScale();
    virtual void getNodeScale_2();
    virtual void setValid();
    virtual void setValidAttachedEffect();
    virtual void fn_63_3334();
    virtual void fn_63_3330();
    virtual void fn_63_3328();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_63_3320();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_63_1884();
    virtual void fn_63_339C();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_63_3394();
    virtual void fn_63_8CE4();
    virtual void fn_63_8C60();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit();
    virtual void disableHit(int, int);
};

struct Position {
    float x, y, z;
};

extern "C" void fn_27_26399C(void*);
extern "C" float randf__Fv();
extern "C" const float lbl_63_rodata_A8[];

extern "C" void fn_63_8CE4(void* self, s32 unused, const float* vec) {
    u8* s = static_cast<u8*>(self);
    float frameStep = vec[1];
    Ground* ground = reinterpret_cast<Ground*>(self);
    const float* k = reinterpret_cast<const float*>(
        reinterpret_cast<u32>(lbl_63_rodata_A8));

    fn_27_26399C(*reinterpret_cast<void**>(s + 0x14c));

    float timer = *reinterpret_cast<float*>(s + 0x238) - frameStep;
    *reinterpret_cast<float*>(s + 0x238) = timer;

    if (timer < k[0]) {
        *reinterpret_cast<u8*>(s + 0x23d) = 8;
        *reinterpret_cast<float*>(s + 0x234) = k[5];
        ground->disableHit(*reinterpret_cast<u8*>(s + 0x23c), 0);

        if (k[1] == vec[31]) {
            u8* data = *reinterpret_cast<u8**>(s + 0x240);
            float y = *reinterpret_cast<float*>(data + 0x04) -
                      *reinterpret_cast<float*>(data + 0x10) * randf__Fv();
            float x = *reinterpret_cast<float*>(data);
            *reinterpret_cast<float*>(s + 0x244) = x;
            *reinterpret_cast<float*>(s + 0x24c) = k[0];
            *reinterpret_cast<float*>(s + 0x248) = y;
        } else {
            u8* data = *reinterpret_cast<u8**>(s + 0x240);
            float y = *reinterpret_cast<float*>(data + 0x04) -
                      *reinterpret_cast<float*>(data + 0x10) * randf__Fv();
            float x = *reinterpret_cast<float*>(data + 0x0c);
            *reinterpret_cast<float*>(s + 0x244) = x;
            *reinterpret_cast<float*>(s + 0x24c) = k[0];
            *reinterpret_cast<float*>(s + 0x248) = y;
        }

        u8 index = *reinterpret_cast<u8*>(s + 0x23c);
        u32 first = *reinterpret_cast<u32*>(
            s + 0x1d4 + (((index << 2) - index) << 2));
        *reinterpret_cast<u32*>(s + 0x278) = first;
        ground->getNodePosition(s + 0x25c, 0, first);

        *reinterpret_cast<Position*>(s + 0x250) =
            *reinterpret_cast<Position*>(s + 0x25c);

        index = *reinterpret_cast<u8*>(s + 0x23c);
        u32 second = *reinterpret_cast<u32*>(s + 0x1d4 + (index * 3 + 1) * 4);
        ground->setNodeVisibility(0, 0, second, 1, 0);

        index = *reinterpret_cast<u8*>(s + 0x23c);
        u32 third = *reinterpret_cast<u32*>(s + 0x1d4 + (index * 3 + 2) * 4);
        ground->setNodeVisibility(0, 0, third, 1, 0);
    }
}

#include <types.h>
#include <ec/ec_mgr.h>

#pragma force_active on
#pragma fp_contract off

extern "C" float randf__Fv();
extern "C" const float lbl_78_rodata_58;

struct Ground_base {
    char pad[0x3C];
};

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_78_1980();
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
    virtual void fn_78_1924();
    virtual void fn_78_1A64();
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
    virtual void fn_78_26A4();
    virtual void startup();
    virtual void fn_78_1CF8();
    virtual void fn_78_58C();
    virtual u32 fn_78_1C40();
    virtual void fn_78_26A0();
    virtual void fn_78_1760();
    virtual void fn_78_2698();
    virtual void fn_78_268C();
    virtual void fn_78_267C();
    virtual void fn_78_266C();
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
    virtual void fn_78_2668();
    virtual void fn_78_2664();
    virtual void fn_78_265C();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_78_2654();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_78_26D0();
    virtual void fn_78_26C8();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_78_26C0();
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
    virtual void fn_78_670();
    virtual void fn_78_1C48(float);
};

typedef void (*UpdateFunc)(void*, float);

extern "C" void fn_78_1A64(Ground* self, float delta) {
    u8* s = reinterpret_cast<u8*>(self);
    float* params = reinterpret_cast<float*>(self->fn_78_1C40());

    if (params == 0)
        return;

    float timer = *reinterpret_cast<float*>(s + 0x154) - delta;
    *reinterpret_cast<float*>(s + 0x154) = timer;
    if (timer < lbl_78_rodata_58)
        *reinterpret_cast<float*>(s + 0x154) = lbl_78_rodata_58;

    switch (*reinterpret_cast<u8*>(s + 0x150)) {
    case 0:
        *reinterpret_cast<float*>(s + 0x154) =
            params[0] + (params[1] - params[0]) * randf__Fv();
        *reinterpret_cast<u8*>(s + 0x150) = 1;
        // fall through
    case 1:
        if (lbl_78_rodata_58 == *reinterpret_cast<float*>(s + 0x154)) {
            u32 handle = g_ecMgr->setEffect(static_cast<EfID>(0x5D0002));
            *reinterpret_cast<u32*>(s + 0x174) = handle;
            g_ecMgr->setParent(
                handle,
                *reinterpret_cast<nw4r::g3d::ScnMdl**>(
                    *reinterpret_cast<void**>(s + 0x44)),
                static_cast<u16>(*reinterpret_cast<u32*>(s + 0x16C)),
                false);
            *reinterpret_cast<float*>(s + 0x154) =
                params[2] + (params[3] - params[2]) * randf__Fv();
            *reinterpret_cast<u8*>(s + 0x150) = 2;
        }
        break;
    case 2:
        if (lbl_78_rodata_58 == *reinterpret_cast<float*>(s + 0x154)) {
            g_ecMgr->endEffect(*reinterpret_cast<u32*>(s + 0x174));
            *reinterpret_cast<u8*>(s + 0x150) = 0;
        }
        break;
    }

    self->fn_78_1C48(delta);

    timer = *reinterpret_cast<float*>(s + 0x178) - delta;
    *reinterpret_cast<float*>(s + 0x178) = timer;
    if (timer < lbl_78_rodata_58)
        *reinterpret_cast<float*>(s + 0x178) = lbl_78_rodata_58;

    if (*reinterpret_cast<float*>(s + 0x178) > lbl_78_rodata_58) {
        *reinterpret_cast<u8*>(*reinterpret_cast<void**>(s + 0x170)) = 0;
    } else {
        *reinterpret_cast<u8*>(*reinterpret_cast<void**>(s + 0x170)) = 2;
    }
}

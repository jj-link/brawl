#include <ft/ft_manager.h>
#include <mt/mt_prng.h>
#include <string.h>
#pragma force_active on
#pragma pool_data on
#pragma pool_fp_consts on
extern "C" int fn_27_10B224(ftManager* mgr, float* rect, int* out, int a, int b);
struct Pos { char pad[0x18]; float x; float y; };
class soAreaData; class ykAreaData;
template <class T> class soSet;
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
    virtual void fn_71_DD60();
    virtual void fn_71_DDC8();
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
    virtual void fn_71_2B8C();
    virtual void startup();
    virtual void setNode();
    virtual void fn_71_85C();
    virtual void fn_71_2B84();
    virtual void fn_71_2B80();
    virtual void fn_71_2700();
    virtual void fn_71_2B78();
    virtual void fn_71_2B6C();
    virtual void fn_71_2B5C();
    virtual void fn_71_F04();
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
    virtual void fn_71_2B58();
    virtual void fn_71_2B54();
    virtual void fn_71_2B4C();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_71_2B44();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_71_2BB8();
    virtual void fn_71_2BB0();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_71_2BA8();
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
    virtual void setAreaGimmick(soAreaData*, soSet<soAreaData>*, ykAreaData*, bool);
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_71_DE3C();
    virtual void fn_71_DFC4();
    virtual int fn_71_E4B0(int, float*, int);
    char pad1[0x110]; unsigned char mode; char pad2[7];
    const Pos* pos; unsigned char* state; char pad3[0x14]; int* player;
};
static inline int clampIndex(int idx, int last) {
    int lo = idx > 0 ? idx : 0;
    return lo < last ? lo : last;
}
// The literals below are pooled by the compiler with the same layout as lbl_71_rodata_1F8.
extern "C" void fn_71_DE3C(Ground* self) {
    switch ((int)*self->state) {
    case 6:
        switch ((int)self->mode) {
        case 9: {
            float zero = 0.0f;
            struct Work {
                float out[4]; float rect[4]; int entries[9];
            } work;
            memset(work.entries, 0, 0x24);
            float y = self->pos->y - 2.5f;
            float scale = 35.0f;
            float radius = scale * 0.5f;
            float x = self->pos->x;
            work.rect[0] = x - radius;
            work.rect[1] = x + radius;
            work.rect[2] = y + radius;
            work.rect[3] = y - radius;
            int count = fn_27_10B224(g_ftManager, work.rect, work.entries, 0, 1);
            if (count > 0) {
                float r = randf();
                int idx = (int)((float)count * r);
                double conversionBias = 4503601774854144.0;
                float c24 = 65535.0f;
                float c28 = 0.00390625f;
                float c32 = 30.0f;
                float c36 = 5.0f;
                float c40 = 90.0f;
                float c44 = 300.0f;
                float c48 = 200.0f;
                float c52 = 1.40625f;
                float c56 = 180.0f;
                float c60 = 0.01745329238474369f;
                int sel = clampIndex(idx, count - 1);
                int playerNo = g_ftManager->getPlayerNo(work.entries[sel]);
                if (self->fn_71_E4B0(playerNo, work.out, 0)) {
                    *self->player = playerNo;
                    *self->state = 4;
                }
            }
        } break;
        }
        break;
    }
}

#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#include <orch_helpers.h>
#pragma force_active on
#pragma fp_contract off

extern "C" {
void mtBezierCurve__FfP5Vec3fP5Vec3f(float t, Vec3f* points, Vec3f* out);
float rsqrtf__Ff(float x);
extern const float lbl_49_rodata_58[];
}

struct Seg {
    char pad0[4];
    float t;
    char pad1[4];
    Vec3f pos;
    char pad2[0x34 - 0x18];
};

struct Info {
    char pad0[4];
    unsigned short* count;
};

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
    virtual void fn_49_1D38();
    virtual void fn_49_1DCC();
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
    virtual void fn_49_1900();
    virtual void startup();
    virtual void setNode();
    virtual void fn_49_4AC();
    virtual void fn_49_18F8();
    virtual void fn_49_18F4();
    virtual void fn_49_13A8();
    virtual void fn_49_18EC();
    virtual void fn_49_18E0();
    virtual void fn_49_18D0();
    virtual void fn_49_18C0();
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
    virtual void fn_49_18BC();
    virtual void fn_49_18B8();
    virtual void fn_49_18B0();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_49_18A8();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_49_192C();
    virtual void fn_49_1924();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_49_191C();
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
    virtual void fn_49_1E64();
    virtual void fn_49_2CD4();
    virtual void fn_49_2DF0();
    virtual void fn_49_32DC();
    virtual void fn_49_37D0();
    virtual void fn_49_3538();
    virtual void fn_49_39C0();
    virtual int fn_49_3BA0(u32 a, u32 b, Vec3f* out);
    virtual void fn_49_3F60();
    virtual void fn_49_422C();
    virtual void fn_49_830();
    virtual Info* fn_49_2CCC();

    char pad_40[0x188 - 0x40];
    unsigned char unk188;
    char pad_189[0x254 - 0x189];
    Seg* segs254;
};

extern "C" u32 fn_49_3F60(Ground* self, u32 arg1, u32 idx, float farg0) {
    const float* d = lbl_49_rodata_58;
    Vec3f pts[4];
    Vec3f cur;
    Vec3f prev;
    Vec3f d1;
    Vec3f d2;
    float zero;
    float acc;

    Info* info = self->fn_49_2CCC();
    if (info == 0) return 0;
    if (info->count == 0) return 0;
    u32 n = *info->count;
    if (self->fn_49_3BA0(arg1, idx, pts) == 0) return 0;

    acc = d[0];
    zero = acc;
    Seg* seg = &self->segs254[self->unk188];
    float t = seg->t;
    cur = seg->pos;

    for (;;) {
        prev = cur;
        cur.m_x = zero;
        cur.m_y = zero;
        cur.m_z = zero;
        mtBezierCurve__FfP5Vec3fP5Vec3f(t, pts, &cur);
        Vec3fSub_v0420ad(&d1, &cur, &prev);
        float sq = d1.m_z * d1.m_z + (d1.m_x * d1.m_x + d1.m_y * d1.m_y);
        acc += ((float)(double)nw4r::math::FAbs(sq) <= d[12]) ? d[0] : sq * rsqrtf__Ff(sq);
        if (acc >= farg0) break;

        Vec3fSub_v0420ad(&d2, &pts[3], &pts[0]);
        float sq2 = d2.m_z * d2.m_z + (d2.m_x * d2.m_x + d2.m_y * d2.m_y);
        float len2 = ((float)(double)nw4r::math::FAbs(sq2) <= d[12]) ? d[0] : sq2 * rsqrtf__Ff(sq2);
        t += d[14] / len2;
        if (t >= d[14]) {
            t -= d[14];
            idx++;
            if (idx > n - 1) idx = 0;
            if (self->fn_49_3BA0(arg1, idx, pts) == 0) break;
        }
    }
    return idx;
}

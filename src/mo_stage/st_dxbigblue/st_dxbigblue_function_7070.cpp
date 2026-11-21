#pragma fp_contract off
#include <types.h>
#include <cm/cm_camera_controller.h>
#include <mt/mt_prng.h>
#pragma force_active on

extern "C" float randf__Fv();
extern "C" const float lbl_81_rodata_E0[];

struct Params {
    char pad[0x24];
    float maxSpeed;
    float accel;
    char pad2[0x30];
    float low;
    float high;
};

struct Entry {
    u8 state;
    char pad[3];
    float x;
    char pad2[0x30];
    u8 direction;
    char pad3[3];
};

struct Bounds {
    float left;
    float pad;
    float pad2;
    float right;
};

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
    virtual Params* getStageData();
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
    virtual void setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab();
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
    virtual u32 fn_81_7824(u32);

    char pad2[0x114];
    float timer;
    Bounds* bounds;
    char pad15c[4];
    float speed;
    char pad3[0x8];
    u8 index;
    char pad4[3];
    u8* start;
    u8* mapping;
    Entry* entries;
};

static inline u32 wrap30(u32 v)
{
    if (v >= 30)
        v -= 30;
    return v;
}

extern "C" void fn_81_7070(Ground* self, float dt)
{
    const float* k = lbl_81_rodata_E0;
    Params* p = self->getStageData();
    if (!p)
        return;

    Entry* e = &self->entries[self->mapping[self->index]];
    if (k[0] == self->timer) {
        if (e->x > k[0]) {
            u32 next = self->index + 1;
            if (next == 30)
                next = 0;
            if (self->fn_81_7824(next) == 1) {
                float r = randf__Fv();
                float high = p->high;
                float low = p->low;
                float delta = high - low;
                self->timer = low + delta * r;
            } else {
                e->direction = 1;
                e->state = 6;
            }
        } else if (e->x < k[0]) {
            u32 prev = self->index == 0 ? 29 : self->index - 1;
            if (self->fn_81_7824(prev) == 1) {
                float r = randf__Fv();
                float high = p->high;
                float low = p->low;
                float delta = high - low;
                self->timer = low + delta * r;
            } else {
                e->direction = 0;
                e->state = 6;
            }
        } else {
            float r = randf__Fv();
            float high = p->high;
            float low = p->low;
            float delta = high - low;
            self->timer = low + delta * r;
        }
        return;
    }

    if (e->x > self->bounds->right) {
        e->state = 6;
        e->direction = 1;
        return;
    }
    if (e->x < self->bounds->left) {
        e->state = 6;
        e->direction = 0;
        return;
    }

    CameraController* cam = CameraController::getInstance();
    Rect2D* rect = (Rect2D*)cam->_328;
    u32 s = *self->start;
    float l, u, rt, dn;
    u = rect->m_up;
    l = rect->m_left;
    dn = rect->m_down;
    rt = rect->m_right;
    Vec3f bounds[2] = {
        Vec3f(l, u, k[0]),
        Vec3f(rt, dn, k[0])
    };

    u32 a = wrap30(s);
    u32 b = wrap30(s + 1);
    u32 c = wrap30(s + 2);
    u32 d = wrap30(s + 3);
    u32 dir = 0;
    float step = (bounds[1].m_x - bounds[0].m_x) / k[1];

    if (self->index == a) {
        if (e->x < bounds[0].m_x + k[2] * step)
            dir = 1;
        else if (e->x > bounds[0].m_x + k[2] * step)
            dir = 0;
    } else if (self->index == b) {
        if (e->x < bounds[0].m_x + k[3] * step)
            dir = 1;
        else if (e->x > bounds[0].m_x + k[3] * step)
            dir = 0;
    } else if (self->index == c) {
        if (e->x < bounds[0].m_x + k[4] * step)
            dir = 1;
        else if (e->x > bounds[0].m_x + k[4] * step)
            dir = 0;
    } else if (self->index == d) {
        if (e->x < bounds[0].m_x + k[5] * step)
            dir = 1;
        else if (e->x > bounds[0].m_x + k[5] * step)
            dir = 0;
    }

    float scale = k[6];
    if (dir == 0) {
        self->speed -= dt * (p->accel * scale);
        float limit = -p->maxSpeed * scale;
        if (self->speed < limit)
            self->speed = limit;
        e->x += self->speed * dt;
        e->direction = dir;
    } else if (dir == 1) {
        self->speed += dt * (p->accel * scale);
        float limit = p->maxSpeed * scale;
        if (self->speed > limit)
            self->speed = limit;
        e->x += self->speed * dt;
        e->direction = dir;
    }
}

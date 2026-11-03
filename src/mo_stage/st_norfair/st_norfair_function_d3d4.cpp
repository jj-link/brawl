#pragma force_active on
#pragma fp_contract off
#include <nw4r/math/math_arithmetic.h>

struct Vec { float x, y, z; };
struct Constants { float x[18]; };
extern "C" const Constants lbl_54_rodata_138;

struct Params {
    char pad[0x14];
    float accel;
    float maxSpeed;
    float offset;
    float range;
    float low;
    float high;
};

struct CamMgr { char pad[0x60]; float x, y, z; };

extern "C" {
float randf__Fv();
void fn_8009F1FC(void*);
void fn_8009EF8C(void*, const void*);
CamMgr* getManager__15gfCameraManagerFv();
int playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);
void stopSE__14snd3DGeneratorFll(void*, int, int);
}

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
    virtual void fn_54_D0F4();
    virtual void fn_54_D190();
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
    virtual void fn_54_338C();
    virtual void startup();
    virtual void setNode();
    virtual void fn_54_1310();
    virtual Params* fn_54_3150();
    virtual void fn_54_3388();
    virtual void fn_54_2C40();
    virtual void fn_54_3380();
    virtual void fn_54_3374();
    virtual void fn_54_3364();
    virtual void fn_54_3354();
    virtual void getNodeIndex();
    virtual void getNodePosition(Vec* pos, unsigned long a, unsigned long b);
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
    virtual void fn_54_3350();
    virtual void fn_54_334C();
    virtual void fn_54_3344();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_54_333C();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_54_33B8();
    virtual void fn_54_33B0();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_54_33A8();
    virtual void onDamage();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit();
    virtual void disableHit();
    virtual void disableAttack(unsigned long index);
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
    virtual void fn_54_1510();
    virtual void fn_54_D234();
    virtual void fn_54_D28C();
    virtual void fn_54_D3D4();
    virtual void fn_54_DAF4();
    virtual void fn_54_DB98();
    virtual void fn_54_DF34();
    virtual void fn_54_E07C();

    char p40[0xc4 - 0x40];
    unsigned long id;
    char pc8[0x150 - 0xc8];
    unsigned char state;
    char p151[3];
    float timer;
    unsigned char* cmd;
    float* bounds;
    float pos;
    char p164[8];
    float speed;
    float offset;
    float prevSpeed;
    unsigned char side;
    char p179;
    unsigned char b17a;
    char p17b[5];
    unsigned char seFlag;
    char p181[3];
    int handle;
    char gen[8];
    char obj[8];
    union {
        struct {
            unsigned a : 3;
            unsigned rest : 29;
        } f;
        unsigned raw;
    } bits;
    char p19c[4];
    Vec vec;
};

extern "C" void fn_54_D3D4(Ground* o, float dt) {
    const Constants* c = &lbl_54_rodata_138;
    Params* p = o->fn_54_3150();
    if (p) {
    o->timer -= dt;
    if (o->timer < c->x[0]) o->timer = c->x[0];
    switch (o->state) {
    case 0:
        o->state = 1;
        break;
    case 1: {
        if (*o->cmd == 1 && o->side == 0) {
            o->state = 3;
            o->fn_54_DF34();
        }
        if (*o->cmd == 2 && o->side == 1) {
            o->state = 3;
            o->fn_54_E07C();
        }
        if (o->state == 3) {
            o->offset = -p->range + c->x[4] * p->range * randf__Fv();
            o->speed = c->x[0];
            o->prevSpeed = c->x[0];
            fn_8009F1FC(o->obj);
            o->bits.raw &= 0x03FFFFFF;
            CamMgr* cam = getManager__15gfCameraManagerFv();
            if (cam) {
            Vec v;
            v.x = cam->x;
            v.y = cam->y;
            v.z = cam->z;
            fn_8009EF8C(o->obj, &v);
            o->seFlag = 0;
            }
        }
        break;
    }
    case 3: {
        Vec n;
        o->getNodePosition(&n, 0, o->id);
        float target = p->offset + o->offset;
        if (target > n.x) o->speed += p->accel * dt;
        if (target < n.x) o->speed -= p->accel * dt;
        if (nw4r::math::FAbs(o->speed) > p->maxSpeed) {
            if (target > n.x) o->speed = p->maxSpeed;
            if (target < n.x) o->speed = c->x[5] * p->maxSpeed;
        }
        o->pos += o->speed * dt;
        Vec v;
        v.x = o->vec.x;
        v.y = o->vec.y;
        v.z = o->vec.z;
        v.x -= o->speed;
        if (o->side == 0 && v.x > o->bounds[3]) v.x = o->bounds[3];
        if (o->side == 1 && v.x < o->bounds[0]) v.x = o->bounds[0];
        fn_8009EF8C(o->obj, &v);
        if (c->x[0] != o->prevSpeed) {
            bool turned = false;
            if (o->prevSpeed > c->x[0] && o->speed < c->x[0]) turned = true;
            if (o->prevSpeed < c->x[0] && o->speed > c->x[0]) turned = true;
            if (c->x[0] == o->speed) turned = true;
            if (turned == true) {
                o->timer = p->low + (p->high - p->low) * randf__Fv();
                o->state = 4;
            }
        }
        if (o->seFlag == 0) {
            Vec m;
            o->getNodePosition(&m, 0, o->id);
            if (o->speed > c->x[0] && m.x > c->x[1] + o->bounds[0]) o->seFlag = 1;
            if (o->speed < c->x[0] && m.x < o->bounds[3] - c->x[1]) o->seFlag = 1;
            if (o->seFlag == 1)
                o->handle = playSE__14snd3DGeneratorF5SndIDiii(o->gen, 0x1bc6, 0, 0x3c, -1);
        }
        o->prevSpeed = o->speed;
        break;
    }
    case 4:
        if (c->x[0] == o->timer) {
            o->speed = c->x[0];
            o->prevSpeed = c->x[0];
            o->bits.f.a = 1;
            o->seFlag = 0;
            o->state = 5;
        }
        break;
    case 5: {
        if (o->pos < c->x[0]) o->speed += p->accel * dt;
        if (o->pos > c->x[0]) o->speed -= p->accel * dt;
        if (nw4r::math::FAbs(o->speed) > p->maxSpeed) {
            if (o->pos < c->x[0]) o->speed = p->maxSpeed;
            if (o->pos > c->x[0]) o->speed = c->x[5] * p->maxSpeed;
        }
        o->pos += o->speed * dt;
        if (c->x[0] != o->prevSpeed) {
            bool turned = false;
            if (o->prevSpeed > c->x[0] && o->speed < c->x[0]) turned = true;
            if (o->prevSpeed < c->x[0] && o->speed > c->x[0]) turned = true;
            if (c->x[0] == o->speed) turned = true;
            if (turned == true) {
                if (o->handle != -1)
                    stopSE__14snd3DGeneratorFll(o->gen, o->handle, 0x3c);
                o->handle = -1;
                if (*o->cmd == 1 || *o->cmd == 2) *o->cmd = 0;
                o->state = 0;
                o->disableAttack(0);
                o->disableAttack(1);
                o->disableAttack(2);
                o->disableAttack(3);
                o->disableAttack(4);
                o->b17a = 0;
            }
        }
        if (o->seFlag == 0) {
            Vec m;
            o->getNodePosition(&m, 0, o->id);
            if (o->speed > c->x[0] && m.x > o->bounds[3] - c->x[1]) o->seFlag = 1;
            if (o->speed < c->x[0] && m.x < c->x[1] + o->bounds[0]) o->seFlag = 1;
            if (o->seFlag == 1) {
                if (o->handle != -1)
                    stopSE__14snd3DGeneratorFll(o->gen, o->handle, 0x3c);
                o->handle = -1;
            }
        }
        o->prevSpeed = o->speed;
        break;
    }
    }
    }
}

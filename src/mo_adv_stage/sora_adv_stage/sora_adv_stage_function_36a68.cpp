#include <gr/gr_gimmick.h>
#include <st/st_trigger.h>

#pragma force_active on

struct Pair {
    unsigned long a, b;
};

struct Vec2 {
    float x, y;
};

struct Work {
    char pad[0x5c];
    unsigned long id, a, b;
    unsigned short c, pad2;
    Vec2 pos;
};

struct AnimRes {
    char pad[0x1c];
    unsigned short frames;
};

struct Anim {
    char pad[0x2c];
    AnimRes* res;
};

struct AnimRoot {
    char pad[0xc];
    Anim* a;
    char pad10[8];
    Anim* b;
};

struct Data {
    char pad[0x9c];
    stTriggerData first, second;
};

struct Damage {
    char pad[4];
    float damage;
    char pad8[0x68];
    unsigned long flags;
};

class grYakumono_base {
public:
    char pad[0x3c];
};

class grYakumono : public grYakumono_base {
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
    virtual void fn_40_35B90();
    virtual void fn_40_36744();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(u32 flag);
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void getModelCount();
    virtual void fn_40_35BE8();
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
    virtual void fn_40_369C0();
    virtual void fn_40_36A14();
    virtual void fn_40_36630();
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
    virtual void changeNodeAnim(u32 a, u32 b);
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void getTransparencyFlag();
    virtual void fn_40_36A68();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit();
    virtual void disableHit(u32, u32);

    char pad40[8];
    AnimRoot** anim;
    char pad4c[0x5c];
    Work* work;
    char padac[0xa4];
    u8 state;
    char pad151[3];
    float timer, hideTimer;
    short health;
    char pad15e[2];
    Data* data;
};

extern "C" {
void fn_27_26D2F0(grYakumono*, int, const Vec3f*);
extern const float lbl_40_rodata_6C0;
}

extern "C" void fn_40_36A68(grYakumono* self, int, const Damage* dmg) {
    self->health -= (int)dmg->damage;
    self->changeNodeAnim(1, 0);
    ((grGimmick*)self)->changeMatColAnim(0, 0);
    self->timer = (float)(*self->anim)->a->res->frames;

    if (self->health <= 0) {
        ((grGimmick*)self)->startGimmickSE(1);
        ((grGimmick*)self)->startGimmickEffect(1);
        Vec3f pos = ((grGimmick*)self)->getPos();
        fn_27_26D2F0(self, 1, &pos);
        self->disableHit(0, 0);
        self->state = 4;
        ((u8*)&self->data->second)[2] &= 0xfe;
        g_stTriggerMng->setTriggerFlag(&self->data->second);
        g_stTriggerMng->setTriggerFlag(&self->data->first);
        ((grGimmick*)self)->changeMatColAnim(1, 0);
        self->hideTimer = (float)(*self->anim)->b->res->frames;
    } else {
        Vec2 l0, v0, v1, v2, v3, l3, l2, l1;
        switch (dmg->flags >> 30) {
        case 0: {
            v0.y = lbl_40_rodata_6C0;
            v0.x = lbl_40_rodata_6C0;
            *(Pair*)&l0 = *(Pair*)&v0;
            self->work->id = 0xc6;
            self->work->a = 0;
            self->work->c = 0;
            self->work->b = 0;
            self->work->pos = l0;
            break;
        }
        case 1: {
            v1.y = lbl_40_rodata_6C0;
            v1.x = lbl_40_rodata_6C0;
            *(Pair*)&l1 = *(Pair*)&v1;
            self->work->id = 0xc7;
            self->work->a = 0;
            self->work->c = 0;
            self->work->b = 0;
            self->work->pos = l1;
            break;
        }
        case 2: {
            v2.y = lbl_40_rodata_6C0;
            v2.x = lbl_40_rodata_6C0;
            *(Pair*)&l2 = *(Pair*)&v2;
            self->work->id = 0xc8;
            self->work->a = 0;
            self->work->c = 0;
            self->work->b = 0;
            self->work->pos = l2;
            break;
        }
        case 3: {
            v3.y = lbl_40_rodata_6C0;
            v3.x = lbl_40_rodata_6C0;
            *(Pair*)&l3 = *(Pair*)&v3;
            self->work->id = 0xc9;
            self->work->a = 0;
            self->work->c = 0;
            self->work->b = 0;
            self->work->pos = l3;
            break;
        }
        }
        ((grGimmick*)self)->startGimmickSE(2);
        ((grGimmick*)self)->startGimmickEffect(2);
    }
}

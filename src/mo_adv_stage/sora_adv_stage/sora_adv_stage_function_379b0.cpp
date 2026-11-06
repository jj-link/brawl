#pragma fp_contract off

#include <mt/mt_vector.h>
#pragma force_active on

extern "C" void update__9grGimmickFf(void* self, float delta);
extern "C" void getPos__9grGimmickFv(Vec3f* out, void* self);
extern "C" void setPos__9grGimmickFP5Vec3f(void* self, Vec3f* pos);
extern "C" void updateCallback__9grGimmickFUl(void* self, unsigned long arg);
extern "C" float randf__Fv();

struct YakumonoParams {
    float f0;
    float f4;
    char pad8[8];
    float f10;
    unsigned short s14;
    unsigned short s16;
    float f18;
    unsigned short s1c;
    unsigned short s1e;
};

struct grYakumono_base { char pad[0x3C]; };
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
    virtual void fn_40_37814();
    virtual void fn_40_379B0();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void fn_40_37DB8(bool flag);
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_40_37D34();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void getModelCount();
    virtual void fn_40_3786C();
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
    virtual void setValid(unsigned long flag);
};

struct Yakumono : grYakumono {
    char pad40[0x6C - 0x40];
    unsigned char b6c;
    char pad6d[0x14C - 0x6D];
    unsigned char state;
    unsigned char b14d;
    char pad14e[2];
    float timer;
    float f154;
    YakumonoParams* params;
    float f15c;
    unsigned int u160;
};

extern "C" void fn_40_379B0(Yakumono* self, float delta) {
    switch (self->state) {
    case 0:
        self->b6c |= 2;
        break;
    case 1:
        if (self->b14d == 0) {
            self->state = 0;
            self->timer = 0.0f;
        }
        if (self->timer >= (float)self->params->s14) {
            self->state = 2;
            self->timer = 0.0f;
        }
        self->b14d = 0;
        break;
    case 2:
    case 3: {
        Vec3f pos;
        update__9grGimmickFf(self, delta);
        getPos__9grGimmickFv(&pos, self);
        if (self->state == 2) {
            if ((unsigned int)self->timer % 10 < 5) {
                pos.m_y = self->params->f4 + self->params->f18 * randf__Fv();
            } else {
                pos.m_y = self->params->f4 - self->params->f18 * randf__Fv();
            }
            if (self->timer >= (float)self->params->s16) {
                pos.m_x = self->params->f0;
                self->state = 3;
                self->timer = 0.0f;
            }
        } else {
            self->f154 += self->params->f10;
            pos.m_y += self->f154;
            if (self->timer >= (float)self->params->s1c) {
                self->state = 4;
                self->timer = 0.0f;
                self->setValid(0);
            }
        }
        setPos__9grGimmickFP5Vec3f(self, &pos);
        updateCallback__9grGimmickFUl(self, 0);
        break;
    }
    case 4: {
        YakumonoParams* p = self->params;
        if (p->s1e != 0) {
            if (self->timer >= (float)p->s1e - 120.0f) {
                self->state = 5;
                self->timer = 0.0f;
                self->f15c = 0.0f;
                self->u160 = 6;
                Vec3f b;
                Vec3f a(p->f0, p->f4, 0.0f);
                b = a;
                setPos__9grGimmickFP5Vec3f(self, &b);
            }
        }
        break;
    }
    case 5:
        if (self->f15c > (float)self->u160) {
            self->fn_40_37DB8(!((self->b6c >> 7) & 1));
            self->f15c = 0.0f;
        }
        if (self->timer > 60.0f) {
            self->u160 = 3;
        }
        if (self->timer > 120.0f) {
            self->state = 0;
            self->timer = 0.0f;
            self->setValid(1);
        }
        self->f15c += delta;
        break;
    }
    self->timer += delta;
}

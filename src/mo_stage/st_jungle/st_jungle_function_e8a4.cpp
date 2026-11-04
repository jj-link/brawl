#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
#pragma fp_contract off

extern "C" const float lbl_51_rodata_120[];

struct Params {
    char pad[0xC];
    unsigned char state;
};

struct Stage_base { char pad[0x3C]; };
class Stage : public Stage_base {
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
    virtual void fn_51_260();
    virtual void fn_51_304();
    virtual void createObjPokeTrainer();
    virtual void fn_51_2700();
    virtual void fn_51_26FC();
    virtual void fn_51_26F0();
    virtual void fn_51_26E8();
    virtual void fn_51_26E0();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_51_2FC();
    virtual void process();
    virtual void updateStagePositions();
};

struct Ground_base { char pad[0x3C]; };
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
    virtual void fn_51_E558();
    virtual void fn_51_E648();
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
    virtual void fn_51_33B4();
    virtual void startup();
    virtual void fn_51_EB2C();
    virtual void fn_51_994();
    virtual Params* fn_51_33AC();
};

struct JungleObject : Ground {
    char pad40[0x110];
    unsigned char motionState;
    char pad151[0x43];
    unsigned char state;
    char pad195[3];
    float timer;
    char pad19C[0x18];
    unsigned char flag;
    char pad1B5[0xF];
    float amount;
};

inline float clamp(float value, float lo, float hi) {
    float t = nw4r::math::FSelect(value - lo, value, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}

extern "C" void fn_51_E8A4(JungleObject* self, float delta) {
    const float* c = lbl_51_rodata_120;
    Params* p = self->fn_51_33AC();
    if (p) {
        self->timer -= delta;
        if (self->timer < c[0])
            self->timer = c[0];

        switch (self->state) {
        case 0:
            if (self->flag != p->state)
                self->state = 1;
            break;
        case 1:
            if (self->motionState == 4) {
                self->state = 3;
                self->timer = c[4];
            }
            break;
        case 3: {
            float value = c[1] - self->timer / c[4];
            float t = clamp(value, c[5], c[1]);
            self->amount = c[1] - t;
            if (c[1] == t)
                self->state = 4;
            break;
        }
        case 4:
            if (self->motionState != 4) {
                if (self->flag == p->state) {
                    self->state = 0;
                } else {
                    self->state = 5;
                    self->timer = c[4];
                }
            }
            break;
        case 5: {
            float value = c[1] - self->timer / c[4];
            float t = clamp(value, c[5], c[1]);
            self->amount = t;
            if (c[1] == t)
                self->state = 0;
            break;
        }
        }
    }
}

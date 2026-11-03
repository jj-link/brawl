#include <gm/gm_global.h>
#pragma force_active on
extern const float lbl_51_rodata_0[];
extern "C" float randf__Fv();
struct Stage_base { char pad[0x3c]; };
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
    virtual void debugCollision();
    virtual void fn_51_26D8();
    virtual void fn_51_26D0();
    virtual void getZoneLightSetIndex();
    virtual void fn_51_2590();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_51_26CC();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_51_2710();
    virtual void getPokeTrainerStartPos();
    virtual void getItemPosCount();
    virtual void getItemPos();
    virtual void getRandItemPos();
    virtual void getKirifudaPos();
    virtual void getKirifudaAngle();
    virtual void getKirifudaScale();
    virtual void getKirifudaModelType();
    virtual void getPokeTrainerPosCount();
    virtual void getPokeTrainerPos();
    virtual void getFighterDeadEffectSizeRate();
    virtual void getEnemyDeadEffectSizeRate();
    virtual void getEnableZ();
    virtual void fn_51_26BC();
    virtual void fn_51_26C4();
    virtual void fn_51_26B4();
    virtual void fn_51_26AC();
    virtual void fn_51_26A4();
    virtual void fn_51_2690();
    virtual void fn_51_2680();
    virtual void fn_51_2674();
    virtual void fn_51_2668();
    virtual void fn_51_2660();
    virtual void fn_51_2658();
    virtual void fn_51_2650();
    virtual void fn_51_264C();
    virtual void isEnd();
    virtual void fn_51_25B0();
    virtual void enableDevil();
    virtual void disableDevil();
    virtual void isDevil();
    virtual void setDevilScrool();
    virtual void getLucarioFinalTechniquePosition();
    virtual void startAppear();
    virtual void setAppearKind();
    virtual void endAppear();
    virtual void getAppearTask();
    virtual void forceStopAppear();
    virtual void getFinalTechniqColor();
    virtual void setMotionRatio();
    virtual void saveMotionRatio();
    virtual void restoreMotionRatio();
    virtual void setMotionSubRatio(float, float);
};
struct Params {
    char pad[0x40];
    float initial, low, high, chance, motion, duration, duration2, low2, high2, value0, value1, value2;
};
struct Jungle : Stage {
    char pad1[0x9c - 0x40];
    Params* params;
    char pad2[0x453 - 0xa0];
    unsigned char state;
    float timer, timer2;
    unsigned char flag;
    char pad3[7];
    unsigned char active;
    char pad4[3];
    float value;
};
extern "C" void fn_51_22C4(Jungle* self, float delta) {
    const float* data = lbl_51_rodata_0;
    Params* p = self->params;
    if (p) {
        if (self->active == 1) {
            switch (self->state) {
            case 0:
                if (g_GameGlobal->m_modeMelee) {
                    unsigned char* mode = (unsigned char*)g_GameGlobal->m_modeMelee;
                    switch ((mode[0xe] >> 5) & 7) {
                    case 0: self->value = p->value0; break;
                    case 1: self->value = p->value1; break;
                    case 2: self->value = p->value2; break;
                    }
                    self->state++;
                }
                break;
            case 2:
                *(float*)((char*)g_GameGlobal->m_stageData + 8) = self->value;
                break;
            }
        } else {
            self->timer -= delta;
            if (self->timer < data[0]) self->timer = data[0];
            self->timer2 -= delta;
            if (self->timer2 < data[0]) self->timer2 = data[0];
            switch (self->state) {
            case 0:
                self->timer = p->initial;
                self->state = 1;
            case 1:
                if (data[0] == self->timer) {
                    if ((unsigned int)(randf__Fv() < p->chance) == 1) {
                        self->flag = 0;
                        self->timer = p->duration;
                        self->timer2 = p->duration2;
                        self->state = 2;
                    } else {
                        self->timer = p->low + (p->high - p->low) * randf__Fv();
                    }
                }
                break;
            case 2:
                if (data[0] == self->timer) {
                    self->setMotionSubRatio(p->motion, data[15]);
                    float t = p->low2 + (p->high2 - p->low2) * randf__Fv();
                    self->state = 3;
                    self->timer = t;
                }
                break;
            case 3:
                if (data[0] == self->timer) {
                    self->setMotionSubRatio(data[10], data[15]);
                    float t = p->low + (p->high - p->low) * randf__Fv();
                    self->state = 1;
                    self->timer = t;
                }
                break;
            }
            if (data[0] != self->timer2) self->flag = 0;
            else self->flag = 1;
        }
    }
}

#include <mt/mt_vector.h>
#include <st/st_utility.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

struct Params {
    float base;
    char pad04[0xf0];
    float low, high;
    char padfc[8];
    float minRate, maxRate;
};
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
    virtual void fn_81_570();
    virtual void fn_81_620();
    virtual void createObjPokeTrainer();
    virtual void fn_81_4050();
    virtual void fn_81_404C();
    virtual void fn_81_4040();
    virtual void fn_81_4038();
    virtual void fn_81_4030();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_81_618();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_81_4028();
    virtual void fn_81_4020();
    virtual void getZoneLightSetIndex();
    virtual void fn_81_4004();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_81_4000();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_81_4058();
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
    virtual void fn_81_3FF0();
    virtual void fn_81_3FF8();
    virtual void fn_81_3FE8();
    virtual void fn_81_3FE0();
    virtual void fn_81_3FD8();
    virtual void fn_81_3FC4();
    virtual void fn_81_3FB4();
    virtual void fn_81_3FA8();
    virtual void fn_81_3F9C();
    virtual void fn_81_3F94();
    virtual void fn_81_3F8C();
    virtual void fn_81_3F84();
    virtual void fn_81_3F80();
    virtual void isEnd();
    virtual void fn_81_3F40();
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
    virtual void setMotionSubRatio();
    virtual void saveMotionSubRatio();
    virtual void restoreMotionSubRatio();
    virtual void fn_81_3F78();
    virtual void fn_81_3F70();
    virtual void fn_81_3F68();
    virtual void isAppear();
    virtual void isStartAppearTimming();
    virtual void getMadeinAiData();
    virtual void isBamperVector();
    virtual void getBamperVector();
    virtual void notifyEventInfoReady();
    virtual void notifyEventInfoGo();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
    virtual void fn_81_3F60();
    virtual void fn_81_3F58();
    virtual void fn_81_3F54();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_81_4060();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_81_1498();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_81_984();
    virtual void fn_81_ABC();
    virtual void fn_81_C04();
    virtual void fn_81_D20();
    virtual void fn_81_DFC();
    virtual void fn_81_ED8();
    virtual void fn_81_11BC();
    virtual void fn_81_130C();
    virtual void fn_81_153C();
    virtual void fn_81_1598();
    virtual void fn_81_16A4();
    virtual void fn_81_1714();
    virtual void fn_81_191C();
    virtual void fn_81_19A8();
    virtual void fn_81_1C84();
    virtual void fn_81_1DE4();
    virtual void fn_81_21EC();
    virtual void fn_81_22DC();
    virtual void fn_81_245C();
    virtual void fn_81_25C4();
    virtual void fn_81_293C();
    virtual void fn_81_2CA0();
    virtual void fn_81_2DB4();
    virtual void fn_81_31C0();
    virtual void fn_81_344C();
    virtual void fn_81_37E0();
    virtual void fn_81_387C();
    virtual unsigned int fn_81_3900(Vec3f*);
    virtual unsigned int fn_81_399C(float*, Vec3f*, int);
    char pad40[0x5c];
    Params* params;
    char padA0[0xb30];
    unsigned char mode;
    char padBD1[7];
    float extra;
    char padBDC[0x2c];
    Vec3f pos;
    Vec3f previous;
    char padC20[0xc];
    float speed;
    float offset;
    unsigned char falling;
};
struct Constants { float v[28]; };
extern "C" const unsigned char lbl_81_rodata_0[];
extern "C" void* fn_27_222878(void*, unsigned int);

inline float clampRange(float value, float lo, float hi) {
    float t = nw4r::math::FSelect(value - lo, value, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}
extern "C" void fn_81_344C(Stage* self, float dt) {
    const Constants* c = (const Constants*)lbl_81_rodata_0;
    Params* p = self->params;
    if (p) {
        float x, z;
        z = self->pos.m_z;
        x = self->pos.m_x;
        Vec3f start, dir;
        start.m_x = x; start.m_y = c->v[26]; start.m_z = z;
        dir.m_x = c->v[0]; dir.m_y = c->v[27]; dir.m_z = c->v[0];
        Vec3f hit, normal;
        float height;
        if (!stRayCheck(&start, &dir, &hit, &normal, true, (grCollision*)fn_27_222878(self, 0), false, 1) || normal.m_y <= c->v[0]) {
            self->falling = 1;
            self->previous = self->pos;
            float adjustment = c->v[0];
            if (self->fn_81_3900(&self->pos) == 1) adjustment += c->v[10];
            if (self->fn_81_399C(&height, &self->pos, 1) == 1) adjustment += height;
            if (self->mode != 10) adjustment += self->extra;
            float change = c->v[0];
            if (self->pos.m_y - (self->offset + adjustment) > c->v[0])
                change += self->speed * dt;
            else
                change -= self->speed * dt;
            self->pos.m_y += change * dt;
            if (self->pos.m_y < p->low + c->v[20] * (p->high - p->low) + nw4r::math::FAbs(p->base))
                self->offset += dt * (c->v[20] * (p->maxRate - p->minRate));
            else
                self->offset -= dt * (c->v[20] * (p->maxRate - p->minRate));
        } else {
            float adjustment = c->v[0];
            if (self->fn_81_3900(&self->pos) == 1) adjustment += c->v[10];
            float height2;
            if (self->fn_81_399C(&height2, &self->pos, 1) == 1) adjustment += height2;
            if (self->mode != 10) adjustment += self->extra;
            self->previous = self->pos;
            float change = c->v[0];
            if (self->pos.m_y - (adjustment + (hit.m_y + self->offset)) > c->v[0])
                { float value = c->v[20] * self->speed; value *= dt; change += value; }
            else
                { float value = c->v[20] * self->speed; value *= dt; change -= value; }
            self->pos.m_y += change * dt;
            if (hit.m_y + self->offset > self->pos.m_y) {
                self->falling = 0;
                self->pos.m_y = hit.m_y + self->offset;
            }
            if (c->v[0] != adjustment)
                self->offset += nw4r::math::FAbs(self->speed);
            else
                self->offset -= nw4r::math::FAbs(self->speed);
            self->offset = clampRange(self->offset, p->low, p->high);
        }
    }
}
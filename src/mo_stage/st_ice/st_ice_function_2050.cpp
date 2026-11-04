#pragma fp_contract off

#include <mt/mt_prng.h>
#pragma force_active on

extern "C" void* memset(void*, int, unsigned long);
extern "C" int fn_27_10B224(void*, void*, void*, int, int);
extern "C" void* g_ftManager;

extern const float lbl_62_rodata_0;
extern const float lbl_62_rodata_40;
extern const double lbl_62_rodata_48;

struct Vec {
    float x, y, z;

    Vec() {}
    Vec(float a, float b, float c) : x(a), y(b), z(c) {}

    void set(float c, float b, float a) {
        x = a;
        y = b;
        z = c;
    }
};

struct Params {
    char pad[0x80];
    float low, high, chance;
};

struct Area {
    char pad[0x18];
    float x, y, w, h;
};

struct Stage_base {
    char pad[0x3c];
};

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
    virtual void fn_62_258();
    virtual void fn_62_368();
    virtual void createObjPokeTrainer();
    virtual void fn_62_2A4C();
    virtual void fn_62_2A48();
    virtual void fn_62_2A3C();
    virtual void fn_62_2A34();
    virtual void fn_62_2A2C();
    virtual void fn_62_28A8();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_62_360();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_62_2A24();
    virtual void fn_62_2A1C();
    virtual void getZoneLightSetIndex();
    virtual void fn_62_2A00();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_62_29FC();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_62_2A54();
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
    virtual void fn_62_29EC();
    virtual void fn_62_29F4();
    virtual void fn_62_29E4();
    virtual void fn_62_29DC();
    virtual void fn_62_29D4();
    virtual void fn_62_29C0();
    virtual void fn_62_29B0();
    virtual void fn_62_29A4();
    virtual void fn_62_2998();
    virtual void fn_62_2990();
    virtual void fn_62_2988();
    virtual void fn_62_2980();
    virtual void fn_62_297C();
    virtual void isEnd();
    virtual void isEventEnd();
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
    virtual void fn_62_2A64();
    virtual void setMotionRatio();
    virtual void saveMotionRatio();
    virtual void restoreMotionRatio();
    virtual void setMotionSubRatio();
    virtual void saveMotionSubRatio();
    virtual void restoreMotionSubRatio();
    virtual void fn_62_2974();
    virtual void fn_62_296C();
    virtual void fn_62_2964();
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
    virtual void fn_62_295C();
    virtual void fn_62_2954();
    virtual void fn_62_2950();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_62_2A5C();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_62_15BC();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_62_950();
    virtual void fn_62_A64();
    virtual void fn_62_B90();
    virtual void fn_62_C5C();
    virtual void fn_62_D28();
    virtual void fn_62_E78();
    virtual void fn_62_FD8();
    virtual void fn_62_1180();
    virtual void fn_62_12AC();
    virtual void fn_62_13B8();
    virtual void fn_62_14F0();
    virtual void fn_62_1758();
    virtual void fn_62_17B4();
    virtual void fn_62_1A74();
    virtual void fn_62_1BF4();
    virtual void fn_62_1D08();
    virtual void fn_62_1E38();
    virtual void fn_62_2050();
    virtual void fn_62_2444();
    virtual unsigned int fn_62_289C(int, Vec*);
};

struct Obj : Stage {
    char p40[0x5c];
    Params* params;
    char pa0[0x20c];
    float ax;
    char p2b0[12];
    float ay;
    char p2c0[12];
    float az;
    char p2d0[0x9c];
    float lx;
    char p370[12];
    float ly;
    char p380[12];
    float lz;
    char p390[0x3c];
    float rx;
    char p3d0[12];
    float ry;
    char p3e0[12];
    float rz;
    char p3f0[0x48];
    unsigned char phase;
    char p439[0x4c];
    unsigned char state;
    char p486[2];
    float timer;
    char p48c[0x18];
    Vec target;
    int id;
    unsigned char action;
    char p4b5[0x1f];
    int enabled;
    Area* area;
};

extern "C" void fn_62_2050(Obj* self, float dt) {
    struct Scratch {
        float bounds[4];
        int results[9];
    } scratch;

    int* out;

    if (!self->enabled)
        return;

    Params* p = self->params;
    if (!p)
        return;

    self->timer -= dt;
    if (self->timer < lbl_62_rodata_0)
        self->timer = lbl_62_rodata_0;

    switch (self->state) {
    case 0: {
        if (self->phase != 3)
            break;
        if (lbl_62_rodata_0 != self->timer)
            break;

        memset(scratch.results, 0, sizeof(scratch.results));
        Area* a = self->area;
        scratch.bounds[0] = a->x - lbl_62_rodata_40 * a->w;
        scratch.bounds[1] = a->x + lbl_62_rodata_40 * a->w;
        scratch.bounds[2] = a->y + lbl_62_rodata_40 * a->h;
        scratch.bounds[3] = a->y - lbl_62_rodata_40 * a->h;

        if (fn_27_10B224(g_ftManager, scratch.bounds, scratch.results, 0, 1) > 0)
            self->state = 1;
        break;
    }

    case 1: {
        if (self->phase != 3)
            break;

        if (randf() > p->chance) {
            self->timer = p->low + (p->high - p->low) * randf();
            self->state = 0;
            break;
        }

        Vec pos;
        Vec top, left, right;
        int count = 0;
        int ids[4];
        memset(ids, -1, sizeof(ids));

        float az = self->az;
        float ay = self->ay;
        float ax = self->ax;
        float lz = self->lz;
        float ly = self->ly;
        float lx = self->lx;
        float rz = self->rz;
        float ry = self->ry;
        float rx = self->rx;
        top.x = ax;
        top.y = ay;
        top.z = az;
        left.x = lx;
        left.y = ly;
        left.z = lz;
        right.x = rx;
        right.y = ry;
        right.z = rz;

        out = ids;
        for (int i = 0; i < 4; i++) {
            if (self->fn_62_289C(i, &pos) == 1 &&
                pos.y < top.y &&
                (pos.x < left.x || pos.x > right.x)) {
                *out++ = i;
                ++count;
            }
        }

        if (count == 0) {
            self->timer = p->low + (p->high - p->low) * randf();
            self->state = 0;
            break;
        }

        float random = randf();
        float converted = (float)count;
        int n = (int)(converted * random);
        n = n > 0 ? n : 0;

        self->id = ids[n < count - 1 ? n : count - 1];
        self->fn_62_289C(self->id, &self->target);
        self->action = 5;
        self->state = 3;
        break;
    }

    case 2:
        break;

    case 3: {
        if (self->id != -1) {
            Vec left, right;
            float lz = self->lz;
            float ly = self->ly;
            float lx = self->lx;
            float rz = self->rz;
            float ry = self->ry;
            float rx = self->rx;
            left.x = lx;
            left.y = ly;
            left.z = lz;
            right.x = rx;
            right.y = ry;
            right.z = rz;

            if (!self->fn_62_289C(self->id, &self->target))
                self->id = -1;

            if (self->target.x > left.x && self->target.x < right.x) {
                if (self->target.x - left.x < right.x - self->target.x)
                    self->target.x = left.x;
                else
                    self->target.x = right.x;
            }
        }

        if (self->action != 5) {
            self->timer = p->low + (p->high - p->low) * randf();
            self->id = -1;
            self->state = 0;
        }
        break;
    }
    }
}

#include <nw4r/math/math_types.h>
#include <mt/mt_prng.h>
#pragma force_active on

using nw4r::math::VEC3;

struct stMelee_base {
    char pad[0x3c];
};

class stMelee : public stMelee_base {
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
    virtual void fn_27_22C4B0();
    virtual void fn_27_22C710();
    virtual void createObjPokeTrainer();
    virtual void getPokeTrainerPointNum();
    virtual void getPokeTrainerPointData();
    virtual void getPokeTrainerPositionZ();
    virtual void getPokeTrainerDrawLayer();
    virtual void isAdventureStage();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_27_22C708();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void getAIRange();
    virtual void getDefaultLightSetIndex();
    virtual void getZoneLightSetIndex();
    virtual void getScrollDir();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void appearanceFighterLocal();
    virtual void fn_27_230E20();
    virtual void fn_27_230E44();
    virtual void fn_27_231D00();
    virtual void fn_27_230E60();
    virtual void fn_27_231D08();
    virtual void fn_27_231020(VEC3*, VEC3*, unsigned long);

    char rest[0x1e5 - 0x40];
    unsigned char count;
};

extern const float lbl_27_rodata_3804;
extern const float lbl_27_rodata_3878;

extern "C" void fn_27_230F38(stMelee* self, VEC3* out) {
    if (self->count == 0) {
        out->z = lbl_27_rodata_3804;
        out->y = lbl_27_rodata_3804;
        out->x = lbl_27_rodata_3804;
    } else {
        VEC3 a, b;
        self->fn_27_231020(&a, &b, (unsigned char)(int)((int)self->count * randf()));
        float t = randf();
        float s = lbl_27_rodata_3878 - t;
        register f32 sr = s;
        register f32 tr = t;
        register VEC3* pa = &a;
        register VEC3* pb = &b;
        register VEC3* po = out;
        register f32 p0, p1, p2, p3;
        asm {
            psq_l p0, 0(pa), 0, 0
            psq_l p1, 8(pa), 1, 0
            ps_muls0 p0, p0, sr
            ps_muls0 p1, p1, sr
            psq_l p2, 0(pb), 0, 0
            psq_l p3, 8(pb), 1, 0
            ps_madds0 sr, p2, tr, p0
            ps_madds0 tr, p3, tr, p1
            psq_st sr, 0(po), 0, 0
            psq_st tr, 8(po), 1, 0
        }
    }
}

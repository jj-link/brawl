#include <types.h>
#include <nw4r/math/math_types.h>
#include <mt/mt_prng.h>
#pragma force_active on
using nw4r::math::VEC3;
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
    virtual void fn_85_1A4();
    virtual void fn_85_404();
    virtual void createObjPokeTrainer();
    virtual void fn_85_5420();
    virtual void fn_85_541C();
    virtual void fn_85_5410();
    virtual void fn_85_5408();
    virtual void fn_85_5400();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_85_3FC();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_85_53F8();
    virtual void fn_85_53F0();
    virtual void getZoneLightSetIndex();
    virtual void fn_85_53D4();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_85_53D0();
    virtual void fn_85_44B4();
    virtual void fn_85_44D8();
    virtual void fn_85_5428();
    virtual void fn_85_44F4();
    virtual void fn_85_5438();
    virtual void fn_85_46B4(VEC3*, VEC3*, u8);
    char rest[0x1e5 - 0x40];
    u8 count;
};
extern "C" const f32 lbl_85_rodata_6C;
extern "C" const f32 lbl_85_rodata_E0;
extern "C" void fn_85_45CC(Stage* self, VEC3* out) {
    if (self->count == 0) {
        out->z = lbl_85_rodata_6C;
        out->y = lbl_85_rodata_6C;
        out->x = lbl_85_rodata_6C;
    } else {
        VEC3 a, b;
        self->fn_85_46B4(&a, &b, (u8)(int)((int)self->count * randf()));
        float t = randf();
        float s = lbl_85_rodata_E0 - t;
        register f32 sr = s;
        register f32 tr = t;
        register VEC3* pa = &a;
        register VEC3* pb = &b;
        register VEC3* po = out;
        register f32 p0, p1, p2, p3;
        asm {
            psq_l p0, 0(pa), 0, 0
            psq_l p1, 8(pa), 1, 0
            psq_l p2, 0(pb), 0, 0
            psq_l p3, 8(pb), 1, 0
            ps_muls0 p0, p0, sr
            ps_muls0 p1, p1, sr
            ps_madds0 sr, p2, tr, p0
            ps_madds0 tr, p3, tr, p1
            psq_st sr, 0(po), 0, 0
            psq_st tr, 8(po), 1, 0
        }
    }
}
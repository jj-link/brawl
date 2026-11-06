#include <ec/ec_mgr.h>
#include <gr/ground.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
#pragma pool_data on
struct StageData {
    float value;
    char pad4[0x24];
    float endFrame;
    float duration;
};
struct Ground_base { char pad[0x3c]; };
class PalutenaGround : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void slot2();
    virtual void slot3();
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
    virtual void slot22();
    virtual void slot23();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(u32);
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void slot31();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_67_2168();
    virtual void slot37();
    virtual void slot38();
    virtual void fn_67_880();
    virtual StageData* fn_67_2160();
    char pad40[4];
    nw4r::g3d::ScnMdl** models;
    char pad48[0x24];
    u8 visible : 1;
    u8 clipped : 1;
    u8 collision : 1;
    u8 flagsRest : 5;
    char pad6d[0xe7];
    float frame;
    char pad158[4];
    float* output;
    char pad160[0x20];
    float x, y, z;
    float scaleX, scaleY, scaleZ;
    u8 mode;
    u8 disabled;
    char pad19a[6];
    u8 effectSet;
};
extern "C" const float lbl_67_rodata_10[];
inline float clampRange(float value, float lower, float upper) {
    lower = nw4r::math::FSelect(value - lower, value, lower);
    return nw4r::math::FSelect(lower - upper, upper, lower);
}
extern "C" void fn_67_2A28(PalutenaGround* self) {
    const float* constants = lbl_67_rodata_10;
    StageData* data = self->fn_67_2160();
    if (data != 0 &&
        !(self->frame < data->endFrame - (constants[4] + data->duration))) {
        if (self->effectSet == 0) {
            u32 effect = g_ecMgr->setEffect((EfID)0x4f0004);
            u32 node;
            switch (self->mode) {
            case 4: node = 2; break;
            default: node = 1; break;
            }
            g_ecMgr->setParent(effect, *self->models, node, false);
            self->effectSet = 1;
        }
        float start = data->endFrame;
        float duration = data->duration;
        float frame = self->frame;
        start -= duration;
        if (!(frame < start)) {
            float ratio = (frame - start) / duration;
            float clamped = clampRange(ratio, constants[5], constants[1]);
            self->scaleY = constants[1];
            self->x = constants[0];
            self->y = constants[0];
            self->z = constants[0];
            self->scaleX = constants[1];
            self->scaleZ = constants[1];
            self->scaleY = clamped;
            self->y = constants[6] + constants[7] * clamped;
            *self->output = data->value;
            if (self->disabled == 0) {
                if (!self->visible)
                    self->setVisibility(1);
                if (!self->collision)
                    ((Ground*)self)->setEnableCollisionStatus(true);
            }
        }
    }
}

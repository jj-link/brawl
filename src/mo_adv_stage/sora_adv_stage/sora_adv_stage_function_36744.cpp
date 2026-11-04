#include <gr/gr_gimmick.h>
#include <cm/cm_camera_controller.h>
#include <gf/gf_model.h>
#include <st/st_trigger.h>
#pragma force_active on

struct AreaPosition { char pad[0x28]; float x; float y; };
struct AreaObject { char pad[0x90]; AreaPosition* position; };
struct GimmickData {
    char pad[0x70];
    float x;
    float y;
    char pad78[0x28];
    stTriggerData trigger;
};
struct grYakumono_base { char pad[0x3c]; };
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

    char pad40[4];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad4C[0x104];
    u8 state;
    char pad151[3];
    float timer;
    float hideTimer;
    char pad15C[4];
    GimmickData* data;
    char bounds[0x10];
    AreaObject* area;
};

extern "C" {
u32 fn_8009CC2C(CameraController*, void*);
int fn_40_139CC(AreaObject*);
void fn_27_26D2F0(grYakumono*, int, const Vec3f*);
extern const float lbl_40_rodata_6C0;
}

extern "C" void fn_40_36744(grYakumono* self, float delta) {
    ((grGimmick*)self)->grGimmick::update(delta);
    if (CameraController::getInstance()) {
        AreaPosition* position = self->area->position;
        position->x = self->data->x + ((grGimmick*)self)->getPos().m_x;
        position = self->area->position;
        position->y = self->data->y + ((grGimmick*)self)->getPos().m_y;
        if (fn_8009CC2C(CameraController::getInstance(), self->bounds) == 1U) {
            if ((int)self->state == 0)
                self->state = 1;
        } else if (self->state == 2) {
            self->state = 3;
        }
        switch (self->state) {
        case 0:
        case 2:
            if (self->timer > lbl_40_rodata_6C0) {
                self->timer -= delta;
                if (self->timer <= lbl_40_rodata_6C0) {
                    self->timer = lbl_40_rodata_6C0;
                    self->changeNodeAnim(0, 0);
                }
            }
            if (fn_40_139CC(self->area)) {
                Vec3f pos = ((grGimmick*)self)->getPos();
                pos.m_x += self->data->x;
                ((grGimmick*)self)->startGimmickSE(0);
                ((grGimmick*)self)->startGimmickEffect(0);
                fn_27_26D2F0(self, 0, &pos);
            }
            break;
        case 1:
            self->data->trigger.m_isValid = true;
            g_stTriggerMng->setTriggerFlag(&self->data->trigger);
            self->state = 2;
            break;
        case 3:
            ((u8*)&self->data->trigger)[2] &= 0xFE;
            g_stTriggerMng->setTriggerFlag(&self->data->trigger);
            self->state = 0;
            break;
        case 4:
            if (self->hideTimer > lbl_40_rodata_6C0) {
                self->hideTimer -= delta;
                if (self->hideTimer <= lbl_40_rodata_6C0) {
                    self->hideTimer = lbl_40_rodata_6C0;
                    (*self->animations)->unbindNodeAnim(*self->models);
                    self->setVisibility(0);
                }
            }
            break;
        }
    }
    ((grGimmick*)self)->grGimmick::updateCallback(0);
}

#include <gr/gr_gimmick.h>
#include <cm/cm_camera_controller.h>
#include <mt/mt_prng.h>
#pragma force_active on

struct Params {
    char pad[0x60];
    float a, b, c, d;
};
struct Prefix { char pad[0x3c]; };
class LocalGround : public Prefix {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_67_9440();
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
    virtual void fn_67_9310();
    virtual void fn_67_9500();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(unsigned int);
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_67_9A48();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_67_2168();
    virtual void fn_67_94C0();
    virtual void setNode();
    virtual void fn_67_880();
    virtual Params* fn_67_2160();
    virtual void fn_67_888();
    virtual void fn_67_2050();
    virtual void fn_67_2158();
    virtual void fn_67_214C();
    virtual void fn_67_213C();
    virtual void fn_67_212C();
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
    virtual void setValid();
    virtual void setValidAttachedEffect();
    virtual void fn_67_2128();
    virtual void fn_67_2124();
    virtual void fn_67_211C();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_67_2114();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_67_E10();
    virtual Vec3f* fn_67_218C();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_67_2184();
    virtual void fn_67_9580();
    virtual void fn_67_CF90(Vec3f*, int, int);
    virtual void fn_67_D03C();
    char pad40[0x2c];
    unsigned char flags;
    char pad6d[0x53];
    int c0, c4;
    char padc8[0x88];
    unsigned char state;
    char pad151[3];
    float timer;
    char pad158[4];
    int direction;
};

extern "C" void fn_67_CB14(LocalGround*);
extern "C" const float lbl_67_rodata_B0;
extern "C" const float lbl_67_rodata_B4;

extern "C" void fn_67_9580(LocalGround* self) {
    float* range;
    fn_67_CB14(self);
    Params* params = self->fn_67_2160();
    if (params) {
        Vec3f* pos = self->fn_67_218C();
        if (pos) {
            switch (self->state) {
            case 0:
                self->fn_67_CF90(pos, self->c0, self->c4);
                self->fn_67_CF90(pos + 1, self->c0, self->c4);
                ((grGimmick*)self)->setPos(pos);
                self->setVisibility(0);
                ((Ground*)self)->setEnableCollisionStatus(false);
                self->timer = params->a;
                self->state = 1;
                break;
            case 1:
                if (lbl_67_rodata_B0 == self->timer) {
                    range = &CameraController::getInstance()->unk158;
                    if (range) {
                        if (randf() <= params->d) {
                            pos[0].m_x = lbl_67_rodata_B4 + range[1];
                            pos[1].m_x = range[0] - lbl_67_rodata_B4;
                            self->direction = 1;
                        } else {
                            pos[0].m_x = range[0] - lbl_67_rodata_B4;
                            pos[1].m_x = lbl_67_rodata_B4 + range[1];
                            self->direction = 0;
                        }
                        if (!((self->flags >> 7) & 1))
                            self->setVisibility(1);
                        if (!((self->flags >> 5) & 1))
                            ((Ground*)self)->setEnableCollisionStatus(true);
                        self->fn_67_D03C();
                    }
                } else {
                    self->setVisibility(0);
                    ((Ground*)self)->setEnableCollisionStatus(false);
                }
                break;
            case 4:
                self->timer = params->b + (params->c - params->b) * randf();
                self->setVisibility(0);
                ((Ground*)self)->setEnableCollisionStatus(false);
                self->state = 1;
                break;
            case 2:
                range = &CameraController::getInstance()->unk158;
                if (range) {
                    if (self->direction == 1) {
                        pos[0].m_x = lbl_67_rodata_B4 + range[1];
                        pos[1].m_x = range[0] - lbl_67_rodata_B4;
                    } else {
                        pos[0].m_x = range[0] - lbl_67_rodata_B4;
                        pos[1].m_x = lbl_67_rodata_B4 + range[1];
                    }
                }
                break;
            }
        }
    }
}

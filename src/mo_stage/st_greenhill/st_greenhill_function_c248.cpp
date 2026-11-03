#pragma force_active on
struct Vec3f;
#include <snd/snd_3d_generator.h>
extern "C" const float lbl_72_rodata_E0;
struct Parameters {
    unsigned char pad[0x40];
    float increment;
    float maximum;
};
struct SharedData {
    unsigned char state;
    unsigned char kind;
    unsigned char pad[0x32];
    float value;
};
struct Ground_base { char pad[0x3c]; };
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
    virtual void fn_72_C16C();
    virtual void fn_72_C1D4();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(unsigned long);
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_72_1A98();
    virtual void startup();
    virtual void setNode();
    virtual void fn_72_468();
    virtual Parameters* fn_72_1A90();
    virtual void fn_72_1A8C();
    virtual void fn_72_1128();
    virtual void fn_72_1A84();
    virtual void fn_72_1A78();
    virtual void fn_72_1A68();
    virtual void fn_72_1A58();
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
    virtual void fn_72_1A54();
    virtual void fn_72_1A50();
    virtual void fn_72_1A48();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual float getMotionFrame(unsigned long);
    virtual void setMotionLoop(bool, unsigned long);
    unsigned char pad40[0x150 - 0x40];
    unsigned char state;
    unsigned char pad151[7];
    SharedData* data;
    snd3DGenerator generator;
    unsigned char played;
};
extern "C" void fn_72_C248(Ground* self) {
    Parameters* params = self->fn_72_1A90();
    if (params != 0) {
        switch ((int)self->state) {
        case 0:
            self->setMotionLoop(true, 0);
            self->setVisibility(0);
            self->state = 1;
        case 1:
            if (self->data->state == 3) {
                self->setVisibility(1);
                self->state = 8;
            }
            break;
        case 8:
            if (self->played == 0 && self->getMotionFrame(0) >= lbl_72_rodata_E0) {
                SndID id;
                switch ((int)self->data->kind) {
                case 0: id = (SndID)0x1D1B; break;
                case 1: id = (SndID)0x1D1C; break;
                case 2: id = (SndID)0x1D1A; break;
                default: return;
                }
                self->generator.playSE(id, 0, 0, -1);
                self->played = 1;
            }
            self->data->value += params->increment;
            if (self->data->value > params->maximum)
                self->data->value = params->maximum;
            if (self->data->state == 5) {
                self->played = 0;
                self->state = 0;
            }
            break;
        }
    }
}

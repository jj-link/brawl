#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#pragma force_active on

extern "C" const float lbl_52_rodata_160[];

struct Ground_base { char pad[0x3c]; };
struct MatrixData { char pad[0x0c]; float x; char pad10[0x0c]; float y; char pad20[0x0c]; float z; };
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
    virtual void fn_52_A408();
    virtual void fn_52_A498();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_52_B8D8();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_52_36EC();
    virtual void startup();
    virtual void setNode();
    virtual void fn_52_83C();
    virtual void fn_52_36E4();
    virtual void fn_52_36E0();
    virtual void fn_52_35C8();
    virtual void fn_52_36D8();
    virtual void fn_52_36CC();
    virtual void fn_52_36BC();
    virtual void fn_52_36AC();
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
    virtual void fn_52_36A8();
    virtual void fn_52_36A4();
    virtual void fn_52_369C();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual float getMotionFrame(unsigned long);
    char pad40[0x110];
    unsigned char state;
    char pad151[0xf];
    MatrixData* matrix;
    char pad164[5];
    unsigned char mode;
    char pad16a[0x12];
    snd3DGenerator generator;
    int handle;
    int step;
};

extern "C" void fn_52_AA98(Ground* self) {
    const float* c = lbl_52_rodata_160;
    switch (self->state) {
    case 0:
    case 1:
        break;
    default:
    MatrixData* matrix = self->matrix;
    if (matrix != 0) {
        float z = matrix->z;
        float y = matrix->y;
        float x = matrix->x;
        Vec3f pos(x, y, z);
        self->generator.setPos(&pos);
        switch (self->mode) {
        case 0:
            switch (self->step) {
            case 0:
                self->generator.playSE((SndID)0x1b98, 0, 0, -1);
                self->step++;
                break;
            case 1:
                if (!(self->getMotionFrame(0) < c[3])) {
                    self->handle = self->generator.playSE((SndID)0x1b99, 0, 0, -1);
                    self->step++;
                }
                break;
            case 2:
                if (!(self->getMotionFrame(0) < c[4])) {
                    if (self->handle != -1) self->generator.stopSE(self->handle, 0);
                    self->handle = -1;
                    self->step++;
                }
                break;
            case 3:
                if (!(self->getMotionFrame(0) < c[5])) {
                    self->handle = self->generator.playSE((SndID)0x1b9a, 0, 0, -1);
                    self->step++;
                }
                break;
            }
            break;
        case 1:
            switch (self->step) {
            case 0:
                self->generator.playSE((SndID)0x1b9c, 0, 0, -1);
                self->step++;
                break;
            case 1:
                if (!(self->getMotionFrame(0) < c[6])) {
                    self->handle = self->generator.playSE((SndID)0x1b99, 0, 0, -1);
                    self->step++;
                }
                break;
            case 2:
                if (!(self->getMotionFrame(0) < c[7])) {
                    if (self->handle != -1) self->generator.stopSE(self->handle, 0);
                    self->handle = -1;
                    self->generator.playSE((SndID)0x1b9b, 0, 0, -1);
                    self->step++;
                }
                break;
            case 3:
                if (!(self->getMotionFrame(0) < c[8])) {
                    self->handle = self->generator.playSE((SndID)0x1b98, 0, 0, -1);
                    self->step++;
                }
                break;
            }
            break;
        }
    }
    }
}

#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#include <revolution/OS/OSError.h>
#pragma force_active on
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
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
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void loadGroundData();
    virtual void slot25();
    virtual void setupMelee();
    virtual void slot27();
    virtual void setVisibilityByClipping();
    virtual void slot29();
    virtual void receiveCollMsg();
    virtual void slot31();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void getModelCount();
    virtual void slot37();
    virtual void slot38();
    virtual void setStageData();
    virtual void getStageData();
    virtual void initStageData();
    virtual void setMdlIndex();
    virtual void getMdlIndex();
    virtual void isEnableCalcCollision();
    virtual void enableCalcCollision();
    virtual void disableCalcCollision();
    virtual void getNodeIndex();
    virtual void getNodePosition(Vec3f*, unsigned long, unsigned long);
    virtual bool getNodePosition_2(Vec3f*, unsigned long, const char*);
};
struct Data { char pad[12]; int failure; int done; char report[44]; char node[18]; };
extern "C" Data lbl_27_data_57DA8;
extern "C" int fn_800797A4(snd3DGenerator*, int);
struct Object {
    char pad0[4];
    int state;
    char pad8[5];
    unsigned char flag;
    char padE[2];
    Ground* ground;
    SndID sound;
    unsigned short delay;
    char pad1a[2];
    Vec3f position;
    float timer;
    unsigned char started;
    char pad2d[3];
    snd3DGenerator generator;
    int handle;
};
extern "C" void fn_27_27129C(Object* self, float delta) {
    Data* data = &lbl_27_data_57DA8;
    if (!self->started) {
        if (self->timer >= (float)self->delay) {
            self->handle = self->generator.prepareSE(self->sound, -1);
            if (self->handle < 0) {
                OSReport(data->report, self->sound);
                self->state = data->failure;
            }
            if (!self->ground->getNodePosition_2(&self->position, 0, data->node)) {
                self->ground->getNodePosition(&self->position, 0, 0);
            }
            self->generator.setPos(&self->position);
            if (self->handle >= 0) {
                self->generator.startSE(self->handle, 0);
            }
            self->flag = 1;
            self->started = 1;
        } else {
            self->timer += delta;
        }
    } else if (!fn_800797A4(&self->generator, self->handle)) {
        self->state = data->done;
    } else {
        if (!self->ground->getNodePosition_2(&self->position, 0, data->node)) {
            self->ground->getNodePosition(&self->position, 0, 0);
        }
        self->generator.setPos(&self->position);
    }
}

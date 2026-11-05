#include <mt/mt_vector.h>
#pragma force_active on
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_81_4814();
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
    virtual void fn_81_47BC();
    virtual void fn_81_495C();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(unsigned int);
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void getModelCount();
    virtual void startup();
    virtual void fn_81_4D38();
    virtual void setStageData();
    virtual float* getStageData();
    void setEnableCollisionStatus(bool);
};
struct BigBlue : Ground {
    char pad40[0xc];
    void* object;
    char pad50[0x100];
    unsigned char state;
    char pad151[3];
    float timer;
    float position[3];
    Vec3f* positions;
    float* threshold;
    char pad16c[8];
    unsigned char index;
    char pad175[7];
    unsigned char* positionState;
};
extern "C" const float lbl_81_rodata_B0;
extern "C" const float lbl_81_rodata_B4;
extern "C" void fn_8011097C(void*);
extern "C" void fn_81_49F8(BigBlue* self, float delta) {
    float* data = self->getStageData();
    if (data) {
        self->timer -= delta;
        if (self->timer < lbl_81_rodata_B0)
            self->timer = lbl_81_rodata_B0;
        switch (self->state) {
        case 0:
            self->setVisibility(0);
            self->setEnableCollisionStatus(false);
            self->state = 1;
            break;
        case 1:
            if (*self->positionState != 12) {
                if (*self->positionState == 13) {
                    float value = *data;
                    self->position[0] = lbl_81_rodata_B4;
                    self->position[1] = value;
                    self->position[2] = lbl_81_rodata_B0;
                } else {
                    Vec3f* position = &self->positions[*self->positionState * 2 + 1];
                    self->position[0] = position->m_x;
                    self->position[1] = position->m_y;
                    self->position[2] = position->m_z;
                }
                self->setVisibility(1);
                self->setEnableCollisionStatus(true);
                if (self->object)
                    fn_8011097C(self->object);
                self->state = 2;
            }
            break;
        case 2:
            if (self->positions[self->index * 2 + 1].m_x < *self->threshold) {
                *self->positionState = 12;
                self->state = 0;
            }
            break;
        }
    }
}

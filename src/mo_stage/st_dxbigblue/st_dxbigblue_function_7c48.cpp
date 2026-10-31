#include <mt/mt_vector.h>

#pragma force_active on

struct Ground_base {
    char pad[0x3C];
};

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_81_7A38();
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
    virtual void fn_81_79E0();
    virtual void fn_81_495C();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(unsigned int);
    virtual void setVisibilityByClipping(unsigned int);
    virtual void setVisibilityAttachedEffect(unsigned int);
    virtual void receiveCollMsg(int, void*, void*);
    virtual void receiveCollMsg_Landing(void*, void*, bool);
    virtual void receiveCollMsg_Heading(void*, void*, bool);
    virtual void receiveCollMsg_Wall(void*, void*, bool);
    virtual void receiveCollMsg_Attack(void*, void*);
    virtual void unloadData();
    virtual int getModelCount();
    virtual void startup(void*, unsigned int, int);
    virtual void fn_81_8234();
    virtual void setStageData(void*);
    virtual void* getStageData();

    void setEnableCollisionStatus(bool);
};

struct BigBlueCollisionObject {
    char _00[0x54];
    unsigned char flags;
};

struct BigBlue : Ground {
    char _040[0x110];
    unsigned char state;
    char _151[7];
    float position[3];
    Vec3f* positions;
    float* threshold;
    char _16C[8];
    unsigned char positionIndex;
    char _175[7];
    unsigned char* positionState;
    char _180[0x14];
    float resetValue;
    char _198[0x0C];
    unsigned char enabled;
    char _1A5[3];
    BigBlueCollisionObject* objectA;
    BigBlueCollisionObject* objectB;
};

struct BigBlueFlagBits {
    unsigned char bit7 : 1;
    unsigned char bit6 : 1;
    unsigned char bit5 : 1;
    unsigned char bit4 : 1;
    unsigned char bit3 : 1;
    unsigned char bit2 : 1;
    unsigned char bit1 : 1;
    unsigned char bit0 : 1;
};

union BigBlueFlagByte {
    unsigned char value;
    BigBlueFlagBits bits;
};

extern "C" const float lbl_81_rodata_100;
extern "C" void fn_8011097C(void*);

static void clearCollisionFlags(BigBlueCollisionObject* object) {
    if (object != 0) {
        BigBlueFlagByte flags;
        flags.value = object->flags;
        flags.bits.bit7 = 0;
        flags.bits.bit4 = flags.bits.bit7;
        flags.bits.bit6 = flags.bits.bit4;
        object->flags = flags.value;
    }
}

extern "C" void fn_81_7C48(BigBlue* self) {
    if (self->getStageData() == 0) {
        return;
    }

    switch (self->state) {
    case 0:
        self->setVisibility(0);
        self->setEnableCollisionStatus(false);
        clearCollisionFlags(self->objectA);
        clearCollisionFlags(self->objectB);
        self->state = 1;
        self->resetValue = lbl_81_rodata_100;
        break;

    case 1:
        if (*self->positionState != 0x0C) {
            Vec3f* position =
                &self->positions[*self->positionState * 2 + 1];
            self->position[0] = position->m_x;
            self->position[1] = position->m_y;
            self->position[2] = position->m_z;

            self->setVisibility(1);
            self->setEnableCollisionStatus(true);

            if (*(void**)((char*)self + 0x4C) != 0) {
                fn_8011097C(*(void**)((char*)self + 0x4C));
            }

            if (self->objectA != 0) {
                BigBlueFlagByte flags;
                flags.value = self->objectA->flags;
                flags.bits.bit4 = 1;
                flags.bits.bit6 = flags.bits.bit4;
                self->objectA->flags = flags.value;
            }

            clearCollisionFlags(self->objectB);
            self->state = 2;
        }
        break;

    case 2:
        if (self->enabled == 1 &&
            self->positions[self->positionIndex * 2 + 1].m_x <
                *self->threshold) {
            *self->positionState = 0x0C;
            self->state = 0;
        }
        break;
    }
}

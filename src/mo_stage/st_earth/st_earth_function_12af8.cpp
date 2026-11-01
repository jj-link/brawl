#pragma force_active on

#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_joint.h>

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_66_129DC();
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
    virtual void fn_66_12984();
    virtual void fn_66_12A90();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_66_2D00();
    virtual void startup();
    virtual void setNode();
    virtual void fn_66_6BC();
    virtual void fn_66_2CF8();
    virtual void fn_66_2CF4();
    virtual void fn_66_2BF4();
    virtual void fn_66_2CEC();
    virtual void fn_66_2CE0();
    virtual void fn_66_2CD0();
    virtual void fn_66_BBC();
    virtual unsigned int getNodeIndex(unsigned int, const char*);

    char pad40[0x0c];
    grCollision* collision;
    char pad50[0x110];
    grCollisionJoint* joint;
};

extern "C" {
extern char lbl_66_data_38D8[];
void* getJoint__11grCollisionFUs(grCollision*, unsigned int);
void fn_66_12AF8(Ground* self);
}

extern "C" void fn_66_12AF8(Ground* self)
{
    grCollision* collision;
    unsigned int i;
    unsigned int count;

    if (self->joint)
        return;

    collision = self->collision;
    if (!collision)
        return;

    count = *(u16*)((char*)collision + 6);
    for (i = 0; i != count; ++i) {
        grCollisionJoint* joint =
            (grCollisionJoint*)getJoint__11grCollisionFUs(collision, i);
        if (!joint)
            return;

        if (joint->m_ground == self && joint->_0x4E == 0) {
            const u16 id = *(u16*)((char*)joint + 80);
            if (id == self->getNodeIndex(0, lbl_66_data_38D8)) {
                self->joint = joint;
                return;
            }
        }
    }
}

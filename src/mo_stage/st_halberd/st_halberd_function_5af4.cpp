#pragma force_active on
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

class grCollisionJoint {
public:
    u8 pad0[0x4e];
    u16 unk4E;
    u16 unk50;
    u8 pad52[2];
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 rest : 4;
    u8 unk55;
    u8 unk56;
    u8 pad57;
    void* unk58;
};

class grCollision {
public:
    u8 pad0[6];
    u16 unk6;
};

extern "C" grCollisionJoint* getJoint__11grCollisionFUs(grCollision*, unsigned int);

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_57_590C();
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
    virtual void fn_57_5894();
    virtual void fn_57_5968();
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
    virtual void fn_57_3A9C();
    virtual void startup();
    virtual void setNode();
    virtual void fn_57_638();
    virtual int fn_57_3A94();
    int getNodeIndex(unsigned long* out, unsigned long flag, const char* name);

    char pad0[0xC];
    grCollision* collision;
    char pad1[0x108];
    f32* unk158;
    s8* unk15C;
    char pad2[0x14];
    grCollisionJoint* joint1;
    grCollisionJoint* joint2;
};

extern const char lbl_57_data_E6C[];
extern const char lbl_57_data_E78[];
extern f32 lbl_57_rodata_1A4[4];

extern "C" void fn_57_5AF4(Ground* self) {
    unsigned long nodeIndex2;
    unsigned long nodeIndex1;

    if (self->joint1 != 0 && self->joint2 != 0) {
        if (self->fn_57_3A94() != 0) {
            switch (*self->unk15C) {
            case 2:
                if (*self->unk158 > lbl_57_rodata_1A4[0]) {
                    self->joint1->unk55 |= 8;
                    self->joint2->unk55 |= 8;
                } else {
                    self->joint1->unk55 &= ~8;
                    self->joint2->unk55 &= ~8;
                }
                break;
            default:
                self->joint1->unk55 &= ~8;
                self->joint2->unk55 &= ~8;
                break;
            }
        }
    } else {
        grCollision* collision = self->collision;
        if (collision != 0
            && self->getNodeIndex(&nodeIndex1, 0, lbl_57_data_E6C) != 0
            && self->getNodeIndex(&nodeIndex2, 0, lbl_57_data_E78) != 0) {
            unsigned int i;
            unsigned int count = collision->unk6;
            for (i = 0; i != count; i++) {
                grCollisionJoint* joint = getJoint__11grCollisionFUs(collision, i);
                if (joint == 0) {
                    return;
                }
                if (joint->unk58 == self && joint->unk4E == 0) {
                    if (nodeIndex1 == joint->unk50) {
                        joint->unk56 |= 0x80;
                        joint->b0 = 0;
                        joint->b3 = joint->b0;
                        joint->b1 = joint->b3;
                        self->joint1 = joint;
                    } else if (nodeIndex2 == joint->unk50) {
                        joint->unk56 |= 0x80;
                        joint->b0 = 0;
                        joint->b3 = joint->b0;
                        joint->b1 = joint->b3;
                        self->joint2 = joint;
                    }
                }
                if (self->joint1 != 0 && self->joint2 != 0) {
                    break;
                }
            }
        }
    }
}

#pragma force_active on

#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>

struct Ground_base {
    char pad[0x3c];
};

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
    virtual void fn_66_3AE4();
    virtual void fn_66_3C60();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_66_5490();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_66_2D00();
    virtual void startup();
    virtual void fn_66_3B58();
    virtual void fn_66_6BC();
    virtual void fn_66_2CF8();
    virtual void fn_66_2CF4();
    virtual void fn_66_2BF4();
    virtual void fn_66_2CEC();
    virtual void fn_66_2CE0();
    virtual void fn_66_2CD0();
    virtual void fn_66_BBC();
    virtual void getNodeIndex();
    virtual void getNodePosition(Vec3f* pos, unsigned int a, unsigned int b);
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
    virtual void fn_66_2CCC();
    virtual void fn_66_2CC8();
    virtual void fn_66_2CC0();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual float getMotionFrame(unsigned int layer);

    char pad40[0x280 - 0x40];
    snd3DGenerator m_gen;
};

extern "C" const float lbl_66_rodata_A8[32];

#define U8(o) (*(unsigned char*)((char*)self + (o)))
#define U32(o) (*(unsigned int*)((char*)self + (o)))

extern "C" void fn_66_4B58(Ground* self) {
    const float* values = lbl_66_rodata_A8;
    Vec3f pos;
    unsigned int hit30 = 0;
    unsigned int hit29 = 0;
    unsigned int hit28 = 0;

    float f1 = self->getMotionFrame(0);

    switch (U8(0x190)) {
    case 0:
        switch (U8(0x288)) {
        case 0:
            if (f1 >= values[18]) hit29 = 1;
            break;
        case 1:
            if (f1 >= values[19]) hit30 = 1;
            break;
        case 2:
            if (f1 >= values[20]) hit29 = 1;
            break;
        case 3:
            if (f1 >= values[21]) hit30 = 1;
            break;
        case 4:
            if (f1 >= values[22]) hit29 = 1;
            break;
        }
        break;
    case 3:
        switch (U8(0x288)) {
        case 0:
            if (values[14] == f1) hit28 = 1;
            break;
        }
        break;
    case 4:
        switch (U8(0x288)) {
        case 0:
            if (values[23] == f1) hit30 = 1;
            break;
        case 1:
            if (values[24] == f1) hit29 = 1;
            break;
        case 2:
            if (values[25] == f1) hit30 = 1;
            break;
        case 3:
            if (values[26] == f1) hit29 = 1;
            break;
        }
        break;
    case 9:
        switch (U8(0x288)) {
        case 0:
            if (values[27] == f1) hit30 = 1;
            break;
        case 1:
            if (values[7] == f1) hit29 = 1;
            break;
        case 2:
            if (values[28] == f1) hit30 = 1;
            break;
        case 3:
            if (values[29] == f1) hit29 = 1;
            break;
        }
        break;
    }

    if (hit30 == 1 || hit29 == 1 || hit28 == 1) {
        U8(0x288) = U8(0x288) + 1;
    }

    if (hit29 == 1) {
        self->getNodePosition(&pos, 0, U32(0x27C));
        self->m_gen.setPos(&pos);
        self->m_gen.playSE((SndID)0x1CD0, 0, 0, -1);
    }
    if (hit30 == 1) {
        self->getNodePosition(&pos, 0, U32(0x278));
        self->m_gen.setPos(&pos);
        self->m_gen.playSE((SndID)0x1CD1, 0, 0, -1);
    }
    if (hit28 == 1) {
        self->getNodePosition(&pos, 0, U32(0x274));
        self->m_gen.setPos(&pos);
        self->m_gen.playSE((SndID)0x1CD3, 0, 0, -1);
    }
}

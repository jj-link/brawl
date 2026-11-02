#pragma force_active on

#include <string.h>
#include <stdio.h>
#include <mt/mt_vector.h>

struct StringData {
    unsigned char first[4];
    char format[28];
    char second[24];
    char third[24];
};

extern "C" {
    void processAnim__6GroundFv(void*);
    extern StringData lbl_63_data_1048;
}

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_63_3C84();
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
    virtual void fn_63_3BE4();
    virtual void fn_63_3D84();
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
    virtual void fn_63_3378();
    virtual void startup();
    virtual void setNode();
    virtual void fn_63_59C();
    virtual void fn_63_3370();
    virtual void fn_63_336C();
    virtual void fn_63_2B64();
    virtual void fn_63_3364();
    virtual void fn_63_3358();
    virtual void fn_63_3348();
    virtual void fn_63_3338();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2(Vec3f*, unsigned long, const char*);
    char pad40[0x140];
    Vec3f* positions;
    char pad184[0x2c];
    Vec3f* additionalPositions;
};

#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants off
extern "C" void fn_63_3C84(Ground* self) {
    StringData* data = &lbl_63_data_1048;
    char buffer[0x80];
    unsigned long offset;
    unsigned int i;
    processAnim__6GroundFv(self);
    if (self->positions) {
        for (i = 0, offset = 0; i < 20; i++, offset += 12) {
            unsigned char (StringData::*first)[4] = &StringData::first;
            strcpy(buffer, (const char*)(void*)&(data->*first));
            sprintf(buffer, data->format, i + 1);
            self->getNodePosition_2(
                (Vec3f*)((char*)self->positions + offset), 0, buffer);
        }
    }
    if (self->additionalPositions) {
        self->getNodePosition_2(self->additionalPositions, 0, data->second);
        self->getNodePosition_2(self->additionalPositions + 1, 0, data->third);
    }
}
#pragma pop

#pragma force_active on
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
    virtual void fn_71_28E0();
    virtual void fn_71_293C();
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
    virtual void fn_71_2B8C();
    virtual void startup();
    virtual void setNode();
    virtual void fn_71_85C();
    virtual void fn_71_2B84();
    virtual void fn_71_2B80();
    virtual void fn_71_2700();
    virtual void fn_71_2B78();
    virtual void fn_71_2B6C();
    virtual void fn_71_2B5C();
    virtual void fn_71_F04();
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
    virtual void fn_71_2B58();
    virtual void fn_71_2B54();
    virtual void fn_71_2B4C();
    virtual void setMotionRatio();
    virtual void setMotionFrame(float, unsigned long);
    char pad40[0x2c];
    unsigned char flags;
    char pad6d[0xe3];
    unsigned char state;
    char pad151[0xb];
    unsigned char* event;
};
extern "C" const float lbl_71_rodata_50;
extern "C" void fn_71_29B0(Ground* self) {
    switch (self->state) {
    case 0:
        self->setVisibility(0);
        self->state = 1;
    case 1:
        if (*self->event == 4) {
            self->setMotionFrame(lbl_71_rodata_50, 0);
            self->state = 6;
        }
        break;
    case 6:
        if (!((self->flags >> 7) & 1)) {
            self->setVisibility(1);
        }
        if (*self->event != 4) {
            self->state = 0;
        }
        break;
    }
}
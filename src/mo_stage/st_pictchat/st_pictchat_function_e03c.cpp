#pragma force_active on

struct GroundBase {
    unsigned char pad[0x3C];
};

class Ground : public GroundBase {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_73_DCD0();
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
    virtual void fn_73_DC78();
    virtual void fn_73_E03C();
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
    virtual void fn_73_33D0();
    virtual void startup();
    virtual void fn_73_E470();
    virtual void fn_73_8DC();
    virtual void fn_73_33C8();
    virtual void fn_73_33C4();
    virtual void fn_73_2C5C();
    virtual void fn_73_33BC();
    virtual void fn_73_33B0();
    virtual void fn_73_33A0();
    virtual void fn_73_3390();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual void getNodeMatrix();
    virtual void getNodeMatrix_2();
    virtual bool setNodeVisibility(bool, unsigned long, unsigned long, bool, bool);

    unsigned char pad40[0x110];
    unsigned char state;
    unsigned char pad151[0x15C - 0x151];
    unsigned long nodeVis[23];
    unsigned char* event;
};

extern "C" void fn_73_E03C(Ground* self) {
    switch (self->state) {
    case 0:
        self->setNodeVisibility(0, 0, self->nodeVis[0], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[1], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[2], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[3], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[4], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[5], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[6], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[7], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[8], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[9], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[10], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[11], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[12], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[13], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[14], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[15], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[16], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[17], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[18], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[19], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[20], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[21], 1, 0);
        self->setNodeVisibility(0, 0, self->nodeVis[22], 1, 0);
        self->state = 1;
    case 1:
        self->state = 5;
    case 5:
        {
            unsigned char idx = *self->event;
            if (idx != 0x17) {
                self->setNodeVisibility(1, 0, self->nodeVis[idx], 1, 0);
            }
        }
        break;
    }
}

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
    virtual void fn_70_6A00();
    virtual void fn_70_6A58();
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
    virtual void fn_70_22A8();
    virtual void startup();
    virtual void fn_70_6CD8();
    virtual void fn_70_78C();
    virtual void fn_70_22A0();
    virtual void fn_70_229C();
    virtual void fn_70_2080();
    virtual void fn_70_2294();
    virtual void fn_70_2288();
    virtual void fn_70_2278();
    virtual void fn_70_2268();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual void getNodeMatrix();
    virtual void getNodeMatrix_2();
    virtual bool setNodeVisibility(bool, unsigned long, unsigned long, bool, bool);
    unsigned char pad40[0x110];
    unsigned char state;
    unsigned char pad151[0xf];
    unsigned char* event;
    unsigned char pad164[4];
    unsigned char previous;
    unsigned char pad169[3];
    unsigned long nodes[4];
};
extern "C" void fn_70_6AB4(Ground* self) {
    switch (self->state) {
    case 0:
        self->setVisibility(0);
        self->state = 4;
        break;
    case 4:
        if (self->previous != *self->event) {
            switch (*self->event) {
            case 0:
                self->setVisibility(1);
                self->setNodeVisibility(0, 0, self->nodes[0], 1, 0);
                self->setNodeVisibility(0, 0, self->nodes[1], 1, 0);
                self->setNodeVisibility(0, 0, self->nodes[2], 1, 0);
                self->setNodeVisibility(0, 0, self->nodes[3], 1, 0);
                break;
            case 1:
                self->setVisibility(1);
                self->setNodeVisibility(1, 0, self->nodes[0], 1, 0);
                self->setNodeVisibility(1, 0, self->nodes[1], 1, 0);
                self->setNodeVisibility(1, 0, self->nodes[2], 1, 0);
                self->setNodeVisibility(1, 0, self->nodes[3], 1, 0);
                break;
            default:
                self->setVisibility(1);
                break;
            }
            self->previous = *self->event;
        }
        break;
    }
}
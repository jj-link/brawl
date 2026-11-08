#pragma force_active on
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void slot2();
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
    virtual void slot22();
    virtual void slot23();
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
    virtual void fn_71_2B8C();
    virtual void startup(void*, int, int);
    virtual void slot38();
    virtual void fn_71_85C(void*);
};
struct Stage {
    char pad0[0x9c];
    void* value;
    char pad1[0x100];
    void* archive;
    char pad2[0xf2];
    unsigned char state;
};
extern "C" {
extern char lbl_71_data_0[];
Ground* fn_71_2628(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
void fn_71_87C(Stage* self, int kind) {
    Ground* ground = 0;
    char* data = lbl_71_data_0;
    switch (kind) {
    case 0:
        switch (self->state) {
        case 3:
            ground = fn_71_2628(5, data + 0x44, data + 0x5c);
            break;
        }
        break;
    case 1:
        switch (self->state) {
        case 5:
            ground = fn_71_2628(0x29, data + 0x70, data + 0x88);
            break;
        case 6:
            ground = fn_71_2628(0x2a, data + 0x9c, data + 0xb4);
            break;
        }
        break;
    }
    if (ground) {
        addGround__5StageFP6Ground(self, ground);
        ground->startup(self->archive, 0, 0);
        ground->fn_71_85C(self->value);
    }
}
}
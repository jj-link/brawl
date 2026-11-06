#pragma force_active on
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void slot2();
    virtual void slot3();
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
    virtual void slot31();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_67_2168();
    virtual void slot37(void*, int, int);
    virtual void slot38();
    virtual void fn_67_880(void*);
    virtual void fn_67_2160();
    virtual void fn_67_888();
};
class Stage {
public:
    char pad[0x9c];
    void* stageData;
    char padA0[0x100];
    void* archive;
    void addGround(Ground*);
};
extern "C" {
extern char lbl_67_data_0[];
Ground* fn_67_1F78(int, const char*, const char*);
void fn_67_79C(Stage* self, int kind) {
    Ground* ground;
    char* data = lbl_67_data_0;
    switch (kind) {
    case 0:
        ground = fn_67_1F78(14, data + 0x1c, data + 0x20);
        break;
    case 1:
        ground = fn_67_1F78(15, data + 0x1c, data + 0x34);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        self->addGround(ground);
        ground->slot37(self->archive, 0, 0);
        ground->fn_67_880(self->stageData);
        ground->fn_67_888();
    }
}
}
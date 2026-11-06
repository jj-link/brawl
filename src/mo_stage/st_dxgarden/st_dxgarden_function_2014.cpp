#pragma force_active on

struct Vec3f {
    float x, y, z;
};

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
    virtual void fn_77_1B9C();
    virtual void fn_77_1C3C();
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
    virtual void fn_77_1004();
    virtual void startup();
    virtual void setNode();
    virtual void fn_77_478();
    virtual void fn_77_FFC();
    virtual void fn_77_FF8();
    virtual void fn_77_EE8();
    virtual void fn_77_FF0();
    virtual void fn_77_FE4();
    virtual void fn_77_FD4();
    virtual void fn_77_FC4();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2(Vec3f* pos, unsigned int idx, const char* name);

    unsigned char pad_0x40[0x170 - 0x40];
    unsigned int effHandle;
    unsigned char effState;
    unsigned char pad_0x175;
    unsigned char active;
};

struct Stage_base { char pad[0x3c]; };

class Stage : public Stage_base {
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
    virtual void fn_77_E8();
    virtual void fn_77_174();
    virtual void createObjPokeTrainer();
    virtual void fn_77_C90();
    virtual void fn_77_C8C();
    virtual void fn_77_C80();
    virtual void fn_77_C78();
    virtual void fn_77_C70();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_77_16C();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_77_C68();
    virtual void fn_77_C60();
    virtual void getZoneLightSetIndex();
    virtual void fn_77_C44();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
};

extern "C" {

extern void* g_ecMgr;
extern char lbl_77_data_BC8[];

unsigned int setEffect__5ecMgrF4EfIDP5Vec3f(void*, int, Vec3f*);
void setPos__5ecMgrFUlP5Vec3f(void*, unsigned int, Vec3f*);
void endEffect__5ecMgrFUl(void*, unsigned int);

void fn_77_2014(Ground* self) {
    Vec3f pos;
    if (self->active == 1) {
        if (self->effState == 0) {
            self->getNodePosition_2(&pos, 0, lbl_77_data_BC8);
            self->effHandle = setEffect__5ecMgrF4EfIDP5Vec3f(g_ecMgr, 0x5c0004, &pos);
            self->effState = 1;
        } else {
            self->getNodePosition_2(&pos, 0, lbl_77_data_BC8);
            setPos__5ecMgrFUlP5Vec3f(g_ecMgr, self->effHandle, &pos);
        }
    } else if (self->effState == 1) {
        endEffect__5ecMgrFUl(g_ecMgr, self->effHandle);
        self->effState = 0;
    }
}

}
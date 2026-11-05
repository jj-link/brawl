#pragma force_active on
#include <mt/mt_vector.h>

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
    virtual void fn_73_1D4();
    virtual void fn_73_2C8();
    virtual void createObjPokeTrainer();
    virtual void fn_73_2B2C();
    virtual void fn_73_2B28();
    virtual void fn_73_2B1C();
    virtual void fn_73_2B14();
    virtual void fn_73_2B0C();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_73_2C0();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_73_2B04();
    virtual void fn_73_2AFC();
    virtual void getZoneLightSetIndex();
    virtual void fn_73_2AE0();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
};

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
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
    virtual bool getNodePosition(Vec3f*, unsigned long, unsigned long);

    char padding[0x118];
    Vec3f* data;
    unsigned long nodes[23];
};

extern "C" void processAnim__6GroundFv(Ground*);

extern "C" void fn_73_DCD0(Ground* self) {
    processAnim__6GroundFv(self);
    if (self->data != 0) {
        self->getNodePosition(self->data, 0, self->nodes[0]);
        self->getNodePosition(self->data + 1, 0, self->nodes[1]);
        self->getNodePosition(self->data + 2, 0, self->nodes[2]);
        self->getNodePosition(self->data + 3, 0, self->nodes[3]);
        self->getNodePosition(self->data + 4, 0, self->nodes[4]);
        self->getNodePosition(self->data + 5, 0, self->nodes[5]);
        self->getNodePosition(self->data + 6, 0, self->nodes[6]);
        self->getNodePosition(self->data + 7, 0, self->nodes[7]);
        self->getNodePosition(self->data + 8, 0, self->nodes[8]);
        self->getNodePosition(self->data + 9, 0, self->nodes[9]);
        self->getNodePosition(self->data + 10, 0, self->nodes[10]);
        self->getNodePosition(self->data + 11, 0, self->nodes[11]);
        self->getNodePosition(self->data + 12, 0, self->nodes[12]);
        self->getNodePosition(self->data + 13, 0, self->nodes[13]);
        self->getNodePosition(self->data + 14, 0, self->nodes[14]);
        self->getNodePosition(self->data + 15, 0, self->nodes[15]);
        self->getNodePosition(self->data + 16, 0, self->nodes[16]);
        self->getNodePosition(self->data + 17, 0, self->nodes[17]);
        self->getNodePosition(self->data + 18, 0, self->nodes[18]);
        self->getNodePosition(self->data + 19, 0, self->nodes[19]);
        self->getNodePosition(self->data + 20, 0, self->nodes[20]);
        self->getNodePosition(self->data + 21, 0, self->nodes[21]);
        self->getNodePosition(self->data + 22, 0, self->nodes[22]);
    }
}

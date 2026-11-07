#pragma force_active on
#include <gr/gr_tengan_event.h>
#include <gr/gr_stadium_vision.h>

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
    virtual void fn_59_270();
    virtual void fn_59_370();
    virtual void createObjPokeTrainer();
    virtual void fn_59_3554();
    virtual void fn_59_3550();
    virtual void fn_59_3544();
    virtual void fn_59_353C();
    virtual void fn_59_3534();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_59_368();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_59_352C();
    virtual void fn_59_3524();
    virtual void getZoneLightSetIndex();
    virtual void fn_59_3508();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_59_3504();
    virtual void getFighterStartPos(int, int, const char*, int, int);
    Stage* getGround(int);
    char pad40[0x1dc - 0x40];
    grTenganEvent e1, e2, e3, e4, e5, e6, e7;
    char pad690[0x6a9 - 0x690];
    u8 kind;
    char pad6aa[2];
    int state;
    char pad6b0[4];
    int sound;
    char pad6b8[0xc];
    int index;
    u8 order[4];
    char pad6cc[0x1a];
    u8 count;
    u8 previous;
    grTenganEvent vision;
    float timer;
};


extern "C" {
extern unsigned short lbl_59_rodata_88[];
extern const char lbl_59_data_224[], lbl_59_data_234[];
void fn_59_25D0(Stage* self, u8 arg1) {
    unsigned short* p = lbl_59_rodata_88;
    unsigned short tbl[20];
    tbl[0] = *p++;
    tbl[1] = *p++;
    tbl[2] = *p++;
    tbl[3] = *p++;
    tbl[4] = *p++;
    tbl[5] = *p++;
    tbl[6] = *p++;
    tbl[7] = *p++;
    tbl[8] = *p++;
    tbl[9] = *p++;
    tbl[10] = *p++;
    tbl[11] = *p++;
    tbl[12] = *p++;
    tbl[13] = *p++;
    tbl[14] = *p++;
    tbl[15] = *p++;
    tbl[16] = *p++;
    tbl[17] = *p++;
    tbl[18] = *p++;
    tbl[19] = *p++;

    ((grStadiumVision*)self->getGround(0))->setDisplay(false);
    self->state = 0;
    self->getGround(0)->getFighterStartPos(0, 0, lbl_59_data_224, 0, 0);
    self->getGround(0)->getFighterStartPos(0, 0, lbl_59_data_234, 0, 0);
    *((u8*)self->getGround(0) + 0x168) = arg1;
    ((grStadiumVision*)self->getGround(0))->setDisplay(true);
    self->vision.end();
    self->vision.set((float)(unsigned int)tbl[arg1], (float)(unsigned int)tbl[arg1]);
    self->vision.start();
    self->vision.setPhase(1);
}
}
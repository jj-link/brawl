#pragma force_active on
#include <gr/gr_tengan_event.h>
#include <ec/ec_mgr.h>
#include <gr/gr_stadium_vision.h>
#include <mt/mt_prng.h>
#include <cm/cm_quake.h>

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
    virtual void fn_83_228();
    virtual void fn_83_320();
    virtual void createObjPokeTrainer();
    virtual void fn_83_2CEC();
    virtual void fn_83_2CE8();
    virtual void fn_83_2CDC();
    virtual void fn_83_2CD4();
    virtual void fn_83_2CCC();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_83_318();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_83_2CC4();
    virtual void fn_83_2CBC();
    virtual void getZoneLightSetIndex();
    virtual void fn_83_2CA0();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_83_2C9C();
    virtual void getFighterStartPos(int, int, const char*, int, int);
    Stage* getGround(int);
    char pad40[0x198];
    grTenganEvent e1;
    grTenganEvent e2;
    grTenganEvent e3;
    grTenganEvent e4;
    grTenganEvent e5;
    grTenganEvent e6;
    u8 kind;
    char pad5e1[0x2b];
    int index;
    u8 order[4];
    u8 pad614;
    u8 flag;
    u8 pad616[2];
    u8 count;
    u8 pad619[3];
    grTenganEvent vision;
    float timer;
};

extern "C" {
extern const float lbl_83_rodata_0[];
extern const char lbl_83_data_4C[];
extern const char lbl_83_data_54[];
void fn_83_246C(Stage*);
void fn_83_29E8(Stage*);
void fn_83_A7C(Stage*, float);
void fn_83_1D84(Stage*, float);
void cmReqQuake__FiP5Vec3f(int, Vec3f*);

void fn_83_1898(Stage* self, float dt) {
    const float* rd = lbl_83_rodata_0;
    g_ecMgr->setDrawPrio(1);
    if (self->e1.isReadyEnd() == true && !self->e2.isEvent()) {
        switch (self->order[self->index]) {
        case 0: self->kind = 1; break;
        case 1: self->kind = 2; break;
        case 2: self->kind = 4; break;
        case 3: self->kind = 7; break;
        }
        self->e2.start();
        if (++self->index >= 4) {
            self->index = 0;
            self->order[0] = 0;
            self->order[1] = 1;
            self->order[2] = 2;
            self->order[3] = 3;
            u32 a;
            for (int i = 0; i < 32; ++i) {
                a = randi(4);
                if (a >= 3) a = 3;
                u32 b = randi(4);
                if (b >= 3) b = 3;
                u8 temp;
                Stage* pa;
                Stage* pb;
                pb = (Stage*)((char*)self + b);
                pa = (Stage*)((char*)self + a);
                temp = pa->order[0];
                pa->order[0] = pb->order[0];
                pb->order[0] = temp;
            }
        }
    }
    self->e1.update(dt);
    self->e2.update(dt);
    self->e3.update(dt);
    self->e4.update(dt);
    self->e5.update(dt);
    self->e6.update(dt);
    self->vision.update(dt);
    if (self->vision.isEvent() == true) {
        switch (self->vision.getPhase()) {
        case 1:
            if (!self->vision.isReadyEnd()) break;
            self->vision.end();
            self->flag = 0;
            self->getGround(0)->getFighterStartPos(0, 0, lbl_83_data_54, 0, 0);
            ((grStadiumVision*)self->getGround(0))->setDisplay(false);
        case 0: {
            u32 random = randi(2);
            if (random >= 1) random = 1;
            int choice = random;
            ++self->count;
            self->vision.set(rd[0x34/4], rd[0x2c/4]);
            if (self->count >= 7) {
                self->count = 0;
                choice = 2;
                self->vision.set(rd[0x3c/4], rd[0x3c/4]);
            }
            self->vision.end();
            self->flag = 0;
            self->getGround(0)->getFighterStartPos(0, 0, lbl_83_data_54, 0, 0);
            ((grStadiumVision*)self->getGround(0))->setDisplay(false);
            self->vision.start();
            switch ((int)choice) {
            case 0:
                self->timer = rd[0x60/4] + rd[0x64/4] * randf();
                fn_83_246C(self);
                self->getGround(0)->getFighterStartPos(0, 0, lbl_83_data_4C, 0, 0);
                break;
            case 1: {
                Stage* ground = self->getGround(0);
                *((u8*)ground + 0x168) = 14;
                ((grStadiumVision*)self->getGround(0))->setDisplay(true);
                self->getGround(0)->getFighterStartPos(1, 0, lbl_83_data_4C, 0, 0);
                break;
            }
            case 2: {
                Stage* ground = self->getGround(0);
                *((u8*)ground + 0x168) = 13;
                ((grStadiumVision*)self->getGround(0))->setDisplay(true);
                self->getGround(0)->getFighterStartPos(1, 0, lbl_83_data_4C, 0, 0);
                break;
            }
            }
            self->vision.setPhase(1);
            break;
        }
        }
    }
    fn_83_29E8(self);
    fn_83_A7C(self, dt);
    if (self->e4.isEvent()) {
        if (self->e4.isReadyEnd() == true) {
            cmRemoveQuake(1);
            self->e4.end();
        } else {
            Vec3f pos;
            pos.m_x = rd[0];
            pos.m_y = rd[0];
            pos.m_z = rd[0];
            cmReqQuake__FiP5Vec3f(1, &pos);
        }
    }
    fn_83_1D84(self, dt);
    g_ecMgr->setDrawPrio(-1);
}
}

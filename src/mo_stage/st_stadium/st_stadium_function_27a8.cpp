#pragma force_active on
#include <gr/gr_tengan_event.h>
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
extern const float lbl_59_rodata_0[];
extern const char lbl_59_data_224[];
extern const char lbl_59_data_234[];
void fn_59_2CA0(Stage*);
void fn_59_3250(Stage*);
void fn_59_C88(Stage*, float);
void fn_59_2328(Stage*, float);
void playSeBasic__7stMeleeF5SndIDf(void*, int, float);
void stopSeBasic__7stMeleeFif(void*, int, float);
void cmReqQuake__FiP5Vec3f(int, Vec3f*);

void fn_59_27A8(Stage* self, float dt) {
    const float* rd = lbl_59_rodata_0;
    if (self->e1.isReadyEnd() == true && !self->e2.isEvent()) {
        switch (self->order[self->index]) {
        case 0: self->kind = 10; break;
        case 1: self->kind = 13; break;
        case 2: self->kind = 12; break;
        case 3: self->kind = 14; break;
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
    self->e7.update(dt);
    if (self->vision.isEvent() == true) {
        switch (self->vision.getPhase()) {
        case 1:
            if (!self->vision.isReadyEnd()) break;
            self->vision.end();
            self->state = 0;
            self->getGround(0)->getFighterStartPos(0, 0, lbl_59_data_224, 0, 0);
            self->getGround(0)->getFighterStartPos(0, 0, lbl_59_data_234, 0, 0);
            ((grStadiumVision*)self->getGround(0))->setDisplay(false);
        case 0: {
            u32 random = randi(2);
            if (random >= 1) random = 1;
            int choice = random;
            ++self->count;
            self->vision.set(rd[0x24/4], rd[0x1c/4]);
            if (self->count >= 7) {
                self->count = 0;
                choice = 2;
                self->vision.set(rd[0x28/4], rd[0x28/4]);
            }
            self->vision.end();
            self->state = 0;
            self->getGround(0)->getFighterStartPos(0, 0, lbl_59_data_224, 0, 0);
            self->getGround(0)->getFighterStartPos(0, 0, lbl_59_data_234, 0, 0);
            ((grStadiumVision*)self->getGround(0))->setDisplay(false);
            self->vision.start();
            switch (choice) {
            case 0:
                self->timer = rd[0xb8/4] + rd[0xbc/4] * randf();
                fn_59_2CA0(self);
                break;
            case 1: {
                Stage* ground = self->getGround(0);
                *((u8*)ground + 0x168) = 14;
                ((grStadiumVision*)self->getGround(0))->setDisplay(true);
                if (self->previous != (u32)choice)
                    playSeBasic__7stMeleeF5SndIDf(self, 0x1c3a, rd[0]);
                break;
            }
            case 2: {
                Stage* ground = self->getGround(0);
                *((u8*)ground + 0x168) = 13;
                ((grStadiumVision*)self->getGround(0))->setDisplay(true);
                if (self->previous != (u32)choice)
                    playSeBasic__7stMeleeF5SndIDf(self, 0x1c3a, rd[0]);
                break;
            }
            }
            self->previous = choice;
            self->vision.setPhase(1);
            break;
        }
        }
    }
    fn_59_3250(self);
    fn_59_C88(self, dt);
    if (self->e4.isEvent()) {
        if (self->e4.isReadyEnd() == true) {
            cmRemoveQuake(1);
            stopSeBasic__7stMeleeFif(self, self->sound, rd[0x80/4]);
            self->sound = -1;
            self->e4.end();
        } else {
            Vec3f pos;
            pos.m_x = rd[0];
            pos.m_y = rd[0];
            pos.m_z = rd[0];
            cmReqQuake__FiP5Vec3f(1, &pos);
        }
    }
    fn_59_2328(self, dt);
}
}

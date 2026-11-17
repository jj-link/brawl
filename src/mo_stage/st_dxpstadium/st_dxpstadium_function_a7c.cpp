// fn_83_A7C (st_dxpstadium). NOT a verified match: 93.1% of lines match, 184 differ (last tried: getData result assigned inside the null-check condition).
// Known gaps:
//  1. A 4-instruction shortfall in the kind==7 case body (before the shared tail) shifts all later branches.
//  2. Virtual calls through VT_OF() load the vtable into r7 where the original uses r12 (cosmetic).
//  3. The original caches g_ecMgr's high half and the 0x5F0000 constant in r27/r28 in the kind==7 block.
#pragma force_active on
#include <gr/gr_tengan_event.h>
#include <types.h>

extern "C" {
extern void* g_ecMgr;
extern const float lbl_83_rodata_0[];
extern const char lbl_83_data_0[];

void endEntity__8grMadeinFv(void* self);
void startEntity__8grMadeinFv(void* self);
void startEntityAutoLoop__8grMadeinFv(void* self);
void setEnableCollisionStatus__6GroundFb(void* self, bool enable);
void setDisplay__15grStadiumVisionFb(void* self, bool enable);
void setScale__9grGimmickFP5Vec3f(void* self, Vec3f* v);
void setPos__9grGimmickFP5Vec3f(void* self, Vec3f* v);
void setRot__9grGimmickFP5Vec3f(void* self, Vec3f* v);
void playSeBasic__7stMeleeF5SndIDf(void* self, int sndId, float vol);
void zoomOutCamera__7stMeleeFff(void* self, float a, float b);
void zoomInCamera__7stMeleeFv(void* self);
void setAreaSleep__9stTriggerFb(void* self, bool sleep);
u32 setEffect__5ecMgrF4EfID(void* mgr, int id);
void endEffect__5ecMgrFUl(void* mgr, u32 handle);
void setScl__5ecMgrFUlP5Vec3f(void* mgr, u32 handle, Vec3f* v);
void setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(void* mgr, u32 handle, void* scnMdl, const char* name, bool flag);
void loadPositionData__11stPositionsFPQ34nw4r3g3d7ResFile(void* self, void* resFile);
s32 getData__9gfArchiveF11ARCNodeTypeiUs(void* self, int nodeType, int id, u16 subId);
}

class Ground {
public:
    char pad[0x3c];
    virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3();
    virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7();
    virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11();
    virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15();
    virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19();
    virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23();
    virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27();
    virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31();
    virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35();
    virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39();
    virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43();
    virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47();
    virtual void u48(); virtual bool getNodePosition(Vec3f*, unsigned long, const char*); virtual void u50(); virtual void u51();
    virtual void u52();
    virtual void setAnimation(int, int, const char*, int, int);
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
    virtual void getFighterStartPos();

    Stage* getGround(int index);

    char pad40[0x50];
    void* posData;          // 0x090
    char pad94[0x10C];
    void* archive;          // 0x1A0
    char pad1A4[0x34];
    grTenganEvent e1;       // 0x1D8
    grTenganEvent e2;       // 0x284
    grTenganEvent e3;       // 0x330
    grTenganEvent e4;       // 0x3DC
    grTenganEvent e5;       // 0x488
    grTenganEvent e6;       // 0x534
    u8 kind;                // 0x5E0
    char pad5E1[3];
    float timer1;           // 0x5E4
    float timer2;           // 0x5E8
    char pad5EC[4];
    s32 fx[5];              // 0x5F0
    s32 fx604;              // 0x604
    s32 fx608;              // 0x608
    char pad60C[9];
    u8 flag615;             // 0x615
    char pad616[6];
    grTenganEvent e7;       // 0x61C
    char pad6C8[0x30];
    u8 flag6F8;             // 0x6F8
    char pad6F9[3];
    void* trigger;          // 0x6FC
};

#define VT_OF(o) (*(void***)((char*)(o) + 0x3C))
#define SCN_OF(g) ((*(void***)((char*)(g) + 0x44))[0])
typedef void (*VFnA8)(void*);

extern "C" void fn_83_A7C(Stage* self, float farg0) {
    const float* rd;
    const char* data;
    Vec3f vF38;
    Vec3f vL1090;
    Vec3f vP3;
    Vec3f vP6a;
    Vec3f vP6b;
    Vec3f vP7;
    Vec3f rot;
    Vec3f pos;
    s32 t18;
    s32 resourceResult;
    s32 t14;
    s32 t10;
    s32 tC;
    s32 t8;

    data = lbl_83_data_0;
    rd = lbl_83_rodata_0;

    if (self->e2.isEvent()) {
        switch (self->e2.getPhase()) {
        case 0:
            if (!self->e4.isEvent()) {
                self->e7.end();
                self->flag615 = 0;
                ((Ground*)self->getGround(0))->setAnimation(0, 0, data + 0x54, 0, 0);
                setDisplay__15grStadiumVisionFb(self->getGround(0), false);
                self->e5.start();
                self->e6.start();
                self->e2.setPhase(self->e2.getPhase() + 1);
                self->flag6F8 = 0;
            }
            break;
        case 1:
            if (self->e6.isReadyEnd() == true) {
                self->e6.end();
                self->timer1 = rd[1];
                self->e2.setPhase(self->e2.getPhase() + 1);
                setEffect__5ecMgrF4EfID(g_ecMgr, 0x5F0002);
                self->e4.start();
                playSeBasic__7stMeleeF5SndIDf(self, 0x1DC8, rd[0]);
                zoomOutCamera__7stMeleeFff(self, rd[15], rd[20]);
                self->fx[0] = -1;
                self->fx[1] = -1;
                self->fx[2] = -1;
                self->fx[3] = -1;
                self->fx[4] = -1;
                self->timer2 = rd[0];
            }
            break;
        case 2:
            self->timer1 = self->timer1 - rd[21] * farg0;
            if (self->timer1 <= rd[0]) {
                self->timer1 = rd[22];
                endEntity__8grMadeinFv(self->getGround(3));
                setEnableCollisionStatus__6GroundFb(self->getGround(3), false);
                if (self->kind == 4) {
                    startEntity__8grMadeinFv(self->getGround(self->kind));
                } else {
                    startEntityAutoLoop__8grMadeinFv(self->getGround(self->kind));
                }
                setEnableCollisionStatus__6GroundFb(self->getGround(self->kind), true);
                switch (self->kind) {
                case 2: {
                    startEntityAutoLoop__8grMadeinFv(self->getGround(0xB));
                    resourceResult = getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 2, 0x67, 0xFFFE);
                    if (resourceResult != 0) {
                        t18 = resourceResult;
                        loadPositionData__11stPositionsFPQ34nw4r3g3d7ResFile(self->posData, &t18);
                    }
                    break;
                }
                case 1: {
                    self->fx[0] = setEffect__5ecMgrF4EfID(g_ecMgr, 0x5F0004);
                    resourceResult = getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 2, 0x66, 0xFFFE);
                    if (resourceResult != 0) {
                        t14 = resourceResult;
                        loadPositionData__11stPositionsFPQ34nw4r3g3d7ResFile(self->posData, &t14);
                    }
                    break;
                }
                case 4: {
                    self->fx[0] = setEffect__5ecMgrF4EfID(g_ecMgr, 0x5F0003);
                    resourceResult = getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 2, 0x68, 0xFFFE);
                    if (resourceResult != 0) {
                        t10 = resourceResult;
                        loadPositionData__11stPositionsFPQ34nw4r3g3d7ResFile(self->posData, &t10);
                    }
                    break;
                }
                case 7: {
                    self->fx[0] = setEffect__5ecMgrF4EfID(g_ecMgr, 0x5F0005);
                    self->fx[1] = setEffect__5ecMgrF4EfID(g_ecMgr, 0x5F0006);
                    self->fx[2] = setEffect__5ecMgrF4EfID(g_ecMgr, 0x5F0006);
                    self->fx[3] = setEffect__5ecMgrF4EfID(g_ecMgr, 0x5F0007);
                    self->fx[4] = setEffect__5ecMgrF4EfID(g_ecMgr, 0x5F0007);
                    startEntityAutoLoop__8grMadeinFv(self->getGround(5));
                    startEntityAutoLoop__8grMadeinFv(self->getGround(6));
                    startEntityAutoLoop__8grMadeinFv(self->getGround(9));
                    startEntityAutoLoop__8grMadeinFv(self->getGround(0xA));
                    Stage* gg1 = self->getGround(self->kind);
                    setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(g_ecMgr, self->fx[1], SCN_OF(gg1), data + 0x5C, false);
                    Stage* gg2 = self->getGround(self->kind);
                    setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(g_ecMgr, self->fx[2], SCN_OF(gg2), data + 0x68, false);
                    Stage* gg3 = self->getGround(self->kind);
                    setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(g_ecMgr, self->fx[3], SCN_OF(gg3), data + 0x74, false);
                    Stage* gg4 = self->getGround(self->kind);
                    setParent__5ecMgrFUlPQ34nw4r3g3d6ScnMdlPCcb(g_ecMgr, self->fx[4], SCN_OF(gg4), data + 0x80, false);
                    resourceResult = getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 2, 0x69, 0xFFFE);
                    if (resourceResult != 0) {
                        tC = resourceResult;
                        loadPositionData__11stPositionsFPQ34nw4r3g3d7ResFile(self->posData, &tC);
                    }
                    break;
                }
                }
                self->updateStagePositions();
                vF38.m_y = self->timer1;
                vF38.m_x = rd[1];
                vF38.m_z = rd[1];
                setScale__9grGimmickFP5Vec3f(self->getGround(self->kind), &vF38);
                setScale__9grGimmickFP5Vec3f(self->getGround(5), &vF38);
                setScale__9grGimmickFP5Vec3f(self->getGround(6), &vF38);
                setScale__9grGimmickFP5Vec3f(self->getGround(9), &vF38);
                setScale__9grGimmickFP5Vec3f(self->getGround(0xA), &vF38);
                setScale__9grGimmickFP5Vec3f(self->getGround(0xB), &vF38);
                if (self->fx[0] + 0x10000U != 0xFFFFU) setScl__5ecMgrFUlP5Vec3f(g_ecMgr, self->fx[0], &vF38);
                if (self->fx[1] + 0x10000U != 0xFFFFU) setScl__5ecMgrFUlP5Vec3f(g_ecMgr, self->fx[1], &vF38);
                if (self->fx[2] + 0x10000U != 0xFFFFU) setScl__5ecMgrFUlP5Vec3f(g_ecMgr, self->fx[2], &vF38);
                if (self->fx[3] + 0x10000U != 0xFFFFU) setScl__5ecMgrFUlP5Vec3f(g_ecMgr, self->fx[3], &vF38);
                if (self->fx[4] + 0x10000U != 0xFFFFU) setScl__5ecMgrFUlP5Vec3f(g_ecMgr, self->fx[4], &vF38);
                self->e2.setPhase(self->e2.getPhase() + 1);
            }
            vL1090.m_y = self->timer1;
            vL1090.m_x = rd[1];
            vL1090.m_z = rd[1];
            setScale__9grGimmickFP5Vec3f(self->getGround(3), &vL1090);
            break;
        case 3:
            self->timer1 = self->timer1 + rd[21] * farg0;
            if (self->timer1 >= rd[1]) {
                self->timer1 = rd[1];
                self->e2.setPhase(self->e2.getPhase() + 1);
                self->e3.start();
                zoomInCamera__7stMeleeFv(self);
                if (self->kind == 7) {
                    setEnableCollisionStatus__6GroundFb(self->getGround(9), true);
                }
                if (self->kind == 4 && self->trigger != 0) {
                    setAreaSleep__9stTriggerFb(self->trigger, false);
                }
            }
            vP3.m_y = self->timer1;
            vP3.m_x = rd[1];
            vP3.m_z = rd[1];
            setScale__9grGimmickFP5Vec3f(self->getGround(self->kind), &vP3);
            setScale__9grGimmickFP5Vec3f(self->getGround(5), &vP3);
            setScale__9grGimmickFP5Vec3f(self->getGround(6), &vP3);
            setScale__9grGimmickFP5Vec3f(self->getGround(9), &vP3);
            setScale__9grGimmickFP5Vec3f(self->getGround(0xA), &vP3);
            setScale__9grGimmickFP5Vec3f(self->getGround(0xB), &vP3);
            if (self->fx[0] + 0x10000U != 0xFFFFU) setScl__5ecMgrFUlP5Vec3f(g_ecMgr, self->fx[0], &vP3);
            if (self->fx[2] + 0x10000U != 0xFFFFU) setScl__5ecMgrFUlP5Vec3f(g_ecMgr, self->fx[2], &vP3);
            if (self->fx[3] + 0x10000U != 0xFFFFU) setScl__5ecMgrFUlP5Vec3f(g_ecMgr, self->fx[3], &vP3);
            if (self->fx[4] + 0x10000U != 0xFFFFU) setScl__5ecMgrFUlP5Vec3f(g_ecMgr, self->fx[4], &vP3);
            break;
        case 4:
            if (self->e3.isReadyEnd() == true && !self->e4.isEvent()) {
                self->e7.end();
                self->flag615 = 0;
                ((Ground*)self->getGround(0))->setAnimation(0, 0, data + 0x54, 0, 0);
                setDisplay__15grStadiumVisionFb(self->getGround(0), false);
                self->e5.start();
                self->e6.start();
                self->e2.setPhase(self->e2.getPhase() + 1);
                self->flag6F8 = 1;
            }
            break;
        case 5:
            if (self->e6.isReadyEnd() == true) {
                self->e6.end();
                self->e3.end();
                self->e2.setPhase(self->e2.getPhase() + 1);
                setEffect__5ecMgrF4EfID(g_ecMgr, 0x5F0002);
                self->e4.start();
                playSeBasic__7stMeleeF5SndIDf(self, 0x1DC7, rd[0]);
                self->fx604 = -1;
                self->fx608 = -1;
                zoomOutCamera__7stMeleeFff(self, rd[15], rd[20]);
                if (self->kind == 7) {
                    setEnableCollisionStatus__6GroundFb(self->getGround(9), false);
                }
                if (self->kind == 4 && self->trigger != 0) {
                    setAreaSleep__9stTriggerFb(self->trigger, true);
                }
            }
            break;
        case 6:
            self->timer1 = self->timer1 - rd[21] * farg0;
            if (self->timer1 <= rd[0]) {
                self->timer1 = rd[22];
                self->e2.setPhase(self->e2.getPhase() + 1);
                endEntity__8grMadeinFv(self->getGround(self->kind));
                setEnableCollisionStatus__6GroundFb(self->getGround(self->kind), false);
                startEntityAutoLoop__8grMadeinFv(self->getGround(3));
                setEnableCollisionStatus__6GroundFb(self->getGround(3), true);
                if (self->kind == 2) {
                    endEntity__8grMadeinFv(self->getGround(0xB));
                }
                if (self->kind == 7) {
                    endEntity__8grMadeinFv(self->getGround(5));
                    endEntity__8grMadeinFv(self->getGround(6));
                    endEntity__8grMadeinFv(self->getGround(9));
                    endEntity__8grMadeinFv(self->getGround(0xA));
                }
                resourceResult = getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 2, 0x64, 0xFFFE);
                if (resourceResult != 0) {
                    t8 = resourceResult;
                    loadPositionData__11stPositionsFPQ34nw4r3g3d7ResFile(self->posData, &t8);
                }
                self->updateStagePositions();
                self->e2.m_manualFramesLeft = rd[0];
                vP6a.m_y = self->timer1;
                vP6a.m_x = rd[1];
                vP6a.m_z = rd[1];
                setScale__9grGimmickFP5Vec3f(self->getGround(3), &vP6a);
                if (self->fx[0] + 0x10000U != 0xFFFFU) endEffect__5ecMgrFUl(g_ecMgr, self->fx[0]);
                if (self->fx[1] + 0x10000U != 0xFFFFU) endEffect__5ecMgrFUl(g_ecMgr, self->fx[1]);
                if (self->fx[2] + 0x10000U != 0xFFFFU) endEffect__5ecMgrFUl(g_ecMgr, self->fx[2]);
                if (self->fx[3] + 0x10000U != 0xFFFFU) endEffect__5ecMgrFUl(g_ecMgr, self->fx[3]);
                if (self->fx[4] + 0x10000U != 0xFFFFU) endEffect__5ecMgrFUl(g_ecMgr, self->fx[4]);
                self->fx[0] = -1;
                self->fx[1] = -1;
                self->fx[2] = -1;
                self->fx[3] = -1;
                self->fx[4] = -1;
                zoomInCamera__7stMeleeFv(self);
            }
            vP6b.m_y = self->timer1;
            vP6b.m_x = rd[1];
            vP6b.m_z = rd[1];
            setScale__9grGimmickFP5Vec3f(self->getGround(self->kind), &vP6b);
            setScale__9grGimmickFP5Vec3f(self->getGround(5), &vP6b);
            setScale__9grGimmickFP5Vec3f(self->getGround(6), &vP6b);
            setScale__9grGimmickFP5Vec3f(self->getGround(9), &vP6b);
            setScale__9grGimmickFP5Vec3f(self->getGround(0xA), &vP6b);
            setScale__9grGimmickFP5Vec3f(self->getGround(0xB), &vP6b);
            if (self->fx[0] + 0x10000U != 0xFFFFU) setScl__5ecMgrFUlP5Vec3f(g_ecMgr, self->fx[0], &vP6b);
            if (self->fx[2] + 0x10000U != 0xFFFFU) setScl__5ecMgrFUlP5Vec3f(g_ecMgr, self->fx[2], &vP6b);
            if (self->fx[3] + 0x10000U != 0xFFFFU) setScl__5ecMgrFUlP5Vec3f(g_ecMgr, self->fx[3], &vP6b);
            if (self->fx[4] + 0x10000U != 0xFFFFU) setScl__5ecMgrFUlP5Vec3f(g_ecMgr, self->fx[4], &vP6b);
            break;
        case 7:
            self->e2.m_manualFramesLeft = self->e2.m_manualFramesLeft + farg0;
            if (self->e2.m_manualFramesLeft >= rd[23]) {
                self->timer1 = self->timer1 + rd[21] * farg0;
                if (self->timer1 >= rd[1]) {
                    self->timer1 = rd[1];
                    self->e2.end();
                    self->e1.end();
                    self->e1.start();
                }
            }
            vP7.m_y = self->timer1;
            vP7.m_x = rd[1];
            vP7.m_z = rd[1];
            setScale__9grGimmickFP5Vec3f(self->getGround(3), &vP7);
            break;
        }

        if (self->kind == 7) {
            rot.m_z = self->timer2;
            rot.m_x = rd[0];
            rot.m_y = rd[0];
            pos.m_x = rd[0];
            pos.m_y = rd[0];
            pos.m_z = rd[0];
            Stage* gk = self->getGround(self->kind);
            ((Ground*)gk)->getNodePosition(&pos, 0, data + 0x74);
            setPos__9grGimmickFP5Vec3f(self->getGround(5), &pos);
            gk = self->getGround(self->kind);
            ((Ground*)gk)->getNodePosition(&pos, 0, data + 0x80);
            setPos__9grGimmickFP5Vec3f(self->getGround(6), &pos);
            gk = self->getGround(self->kind);
            ((Ground*)gk)->getNodePosition(&pos, 0, data + 0x8C);
            setRot__9grGimmickFP5Vec3f(self->getGround(9), &rot);
            setPos__9grGimmickFP5Vec3f(self->getGround(9), &pos);
            self->timer2 = self->timer2 - rd[5];
        }
    }
}

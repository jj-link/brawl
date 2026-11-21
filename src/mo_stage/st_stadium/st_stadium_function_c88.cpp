
#pragma force_active on
#include <gr/gr_tengan_event.h>
#include <types.h>

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
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
    virtual void u48();
    virtual bool getNodePosition(Vec3f*, unsigned long, const char*);
    virtual void u50(); virtual void u51(); virtual void u52();
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
    virtual void getFighterStartPos();
    Ground* getGround(int);
    char pad40[0x50];
    void* positions;
    char pad94[8];
    float* params;
    char padA0[0x100];
    void* archive;
    char pad1A4[0x20];
    void* trigger;
    char pad1C8[0x14];
    grTenganEvent e1, e2, e3, e4, e5, e6, e7;
    char pad690[8];
    void* trigger1;
    void* trigger2;
    char pad6A0[9];
    u8 kind;
    char pad6AA[2];
    int state;
    float scale;
    int sound;
    u8 flag;
    char pad6B9[3];
    int sound1, sound2;
    char pad6C4[8];
    float pos1, pos2, pos3;
    float weight1, weight2, weight3;
    char pad6E4[4];
    grTenganEvent e8;
};
extern "C" {
extern const float lbl_59_rodata_0[];
extern const char lbl_59_data_0[];
extern void* g_ecMgr;
void endEntity__8grMadeinFv(void*);
void startEntity__8grMadeinFv(void*);
void startEntityAutoLoop__8grMadeinFv(void*);
bool isEndEntity__8grMadeinFv(void*);
void setMotion__8grMadeinFUl(void*, unsigned long);
void setEnableCollisionStatus__6GroundFb(void*, bool);
void setDisplay__15grStadiumVisionFb(void*, bool);
void setScale__9grGimmickFP5Vec3f(void*, Vec3f*);
void setPos__9grGimmickFP5Vec3f(void*, Vec3f*);
void setPos__9grGimmickFfff(void*, float, float, float);
void setRot__9grGimmickFP5Vec3f(void*, Vec3f*);
int playSeBasic__7stMeleeF5SndIDf(void*, int, float);
void stopSeBasic__7stMeleeFif(void*, int, float);
void zoomOutCamera__7stMeleeFff(void*, float, float);
void zoomInCamera__7stMeleeFv(void*);
void setGravityHalf__7stMeleeFv(void*);
void setGravityNormal__7stMeleeFv(void*);
void setAreaSleep__9stTriggerFb(void*, bool);
void setEffect__5ecMgrF4EfID(void*, int);
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, u16);
void loadPositionData__11stPositionsFPQ34nw4r3g3d7ResFile(void*, void*);
float randf__Fv();
unsigned long randi__Fl(long);
}

#define END(i) endEntity__8grMadeinFv(self->getGround(i))
#define AUTO(i) startEntityAutoLoop__8grMadeinFv(self->getGround(i))
#define START(i) startEntity__8grMadeinFv(self->getGround(i))
#define COLL(i,b) setEnableCollisionStatus__6GroundFb(self->getGround(i), b)
#define SCALE(i,v) setScale__9grGimmickFP5Vec3f(self->getGround(i), &v)
#define POS(i,v) setPos__9grGimmickFP5Vec3f(self->getGround(i), &v)
#define MOTION(i,n) setMotion__8grMadeinFUl(self->getGround(i), n)
#define PHASE() self->e2.setPhase(self->e2.getPhase()+1)
#define LOAD(n,t) { void* resource = getData__9gfArchiveF11ARCNodeTypeiUs(self->archive,2,n,0xfffe); if (resource) { t = resource; loadPositionData__11stPositionsFPQ34nw4r3g3d7ResFile(self->positions,&t); } }
#define RESET(b) self->e8.end(); self->state=0; self->getGround(0)->setAnimation(0,0,data+0x224,0,0); self->getGround(0)->setAnimation(0,0,data+0x234,0,0); setDisplay__15grStadiumVisionFb(self->getGround(0),false); self->e5.start(); self->e6.start(); PHASE(); self->flag=b
#define RANDSTART(i,n,add) { unsigned long r = randi__Fl(n); if (r >= (n)-1) r=(n)-1; MOTION(i,(u8)(r+(add))); START(i); }
#define RANDUPDATE(i,n,add) { Ground* g = self->getGround(i); if (g && isEndEntity__8grMadeinFv(g)) { unsigned long r = randi__Fl(n); if (r >= (n)-1) r=(n)-1; setMotion__8grMadeinFUl(g,(u8)(r+(add))); startEntity__8grMadeinFv(g); } }
#define SCALES(v) SCALE(self->kind,v); if(self->kind==10){ SCALE(11,v); SCALE(24,v); SCALE(25,v); } if(self->kind==12){ SCALE(26,v); }

extern "C" void fn_59_C88(Stage* self, float dt) {
    const char* data = lbl_59_data_0;
    const float* rd = lbl_59_rodata_0;
    float* params = self->params;
    Vec3f vInit, rot, vShrink, vGrow, vRestore, vShrink2, vGrow2;
    Vec3f p1,p2,p3, s1,s2,s3;
    void *t18,*t14,*t10,*tC,*t8;

    if (self->e2.isEvent()) {
        switch (self->e2.getPhase()) {
        case 0:
            if (!self->e4.isEvent()) {
                RESET(0);
                float f31;
                float f30;
                f30 = rd[14] + rd[15]*randf__Fv();
                f31 = rd[16] + rd[15]*randf__Fv();
                float f2 = rd[5] + rd[15]*randf__Fv();
                self->pos2=f31;
                self->pos3=f30;
                self->weight1=rd[17];
                self->pos1=f2;
                self->weight2=rd[17];
                self->weight3=rd[17];
            }
            break;
        case 1:
            if (self->e6.isReadyEnd() == 1) {
                self->e6.end();
                self->scale=rd[1];
                PHASE();
                setEffect__5ecMgrF4EfID(g_ecMgr,0x450001);
                self->e4.start();
                self->sound=playSeBasic__7stMeleeF5SndIDf(self,0x1c2e,rd[0]);
                zoomOutCamera__7stMeleeFff(self,rd[10],rd[18]);
            }
            break;
        case 2:
            float delta = rd[1]/params[15];
            delta *= dt;
            self->scale = self->scale - delta;
            if (self->scale <= rd[0]) {
                self->scale=rd[19];
                PHASE();
                END(8); END(9); COLL(8,false); COLL(9,false);
                AUTO(self->kind); COLL(self->kind,true);
                vInit.m_y=self->scale; vInit.m_x=rd[1]; vInit.m_z=rd[1];
                SCALE(self->kind,vInit);
                if(self->kind==10) { SCALE(11,vInit); SCALE(24,vInit); SCALE(25,vInit); COLL(25,true); }
                if(self->kind==12) { SCALE(26,vInit); COLL(26,true); }
                if(self->kind==10) { AUTO(11); AUTO(24); AUTO(25); }
                if(self->kind==12) { AUTO(26); }
                if(self->kind==14) setPos__9grGimmickFfff(self->getGround(14),rd[0],rd[20],rd[0]);
                switch(self->kind) {
                case 10:
                    self->e7.end(); self->e7.start();
                    playSeBasic__7stMeleeF5SndIDf(self,0x1c34,rd[0]);
                    MOTION(20,0); START(20);
                    RANDSTART(17,2,0);
                    break;
                case 12:
                    playSeBasic__7stMeleeF5SndIDf(self,0x1c32,rd[0]);
                    RANDSTART(22,3,0); RANDSTART(23,2,0);
                    break;
                case 13:
                    playSeBasic__7stMeleeF5SndIDf(self,0x1c30,rd[0]);
                    RANDSTART(21,3,0); RANDSTART(16,2,2);
                    break;
                case 14:
                    rot.m_x=rd[0]; rot.m_y=rd[14]; rot.m_z=rd[0];
                    self->sound1=playSeBasic__7stMeleeF5SndIDf(self,0x1c38,rd[0]);
                    setRot__9grGimmickFP5Vec3f(self->getGround(15),&rot);
                    AUTO(15); RANDSTART(18,2,0); AUTO(19);
                    break;
                }
                zoomInCamera__7stMeleeFv(self);
            }
            vShrink.m_y=self->scale; vShrink.m_x=rd[1]; vShrink.m_z=rd[1];
            SCALE(8,vShrink); SCALE(9,vShrink);
            break;
        case 3:
            float delta3 = rd[1]/params[15];
            delta3 *= dt;
            self->scale = self->scale + delta3;
            if (self->scale >= rd[1]) {
                self->scale=rd[1]; PHASE(); self->e3.start();
                switch(self->kind) {
                case 10:
                    self->sound1=playSeBasic__7stMeleeF5SndIDf(self,0x1c36,rd[0]);
                    self->sound2=playSeBasic__7stMeleeF5SndIDf(self,0x1c37,rd[0]);
                    setAreaSleep__9stTriggerFb(self->trigger1,false);
                    setAreaSleep__9stTriggerFb(self->trigger2,false);
                    playSeBasic__7stMeleeF5SndIDf(self,0x1c35,rd[0]);
                    LOAD(0x65,t18);
                    break;
                case 14:
                    setGravityHalf__7stMeleeFv(self);
                    setPos__9grGimmickFfff(self->getGround(14),rd[0],rd[0],rd[0]);
                    if(self->trigger) setAreaSleep__9stTriggerFb(self->trigger,false);
                    LOAD(0x68,t14);
                    break;
                case 13:
                    playSeBasic__7stMeleeF5SndIDf(self,0x1c31,rd[0]);
                    LOAD(0x67,t10);
                    break;
                case 12:
                    playSeBasic__7stMeleeF5SndIDf(self,0x1c33,rd[0]);
                    LOAD(0x66,tC);
                    break;
                }
                self->updateStagePositions();
            }
            vGrow.m_y=self->scale; vGrow.m_x=rd[1]; vGrow.m_z=rd[1];
            SCALES(vGrow);
            if(self->kind==14) setPos__9grGimmickFfff(self->getGround(14),rd[0],rd[20]+rd[21]*self->scale,rd[0]);
            break;
        case 4:
            self->weight1 += rd[22]; if(self->weight1 >= rd[1]) self->weight1=rd[1];
            if(rd[1]==self->weight1) { self->weight2 += rd[23]; if(self->weight2>=rd[1]) self->weight2=rd[1]; }
            if(rd[1]==self->weight2) { self->weight3 += rd[24]; if(self->weight3>=rd[1]) self->weight3=rd[1]; }
            switch(self->kind) {
            case 10: RANDUPDATE(20,2,0); RANDUPDATE(17,2,0); break;
            case 12: RANDUPDATE(22,3,0); RANDUPDATE(23,2,0); break;
            case 13: RANDUPDATE(21,3,0); RANDUPDATE(16,2,2); break;
            case 14: RANDUPDATE(18,2,0); break;
            }
            if(self->e3.isReadyEnd()==1 && !self->e4.isEvent() && rd[1]==self->weight1 && rd[1]==self->weight2 && rd[1]==self->weight3) { RESET(1); }
            break;
        case 5:
            self->weight3-=rd[22]; if(self->weight3<rd[17]) self->weight3=rd[17];
            if(rd[17]==self->weight3) { self->weight2-=rd[23]; if(self->weight2<rd[17]) self->weight2=rd[17]; }
            if(rd[17]==self->weight2) { self->weight1-=rd[24]; if(self->weight1<rd[17]) self->weight1=rd[17]; }
            if(self->e6.isReadyEnd()==1 && rd[17]==self->weight1 && rd[17]==self->weight2 && rd[17]==self->weight3) {
                self->e6.end(); self->e3.end(); PHASE();
                setEffect__5ecMgrF4EfID(g_ecMgr,0x450001); self->e4.start();
                self->sound=playSeBasic__7stMeleeF5SndIDf(self,0x1c2e,rd[0]);
                stopSeBasic__7stMeleeFif(self,self->sound1,rd[25]);
                stopSeBasic__7stMeleeFif(self,self->sound2,rd[25]);
                self->sound1=-1; self->sound2=-1;
                zoomOutCamera__7stMeleeFff(self,rd[10],rd[18]);
                setGravityNormal__7stMeleeFv(self);
            }
            break;
        case 6:
            float delta6 = rd[1]/params[15];
            delta6 *= dt;
            self->scale=self->scale-delta6;
            if(self->scale<=rd[0]) {
                self->scale=rd[19]; PHASE();
                END(self->kind); COLL(self->kind,false);
                if(self->trigger) setAreaSleep__9stTriggerFb(self->trigger,true);
                if(self->kind==10) { setAreaSleep__9stTriggerFb(self->trigger1,true); setAreaSleep__9stTriggerFb(self->trigger2,true); }
                if(self->kind==10) { END(11); END(24); END(25); COLL(25,false); }
                if(self->kind==12) { END(26); COLL(26,false); }
                AUTO(8); AUTO(9); COLL(8,true); COLL(9,true);
                vRestore.m_y=self->scale; vRestore.m_x=rd[1]; vRestore.m_z=rd[1];
                SCALE(8,vRestore); SCALE(9,vRestore);
                END(15); END(16); END(17); END(18); END(19); END(20); END(21); END(22); END(23);
                zoomInCamera__7stMeleeFv(self);
            }
            vShrink2.m_y=self->scale; vShrink2.m_x=rd[1]; vShrink2.m_z=rd[1];
            SCALES(vShrink2);
            break;
        case 7:
            float delta7 = rd[1]/params[15];
            delta7 *= dt;
            self->scale=self->scale+delta7;
            if(self->scale>=rd[1]) {
                self->scale=rd[1];
                self->e2.end(); self->e1.end(); self->e1.start();
                playSeBasic__7stMeleeF5SndIDf(self,0x1c2f,rd[0]);
                LOAD(0x64,t8);
                self->updateStagePositions();
            }
            vGrow2.m_y=self->scale; vGrow2.m_x=rd[1]; vGrow2.m_z=rd[1];
            SCALE(8,vGrow2); SCALE(9,vGrow2);
            break;
        }
        switch(self->kind) {
        case 10:
            s1.m_x=rd[26]*self->weight1; s1.m_y=s1.m_x; s1.m_z=s1.m_x;
            s2.m_x=rd[27]*self->weight2; s2.m_y=s2.m_x; s2.m_z=s2.m_x;
            self->getGround(self->kind)->getNodePosition(&p1,0,data+0x24c);
            self->getGround(self->kind)->getNodePosition(&p2,0,data+0x258);
            POS(20,p1); POS(17,p2); SCALE(20,s1); SCALE(17,s2);
            break;
        case 12:
            s1.m_x=rd[27]*self->weight1; s1.m_y=s1.m_x; s1.m_z=s1.m_x;
            s2.m_x=rd[28]*self->weight2; s2.m_y=s2.m_x; s2.m_z=s2.m_x;
            self->getGround(self->kind)->getNodePosition(&p1,0,data+0x264);
            self->getGround(self->kind)->getNodePosition(&p2,0,data+0x270);
            POS(22,p1); POS(23,p2); SCALE(22,s1); SCALE(23,s2);
            break;
        case 13:
            s1.m_x=rd[29]*self->weight1; s1.m_y=s1.m_x; s1.m_z=s1.m_x;
            s2.m_x=rd[28]*self->weight2; s2.m_y=s2.m_x; s2.m_z=s2.m_x;
            self->getGround(self->kind)->getNodePosition(&p1,0,data+0x280);
            self->getGround(self->kind)->getNodePosition(&p2,0,data+0x28c);
            POS(21,p1); POS(16,p2); SCALE(21,s1); SCALE(16,s2);
            break;
        case 14:
            s1.m_x=rd[28]*self->weight1; s1.m_y=s1.m_x; s1.m_z=s1.m_x;
            s2.m_x=rd[30]*self->weight2; s2.m_y=s2.m_x; s2.m_z=s2.m_x;
            s3.m_x=rd[31]*self->weight3; s3.m_y=s3.m_x; s3.m_z=s3.m_x;
            self->getGround(self->kind)->getNodePosition(&p1,0,data+0x298);
            self->getGround(self->kind)->getNodePosition(&p2,0,data+0x2a0);
            self->getGround(self->kind)->getNodePosition(&p3,0,data+0x2ac);
            p1.m_y=self->pos1; p2.m_y=self->pos2; p3.m_y=self->pos3;
            POS(15,p1); POS(18,p2); POS(19,p3); SCALE(15,s1); SCALE(18,s2); SCALE(19,s3);
            break;
        }
    }
}

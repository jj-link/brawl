#pragma force_active on
#pragma fp_contract off
#include <mt/mt_vector.h>
#include <nw4r/g3d/g3d_resfile.h>

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
    virtual void slot31();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_66_2D00();
    virtual void startup();
    virtual void slot38();
    virtual void fn_66_6BC();
    virtual void fn_66_2CF8();
    virtual void fn_66_2CF4();
    virtual void fn_66_2BF4();
    virtual void fn_66_2CEC();
    virtual void fn_66_2CE0();
    virtual void fn_66_2CD0();
    virtual void fn_66_BBC();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual void getNodeMatrix();
    virtual void getNodeMatrix_2();
    virtual void setNodeVisibility();
    virtual void setNodeVisibility_2();
    virtual void setNodeVisibilityAll();
    virtual void isNodeVisible();
    virtual void setNodeCollision();
    virtual void setNodeCollision_2();
    virtual void getNodeScale();
    virtual void getNodeScale_2();
    virtual void setValid();
    virtual void setValidAttachedEffect();
    virtual void fn_66_2CCC();
    virtual void fn_66_2CC8();
    virtual void fn_66_2CC0();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_66_2CB8();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_66_2D2C();
    virtual void fn_66_2D24();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_66_2D1C();
    virtual void slot90();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void slot93();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit();
    virtual void disableHit();
    virtual void disableAttack();
    virtual void enableArea();
    virtual void disableArea();
    virtual void setSleepArea();
    virtual void setTeamYakumonoOwnerId();
    virtual void setTeamYakumono();
    virtual void getTeamYakumono();
    virtual void setOffsetAttack();
    virtual void setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual bool slot115();
    virtual void slot116();
    virtual void slot117(int);
    virtual void slot118(int);
};

struct Parameters {
    char pad[0xb4];
    float b4, b8, bc, c0, c4, c8;
    char padcc[8];
    float d4, d8;
};
struct Stage {
    char pad0[0x9c];
    Parameters* params;
    char pada0[0x100];
    void* archive;
    char pad1a4[0x87];
    unsigned char state;
    float timer;
    unsigned char anim;
    char pad231[3];
    float timer2;
    unsigned char flag;
    unsigned char active;
    char pad23a[6];
    unsigned long effect0, effect1, effect2, effect3;
    int sound;
};

extern "C" {
extern const float lbl_66_rodata_0;
extern void* g_sndSystem;
extern void* g_ecMgr;
Ground* getGround__5StageFi(Stage*, int);
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, unsigned short);
void registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(Stage*, void*, unsigned long);
int fn_8018E588(void*);
void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
void fn_80075F1C(void*, int, int);
int playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
float randf__Fv();
void endEffect__5ecMgrFUl(void*, unsigned long);
unsigned long setEffect__5ecMgrF4EfIDP5Vec3f(void*, int, Vec3f*);
}

extern "C" void fn_66_181C(Stage* self, float delta) {
    Ground* ground = getGround__5StageFi(self, 1);
    if (!ground) return;
    Parameters* p = self->params;
    if (!p) return;
    self->timer -= delta;
    if (self->timer < lbl_66_rodata_0) self->timer = lbl_66_rodata_0;
    self->timer2 -= delta;
    if (self->timer2 < lbl_66_rodata_0) self->timer2 = lbl_66_rodata_0;
    switch (self->state) {
    case 5:
        if (ground->slot115()) {
            self->anim = 3;
            registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(self, getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 5, 0, 0xfffe), self->anim);
            ground->slot112();
            void* file = getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 5, 0, 0xfffe);
            if (file && fn_8018E588(&file)) {
                void* anm = GetResAnmScn__Q34nw4r3g3d7ResFileFi(&file, self->anim);
                float frames = (int)*(unsigned short*)((char*)anm + 0x30);
                self->timer2 = lbl_66_rodata_0;
                self->timer = frames;
            }
            if (self->flag != 1) {
                if (self->sound >= 0) fn_80075F1C(g_sndSystem, self->sound, 60);
                self->sound = playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1cd9, 0, 60, 0, -1);
            }
            self->state = 0;
        }
        break;
    case 0:
        if (lbl_66_rodata_0 == self->timer) {
            self->anim = 0;
            registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(self, getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 5, 0, 0xfffe), self->anim);
            if (self->flag == 1) {
                float r = randf__Fv();
                float high = p->b8;
                float low = p->b4;
                float diff = high - low;
                self->flag = 0;
                self->timer = low + diff * r;
            } else {
                self->timer = p->bc + (p->c0 - p->bc) * randf__Fv();
            }
            Ground* other = getGround__5StageFi(self, 3);
            if (!other) return;
            other->slot117(0);
            other->slot118(4);
            self->state = 1;
        }
        if (lbl_66_rodata_0 == self->timer2 && self->active == 1) {
            Ground* other = getGround__5StageFi(self, 8);
            if (other) other->slot113();
            self->active = 0;
            endEffect__5ecMgrFUl(g_ecMgr, self->effect0);
            endEffect__5ecMgrFUl(g_ecMgr, self->effect1);
            endEffect__5ecMgrFUl(g_ecMgr, self->effect2);
            endEffect__5ecMgrFUl(g_ecMgr, self->effect3);
        }
        break;
    case 1:
        if (lbl_66_rodata_0 == self->timer) {
            if (p->c4 > randf__Fv()) self->state = 2;
            else {
                float r = randf__Fv();
                float high = p->c0;
                float low = p->bc;
                float diff = high - low;
                self->state = 0;
                self->timer = low + diff * r;
            }
        }
        break;
    case 2:
        if (ground->slot115()) {
            self->anim = 1;
            registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(self, getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 5, 0, 0xfffe), self->anim);
            ground->slot113();
            void* file = getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 5, 0, 0xfffe);
            if (file && fn_8018E588(&file)) {
                void* anm = GetResAnmScn__Q34nw4r3g3d7ResFileFi(&file, self->anim);
                self->timer = (int)*(unsigned short*)((char*)anm + 0x30);
            }
            self->timer2 = p->c8;
            self->active = 0;
            self->sound = playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1cd7, 0, 0, 0, -1);
            self->state = 3;
        }
        break;
    case 3:
        if (lbl_66_rodata_0 == self->timer) {
            self->anim = 2;
            registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(self, getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 5, 0, 0xfffe), self->anim);
            self->timer = p->d4 + (p->d8 - p->d4) * randf__Fv();
            if (self->sound >= 0) fn_80075F1C(g_sndSystem, self->sound, 60);
            self->sound = playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1cd8, 0, 60, 0, -1);
            Vec3f pos1(lbl_66_rodata_0, lbl_66_rodata_0, lbl_66_rodata_0);
            self->effect0 = setEffect__5ecMgrF4EfIDP5Vec3f(g_ecMgr, 0x4e0001, &pos1);
            Vec3f pos2(lbl_66_rodata_0, lbl_66_rodata_0, lbl_66_rodata_0);
            self->effect1 = setEffect__5ecMgrF4EfIDP5Vec3f(g_ecMgr, 0x4e0002, &pos2);
            Ground* other = getGround__5StageFi(self, 3);
            if (!other) return;
            other->slot117(1);
            other->slot118(30);
            self->state = 4;
        }
        break;
    case 4:
        if (lbl_66_rodata_0 == self->timer) self->state = 5;
        if (lbl_66_rodata_0 == self->timer2 && self->active == 0) {
            Ground* other = getGround__5StageFi(self, 8);
            if (other) {
                other->slot112();
                self->active = 1;
            }
        }
        break;
    }
}

#pragma force_active on
#include <nw4r/g3d/g3d_scnmdlsmpl.h>

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
    virtual void fn_81_570();
    virtual void fn_81_620();
    virtual void createObjPokeTrainer();
    virtual void fn_81_4050();
    virtual void fn_81_404C();
    virtual void fn_81_4040();
    virtual void fn_81_4038();
    virtual void fn_81_4030();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_81_618();
    virtual void process();
    virtual void updateStagePositions();
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
    virtual void fn_81_69C8();
    virtual void fn_81_6A20();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_81_787C();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void getModelCount();
    virtual void startup();
    virtual void setNode();
    virtual void setStageData();
    virtual void* getStageData();
};

extern "C" void fn_81_7688(Ground* self, float dt) {
    unsigned char* sb = (unsigned char*)self;
    if (*(void**)(sb + 0x178) != 0) {
        unsigned char* p = sb + 0xd0;
        if (p != 0) {
            unsigned char* a = *(unsigned char**)(sb + 0x44);
            nw4r::g3d::ScnMdlSimple* m = *(nw4r::g3d::ScnMdlSimple**)a;
            if (m != 0) {
                if (*(unsigned int*)((unsigned char*)m + 0x11c) == 0) {
                    *(unsigned int*)(p + 0xc) = 0;
                    unsigned int* q = *(unsigned int**)(p + 4);
                    *q = *(unsigned int*)(sb + 0xc4);
                    *(unsigned char**)((unsigned char*)m + 0x11c) = p;
                    m->EnableScnMdlCallbackTiming(1);
                    q = *(unsigned int**)(p + 4);
                    *(unsigned short*)((unsigned char*)m + 0x122) = (unsigned short)*q;
                }
                unsigned char* sc = (unsigned char*)self->getStageData();
                if (sc != 0) {
                    unsigned char* s = *(unsigned char**)(sb + 0x178) +
                        (*(unsigned char**)(sb + 0x174))[sb[0x16c]] * 0x3c;
                    float v[3];
                    v[0] = *(float*)(s + 4);
                    v[1] = *(float*)(s + 8);
                    v[2] = *(float*)(s + 12);
                    if (*(float*)(sb + 0x168) > *(float*)(sc + 0x4c))
                        v[1] -= *(float*)(sc + 0x4c);
                    else
                        v[1] -= *(float*)(sb + 0x168);
                    float* d = *(float**)(p + 4);
                    d[2] = v[0];
                    d[3] = v[1];
                    d[4] = v[2];
                    d = *(float**)(p + 4);
                    float w[3];
                    w[0] = d[5];
                    w[1] = d[6];
                    w[2] = d[7];
                    float delta = *(float*)(s + 0x24) - w[2];
                    float speed;
                    if (s[0x30] == 1)
                        speed = *(float*)(sc + 0x54);
                    else
                        speed = *(float*)(sc + 0x50);
                    speed *= dt;
                    w[2] += delta * speed;
                    d[5] = w[0];
                    d[6] = w[1];
                    d[7] = w[2];
                }
            }
        }
    }
}

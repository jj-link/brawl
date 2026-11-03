#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);
}

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
    virtual void* updateStagePositions();
};

extern "C" void fn_81_5598(Stage* self) {
    u8* sb = (u8*)self;
    u8* p = sb + 0xD0;
    if (p != 0) {
        u8* a = *(u8**)(sb + 0x44);
        u8* m = *(u8**)a;
        if (m != 0) {
            if (*(u32*)(m + 0x11c) == 0) {
                *(u32*)(p + 0xc) = 0;
                u32* q = *(u32**)(p + 4);
                *q = *(u32*)(sb + 0xc4);
                *(u8**)(m + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                q = *(u32**)(p + 4);
                *(u16*)(m + 0x122) = (u16)*q;
            }
            if (*(u8**)(sb + 0x164) != 0) {
                void* sc = self->updateStagePositions();
                if (sc != 0) {
                    float* s = *(float**)(sb + 0x164);
                    float* d = *(float**)(p + 4);
                    float v[3];
                    v[0] = d[5];
                    v[1] = d[6];
                    v[2] = d[7];
                    float f1 = s[9] + *(float*)(sb + 0x170);
                    float f6 = *(float*)((u8*)sc + 0x9c);
                    d[2] = s[1];
                    f1 = f1 - v[2];
                    f1 = f1 * f6;
                    d[3] = s[2];
                    f1 = v[2] + f1;
                    d[4] = s[3];
                    v[2] = f1;
                    d = *(float**)(p + 4);
                    d[5] = v[0];
                    d[6] = v[1];
                    d[7] = f1;
                }
            }
        }
    }
}

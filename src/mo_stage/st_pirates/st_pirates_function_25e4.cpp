#pragma force_active on

extern "C" float randf__Fv();
extern const float lbl_52_rodata_0;
extern void* g_GameGlobal;

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
    virtual void fn_52_218();
    virtual void fn_52_2B0();
    virtual void createObjPokeTrainer();
    virtual void fn_52_34A0();
    virtual void fn_52_349C();
    virtual void fn_52_3490();
    virtual void fn_52_3488();
    virtual void fn_52_3480();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_52_2A8();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_52_3478();
    virtual void fn_52_3470();
    virtual void getZoneLightSetIndex();
    virtual void fn_52_3454();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_52_3450();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_52_34A8();
    virtual void getPokeTrainerStartPos();
    virtual void getItemPosCount();
    virtual void getItemPos();
    virtual void getRandItemPos();
    virtual void getKirifudaPos();
    virtual void getKirifudaAngle();
    virtual void getKirifudaScale();
    virtual void getKirifudaModelType();
    virtual void getPokeTrainerPosCount();
    virtual void getPokeTrainerPos();
    virtual void getFighterDeadEffectSizeRate();
    virtual void getEnemyDeadEffectSizeRate();
    virtual void getEnableZ();
    virtual void fn_52_3440();
    virtual void fn_52_3448();
    virtual void fn_52_3438();
    virtual void fn_52_3430();
    virtual void fn_52_3428();
    virtual void fn_52_3414();
    virtual void fn_52_3404();
    virtual void fn_52_33F8();
    virtual void fn_52_33EC();
    virtual void fn_52_33E4();
    virtual void fn_52_33DC();
    virtual float fn_52_2810();
};

struct PirateData {
    char pad[0x48];
    float w0;
    float w1;
    float w2;
    float w3;
    float scale;
    float limit;
};

class StPirates : public Stage {
public:
    char pad1[0x5c];
    PirateData* data;
    char pad2[0x55d - 0xa0];
    unsigned char state;
    char pad3[0x569 - 0x55e];
    unsigned char mode;
    char pad4[0x608 - 0x56a];
    unsigned char flag;
};

#pragma opt_lifetimes off

extern "C" void fn_52_25E4(StPirates* self) {
    PirateData* obj = self->data;
    if (obj != 0) {
        if (self->flag == 1) {
            self->state = 7;
            return;
        }
        unsigned char* gg = *(unsigned char**)((char*)g_GameGlobal + 8);
        if (gg != 0) {
            unsigned int hit = 0;
            switch ((((unsigned char)gg[9] >> 5) & 7)) {
            case 0:
                if (lbl_52_rodata_0 != self->fn_52_2810() && self->fn_52_2810() < obj->limit) {
                    hit = 1;
                }
                break;
            }
            if (hit == 1) {
                self->state = 3;
                return;
            }
            float a = obj->w0;
            float b = obj->w1;
            float c = obj->w2;
            float d = obj->w3;
            switch (self->mode) {
            case 1:
                a *= obj->scale;
                break;
            case 2:
                a *= obj->scale;
                break;
            case 3:
                a *= obj->scale;
                break;
            case 6:
                b *= obj->scale;
                break;
            case 7:
                c *= obj->scale;
                break;
            case 9:
                d *= obj->scale;
                break;
            }
            float sum = a + b + c + d;
            a = a / sum;
            b = b / sum;
            c = c / sum;
            d = d / sum;
            float r = randf__Fv();
            if (r < d) {
                self->state = 0xc;
                return;
            }
            if (r < (c + d)) {
                self->state = 0xa;
                return;
            }
            if (r < (d + (b + c))) {
                self->state = 7;
                return;
            }
            if (r < (d + (c + (a + b)))) {
                self->mode = 4;
                self->state = 3;
                return;
            }
            self->state = 0;
        }
    }
}

#pragma opt_lifetimes reset

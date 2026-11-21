#include <types.h>
#include <gf/gf_application.h>
#include <ef/ef_screen.h>
#pragma force_active on
extern "C" void* memset(void*, int, int);
extern "C" void* g_ftManager;
struct Entry { int key; unsigned int cmp; int val; };
struct StageObj {
    char pad[0x528]; unsigned int f528;
    char pad2[0x603 - 0x52c]; unsigned char f603, f604, f605;
    char pad3[0x62c - 0x606]; int f62c; char f630[0x20];
};
struct ModePtr { char pad[0x4c]; int mode; };
struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_40_2024();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void fn_40_21B8();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void fn_40_222C();
    virtual void renderPre();
    virtual void fn_40_8A84();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_40_12F8();
    virtual void fn_40_D24();
    virtual void createObjPokeTrainer();
    virtual void fn_40_5098();
    virtual void fn_40_50A0();
    virtual void fn_40_50BC();
    virtual void fn_40_8B18();
    virtual void fn_40_8B28();
    virtual void fn_40_7D94();
    virtual void fn_40_8154();
    virtual void fn_40_80AC();
    virtual void fn_40_8160();
    virtual void fn_40_8478();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_40_45C();
    virtual void process();
    virtual void fn_40_7D44();
    virtual void debugCollision();
    virtual void fn_40_6FF4();
    virtual void fn_40_8B10();
    virtual void getZoneLightSetIndex();
    virtual void fn_40_8AF4();
    virtual void clearCameraParam();
    virtual void fn_40_6C6C();
    virtual void fn_40_464();
    virtual void fn_40_5EC();
    virtual void fn_40_990();
    virtual void fn_40_A7C();
    virtual void fn_40_B98();
    virtual void fn_40_5FD8();
    virtual void fn_40_6050();
    virtual void isReStartSamePoint();
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
    virtual void fn_40_7034();
    virtual void fn_40_70B4();
    virtual void getEnableZ();
    virtual void fn_40_8AEC();
    virtual void fn_40_76F8();
    virtual void fn_40_76E0();
    virtual void fn_40_8AE4();
    virtual void fn_40_8ADC();
    virtual void fn_40_8AC8();
    virtual void fn_40_8AB8();
    virtual void fn_40_774C();
    virtual void fn_40_77DC();
    virtual void fn_40_783C();
    virtual void fn_40_8AB0();
    virtual void fn_40_8AA8();
    virtual void fn_40_7A94();
    virtual void isEnd();
    virtual void isEventEnd();
    virtual void enableDevil();
    virtual void disableDevil();
    virtual void isDevil();
    virtual void setDevilScrool();
    virtual void getLucarioFinalTechniquePosition();
    virtual void startAppear();
    virtual void setAppearKind();
    virtual void endAppear();
    virtual void getAppearTask();
    virtual void forceStopAppear();
    virtual void getFinalTechniqColor();
    virtual void setMotionRatio();
    virtual void saveMotionRatio();
    virtual void restoreMotionRatio();
    virtual void setMotionSubRatio();
    virtual void saveMotionSubRatio();
    virtual void restoreMotionSubRatio();
    virtual void fn_40_7134();
    virtual void fn_40_71A0();
    virtual void fn_40_71C4();
    virtual void isAppear();
    virtual void isStartAppearTimming();
    virtual void getMadeinAiData();
    virtual void fn_40_8B20();
    virtual void getBamperVector();
    virtual void notifyEventInfoReady();
    virtual void notifyEventInfoGo();
    virtual void fn_40_7848();
    virtual void fn_40_7BB0();
    virtual void fn_40_8510(int);
};
struct Self {
    char pad0[0x44]; StageObj* stage; ModePtr* modePtr;
    char pad4c[0xbc - 0x4c]; int fbc; unsigned char c0, c1;
    char padc2[0xc8 - 0xc2]; int c8; char padcc[0xd1 - 0xcc]; unsigned char d1;
};
extern "C" void fn_40_193AC(Self*, int, int);
extern "C" void fn_27_109F90(char*);
extern "C" Stage* lbl_27_bss_5668;
extern "C" StageObj* lbl_40_bss_15C;
extern "C" const Entry lbl_40_data_3750[4];
extern "C" const float lbl_40_rodata_268;
extern "C" const GXColor lbl_40_rodata_26C;
inline bool same(unsigned int a, unsigned int b) { return a == b; }
inline void helper(Self* self, int mode) {
    switch (mode) {
    case 1:
        fn_40_193AC(self, 1, 0);
        return;
    case 2:
        fn_40_193AC(self, 0, 0);
        self->stage->f603 = 8;
        self->stage->f62c = 0;
        memset(&self->stage->f630, 0, 0x20);
        self->stage->f605 = 4;
        if (g_ftManager != 0) fn_27_109F90((char*)g_ftManager);
        return;
    case 7:
        if (self->fbc == 3) {
            fn_40_193AC(self, 1, 0);
            self->fbc = 0;
        }
        return;
    case 6:
        fn_40_193AC(self, 0, 1);
        self->c1 = 1;
        g_gfApplication->unkD0.startKeepScreen();
        return;
    case 8: case 9: case 10: case 11:
        fn_40_193AC(self, 0, 0);
        const Entry* table = lbl_40_data_3750;
        for (int i = 0; i < 4; ++i) {
            if (mode == table[i].key) {
                if (same(table[i].cmp, lbl_40_bss_15C->f528)) {
                    self->d1 = 1;
                    return;
                }
                self->c8 = table[i].val;
            }
        }
        {
            GXColor color = lbl_40_rodata_26C;
            g_efScreen->requestFill(lbl_40_rodata_268, 7, 0, &color);
        }
        if (lbl_27_bss_5668 != 0) lbl_27_bss_5668->fn_40_8510(1);
        self->c0 = 1;
        break;
    }
}
extern "C" void fn_40_17CC8(Self* self) { helper(self, self->modePtr->mode); }

#include <types.h>
#include <ad/ad_static_data.h>
#include <cm/cm_camera_controller.h>
#include <gf/gf_archive.h>
#include <st/st_data_container.h>
#include <st/st_trigger.h>
#pragma force_active on

struct CameraParams {
    char pad00[0x20];
    float value20;
    float value24;
    unsigned char value28;
    char pad29[3];
    unsigned short value2c;
    unsigned short value2e;
    float value30;
};

struct CameraTarget {
    char pad00[0x12];
    unsigned short value12;
    unsigned short value14;
    char pad16[0xf2];
    float value108;
    unsigned long value10c;
};

struct AdventureState {
    char pad00[0x604];
    unsigned char mode;
    char pad605[0xcb];
    unsigned char flags[1];
};

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
    virtual void fn_40_8510();
    virtual void fn_40_8640();
    virtual void fn_40_5AA4();
    virtual void fn_40_8680();
    virtual void fn_40_873C();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void fn_40_8AA0();
    virtual void fn_40_8A98();
    virtual void fn_40_8A94();
    virtual void setVision();
    virtual unsigned long long fn_40_7960();

    char pad40[0x50];
    void* value90;
    char pad94[0x10c];
    gfArchive* archive1a0;
    char pad1a4[0xc];
    gfArchive* archive1b0;
    char pad1b4[0xc];
    unsigned char* value1c0;
    char pad1c4[4];
    CameraParams* cameraParams;
    char pad1cc[0x34c];
    void* value518;
    char pad51c[8];
    AdventureState* state;
    unsigned long step;
    char pad52c[0x2c];
    stDataMultiContainer* container;
};

extern "C" {
void fn_40_2260(Stage*);
void fn_40_6B4C(Stage*);
void fn_800A59D0(CameraTarget*, const float*);
void fn_800A59DC(CameraTarget*, const float*);
int registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(Stage*, void*, unsigned long);
void loadStageAttrParam__5StageFP9gfArchivei(Stage*, gfArchive*, int);
void fn_27_223824(Stage*, gfArchive*, int, unsigned char);
void fn_27_222990(Stage*, void*, int);
void fn_40_33E4(Stage*, void*, unsigned long);
void fn_40_16DE4();
void fn_40_152CC(void*);
void fn_40_152F4(void*, void*, unsigned short, unsigned short);
void fn_40_1530C(void*);
void OSReport(const char*, ...);

extern char lbl_40_data_10[];
extern unsigned char lbl_40_bss_8[];
extern const float lbl_40_rodata_0[];
extern void* g_GameGlobal;
}

#define SET_STEP_FLAG(stepValue)                                            \
    do {                                                                    \
        int stepIndex = adventureStaticData::getStepIndex(stepValue);        \
        if (stepIndex >= 0)                                                 \
            self->state->flags[(unsigned int)stepIndex >> 3] |=              \
                1 << (stepIndex & 7);                                       \
    } while (0)

extern "C" void fn_40_D24(Stage* arg0) {
    Stage* self = arg0;
    const float* rd = lbl_40_rodata_0;
    fn_40_2260(self);
    self->fn_40_6C6C();

    CameraParams* params = self->cameraParams;
    unsigned long n;
    unsigned long i;
    stDataContainer* container;
    unsigned short lowHiWord;
    unsigned long cameraOrKind = (unsigned long)*(CameraTarget**)((char*)CameraController::getInstance() + 0x60);
    if (params && cameraOrKind) {
        fn_800A59D0((CameraTarget*)cameraOrKind, &params->value20);
        ((CameraTarget*)cameraOrKind)->value108 = params->value24;
        ((CameraTarget*)cameraOrKind)->value10c = params->value28;
        fn_800A59DC((CameraTarget*)cameraOrKind, &params->value30);
        unsigned short value2e = params->value2e;
        ((CameraTarget*)cameraOrKind)->value14 = params->value2c;
        ((CameraTarget*)cameraOrKind)->value12 = value2e;
    }

    fn_40_6B4C(self);
    if (!registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(
            self, self->archive1a0->getData(Data_Type_Scene, 0, 0xfffe), 0)) {
        OSReport(lbl_40_data_10);
        registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(
            self, self->archive1b0->getData(Data_Type_Scene, 0, 0xfffe), 0);
    }
    loadStageAttrParam__5StageFP9gfArchivei(self, self->archive1b0, 0);

    unsigned char choice;
    if (self->value1c0) {
        unsigned char* game = *(unsigned char**)((char*)g_GameGlobal + 0x30);
        int current = game[0x5fd];
        int low = current - 5;
        int index = current - game[0x4916];
        if (index < low)
            index = low;
        if (index < 0)
            index = 0;
        if (index > 14)
            index = 14;
        choice = ((unsigned char*)self->value1c0 + (unsigned char)index)[0x8f];
    } else {
        choice = 1;
    }
    fn_27_223824(self, self->archive1a0, 5, choice);

    SET_STEP_FLAG(self->step);

    if (self->step == 0x10000100)
        SET_STEP_FLAG(0x10000200);
    else if (self->step == 0x10000200)
        SET_STEP_FLAG(0x10000100);
    else if (self->step == 0x10010100)
        SET_STEP_FLAG(0x10010200);
    else if (self->step == 0x10010200)
        SET_STEP_FLAG(0x10010100);
    else if (self->step == 0x08010302)
        SET_STEP_FLAG(0x08010301);
    else if (self->step == 0x08010402)
        SET_STEP_FLAG(0x08010401);

    if (g_stTriggerMng) {
        struct TriggerInit { short a; unsigned char b; unsigned char c; } t;
        t.a = 1000;
        t.b = 0;
        t.c = 0;
        g_stTriggerMng->createTrigger((Gimmick::AreaKind)0, (stTriggerData*)&t);
        g_stTriggerMng->setTriggerFlag((stTriggerData*)&t);
    }

    if (self->state->mode == 3) {
        stDataContainerData* data = (stDataContainerData*)
            self->archive1a0->getData(Data_Type_Misc, 7, 0xfffe);
        if (data)
            self->container = stDataMultiContainer::create(data, (HeapType)15);

        stDataMultiContainer* multi = self->container;
        if (multi) {
            if (g_BlocMagic.data == multi->m_filedata->m_MAGIC) {
                container = (stDataContainer*)*(unsigned long*)(lbl_40_bss_8 + 0x28);
                n = 0;
                while ((cameraOrKind = (unsigned long)multi->searchContainer((unsigned long)container, n++)) != 0) {
                    for (i = 0; i < ((stDataContainer*)cameraOrKind)->m_filedata->m_numFiles; ++i)
                        fn_40_33E4(self, ((stDataContainer*)cameraOrKind)->getData(i), i);
                }
            }
            delete self->container;
            self->container = 0;
        }
    }

    void* texture = self->archive1b0->getData(Data_Type_Tex, 0, 0xfffe);
    if (texture)
        fn_27_222990(self, texture, 0);

    ((unsigned char*)g_gfSceneRoot)[0x464] |= 0x40;
    fn_40_16DE4();

    unsigned long long value = self->fn_40_7960();
    unsigned long hiWord = (unsigned long)(value >> 32);
    unsigned long loWord = (unsigned long)value;
    unsigned short h[4];
    lowHiWord = (unsigned short)hiWord;
    unsigned short highLoWord = (unsigned short)(loWord >> 16);
    h[0] = (unsigned short)(hiWord >> 16);
    h[2] = highLoWord;
    unsigned char kind = ((unsigned char*)h)[1];
    h[3] = (unsigned short)loWord;
    h[1] = lowHiWord;

    if (self->value518 && kind != 1) {
        fn_40_152CC(self->value518);
        fn_40_152F4(self->value518, self->value90, lowHiWord, highLoWord);
        if ((self->state && self->state->mode == 1) ||
            (self->state && self->state->mode == 2) ||
            (self->state && self->state->mode == 3))
            fn_40_1530C(self->value518);
    }

    if (self->state->mode == 1) {
        float f0;
        float f1;
        float f2;
        f2 = rd[20];
        f1 = rd[21];
        f0 = rd[11];
        struct TailTemps {
            float v48;
            float v1c;
            float v30;
            float v44;
        } tail;
        tail.v48 = f2;
        tail.v1c = f1;
        tail.v30 = f0;
        tail.v44 = f2;
        (void)tail;
    }
}

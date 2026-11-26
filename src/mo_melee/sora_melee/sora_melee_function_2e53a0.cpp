#include <types.h>
#include <so/event/so_event_system.h>
#include <so/collision/so_collision_search_event_presenter.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_7D128[];
extern char lbl_27_data_7D138[];
extern char lbl_27_data_7D470[];
extern char lbl_27_data_13730[];
extern char lbl_27_data_458C0[];
extern char lbl_27_data_7270[];
extern char lbl_27_data_4950[];
extern char lbl_27_bss_74E4[];
extern char __RTTI__11soEventUnit[];
extern char g_soParamAccesserNull[];
extern const float lbl_27_rodata_6428;
extern const float lbl_27_rodata_642C;
void fn_27_1DC5E8(void*, int, const void*, int, int, int, unsigned char, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_2E59EC(void*, void*, void*);
void fn_27_2E7828(void*, void*, void*);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_89544(void*, int);
void fn_27_1D8FC8(void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2();
    virtual void slot3(void*, int, short*, int);
    virtual int slot4();
    virtual int slot5();
    virtual s16 slot6(soCollisionSearchEventObserver*, s8);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28(void**, int);
};
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void processDefault();
    virtual void slot1();
    virtual void processAnim();
    virtual void slot3();
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
    virtual void createObjPokeTrainer();
    virtual void getPokeTrainerPointNum();
    virtual void getPokeTrainerPointData();
    virtual void getPokeTrainerPositionZ();
    virtual void getPokeTrainerDrawLayer();
    virtual void isAdventureStage();
    virtual void getItemPac();
    virtual void slot31();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void slot38();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void getAIRange();
    virtual void getDefaultLightSetIndex();
    virtual void getZoneLightSetIndex();
    virtual void getScrollDir();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void appearanceFighterLocal();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void getKirifudaPos();
    virtual void getKirifudaAngle();
    virtual void getKirifudaScale();
    virtual void getKirifudaModelType();
    virtual void getPokeTrainerPosCount();
    virtual void getPokeTrainerPos();
    virtual void getFighterDeadEffectSizeRate();
    virtual void getEnemyDeadEffectSizeRate();
    virtual void getEnableZ();
    virtual void slot69();
    virtual void getBgmID();
    virtual void getNowStepBgmID();
    virtual void getBgmOptionID();
    virtual void isBgmChange();
    virtual void getBgmChangeID();
    virtual void setBgmChange();
    virtual void getBgmVolume();
    virtual void getBgmPlayOffsetFrame();
    virtual void isNextStepBgmEqualNowStepBgmFromFlag();
    virtual void setFrameRuleTime();
    virtual void getFrameRuleTime();
    virtual void notifyTimmingGameStart();
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
    virtual void slot94();
    virtual void setMotionRatio();
    virtual void saveMotionRatio();
    virtual void restoreMotionRatio();
    virtual void setMotionSubRatio();
    virtual void saveMotionSubRatio();
    virtual void restoreMotionSubRatio();
    virtual void isCameraLocked();
    virtual void isBossBattleMode();
    virtual void isSimpleBossBattleMode();
    virtual void isAppear();
    virtual void isStartAppearTimming();
    virtual void getMadeinAiData();
    virtual void slot107();
    virtual void getBamperVector();
    virtual void slot109();
    virtual void slot110();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
    virtual void helperStarWarp();
    virtual void initializeFighterAttackRatio();
    virtual void startFighterEvent();
    virtual s32 getZoneState();
};
struct Arg2 { int pad; Object_vptr_0* heap; };
struct Build { int data[16]; };
struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };
struct ShortSlot { short n; short pad; };
struct FloatVec { float x; float y; float z; };
struct SearchShape {
    char* table;
    u8 kind;
    FlagByte flag;
    u8 group;
    FloatVec offset;
};
static inline Object_vptr_0* registry(char* object) {
    char* p = *(char**)(object + 0x60);
    p = *(char**)(p + 0xD8);
    return *(Object_vptr_0**)(p + 0x7C);
}

extern "C" void* fn_27_2E53A0(char* self, int arg1, Arg2* arg2, const int* arg3) {
    Build build;
    float tbl[15];
    void* process[2];
    ShortSlot k;
    ShortSlot m;
    ShortSlot n;
    int t22;
    int t23;
    Object_vptr_0* r24 = *(Object_vptr_0**)((char*)arg2 + 4);
    t23 = r24->slot5();
    t22 = r24->slot4();
    int t6 = r24->slot2();
    unsigned char id = *arg3 & 0xff;
    fn_27_1DC5E8(&build, 0x54, arg3, t6, t22, t23, id, -1,
                 g_soParamAccesserNull, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_7D128, build.data[1], build.data[2], arg1, arg2,
                 self + 0x5ac, 1);
    char* sub = self + 0xcc;
    *(char**)(self + 0x3c) = lbl_27_data_7D470;
    *(char**)(self + 0x40) = lbl_27_data_7D470 + 0x64;
    *(char**)(self + 0x48) = lbl_27_data_7D470 + 0x70;
    *(char**)(self + 0x54) = lbl_27_data_7D470 + 0x84;
    *(char**)(self + 0x64) = lbl_27_data_7D470 + 0xdc;
    *(char**)(self + 0x70) = lbl_27_data_7D470 + 0xec;
    *(char**)(self + 0x7c) = lbl_27_data_7D470 + 0x100;
    *(char**)(self + 0x88) = lbl_27_data_7D470 + 0x118;
    *(char**)(self + 0x90) = lbl_27_data_7D470 + 0x124;
    fn_27_2E59EC(sub, self, &build);
    fn_27_2E7828(sub + 0x15d4, sub + 0x4e0, &build);
    fn_27_1DBA64(self + 0x19f8);

    tbl[12] = lbl_27_rodata_6428;
    tbl[9] = lbl_27_rodata_642C;
    tbl[13] = lbl_27_rodata_6428;
    tbl[14] = lbl_27_rodata_6428;
    tbl[10] = lbl_27_rodata_642C;
    tbl[11] = lbl_27_rodata_642C;
    tbl[6] = lbl_27_rodata_6428;
    tbl[7] = lbl_27_rodata_6428;
    tbl[8] = lbl_27_rodata_6428;
    tbl[3] = lbl_27_rodata_642C;
    tbl[4] = lbl_27_rodata_642C;
    tbl[5] = lbl_27_rodata_642C;
    tbl[0] = lbl_27_rodata_642C;
    tbl[1] = lbl_27_rodata_642C;
    tbl[2] = lbl_27_rodata_642C;
    int* ti = (int*)tbl;
    self[0x1a34] = 0;
    ((FlagByte*)(self + 0x1a35))->flag = 1;
    self[0x1a36] = 0;
    *(char**)(self + 0x1a30) = lbl_27_data_13730;
    *(int*)(self + 0x1a38) = ti[0];
    *(int*)(self + 0x1a3c) = ti[1];
    *(int*)(self + 0x1a40) = ti[2];
    *(int*)(self + 0x1a44) = ti[3];
    *(int*)(self + 0x1a48) = ti[4];
    *(int*)(self + 0x1a4c) = ti[5];
    *(int*)(self + 0x1a50) = ti[6];
    *(int*)(self + 0x1a54) = ti[7];
    *(int*)(self + 0x1a58) = ti[8];
    *(int*)(self + 0x1a5c) = ti[9];
    *(int*)(self + 0x1a60) = ti[10];
    *(int*)(self + 0x1a64) = ti[11];
    *(int*)(self + 0x1a68) = ti[12];
    *(int*)(self + 0x1a6c) = ti[13];
    *(int*)(self + 0x1a70) = ti[14];
    fn_27_1D90FC(self);

    n.n = 1;
    ((Object_vptr_0*)*(void**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c))
        ->slot3(self + 0x19f8, 0, &n.n, -1);
    m.n = 1;
    ((Object_vptr_0*)*(void**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c))
        ->slot3(self + 0x1a30, 1, &m.n, -1);

    soCollisionSearchEventObserver* observer =
        reinterpret_cast<soCollisionSearchEventObserver*>(self + 0x1a74);
    observer->m_manageID = -1;
    observer->m_unitID = 0x11;
    observer->m_sendID = -1;
    *reinterpret_cast<char**>(observer) = lbl_27_data_7270;
    observer->addObserver(-1, -1);

    *(char**)(self + 0x3c) = lbl_27_data_7D138;
    *(char**)(self + 0x40) = lbl_27_data_7D138 + 0x64;
    *(char**)(self + 0x48) = lbl_27_data_7D138 + 0x70;
    *(char**)(self + 0x54) = lbl_27_data_7D138 + 0x84;
    *(char**)(self + 0x64) = lbl_27_data_7D138 + 0xdc;
    *(char**)(self + 0x70) = lbl_27_data_7D138 + 0xec;
    *(char**)(self + 0x7c) = lbl_27_data_7D138 + 0x100;
    *(char**)(self + 0x88) = lbl_27_data_7D138 + 0x118;
    *(char**)(self + 0x90) = lbl_27_data_7D138 + 0x124;
    *(char**)(self + 0x1a74) = lbl_27_data_7D138 + 0x26c;
    *(char**)(self + 0x1a80) = (char*)arg3[13];
    SearchShape* shape = reinterpret_cast<SearchShape*>(self + 0x1a84);
    float fy = -*(float*)((char*)arg3[13] + 0x10);
    float fz = *(float*)((char*)arg3[13] + 0x14);
    shape->kind = 0;
    shape->flag.flag = 1;
    shape->group = 0;
    shape->table = lbl_27_data_458C0;
    shape->offset.x = lbl_27_rodata_642C;
    shape->offset.y = fy;
    shape->offset.z = fz;
    k.n = 1;
    registry(self)->slot3(shape, 2, &k.n, -1);
    fn_27_89544(registry(self), 2);
    process[0] = lbl_27_bss_74E4;
    process[1] = lbl_27_bss_74E4;
    ((Object_vptr_0*)*(void**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x70))
        ->slot28(process, 2);

    s32 zone = ((Object_vptr_3c*)self)->getZoneState();
    bool f31 = false;
    bool f30 = false;
    bool f4 = false;
    bool f5 = false;
    s16 ret;
    s16 id2;
    s16 a = (*(s16*)(self + 0x1A78));
    if (a >= 0 && (*(s16*)(self + 0x1A7A)) >= 0) f5 = 1;
    if (f5 != 0 && (*(s16*)(self + 0x1A7C)) > -1) f4 = 1;
    if (f4 != 0) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(a) == 1) f30 = 1;
    }
    if (f30 != 0) {
        if (soEventSystem::getInstance()->getManager((*(s16*)(self + 0x1A78)))->getObserverCapacity((*(s16*)(self + 0x1A7A))) == 1) f31 = 1;
    }
    if (f31 == 1) {
        id2 = (*(s16*)(self + 0x1A78));
        if (soEventSystem::getInstance()->getInstanceManager().isContain(id2) == 1)
            soEventSystem::getInstance()->getManager((*(s16*)(self + 0x1A78)))->eraseObserver((*(s16*)(self + 0x1A7A)), (*(s16*)(self + 0x1A7C)));
        (*(s16*)(self + 0x1A7C)) = -1;
        (*(s16*)(self + 0x1A78)) = -1;
    }
    if ((s16)zone > -1 && (*(s16*)(self + 0x1A7A)) > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain((s16)zone) != 0) {
            if (soEventSystem::getInstance()->getManager((s16)zone)->isNullUnit((*(s16*)(self + 0x1A7A))) != 1) {
                soEventManager* mgr = soEventSystem::getInstance()->getManager((s16)zone);
                if (mgr->getObserverCapacity((*(s16*)(self + 0x1A7A))) == 0) {
                    ret = -1;
                } else {
                    soEventUnit* unit = mgr->getEventUnit((*(s16*)(self + 0x1A7A)));
                    Object_vptr_0* cast = (Object_vptr_0*)__dynamic_cast(unit, 0, lbl_27_data_4950, __RTTI__11soEventUnit, 0);
                    if (cast == 0) ret = -1;
                    else ret = cast->slot6(reinterpret_cast<soCollisionSearchEventObserver*>(self + 0x1A74), -1);
                }
                (*(s16*)(self + 0x1A7C)) = ret;
                if (ret > -1 && ret > -1) (*(s16*)(self + 0x1A78)) = (s16)zone;
            }
        }
    }
    fn_27_1D8FC8(self, 0);
    return self;
}

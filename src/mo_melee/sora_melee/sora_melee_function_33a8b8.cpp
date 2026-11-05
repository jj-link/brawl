#pragma force_active on
struct Vec3f {
    float x, y, z;
};

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
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
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79(int);
};

struct Sub54Holder {
    char pad[0x54];
    soNullable* p54;
};

struct Sub60Holder {
    char pad[0xd8];
    Sub54Holder* pd8;
};

struct Stage_base {
    char pad[0x3c];
};

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
    virtual ~Stage();
    virtual void createObj();
    virtual void createObjPokeTrainer();
    virtual void getPokeTrainerPointNum();
    virtual void getPokeTrainerPointData();
    virtual void getPokeTrainerPositionZ();
    virtual void getPokeTrainerDrawLayer();
    virtual void isAdventureStage();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void loading();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void getAIRange();
    virtual void getDefaultLightSetIndex();

    char pad2[0x20];
    Sub60Holder* f60;
};

struct InitParam {
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    Vec3f pos;
    float f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    struct {
        unsigned char a : 1;
        unsigned char b : 3;
        unsigned char c : 1;
        unsigned char d : 3;
    } flags64;
    struct {
        unsigned char x : 2;
        unsigned char y : 6;
    } flags65;
};

extern "C" void fn_27_1D8370(void*, void*);
extern "C" void fn_27_1DA698(void*, int, int, int);

extern "C" void fn_27_33A8B8(void* self, int a1, int a2, int a3, int a4) {
    InitParam p;
    Vec3f zero;
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;

    p.f00 = a1;
    p.f04 = a2;
    p.f08 = a2;
    p.f0c = a2;
    p.f10 = -1;
    p.f14 = -1;
    p.f18 = 0;
    p.f1c = 0;
    *(int*)&p.pos.x = *(int*)&zero.x;
    *(int*)&p.pos.y = *(int*)&zero.y;
    *(int*)&p.pos.z = *(int*)&zero.z;
    p.f28 = 0.0f;
    p.f2c = a3;
    p.f30 = 0;
    p.f34 = 2;
    p.f38 = 0x80;
    p.f3c = 0;
    p.f40 = 0x35f;
    p.f44 = 0;
    p.flags64.a = 1;
    p.flags64.b = 0;
    p.flags64.c = 1;
    p.flags64.d = 0;
    p.flags65.x = 0;

    fn_27_1D8370(self, &p);
    fn_27_1DA698(self, a1, a4, -1);
    ((Stage*)self)->f60->pd8->p54->slot79(8);
    ((Stage*)self)->getDefaultLightSetIndex();
}

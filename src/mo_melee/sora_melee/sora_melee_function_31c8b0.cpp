#include <types.h>
#pragma force_active on

class soNullable {
public:
    virtual void isNull();               // 0x8
    virtual void slot1();                // 0xc
    virtual void slot2();                // 0x10
    virtual void slot3();                // 0x14
    virtual void slot4();                // 0x18
    virtual void slot5();                // 0x1c
    virtual void slot6();                // 0x20
    virtual void slot7();                // 0x24
    virtual void slot8();                // 0x28
    virtual void slot9();                // 0x2c
    virtual void slot10();               // 0x30
    virtual void slot11();               // 0x34
    virtual f32 slot12(u32 id);          // 0x38
    virtual void slot13(u32 id, f32 v);  // 0x3c
    virtual void slot14();               // 0x40
    virtual void slot15(f32* v, int n);  // 0x44
    virtual int slot16();                // 0x48
    virtual void slot17();               // 0x4c
    virtual void slot18();               // 0x50
    virtual void slot19();               // 0x54
};

struct StageBase {
    char pad[0x3c];
};

class Stage : public StageBase {
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
};

extern "C" void fn_27_31C8B0(void* unused, u8* p) {
    soNullable* a = *(soNullable**)(*(u8**)(p + 0xd8) + 0x70);
    if (a->slot16() == 2) {
        u32 base = 0x11000000;
        soNullable* b = *(soNullable**)(*(u8**)(p + 0xd8) + 0x64);
        f32 f = b->slot12(base + 4);
        b->slot13(base + 4, -f);
        b->slot13(base + 5, -b->slot12(base + 5));
        b->slot13(base + 6, -b->slot12(base + 6));
        b->slot13(base + 7, -b->slot12(base + 7));
        soNullable* c = *(soNullable**)(*(u8**)(p + 0xd8) + 0xc);
        c->slot11();
        f32 v[3];
        v[0] = f;
        v[1] = 0.0f;
        v[2] = 0.0f;
        c->slot15(v, 0);
        c->slot19();
        Stage* s = *(Stage**)(p + 0x8);
        s->getDefaultLightSetIndex();
    }
}

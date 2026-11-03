#include <types.h>
#include <GX.h>
#pragma force_active on

struct StagePositions {
    char pad[0x54];
    float f54;
    float f58;
    float f5c;
    float f60;
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
    virtual void fn_66_1B4();
    virtual void fn_66_274();
    virtual void createObjPokeTrainer();
    virtual void fn_66_2AC4();
    virtual void fn_66_2AC0();
    virtual void fn_66_2AB4();
    virtual void fn_66_2AAC();
    virtual void fn_66_2AA4();
    virtual void fn_66_29AC();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_66_26C();
    virtual void process();
    virtual StagePositions* updateStagePositions();
};

union ColorWord {
    GXColor c;
    u32 w;
};

extern "C" {
extern char lbl_66_data_1534[0x5];

void* GetResMat__Q34nw4r3g3d6ResMdlCFPCc(void*, const char*);
void __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(void*, void*, unsigned long);
void* GetResMatTevColor__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFb(void*, bool);
void GXSetTevColor__Q34nw4r3g3d14ResMatTevColorFUl8_GXColor(void*, unsigned long, GXColor);
void fn_80190A3C(void*, bool);
void DCStore__Q34nw4r3g3d6ResMatFb(void*, bool);
float randf__Fv();
}

extern "C" int fn_66_8818(Stage* self, int arg1) {
    StagePositions* p = self->updateStagePositions();
    if (p == 0) {
        return 0;
    }

    float a = p->f54;
    float b = p->f58;
    float c = p->f5c;
    switch (arg1) {
    case 0:
        a *= p->f60;
        break;
    case 1:
        b *= p->f60;
        break;
    case 2:
        c *= p->f60;
        break;
    }

    float r = (c + (a + b)) * randf__Fv();
    int choice;
    if (r < a) {
        choice = 0;
    } else if (r < a + b) {
        choice = 1;
    } else {
        choice = 2;
    }

    void* mdl = 0;
    void* mat = 0;
    void* tev = 0;
    ColorWord colA;
    ColorWord colB;
    colA.w = 0xFFFFFFFF;
    colB.w = 0xFFFFFFFF;
    unsigned char* s = (unsigned char*)self;

    void* obj = **(void***)(s + 0x44);
    if (obj == 0) {
        return choice;
    }
    mdl = *(void**)((unsigned char*)obj + 0xe8);
    if (mdl == 0) {
        return choice;
    }

    mat = GetResMat__Q34nw4r3g3d6ResMdlCFPCc(&mdl, lbl_66_data_1534);
    if (mat == 0) {
        return choice;
    }

    unsigned char access[0x34];
    __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(
        access, obj, *(unsigned long*)((unsigned char*)mat + 0xc));
    tev = GetResMatTevColor__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFb(access, false);
    if (tev == 0) {
        return choice;
    }

    switch (choice) {
    case 0:
        colA.c.r = 0x80;
        colA.c.g = 0;
        colA.c.b = 0;
        colA.c.a = 0xFF;
        colB.c.r = 0x80;
        colB.c.g = 0;
        colB.c.b = 0;
        colB.c.a = 0xFF;
        break;
    case 1:
        colA.c.r = 0;
        colA.c.g = 0;
        colA.c.b = 0x80;
        colA.c.a = 0xFF;
        colB.c.r = 0;
        colB.c.g = 0;
        colB.c.b = 0x80;
        colB.c.a = 0xFF;
        break;
    case 2:
        colA.c.r = 0x80;
        colA.c.g = 0x64;
        colA.c.b = 0;
        colA.c.a = 0xFF;
        colB.c.r = 0x80;
        colB.c.g = 0x64;
        colB.c.b = 0;
        colB.c.a = 0xFF;
        break;
    default:
        return choice;
    }

    GXSetTevColor__Q34nw4r3g3d14ResMatTevColorFUl8_GXColor(&tev, 1, colA.c);
    GXSetTevColor__Q34nw4r3g3d14ResMatTevColorFUl8_GXColor(&tev, 2, colB.c);
    fn_80190A3C(&tev, false);
    DCStore__Q34nw4r3g3d6ResMatFb(&mat, false);
    s[0x158] = (unsigned char)choice;
    return choice;
}

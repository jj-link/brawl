#include <types.h>
#include <GX.h>
#include <revolution/OS/OSFastCast.h>
#pragma force_active on

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
    virtual void fn_74_3B4();
    virtual void fn_74_A6C();
    virtual void createObjPokeTrainer();
    virtual void fn_74_2508();
    virtual void fn_74_2504();
    virtual void fn_74_24F8();
    virtual void fn_74_24F0();
    virtual void fn_74_24E8();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_74_A64();
    virtual void process();
    virtual int updateStagePositions();
};

extern "C" {
extern const float lbl_74_rodata_D0[];
extern char lbl_74_data_D68[];

void* GetResMat__Q34nw4r3g3d6ResMdlCFPCc(void*, const char*);
void __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(void*, void*, unsigned long);
void* GetResMatTevColor__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFb(void*, bool);
float fn_801622C4(float);
void GXSetTevColor__Q34nw4r3g3d14ResMatTevColorFUl8_GXColor(void*, unsigned long, GXColor);
void fn_80190A3C(void*, bool);
void DCStore__Q34nw4r3g3d6ResMatFb(void*, bool);
}

extern "C" void fn_74_4734(Stage* self, float dt) {
    unsigned char* s = (unsigned char*)self;
    const float* k = lbl_74_rodata_D0;

    if (self->updateStagePositions() == 0) return;

    float timer = *(float*)(s + 0x170) - dt;
    *(float*)(s + 0x170) = timer;
    if (timer < k[0]) *(float*)(s + 0x170) = k[0];
    if (k[0] == *(float*)(s + 0x170)) return;

    void* mdl = 0;
    void* mat = 0;
    void* tev = 0;

    void* obj = **(void***)(s + 0x44);
    if (!obj) return;
    mdl = *(void**)((unsigned char*)obj + 0xe8);
    if (!mdl) return;

    mat = GetResMat__Q34nw4r3g3d6ResMdlCFPCc(&mdl, lbl_74_data_D68);
    if (!mat) return;

    unsigned char access[0x34];
    __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(
        access, obj, *(unsigned long*)((unsigned char*)mat + 0xc));
    tev = GetResMatTevColor__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFb(access, false);
    if (!tev) return;

    float t = *(float*)(s + 0x170) / k[9];
    u16 q = (u16)(int)(k[10] * (k[8] - t));
    float v = fn_801622C4(k[11] * __OSu16tof32(&q));
    if (v < k[0]) v = k[0];
    if (v > k[8]) v = k[8];

    GXColor color;
    color.r = (u8)(int)(k[12] - k[13] * v);
    color.g = (u8)(int)(k[12] - k[13] * v);
    color.b = (u8)(int)(k[12] - k[14] * v);
    color.a = 0;
    GXSetTevColor__Q34nw4r3g3d14ResMatTevColorFUl8_GXColor(&tev, 1, color);

    float w = k[12] - k[12] * v;
    color.r = (u8)(int)w;
    color.g = (u8)(int)w;
    color.b = (u8)(int)w;
    color.a = 0;
    GXSetTevColor__Q34nw4r3g3d14ResMatTevColorFUl8_GXColor(&tev, 2, color);

    fn_80190A3C(&tev, false);
    DCStore__Q34nw4r3g3d6ResMatFb(&mat, false);
}

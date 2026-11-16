#include <types.h>
#include <nw4r/math/math_types.h>
#pragma force_active on

using namespace nw4r::math;

struct M {
    float m[12];
};

struct StageVTable {
    void* unused[0x98 / 4];
    void (*closeStageEntry)(void*);
};

struct Stage_base {
    char pad0[0x3c];
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
    virtual float getPokeTrainerPositionZ();
    virtual int getPokeTrainerDrawLayer();
    virtual bool isAdventureStage();
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

    s32 m40;
    char pad44[0x5c];
    void* ma0;
    char padA4[0x54];
    char mf8[0xc];
    char m104[0x10];
};

struct RoData33D0 {
    float f0, f4, f8, fc, f10, f14, f18, f1c;
};

struct SndSystemView {
    char p0[0x294];
    M mtx;
    float fa, fb, fc;
    char p1[0xb90 - 0x2d0];
    u8 b90;
};

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_22A914(void*);
void fn_27_22AC28(void*);
void fn_8015C304(void*);
void fn_80076714(void*, int, int);
float fn_8016232C(float);
float fn_801622C4(float);
void fn_801EC9D8(M*, VEC3*, VEC3*, VEC3*);
void* fn_801B77F8(void);
void fn_801B8390(void*, int, int);
void fn_27_227EF0(void*, int);
void exit__6gfTaskFv(void*);
void __dt__9gfArchiveFv(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
extern StageVTable lbl_27_data_4A1E8;
extern const RoData33D0 lbl_27_rodata_33D0;
extern void* lbl_27_bss_5780;
extern void* lbl_27_bss_5668;
extern char g_grCollisionList;
extern void* g_sndSystem;
}

extern "C" Stage* __dt__5StageFv(Stage* self, int destroyFlag) {
    const RoData33D0* rd = &lbl_27_rodata_33D0;
    if (self != 0) {
        *(StageVTable**)((char*)self + 0x3c) = &lbl_27_data_4A1E8;
        self->closeStage();
        if (self->ma0 != 0) {
            exit__6gfTaskFv(self->ma0);
            self->ma0 = 0;
        }
        if (lbl_27_bss_5780 == 0) {
            void* m = __nw__FUlQ25Heaps8HeapType(0x54, 2);
            if (m != 0) {
                m = fn_27_22A914(m);
            }
            lbl_27_bss_5780 = m;
        }
        fn_27_22AC28(lbl_27_bss_5780);
        lbl_27_bss_5668 = 0;
        fn_8015C304(&g_grCollisionList);
        self->m40 = 0;
        fn_80076714(g_sndSystem, 0, 0);
        VEC3 pos(rd->f8, rd->f8, rd->f8);
        VEC3 up(rd->f8, rd->f0, rd->f8);
        float s = -fn_8016232C(rd->f8);
        float x = fn_801622C4(rd->f8);
        VEC3 d(x, rd->f8, s);
        VEC3 t = pos + d;
        M mtx;
        fn_801EC9D8(&mtx, &pos, &up, &t);
        ((SndSystemView*)g_sndSystem)->mtx = mtx;
        ((SndSystemView*)g_sndSystem)->fa = rd->f14;
        ((SndSystemView*)g_sndSystem)->fb = rd->f18;
        ((SndSystemView*)g_sndSystem)->fc = rd->f1c;
        SndSystemView* snd = (SndSystemView*)g_sndSystem;
        fn_801B8390(fn_801B77F8(), 0, 0);
        snd->b90 = 0;
        __dt__9gfArchiveFv(self->m104, -1);
        fn_27_227EF0(self->mf8, -1);
        __dt__6gfTaskFv(self, 0);
        if (destroyFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
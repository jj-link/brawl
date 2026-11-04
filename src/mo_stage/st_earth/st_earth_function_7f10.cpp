#pragma force_active on
#include <gm/gm_global.h>
#include <it/it_manager.h>
#include <snd/snd_3d_generator.h>
#include <types.h>

struct Pair {
    u32 x;
    u32 y;
    Pair(u32 a, u32 b) : x(a), y(b) {}
};

extern "C" {
extern void* lbl_27_bss_5668;
void fn_27_2AA7AC(void* mgr, Pair pair, int a, Vec3f* pos, int b, int c, int d, u32 e);
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
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_66_2A9C();
    virtual void fn_66_2A94();
    virtual void getZoneLightSetIndex();
    virtual void fn_66_2A78();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData(Vec3f* out, int a, int b);

    char pad40[0x80];
    int m_c0;
    char pad_c4[0x9c];
    u8 m_mode;
};

extern "C" void fn_66_7F10(Stage* self) {
    Vec3f pos;
    int var;

    if (g_GameGlobal->m_modeMelee != NULL && ((signed char*)g_GameGlobal->m_modeMelee)[0x16] != 0) {
        itManager* mgr = itManager::getInstance();
        if (mgr != NULL) {
            self->startLoadLocalData(&pos, self->m_c0, 3);
            switch (self->m_mode) {
            case 1: var = 3; break;
            case 2: var = 4; break;
            case 3: var = 5; break;
            case 4: var = 6; break;
            default: return;
            }
            u32 id = *(u32*)((char*)lbl_27_bss_5668 + 0x44);
            fn_27_2AA7AC(mgr, Pair(id, 0), var, &pos, -1, -1, -1, id);
            ((snd3DGenerator*)((char*)self + 0x1bc))->playSE((SndID)0x1CCE, 0, 0, -1);
        }
    }
}

#include <types.h>
#pragma force_active on
extern "C" float randf__Fv();
extern "C" const float lbl_79_rodata_0;
extern "C" const float lbl_79_rodata_8;
struct Vec3f { float x, y, z; };
struct Entry { Vec3f a; Vec3f b; u8 idx; u8 state; u8 flag; };
struct Slot { u32 state; u32 pad[2]; };
struct Info { char pad[8]; u8 kind; };
struct Params { float base; float scale; float table[5]; float chance; };
struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base { public:
virtual void processDefault(); virtual void processBegin(); virtual void processAnim(); virtual void processUpdate(); virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void processFixPosition(); virtual void processPreCollision(); virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera(); virtual void processFixCamera(); virtual void processEffect(); virtual void processGameProc(); virtual void processEnd(); virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug(); virtual void renderDebug(); virtual void init(); virtual void fn_79_1F0(); virtual void fn_79_2E4(); virtual void createObjPokeTrainer(); virtual void fn_79_1868(); virtual void fn_79_1864(); virtual void fn_79_1858(); virtual void fn_79_1850(); virtual void fn_79_1848(); virtual void fn_79_1584(); virtual void getItemGenPac(); virtual void getItemPacEnemyFigure(); virtual void getEnemyPac(); virtual void getAdvRadarData(); virtual void initializeStage(); virtual void closeStage(); virtual void renderDebugPositions(); virtual void fn_79_2DC(); virtual void process(); virtual void updateStagePositions(); virtual void debugCollision(); virtual void fn_79_1840(); virtual void fn_79_1838(); virtual void getZoneLightSetIndex(); virtual void fn_79_181C(); virtual void clearCameraParam(); virtual void initCameraParam(); virtual void startLoadLocalData(); virtual void isLoadLocalData(); virtual void entryLocalData(); virtual void removeLocalData(); virtual void fn_79_1818(); virtual void getFighterStartPos(); virtual void getFighterReStartPos(); virtual void fn_79_1870(); virtual void getPokeTrainerStartPos(); virtual void getItemPosCount(); virtual void getItemPos(); virtual void getRandItemPos(); virtual void getKirifudaPos(); virtual void getKirifudaAngle(); virtual void getKirifudaScale(); virtual void getKirifudaModelType(); virtual void getPokeTrainerPosCount(); virtual void getPokeTrainerPos(); virtual void getFighterDeadEffectSizeRate(); virtual void getEnemyDeadEffectSizeRate(); virtual void getEnableZ(); virtual void fn_79_1808(); virtual void fn_79_1810(); virtual void fn_79_1800(); virtual void fn_79_17F8(); virtual void fn_79_17F0(); virtual void fn_79_17DC(); virtual void fn_79_17CC(); virtual void fn_79_17C0(); virtual void fn_79_17B4(); virtual void fn_79_17AC(); virtual void fn_79_17A4(); virtual void fn_79_179C(); virtual void fn_79_1798(); virtual void isEnd(); virtual void isEventEnd(); virtual void enableDevil(); virtual void disableDevil(); virtual void isDevil(); virtual void setDevilScrool(); virtual void getLucarioFinalTechniquePosition(); virtual void startAppear(); virtual void setAppearKind(); virtual void endAppear(); virtual void getAppearTask(); virtual void forceStopAppear(); virtual void getFinalTechniqColor(); virtual void setMotionRatio(); virtual void saveMotionRatio(); virtual void restoreMotionRatio(); virtual void setMotionSubRatio(); virtual void saveMotionSubRatio(); virtual void restoreMotionSubRatio(); virtual void fn_79_1790(); virtual void fn_79_1788(); virtual void fn_79_1780(); virtual void isAppear(); virtual void isStartAppearTimming(); virtual void getMadeinAiData(); virtual void fn_79_1880(); virtual void getBamperVector(); virtual void notifyEventInfoReady(); virtual void notifyEventInfoGo(); virtual void getDestroyBossParamCommon(); virtual void stAdventureEventGetItem(); virtual void setStageOutEffectInit(); virtual void setStageInEffectInit(); virtual void fn_79_1778(); virtual void fn_79_1770(); virtual void fn_79_176C(); virtual void getZoneState(); virtual void getZonePos(); virtual void getMagmaHeight(); virtual void getAcidHeight(); virtual void getIteamDropStatus(); virtual void createWind2ndOnly(); virtual void fn_79_1878(); virtual void updateWind2ndOnly(); virtual void setVision(); virtual void fn_79_ABC(); virtual void setCameraLimitRange(); virtual void resetCameraLimitRange(); virtual void checkChangeScene(); virtual void resetChangeScene(); virtual void setChangeSceneNumber(); virtual void fn_79_554(); virtual void fn_79_62C(); virtual void fn_79_704(); virtual void fn_79_7DC(); virtual void fn_79_8A8(); virtual void fn_79_A00(); virtual void fn_79_B60(); virtual void fn_79_BBC(); virtual void fn_79_F08(); virtual void fn_79_11AC(); virtual void fn_79_133C(); virtual u8 fn_79_14D4(); virtual void fn_79_15A0(u8 kind, Slot* s); virtual void fn_79_1618(); virtual void fn_79_1680(); virtual void fn_79_16FC(); virtual void fn_79_172C(); virtual Info* fn_79_1734(Slot* s);
char pad0[0x5c];
Params* params;
char pad1[0x150];
float timer;
Entry entries[6][5];
Vec3f pos[6][5];
Slot slots[6];
u8 flag;
};
extern "C" void fn_79_F08(Stage* self, float delta) {
    Stage* base = self; Slot* slot; Params* p; Entry* e; s32 idx; u8 i;
    if (base->flag == 1) return;
    base->timer = base->timer - delta;
    if (base->timer < lbl_79_rodata_0) base->timer = lbl_79_rodata_0;
    if (lbl_79_rodata_0 == base->timer) {
        p = base->params;
        if (p) {
            float prod = p->scale * p->table[self->fn_79_14D4()];
            float random = randf__Fv();
            float rnd = random * prod;
            base->timer = p->base + rnd;
            idx = (s32)(lbl_79_rodata_8 * randf__Fv());
            slot = &base->slots[(u8)idx];
            if (slot->state != 5) {
                Info* info = self->fn_79_1734(slot);
                if (info == 0 || base->pos[(u8)idx][4].y != base->entries[(u8)idx][info->kind].b.y) {
                    Entry* row = base->entries[(u8)idx];
                    for (i = 0; i < 5; i++) {
                        if (row[i].state == 7) break;
                    }
                    if (i != 5) {
                        e = &row[i];
                        u8 r6;
                        if (info != 0) r6 = row[info->kind].idx + 1;
                        else r6 = 0;
                        e->a = base->pos[(u8)idx][0];
                        e->b = base->pos[(u8)idx][r6];
                        e->idx = r6;
                        e->state = 0;
                        if (randf__Fv() < p->chance) e->flag = 1;
                        else e->flag = 0;
                        self->fn_79_15A0(i, slot);
                    }
                }
            }
        }
    }
}

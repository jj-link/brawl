#include <gf/gf_archive.h>
#include <gm/gm_global.h>
#include <gr/gr_tengan_event.h>
#include <memory.h>
#include <mt/mt_vector.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <so/collision/so_collision_attack_part.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_54_rodata_0[];
extern char lbl_54_data_0[];
}

struct AtkBits {
    unsigned int m_nodeIndex : 9;
    unsigned int m_targetCategory : 10;
    unsigned int m_targetSituation : 3;
    unsigned int m_targetLr : 1;
    unsigned int m_targetPart : 4;
    unsigned int m_attribute : 5;
    unsigned int m_soundLevel : 2;
    unsigned int m_soundAttribute : 5;
    unsigned int m_isClankable : 1;
    unsigned int m_unk2 : 1;
    unsigned int m_unk3 : 1;
    unsigned int m_isShieldable : 1;
    unsigned int m_isReflectable : 1;
    unsigned int m_isAbsorbable : 1;
    unsigned int m_subShield : 9;
    unsigned int m_pad1 : 10;
    unsigned int m_serialHitFrame : 16;
    unsigned int m_isDirect : 1;
    unsigned int m_isInvalidInvincible : 1;
    unsigned int m_isInvalidXlu : 1;
    unsigned int m_lrCheck : 3;
    unsigned int m_isCatch : 1;
    unsigned int m_noTeam : 1;
    unsigned int m_noHitStop : 1;
    unsigned int m_noEffect : 1;
    unsigned int m_noTransaction : 1;
    unsigned int m_region : 5;
    unsigned int m_shapeType : 1;
    unsigned int m_pad2 : 31;
};

struct GroundBase {
    char pad[0x3c];
};

class Ground : public GroundBase {
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
    virtual void update(float deltaFrame);
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual int getModelCount();
    virtual void vf_98();
    virtual void startup(gfArchive* data, u32 unk1, int layerType);
    virtual void setNode();
    virtual void setStageData(void* stageData);
};

class grGimmick : public Ground {
public:
    void setPos(Vec3f* pos);
};

class grMadein : public grGimmick {
public:
    virtual void vf_a0();
    virtual void vf_a4();
    virtual void vf_a8();
    virtual void vf_ac();
    virtual void vf_b0();
    virtual void vf_b4();
    virtual void vf_b8();
    virtual void vf_bc();
    virtual void vf_c0();
    virtual void vf_c4();
    virtual void vf_c8();
    virtual void vf_cc();
    virtual void vf_d0();
    virtual void vf_d4();
    virtual void vf_d8();
    virtual void vf_dc();
    virtual void vf_e0();
    virtual void vf_e4();
    virtual void vf_e8();
    virtual void vf_ec();
    virtual void vf_f0();
    virtual void vf_f4();
    virtual void vf_f8();
    virtual void vf_fc();
    virtual void vf_100();
    virtual void vf_104();
    virtual void vf_108();
    virtual void vf_10c();
    virtual void vf_110();
    virtual void vf_114();
    virtual void vf_118();
    virtual void vf_11c();
    virtual void vf_120();
    virtual void vf_124();
    virtual void vf_128();
    virtual void vf_12c();
    virtual void vf_130();
    virtual void vf_134();
    virtual void vf_138();
    virtual void vf_13c();
    virtual void vf_140();
    virtual void vf_144();
    virtual void vf_148();
    virtual void vf_14c();
    virtual void vf_150();
    virtual void vf_154();
    virtual void vf_158();
    virtual void vf_15c();
    virtual void vf_160();
    virtual void vf_164();
    virtual void vf_168();
    virtual void vf_16c();
    virtual void vf_170();
    virtual void vf_174();
    virtual void vf_178();
    virtual void vf_17c();
    virtual void vf_180();
    virtual void vf_184();
    virtual void vf_188();
    virtual void vf_18c();
    virtual void vf_190();
    virtual void vf_194();
    virtual void vf_198();
    virtual void vf_19c();
    virtual void vf_1a0();
    virtual void vf_1a4();
    virtual void vf_1a8();
    virtual void vf_1ac();
    virtual void vf_1b0();
    virtual void setAttackGimmickDetails(soCollisionAttackData* attackData, float size, float tripRate,
                                         float hitstopMultiplier, float sdiMultiplier, int power, Vec3f* offsetPos,
                                         int vector, int reactionEffect, int reactionFix, int reactionAdd,
                                         u32 nodeIndex, soCollision::CategoryMask collisionCategoryMask, soCollision::SituationMask collisionSituationMask,
                                         bool unk1, soCollision::PartMask collisionPartMask, soCollisionAttackData::Attribute attribute,
                                         soCollisionAttackData::SoundLevel soundLevel, soCollisionAttackData::SoundAttribute soundAttr,
                                         bool isClankable, bool unk2, bool unk3, bool isShieldable, bool isReflectable,
                                         bool isAbsorbable, u32 addedShieldDamage, u32 detectionRate, bool unk5, bool ignoreInvincibility,
                                         bool ignoreIntangibility, soCollisionAttackData::LrCheck lrCheck,
                                         bool unk6, bool unk7, bool disableHitstop, bool disableHitGfx,
                                         bool disableFlinch, soCollisionAttackData::Region region, bool isShapeCapsule);

    static grMadein* create(int mdlIndex, const char* tgtNodeName, const char* taskName, Heaps::HeapType heapType);
    void setAttack(float size, Vec3f* offsetPos);
    inline void setAttackPreset(int preset) {
        *(int*)(*(char**)((char*)this + 0x15c) + 0x28) = preset;
    }
    soCollisionAttackData* getOverwriteAttackData();
    void initializeEntity();
};

class Stage_base {
public:
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
    virtual void fn_54_1EC();
    virtual void fn_54_2FC();
    virtual void createObjPokeTrainer(gfArchive* archive, int fileIndex, const char* name, Vec3f* pokeTrainerPos, Vec3f* unk2);
    virtual void fn_54_2AE0();
    virtual void fn_54_2ADC();
    virtual void fn_54_2AD0();
    virtual void fn_54_2AC8();
    virtual void fn_54_2AC0();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_54_2F4();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_54_2AB8();
    virtual void fn_54_2AB0();
    virtual void getZoneLightSetIndex();
    virtual void fn_54_2A94();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_54_2A90();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_54_2AE8();
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
    virtual void getFighterDeadEffectSizeRate();
    virtual void getEnemyDeadEffectSizeRate();
    virtual void getEnableZ();
    virtual void fn_54_2A80();
    virtual void fn_54_2A88();
    virtual void fn_54_2A78();
    virtual void fn_54_2A70();
    virtual void fn_54_2A68();
    virtual void fn_54_2A54();
    virtual void fn_54_2A44();
    virtual void fn_54_2A38();
    virtual void fn_54_2A2C();
    virtual void fn_54_2A24();
    virtual void fn_54_2A1C();
    virtual void fn_54_2864();
    virtual void fn_54_2A18();
    virtual void isEnd();
    virtual void fn_54_2900();
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
    virtual void fn_54_2B00();
    virtual void setMotionRatio();
    virtual void saveMotionRatio();
    virtual void restoreMotionRatio();
    virtual void setMotionSubRatio();
    virtual void saveMotionSubRatio();
    virtual void restoreMotionSubRatio();
    virtual void fn_54_2A10();
    virtual void fn_54_2A08();
    virtual void fn_54_2A00();
    virtual void isAppear();
    virtual void isStartAppearTimming();
    virtual void getMadeinAiData();
    virtual void fn_54_2AF8();
    virtual void getBamperVector();
    virtual void notifyEventInfoReady();
    virtual void notifyEventInfoGo();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
    virtual void fn_54_29F8();
    virtual void fn_54_29F0();
    virtual void fn_54_29EC();
    virtual void fn_54_29AC();
    virtual void fn_54_29B4();
    virtual void fn_54_29E4();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_54_2AF0();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_54_1CF4();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_54_1318(int);
    virtual void fn_54_1404(int);
    virtual void fn_54_1530(int);
    virtual void fn_54_165C(int);
    virtual void fn_54_17C0(int);
    virtual void fn_54_18C4(int);
    virtual void fn_54_19A8(int);
    virtual void fn_54_1ACC(int);
    virtual void fn_54_1C30(int);
    virtual void fn_54_1E04();
    virtual void fn_54_1E60();
    virtual void fn_54_286C();

    void testStageParamInit(gfArchive* archive, int fileIndex);
    void testStageDataInit(gfArchive* archive, int fileIndex, int unk2);
    void addGround(Ground* ground);
    Ground* getGround(int index);
    void createCollision(gfArchive* archive, int unk, Ground* ground);
    void createStagePositions();
    void createStagePositions(nw4r::g3d::ResFile* res);
    void registScnAnim(nw4r::g3d::ResFileData* data, u32 unk);
    void loadStageAttrParam(gfArchive* archive, int unk);
    void initPosPokeTrainer(int a, int b);

    char _40[0x9c - 0x40];
    void* m_unk9C;
    char _a0[0xbc - 0xa0];
    Vec3f* m_unkBC;
    char _c0[0x1a0 - 0xc0];
    gfArchive* m_archive;
    char _1a4[0x1d8 - 0x1a4];
    Vec3f m_vec[5];
    grTenganEvent m_tenganEvent[5];
    grTenganEvent m_tenganEvent570;
    grTenganEvent m_tenganEvent61c;
    grTenganEvent m_tenganEvent6c8;
    char _774[0x79a - 0x774];
    u8 m_unk79a;
    char _79b[0x831 - 0x79b];
    u8 m_unk831;
};

extern "C" void fn_54_2FC(Stage* self) {
    char* names;
    const float* rodata;
    rodata = lbl_54_rodata_0;
    names = lbl_54_data_0;
    Vec3f pos;
    Vec3f tmp;
    grMadein* g;
    soCollisionAttackData* atk;
    AtkBits* ab;
    int i;

    self->testStageParamInit(self->m_archive, 10);
    self->testStageDataInit(self->m_archive, 0x14, 0x6c);
    self->fn_54_286C();
    self->fn_54_1318(0);
    self->fn_54_1404(1);
    self->fn_54_1530(2);
    self->fn_54_165C(3);
    self->fn_54_17C0(4);
    self->fn_54_18C4(5);
    self->fn_54_19A8(6);
    self->fn_54_1ACC(7);
    self->fn_54_1ACC(8);
    self->fn_54_1C30(9);

    g = grMadein::create(9, names + 0xC, names + 0x10, (Heaps::HeapType)15);
    self->addGround(g);
    g->startup(self->m_archive, 0, 0);
    g->setStageData(self->m_unk9C);
    if (g != NULL) {
        g = grMadein::create(9, names + 0xC, names + 0x18, (Heaps::HeapType)15);
        self->addGround(g);
        g->startup(self->m_archive, 0, 0);
        g->setStageData(self->m_unk9C);
        if (g != NULL) {
            g = grMadein::create(9, names + 0xC, names + 0x20, (Heaps::HeapType)15);
            self->addGround(g);
            g->startup(self->m_archive, 0, 0);
            g->setStageData(self->m_unk9C);
            if (g != NULL) {
                g = grMadein::create(9, names + 0xC, names + 0x28, (Heaps::HeapType)15);
                self->addGround(g);
                g->startup(self->m_archive, 0, 0);
                g->setStageData(self->m_unk9C);
                if (g != NULL) {
                    g = grMadein::create(9, names + 0xC, names + 0x30, (Heaps::HeapType)15);
                    self->addGround(g);
                    g->startup(self->m_archive, 0, 0);
                    g->setStageData(self->m_unk9C);
                    if (g != NULL) {
                        g = grMadein::create(9, names + 0xC, names + 0x38, (Heaps::HeapType)15);
                        self->addGround(g);
                        g->startup(self->m_archive, 0, 0);
                        g->setStageData(self->m_unk9C);
                        if (g != NULL) {
                            g = grMadein::create(9, names + 0xC, names + 0x44, (Heaps::HeapType)15);
                            self->addGround(g);
                            g->startup(self->m_archive, 0, 0);
                            g->setStageData(self->m_unk9C);
                            if (g != NULL) {
                                g = grMadein::create(9, names + 0xC, names + 0x50, (Heaps::HeapType)15);
                                self->addGround(g);
                                g->startup(self->m_archive, 0, 0);
                                g->setStageData(self->m_unk9C);
                                if (g != NULL) {
                                    g = grMadein::create(9, names + 0xC, names + 0x5C, (Heaps::HeapType)15);
                                    self->addGround(g);
                                    g->startup(self->m_archive, 0, 0);
                                    g->setStageData(self->m_unk9C);
                                    if (g != NULL) {
                                        pos.m_x = rodata[0];
                                        pos.m_y = rodata[1];
                                        pos.m_z = rodata[0];

                                        g = static_cast<grMadein*>(self->getGround(10));
                                        g->setAttack(rodata[2], &pos);
                                        g->setAttackPreset(4);
                                        atk = g->getOverwriteAttackData();
                                        g->setAttackGimmickDetails(atk, rodata[2], rodata[3], rodata[3], rodata[3], 10, &pos, 361, 100, 0, 70, 0,
                                            (soCollision::CategoryMask)0x3ff, (soCollision::SituationMask)7, false, (soCollision::PartMask)0xf,
                                            soCollisionAttackData::Attribute_Fire, soCollisionAttackData::Sound_Level_Medium, soCollisionAttackData::Sound_Attribute_Fire,
                                            false, false, false, true, false, false, 0, 60, false, false, false,
                                            soCollisionAttackData::Lr_Check_Pos, false, false, false, false, false,
                                            soCollisionAttackData::Region_None, true);

                                        g = static_cast<grMadein*>(self->getGround(11));
                                        g->setAttack(rodata[2], &pos);
                                        g->setAttackPreset(4);
                                        atk = g->getOverwriteAttackData();
                                        g->setAttackGimmickDetails(atk, rodata[2], rodata[3], rodata[3], rodata[3], 10, &pos, 361, 100, 0, 70, 0,
                                            (soCollision::CategoryMask)0x3ff, (soCollision::SituationMask)7, false, (soCollision::PartMask)0xf,
                                            soCollisionAttackData::Attribute_Fire, soCollisionAttackData::Sound_Level_Medium, soCollisionAttackData::Sound_Attribute_Fire,
                                            false, false, false, true, false, false, 0, 60, false, false, false,
                                            soCollisionAttackData::Lr_Check_Pos, false, false, false, false, false,
                                            soCollisionAttackData::Region_None, true);

                                        g = static_cast<grMadein*>(self->getGround(12));
                                        g->setAttack(rodata[4], &pos);
                                        g->setAttackPreset(4);
                                        atk = g->getOverwriteAttackData();
                                        g->setAttackGimmickDetails(atk, rodata[4], rodata[3], rodata[3], rodata[3], 10, &pos, 361, 100, 0, 70, 0,
                                            (soCollision::CategoryMask)0x3ff, (soCollision::SituationMask)7, false, (soCollision::PartMask)0xf,
                                            soCollisionAttackData::Attribute_Fire, soCollisionAttackData::Sound_Level_Medium, soCollisionAttackData::Sound_Attribute_Fire,
                                            false, false, false, true, false, false, 0, 60, false, false, false,
                                            soCollisionAttackData::Lr_Check_Pos, false, false, false, false, false,
                                            soCollisionAttackData::Region_None, true);

                                        g = static_cast<grMadein*>(self->getGround(13));
                                        g->setAttack(rodata[2], &pos);
                                        g->setAttackPreset(4);
                                        atk = g->getOverwriteAttackData();
                                        g->setAttackGimmickDetails(atk, rodata[2], rodata[3], rodata[3], rodata[3], 10, &pos, 361, 100, 0, 70, 0,
                                            (soCollision::CategoryMask)0x3ff, (soCollision::SituationMask)7, false, (soCollision::PartMask)0xf,
                                            soCollisionAttackData::Attribute_Fire, soCollisionAttackData::Sound_Level_Medium, soCollisionAttackData::Sound_Attribute_Fire,
                                            false, false, false, true, false, false, 0, 60, false, false, false,
                                            soCollisionAttackData::Lr_Check_Pos, false, false, false, false, false,
                                            soCollisionAttackData::Region_None, true);

                                        g = static_cast<grMadein*>(self->getGround(14));
                                        g->setAttack(rodata[2], &pos);
                                        g->setAttackPreset(4);
                                        atk = g->getOverwriteAttackData();
                                        g->setAttackGimmickDetails(atk, rodata[2], rodata[3], rodata[3], rodata[3], 10, &pos, 361, 100, 0, 70, 0,
                                            (soCollision::CategoryMask)0x3ff, (soCollision::SituationMask)7, false, (soCollision::PartMask)0xf,
                                            soCollisionAttackData::Attribute_Fire, soCollisionAttackData::Sound_Level_Medium, soCollisionAttackData::Sound_Attribute_Fire,
                                            false, false, false, true, false, false, 0, 60, false, false, false,
                                            soCollisionAttackData::Lr_Check_Pos, false, false, false, false, false,
                                            soCollisionAttackData::Region_None, true);

                                        pos.m_x = rodata[0];
                                        pos.m_y = rodata[0];
                                        pos.m_z = rodata[0];

                                        g = static_cast<grMadein*>(self->getGround(15));
                                        *(s32*)((char*)g + 0x174) = 14;
                                        g->setAttack(rodata[5], &pos);
                                        g->setAttackPreset(4);
                                        atk = g->getOverwriteAttackData();
                                        atk->m_reactionEffect = 50;
                                        atk->m_reactionFix = 0;
                                        atk->m_reactionAdd = 80;
                                        atk->m_power = 18;
                                        atk->m_vector = 80;
                                        atk->m_nodeIndex = 0;
                                        atk->m_size = rodata[5];
                                        atk->m_offsetPos = pos;
                                        atk->m_attribute = (soCollisionAttackData::Attribute)5;
                                        atk->m_targetSituation = (soCollision::SituationMask)7;
                                        atk->m_targetCategory = (soCollision::CategoryMask)0x3ff;
                                        ab = (AtkBits*)((u8*)atk + 0x30);
                                        ab->m_isClankable = false;
                                        ab->m_unk2 = false;
                                        ab->m_unk3 = false;
                                        ab->m_soundLevel = 2;
                                        ab->m_isDirect = false;
                                        ab->m_targetLr = false;
                                        ab->m_targetPart = 15;
                                        ab->m_soundAttribute = 0;
                                        ab->m_serialHitFrame = 60;
                                        ab->m_isShieldable = true;
                                        ab->m_isInvalidInvincible = false;
                                        ab->m_isInvalidXlu = false;
                                        ab->m_lrCheck = 2;
                                        ab->m_isReflectable = false;
                                        ab->m_isAbsorbable = false;
                                        ab->m_isCatch = false;
                                        ab->m_noTeam = false;
                                        ab->m_noHitStop = true;
                                        ab->m_noEffect = false;
                                        ab->m_noTransaction = false;
                                        ab->m_shapeType = 1;

                                        g = static_cast<grMadein*>(self->getGround(16));
                                        *(s32*)((char*)g + 0x174) = 14;
                                        g->setAttack(rodata[5], &pos);
                                        g->setAttackPreset(4);
                                        atk = g->getOverwriteAttackData();
                                        atk->m_reactionEffect = 50;
                                        atk->m_reactionFix = 0;
                                        atk->m_reactionAdd = 110;
                                        atk->m_power = 18;
                                        atk->m_vector = 80;
                                        atk->m_nodeIndex = 0;
                                        atk->m_size = rodata[5];
                                        atk->m_offsetPos = pos;
                                        atk->m_attribute = (soCollisionAttackData::Attribute)5;
                                        atk->m_targetSituation = (soCollision::SituationMask)7;
                                        atk->m_targetCategory = (soCollision::CategoryMask)0x3ff;
                                        ab = (AtkBits*)((u8*)atk + 0x30);
                                        ab->m_isClankable = false;
                                        ab->m_unk2 = false;
                                        ab->m_unk3 = false;
                                        ab->m_soundLevel = 2;
                                        ab->m_isDirect = false;
                                        ab->m_targetLr = false;
                                        ab->m_targetPart = 15;
                                        ab->m_soundAttribute = 0;
                                        ab->m_serialHitFrame = 60;
                                        ab->m_isShieldable = true;
                                        ab->m_isInvalidInvincible = false;
                                        ab->m_isInvalidXlu = false;
                                        ab->m_lrCheck = 2;
                                        ab->m_isReflectable = false;
                                        ab->m_isAbsorbable = false;
                                        ab->m_isCatch = false;
                                        ab->m_noTeam = false;
                                        ab->m_noHitStop = true;
                                        ab->m_noEffect = false;
                                        ab->m_noTransaction = false;
                                        ab->m_shapeType = 1;

                                        g = static_cast<grMadein*>(self->getGround(17));
                                        *(s32*)((char*)g + 0x174) = 14;
                                        g->setAttack(rodata[5], &pos);
                                        g->setAttackPreset(4);
                                        atk = g->getOverwriteAttackData();
                                        atk->m_reactionEffect = 50;
                                        atk->m_reactionFix = 0;
                                        atk->m_reactionAdd = 110;
                                        atk->m_power = 18;
                                        atk->m_vector = 80;
                                        atk->m_nodeIndex = 0;
                                        atk->m_size = rodata[5];
                                        atk->m_offsetPos = pos;
                                        atk->m_attribute = (soCollisionAttackData::Attribute)5;
                                        atk->m_targetSituation = (soCollision::SituationMask)7;
                                        atk->m_targetCategory = (soCollision::CategoryMask)0x3ff;
                                        ab = (AtkBits*)((u8*)atk + 0x30);
                                        ab->m_isClankable = false;
                                        ab->m_unk2 = false;
                                        ab->m_unk3 = false;
                                        ab->m_soundLevel = 2;
                                        ab->m_isDirect = false;
                                        ab->m_targetLr = false;
                                        ab->m_targetPart = 15;
                                        ab->m_soundAttribute = 0;
                                        ab->m_serialHitFrame = 60;
                                        ab->m_isShieldable = true;
                                        ab->m_isInvalidInvincible = false;
                                        ab->m_isInvalidXlu = false;
                                        ab->m_lrCheck = 2;
                                        ab->m_isReflectable = false;
                                        ab->m_isAbsorbable = false;
                                        ab->m_isCatch = false;
                                        ab->m_noTeam = false;
                                        ab->m_noHitStop = true;
                                        ab->m_noEffect = false;
                                        ab->m_noTransaction = false;
                                        ab->m_shapeType = 1;

                                        g = static_cast<grMadein*>(self->getGround(18));
                                        *(s32*)((char*)g + 0x174) = 14;
                                        g->setAttack(rodata[5], &pos);
                                        g->setAttackPreset(4);
                                        atk = g->getOverwriteAttackData();
                                        atk->m_reactionEffect = 50;
                                        atk->m_reactionFix = 0;
                                        atk->m_reactionAdd = 110;
                                        atk->m_power = 18;
                                        atk->m_vector = 80;
                                        atk->m_nodeIndex = 0;
                                        atk->m_size = rodata[5];
                                        atk->m_offsetPos = pos;
                                        atk->m_attribute = (soCollisionAttackData::Attribute)5;
                                        atk->m_targetSituation = (soCollision::SituationMask)7;
                                        atk->m_targetCategory = (soCollision::CategoryMask)0x3ff;
                                        ab = (AtkBits*)((u8*)atk + 0x30);
                                        ab->m_isClankable = false;
                                        ab->m_unk2 = false;
                                        ab->m_unk3 = false;
                                        ab->m_soundLevel = 2;
                                        ab->m_isDirect = false;
                                        ab->m_targetLr = false;
                                        ab->m_targetPart = 15;
                                        ab->m_soundAttribute = 0;
                                        ab->m_serialHitFrame = 60;
                                        ab->m_isShieldable = true;
                                        ab->m_isInvalidInvincible = false;
                                        ab->m_isInvalidXlu = false;
                                        ab->m_lrCheck = 2;
                                        ab->m_isReflectable = false;
                                        ab->m_isAbsorbable = false;
                                        ab->m_isCatch = false;
                                        ab->m_noTeam = false;
                                        ab->m_noHitStop = true;
                                        ab->m_noEffect = false;
                                        ab->m_noTransaction = false;
                                        ab->m_shapeType = 1;

                                        static_cast<grMadein*>(self->getGround(10))->initializeEntity();
                                        static_cast<grMadein*>(self->getGround(11))->initializeEntity();
                                        static_cast<grMadein*>(self->getGround(12))->initializeEntity();
                                        static_cast<grMadein*>(self->getGround(13))->initializeEntity();
                                        static_cast<grMadein*>(self->getGround(14))->initializeEntity();
                                        static_cast<grMadein*>(self->getGround(15))->initializeEntity();
                                        static_cast<grMadein*>(self->getGround(16))->initializeEntity();
                                        static_cast<grMadein*>(self->getGround(17))->initializeEntity();
                                        static_cast<grMadein*>(self->getGround(18))->initializeEntity();

                                        self->createCollision(self->m_archive, 2, NULL);
                                        self->initCameraParam();

                                        {
                                            void* posRes = self->m_archive->getData(Data_Type_Model, 100, (u16)(0x10000 - 2));
                                            if (posRes != NULL) {
                                                nw4r::g3d::ResFile res(posRes);
                                                self->createStagePositions(&res);
                                            } else {
                                                self->createStagePositions();
                                            }
                                        }
                                        self->createWind2ndOnly();
                                        self->registScnAnim(static_cast<nw4r::g3d::ResFileData*>(self->m_archive->getData(Data_Type_Scene, 0, (u16)(0x10000 - 2))), 0);

                                        self->m_vec[0].m_x = rodata[6];
                                        self->m_vec[0].m_y = rodata[0];
                                        self->m_vec[0].m_z = rodata[7];
                                        self->m_vec[1].m_x = rodata[8];
                                        self->m_vec[1].m_y = rodata[0];
                                        self->m_vec[1].m_z = rodata[4];
                                        self->m_vec[2].m_x = rodata[0];
                                        self->m_vec[2].m_y = rodata[0];
                                        self->m_vec[2].m_z = rodata[9];
                                        self->m_vec[3].m_x = rodata[7];
                                        self->m_vec[3].m_y = rodata[0];
                                        self->m_vec[3].m_z = rodata[4];
                                        self->m_vec[4].m_x = rodata[10];
                                        self->m_vec[4].m_y = rodata[0];
                                        self->m_vec[4].m_z = rodata[7];

                                        for (i = 0; i < 5; i++) {
                                            self->m_tenganEvent[i].set(rodata[11], rodata[12]);
                                            tmp = self->m_vec[i];
                                            switch (i) {
                                            case 0: tmp.m_y = rodata[13]; break;
                                            case 1: tmp.m_y = rodata[14]; break;
                                            case 2: tmp.m_y = rodata[15]; break;
                                            case 3: tmp.m_y = rodata[14]; break;
                                            case 4: tmp.m_y = rodata[13]; break;
                                            }
                                            tmp.m_z = rodata[0];
                                            static_cast<grGimmick*>(self->getGround(i + 10))->setPos(&tmp);
                                        }

                                        self->m_tenganEvent570.set(rodata[16], rodata[17]);
                                        self->m_tenganEvent61c.set(rodata[18], rodata[16]);
                                        self->m_tenganEvent6c8.set(rodata[18], rodata[16]);

                                        self->loadStageAttrParam(self->m_archive, 30);
                                        self->initPosPokeTrainer(1, 0);
                                        self->createObjPokeTrainer(self->m_archive, 0x65, names + 0x68, self->m_unkBC, NULL);

                                        u8* mode = (u8*)g_GameGlobal->m_modeMelee;
                                        if (mode != NULL) {
                                            if ((((u32)mode[8] >> 2) & 0x3f) == 7) {
                                                if ((u32)mode[0x10] == 0x1c) {
                                                    self->m_unk831 = 1;
                                                    self->m_unk79a = 0;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
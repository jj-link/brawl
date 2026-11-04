#pragma force_active on
#include <sr/sr_common.h>
#include <gr/collision/gr_collision_data.h>

class gfArchive;
class Ground;
class grCollision;
class stDataMultiContainer;

struct Entry {
    char pad[0x3c];
    unsigned char kind;
    unsigned char collisionIndex;
};

struct Count {
    u32 pad;
    u32 count;
};

class Class_5648 {
public:
    virtual void fn_40_215A4();
    virtual void fn_40_20A6C();
    virtual void fn_40_20A7C();
    virtual Entry* fn_40_1E5E0(u32);
    u32 pad;
    Count* data;
};

class Class_6C68 {
public:
    virtual void fn_40_215A4();
    virtual void fn_40_20A6C();
    virtual void fn_40_20A7C();
    virtual Entry* fn_40_24BA4(u32);
    u32 pad;
    Count* data;
};

class Class_83C8 {
public:
    virtual void fn_40_295F8();
    virtual void fn_40_28A18();
    virtual void fn_40_28A28();
    virtual Entry* fn_40_28908(u32);
    u32 pad;
    Count* data;
};

class Class_CEC8 {
public:
    virtual void fn_40_215A4();
    virtual void fn_40_20A6C();
    virtual void fn_40_20A7C();
    virtual Entry* fn_40_30C08(u32);
    u32 pad;
    Count* data;
};

class Class_D270 {
public:
    virtual void fn_40_295F8();
    virtual void fn_40_28A18();
    virtual void fn_40_28A28();
    virtual Entry* fn_40_30D68(u32);
    u32 pad;
    Count* data;
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
    char pad40[0x160];
    gfArchive* resource;
};

struct grYakumono_base { char pad[0x3c]; };
class grYakumono : public grYakumono_base {
public:
    virtual void slot0();
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
    virtual void slot37(gfArchive*, u32, u32);
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
    virtual void setNodeVisibilityAll();
    virtual void isNodeVisible();
    virtual void setNodeCollision();
    virtual void setNodeCollision_2();
    virtual void getNodeScale();
    virtual void getNodeScale_2();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void setGimmickData(Entry*);
};

struct grGimmickWarpZone_base { char pad[0x3c]; };
class grGimmickWarpZone : public grGimmickWarpZone_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void fn_40_37EA8();
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
    virtual void fn_40_37E50();
    virtual void update();
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
    virtual void getModelCount();
    virtual void startup();
    virtual void setNode();
    virtual void setStageData();
    virtual void getStageData();
    virtual void initStageData();
    virtual void setMdlIndex();
    virtual void getMdlIndex();
    virtual void isEnableCalcCollision();
    virtual void enableCalcCollision();
    virtual void disableCalcCollision();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual void getNodeMatrix();
    virtual void getNodeMatrix_2();
    virtual void setNodeVisibility();
    virtual void setNodeVisibility_2();
    virtual void setNodeVisibilityAll();
    virtual void isNodeVisible();
    virtual void setNodeCollision();
    virtual void setNodeCollision_2();
    virtual void getNodeScale();
    virtual void getNodeScale_2();
    virtual void setValid();
    virtual void setValidAttachedEffect();
    virtual void setInitializeFlag();
    virtual void setInitializeInfo();
    virtual void getInitializeInfo();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void adventureEventGetItem();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void setGimmickData();
};

extern "C" {
extern char lbl_40_data_1B0[];
grYakumono* fn_27_272CF0(short, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
Class_5648* searchContainer__20stDataMultiContainerFUlUl(stDataMultiContainer*, u32, u32);
void testCollDataInit__5StageFP9gfArchiveP10grCollDataUl(Stage*, gfArchive*, grCollData*, u32);
grCollision* create__11grCollisionFP5StagePvP6Groundi(Stage*, void*, Ground*, int);
void setCollision__5StageFP11grCollision(Stage*, grCollision*);

void fn_40_AF64(Stage* stage, u32 type, stDataMultiContainer* multi) {
    grCollData* collData;
    unsigned char collisionIndex;
    Entry* entry;
    grYakumono* ground;
    Class_5648* container;
    u32 index = 0;
    u32 i;

    while ((container = searchContainer__20stDataMultiContainerFUlUl(multi, type, index++)) != 0) {
        for (i = 0; i < container->data->count; ++i) {
            entry = container->fn_40_1E5E0(i);
            ground = fn_27_272CF0((short)entry->kind, lbl_40_data_1B0);
            if (ground) {
                addGround__5StageFP6Ground(stage, (Ground*)ground);
                ground->setGimmickData(entry);
                ground->slot37(stage->resource, 0, 0);
                collisionIndex = entry->collisionIndex;
                if (collisionIndex != 0xff) {
                    collData = (grCollData*)operator new(sizeof(grCollData), Heaps::StageInstance);
                    if (collData) {
                        testCollDataInit__5StageFP9gfArchiveP10grCollDataUl(stage, stage->resource, collData, collisionIndex);
                        setCollision__5StageFP11grCollision(stage, create__11grCollisionFP5StagePvP6Groundi(stage, collData, (Ground*)ground, 1));
                    }
                    operator delete(collData);
                }
            }
        }
    }
}
}

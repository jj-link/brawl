#include <sr/sr_common.h>
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#include <new>
#pragma force_active on

extern "C" void fn_52_35D0(void*, const char*);
extern char lbl_52_data_3C34[];
extern const float lbl_52_rodata_310;

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
    virtual void fn_52_218();
    virtual void fn_52_2B0();
    virtual void createObjPokeTrainer();
    virtual void fn_52_34A0();
    virtual void fn_52_349C();
    virtual void fn_52_3490();
    virtual void fn_52_3488();
    virtual void fn_52_3480();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_52_2A8();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_52_3478();
    virtual void fn_52_3470();
    virtual void getZoneLightSetIndex();
    virtual void fn_52_3454();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_52_3450();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_52_34A8();
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
    virtual void fn_52_3440();
    virtual void fn_52_3448();
    virtual void fn_52_3438();
    virtual void fn_52_3430();
    virtual void fn_52_3428();
    virtual void fn_52_3414();
    virtual void fn_52_3404();
    virtual void fn_52_33F8();
    virtual void fn_52_33EC();
    virtual void fn_52_33E4();
};

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void slot2();
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
    virtual void slot22();
    virtual void slot23();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void slot31();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_52_36EC();
    virtual void startup();
    virtual void setNode();
    virtual void fn_52_83C();
    virtual void fn_52_36E4();
    virtual void fn_52_36E0();
    virtual void fn_52_35C8(const char*);
    virtual void fn_52_36D8();
    virtual void fn_52_36CC();
    virtual void fn_52_36BC();
    virtual void fn_52_36AC();
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
    virtual void fn_52_36A8();
    virtual void fn_52_36A4();
    virtual void fn_52_369C();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_52_3694();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode(const char*);
};

struct ObjectPrefix {
    char pad[0x170];
    ObjectPrefix(const char* name) {
        fn_52_35D0(this, name);
        *(void**)((char*)this + 0x3c) = lbl_52_data_3C34;
    }
};
struct Object : public ObjectPrefix {
    snd3DGenerator generator;
    int sound;
    Object(const char* name) : ObjectPrefix(name) {
        *(unsigned char*)((char*)this + 0x150) = 0;
        *(float*)((char*)this + 0x154) = lbl_52_rodata_310;
        *(int*)((char*)this + 0x160) = 0;
        *(unsigned char*)((char*)this + 0x164) = 3;
        *(float*)((char*)this + 0x168) = lbl_52_rodata_310;
        *(float*)((char*)this + 0x16c) = lbl_52_rodata_310;
        sound = -1;
    }
};

extern "C" void* fn_52_11C50(const char* a, const char* b, const char* c) {
    Object* obj = new (Heaps::StageInstance) Object(c);
    if (obj) {
        ((Ground*)obj)->fn_52_35C8(a);
        ((Ground*)obj)->setTgtNode(b);
    }
    return obj;
}

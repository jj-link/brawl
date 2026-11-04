#pragma force_active on
#include <sr/sr_common.h>

struct Flags { u32 pad; u32 flags; };

class Class_1890 {
public:
    virtual void fn_62_79D0();
    virtual void fn_62_6DF0();
    virtual void fn_62_6E00();
    virtual void fn_62_6134();
    virtual void fn_62_5E28(int, int);
    Flags* data;
    u32 state;
};

class Class_2C60 {
public:
    virtual void fn_62_CA3C();
    virtual void fn_62_BF04();
    virtual void fn_62_BF14();
    virtual void fn_62_A624();
    virtual void fn_62_A3AC();
};

class Class_4768 {
public:
    virtual void fn_62_79D0();
    virtual void fn_62_6DF0();
    virtual void fn_62_6E00();
    virtual void fn_62_F038();
    virtual void fn_62_5E28();
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
    virtual void fn_62_258();
    virtual void fn_62_368();
    virtual void createObjPokeTrainer();
    virtual void fn_62_2A4C();
    virtual void fn_62_2A48();
    virtual void fn_62_2A3C();
    virtual void fn_62_2A34();
    virtual void fn_62_2A2C();
    virtual void fn_62_28A8();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_62_360();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_62_2A24();
    virtual void fn_62_2A1C();
    virtual void getZoneLightSetIndex();
    virtual void fn_62_2A00();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_62_29FC();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_62_2A54();
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
    virtual void fn_62_29EC();
    virtual void fn_62_29F4();
    virtual void fn_62_29E4();
    virtual void fn_62_29DC();
    virtual void fn_62_29D4();
    virtual void fn_62_29C0();
    virtual void fn_62_29B0();
    virtual void fn_62_29A4();
    virtual void fn_62_2998();
    virtual void fn_62_2990();
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
    virtual void fn_62_3114();
    virtual void startup();
    virtual void slot38();
    virtual void fn_62_A44();
    virtual void fn_62_310C();
    virtual void fn_62_3108();
    virtual void fn_62_2C7C(int);
    virtual void fn_62_3100();
    virtual void fn_62_30F4();
    virtual void fn_62_30E4();
    virtual void fn_62_30D4();
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
    virtual void fn_62_30D0();
    virtual void fn_62_30CC();
    virtual void fn_62_30C4();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_62_30BC();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode(const char*);
};

struct Obj {
    Obj(const char* name);
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    char part[0xc];
    char paddc[0x7c];
    u32 f158;
    float f15c;
    float f160;
    float f164;
    u32 f168;
    u32 f16c;
};

extern "C" void fn_62_2C84(void*, const char*);
extern char lbl_62_data_30D8[];
extern const float lbl_62_rodata_158;

inline Obj::Obj(const char* name) {
    fn_62_2C84(this, name);
    vtable = lbl_62_data_30D8;
    f158 = 0;
    f15c = lbl_62_rodata_158;
    f160 = lbl_62_rodata_158;
    f164 = lbl_62_rodata_158;
    f168 = 0;
    f16c = 0;
    Class_1890* p = (Class_1890*)part;
    if (!p)
        return;
    p->state = 1;
    p->fn_62_5E28(0, 15);
    p->data->flags |= 1;
}

extern "C" Obj* fn_62_CDCC(int mdlIndex, const char* node, const char* name) {
    Obj* obj = new (Heaps::StageInstance) Obj(name);
    if (obj) {
        ((Ground*)obj)->fn_62_2C7C(mdlIndex);
        ((Ground*)obj)->setTgtNode(node);
    }
    return obj;
}

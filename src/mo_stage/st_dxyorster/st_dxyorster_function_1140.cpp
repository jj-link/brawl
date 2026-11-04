#pragma force_active on
#include <sr/sr_common.h>

struct Flags { u32 pad; u32 flags; };

class Class_1AB0 {
public:
    virtual void fn_76_6F4C();
    virtual void fn_76_6414();
    virtual void fn_76_6424();
    virtual void fn_76_3F88();
    virtual void fn_76_3BC8(int, int);
    Flags* data;
    u32 state;
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
    virtual void fn_76_100();
    virtual void fn_76_174();
    virtual void createObjPokeTrainer();
    virtual void fn_76_974();
    virtual void fn_76_970();
    virtual void fn_76_964();
    virtual void fn_76_95C();
    virtual void fn_76_954();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_76_16C();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_76_94C();
    virtual void fn_76_944();
    virtual void getZoneLightSetIndex();
    virtual void fn_76_928();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_76_924();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_76_97C();
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
    virtual void fn_76_914();
    virtual void fn_76_91C();
    virtual void fn_76_90C();
    virtual void fn_76_904();
    virtual void fn_76_8FC();
    virtual void fn_76_8E8();
    virtual void fn_76_8D8();
    virtual void fn_76_8CC();
    virtual void fn_76_8C0();
    virtual void fn_76_8B8();
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
    virtual void receiveCollMsg_Landing();
    virtual void slot32();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_76_110C();
    virtual void startup();
    virtual void slot38();
    virtual void fn_76_4F4();
    virtual void fn_76_1104();
    virtual void fn_76_1100();
    virtual void fn_76_BD8(int);
    virtual void fn_76_10F8();
    virtual void fn_76_10EC();
    virtual void fn_76_10DC();
    virtual void fn_76_10CC();
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
    virtual void fn_76_10C8();
    virtual void fn_76_10C4();
    virtual void fn_76_10BC();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_76_10B4();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode(const char*);
};

extern "C" void fn_76_BE0(void*, const char*);
extern char lbl_76_data_8C8[];
extern const float lbl_76_rodata_20;

struct Obj {
    Obj(const char*);
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    char part[0xc];
    char paddc[0x7c];
    u32 f158;
    u32 f15c;
    unsigned char f160;
    unsigned char f161;
    float f164;
    u32 f168;
};

inline Obj::Obj(const char* name) {
    fn_76_BE0(this, name);
    vtable = lbl_76_data_8C8;
    f158 = 0;
    f15c = 0;
    f160 = 0;
    f161 = 3;
    f164 = lbl_76_rodata_20;
    f168 = 0;
    Class_1AB0* p = (Class_1AB0*)part;
    if (!p) return;
    p->state = 1;
    p->fn_76_3BC8(0, 15);
    p->data->flags |= 1;
}

extern "C" Obj* fn_76_1140(int arg0, const char* arg1, const char* arg2) {
    Obj* obj = new (Heaps::StageInstance) Obj(arg2);
    if (obj) {
        ((Ground*)obj)->fn_76_BD8(arg0);
        ((Ground*)obj)->setTgtNode(arg1);
    }
    return obj;
}

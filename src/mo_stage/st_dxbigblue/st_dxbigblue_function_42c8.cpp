#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 pad;
    u32 flags;
};

struct Part {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void clear(int, int);
    Flags* data;
    u32 state;
};

extern char lbl_81_data_A20[];

struct grDxBigBlue {
    grDxBigBlue(const char* name);
    char pad0[0x3C];
    void* vtable;
    char pad40[0x90];
    Part part;
    char padDC[0x7C];
    u32 a158;
    u32 a15c;
    u32 a160;
};

struct grDxBigBlueNew : grDxBigBlue {
    grDxBigBlueNew(const char* name) : grDxBigBlue(name) {
        vtable = lbl_81_data_A20;
        a158 = 0;
        a15c = 0;
        a160 = 0;
        Part* p = &part;
        if (!p) {
            return;
        }
        p->state = 1;
        p->clear(0, 15);
        p->data->flags |= 1;
        p->data->flags |= 2;
    }
};

struct Ground_base {
    char pad[0x3c];
};

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
    virtual void getModelCount();
    virtual void startup();
    virtual void slot38();
    virtual void setStageData();
    virtual void getStageData();
    virtual void initStageData();
    virtual void setMdlIndex(int);
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
    virtual void setTgtNode(const char*);
};

namespace Heaps {
    enum HeapType { StageInstance = 15 };
}

extern void* operator new(unsigned long, Heaps::HeapType);

extern "C" grDxBigBlue* fn_81_42C8(int mdlIndex, const char* node, const char* name) {
    grDxBigBlueNew* obj = new (Heaps::StageInstance) grDxBigBlueNew(name);
    if (obj) {
        ((Ground*)obj)->setMdlIndex(mdlIndex);
        ((Ground*)obj)->setTgtNode(node);
    }
    return obj;
}

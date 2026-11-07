#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" unsigned char lbl_70_data_A68[];
extern "C" const float lbl_70_rodata_28;

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
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
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void slot36();
    virtual void startup();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42(int);
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
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
    virtual void preExit();
    virtual void slot73();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode(const char*);
    char pad1[0x110];
    unsigned char state;
    char pad2[3];
    float value;
    int field;
    unsigned char flag15C;
    char pad3[3];
    int field160;
    int field164;
};

extern "C" Ground* fn_70_1F98(int model, const char* node, const char* name) {
    Ground* p = (Ground*)__nw__FUlQ25Heaps8HeapType(0x168, 15);
    if (p) {
        __ct__10grYakumonoFPCc(p, name);
        *(void**)((char*)p + 0x3c) = lbl_70_data_A68;
        p->state = 0;
        p->value = lbl_70_rodata_28;
        p->field = 0;
        p->flag15C = 0;
        p->field160 = 0;
        p->field164 = 0;
        p->setupMelee();
    }
    if (p) {
        p->slot42(model);
        p->setTgtNode(node);
    }
    return p;
}

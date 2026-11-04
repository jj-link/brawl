#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" unsigned char lbl_49_data_690[];
extern "C" const float lbl_49_rodata_50[];

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
    virtual void fn_49_1900();
    virtual void startup();
    virtual void setNode();
    virtual void fn_49_4AC();
    virtual void fn_49_18F8();
    virtual void fn_49_18F4();
    virtual void fn_49_13A8(int);
    virtual void fn_49_18EC();
    virtual void fn_49_18E0();
    virtual void fn_49_18D0();
    virtual void fn_49_18C0();
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
    virtual void fn_49_18BC();
    virtual void fn_49_18B8();
    virtual void fn_49_18B0();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_49_18A8();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode(const char*);
    char pad1[0x110];
    unsigned char state;
    char pad2[3];
    float frame;
};

extern "C" Ground* fn_49_12D0(int model, const char* node, const char* name) {
    Ground* p = (Ground*)__nw__FUlQ25Heaps8HeapType(0x158, 15);
    if (p) {
        __ct__10grYakumonoFPCc(p, name);
        *(void**)((char*)p + 0x3c) = lbl_49_data_690;
        p->state = 0;
        p->frame = lbl_49_rodata_50[0];
        p->setupMelee();
    }
    if (p) {
        p->fn_49_13A8(model);
        p->setTgtNode(node);
    }
    return p;
}
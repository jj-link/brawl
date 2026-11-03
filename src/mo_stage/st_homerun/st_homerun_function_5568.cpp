#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_88_5610(void*, void*);

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void slot6();
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
    virtual void slot33();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_88_447C();
    virtual void startup();
    virtual void slot38();
    virtual void fn_88_B1C();
    virtual void fn_88_4474();
    virtual void fn_88_4470();
    virtual void fn_88_4360(void*);
    virtual void fn_88_4468();
    virtual void fn_88_445C();
    virtual void fn_88_444C();
    virtual void fn_88_443C();
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
    virtual void fn_88_4438();
    virtual void fn_88_4434();
    virtual void fn_88_442C();
    virtual void setMotionRatio();
    virtual void slot66();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_88_4424();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode(const char*);
};

extern "C" void* fn_88_5568(void* a, void* b, void* c) {
    Ground* obj = (Ground*)__nw__FUlQ25Heaps8HeapType(0x1b4, 0xF);
    if (obj != 0) {
        obj = (Ground*)fn_88_5610(obj, c);
    }
    if (obj != 0) {
        obj->fn_88_4360(a);
        obj->setTgtNode((const char*)b);
    }
    return obj;
}

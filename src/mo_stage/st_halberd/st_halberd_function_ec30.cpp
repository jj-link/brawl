#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_57_ECD8(void*, void*);

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
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_57_3A9C();
    virtual void slot37();
    virtual void setNode();
    virtual void fn_57_638();
    virtual void fn_57_3A94();
    virtual void fn_57_3A90();
    virtual void fn_57_3978(void*);
    virtual void fn_57_3A88();
    virtual void fn_57_3A7C();
    virtual void fn_57_3A6C();
    virtual void fn_57_3A5C();
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
    virtual void fn_57_3A58();
    virtual void fn_57_3A54();
    virtual void fn_57_3A4C();
    virtual void setMotionRatio();
    virtual void slot66();
    virtual void slot67();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_57_3A44();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode(const char*);
};

extern "C" void* fn_57_EC30(void* a, void* b, void* c)
{
    Ground* obj = (Ground*)__nw__FUlQ25Heaps8HeapType(0x278, 0xf);
    if (obj != 0) {
        obj = (Ground*)fn_57_ECD8(obj, c);
    }
    if (obj != 0) {
        obj->fn_57_3978(a);
        obj->setTgtNode((const char*)b);
    }
    return obj;
}
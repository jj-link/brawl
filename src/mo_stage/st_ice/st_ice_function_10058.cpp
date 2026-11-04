#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_62_10100(void*, void*);

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
    virtual void fn_62_2C7C(void*);
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
    virtual void setTgtNode(void*);
};

extern "C" void* fn_62_10058(void* a, void* b, void* c)
{
    Ground* obj = (Ground*)__nw__FUlQ25Heaps8HeapType(0x19c, 0xf);
    if (obj != 0) {
        obj = (Ground*)fn_62_10100(obj, c);
    }
    if (obj != 0) {
        obj->fn_62_2C7C(a);
        obj->setTgtNode(b);
    }
    return obj;
}

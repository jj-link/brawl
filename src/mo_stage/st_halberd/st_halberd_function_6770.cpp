#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_57_6818(void*, void*);

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
    virtual void loadGroundData(void*, unsigned long, void*);
    virtual void bindData(void*);
    virtual void setupMelee();
    virtual void setVisibility(unsigned long);
    virtual void setVisibilityByClipping(unsigned long);
    virtual void setVisibilityAttachedEffect(unsigned long);
    virtual void receiveCollMsg(int, void*, void*);
    virtual void receiveCollMsg_Landing(void*, void*, bool);
    virtual void receiveCollMsg_Heading(void*, void*, bool);
    virtual void receiveCollMsg_Wall(void*, void*, bool);
    virtual void receiveCollMsg_Attack(void*, void*);
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
    virtual void getNodeIndex(unsigned long, const char*);
    virtual void getNodePosition(void*, unsigned long, unsigned long);
    virtual void getNodePosition_2(void*, unsigned long, const char*);
    virtual void getNodeMatrix(void*, unsigned long, unsigned long);
    virtual void getNodeMatrix_2(void*, unsigned long, const char*);
    virtual void setNodeVisibility(bool, unsigned long, unsigned long, bool, bool);
    virtual void setNodeVisibility_2(bool, unsigned long, const char*, bool, bool);
    virtual void setNodeVisibilityAll(bool, unsigned long);
    virtual void isNodeVisible(unsigned long, unsigned long);
    virtual void setNodeCollision(bool, unsigned long, unsigned long, bool);
    virtual void setNodeCollision_2(bool, unsigned long, const char*, bool);
    virtual void getNodeScale(void*, unsigned long, unsigned long);
    virtual void getNodeScale_2(void*, unsigned long, const char*);
    virtual void setValid(unsigned long);
    virtual void setValidAttachedEffect(unsigned long);
    virtual void fn_57_3A58();
    virtual void fn_57_3A54();
    virtual void fn_57_3A4C();
    virtual void setMotionRatio(float);
    virtual void slot66();
    virtual void slot67();
    virtual void setMotionLoop(bool, unsigned long);
    virtual void setMatAlphaMul(unsigned long, unsigned long);
    virtual void setMatAlpha(unsigned long, unsigned long);
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_57_3A44();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag(char);
    virtual void updateCallback(unsigned long);
    virtual void fixedPosition(float);
    virtual void setTgtNode(const char*);
};

extern "C" void* fn_57_6770(void* a, void* b, void* c)
{
    Ground* obj = (Ground*)__nw__FUlQ25Heaps8HeapType(0x2ec, 0xf);
    if (obj != 0) {
        obj = (Ground*)fn_57_6818(obj, c);
    }
    if (obj != 0) {
        obj->fn_57_3978(a);
        obj->setTgtNode((const char*)b);
    }
    return obj;
}

class Vec3f;
#include <snd/snd_3d_generator.h>
#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_51_3BAC(void*, void*);
void __ct__14snd3DGeneratorFv(void*);
extern char lbl_51_data_7864[];
}
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
    virtual void fn_51_33B4();
    virtual void slot37();
    virtual void slot38();
    virtual void fn_51_994();
    virtual void fn_51_33AC();
    virtual void fn_51_33A8();
    virtual void fn_51_2830(int);
    virtual void fn_51_33A0();
    virtual void fn_51_3394();
    virtual void fn_51_3384();
    virtual void fn_51_3374();
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
    virtual void fn_51_336C();
    virtual void fn_51_3364();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_51_335C();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode(const char*);
};
extern "C" void* fn_51_10FB4(int a, int b, int c) {
    Ground* obj = (Ground*)__nw__FUlQ25Heaps8HeapType(0x1b4, 0xf);
    if (obj != 0) {
        fn_51_3BAC(obj, (void*)c);
        *(void**)((char*)obj + 0x3c) = lbl_51_data_7864;
        __ct__14snd3DGeneratorFv((char*)obj + 0x1a8);
        *(int*)((char*)obj + 0x194) = 0;
        *(int*)((char*)obj + 0x198) = 0;
        *(int*)((char*)obj + 0x19c) = 0;
        *(int*)((char*)obj + 0x1a0) = 0;
        *(int*)((char*)obj + 0x1a4) = 0;
        *(int*)((char*)obj + 0x1b0) = -1;
    }
    if (obj != 0) {
        obj->fn_51_2830(a);
        obj->setTgtNode((const char*)b);
    }
    return obj;
}
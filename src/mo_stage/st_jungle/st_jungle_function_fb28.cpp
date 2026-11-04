#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#include <string.h>
#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_51_3BAC(void*, void*);
void __ct__14snd3DGeneratorFv(snd3DGenerator*);
extern char lbl_51_data_6200[];
extern float lbl_51_rodata_178;
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
    virtual void fn_51_2830(void*);
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
    virtual void setTgtNode(void*);
};
extern "C" void* fn_51_FB28(void* a, void* b, void* c) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x1cc, 0xf);
    if (obj) {
        fn_51_3BAC(obj, c);
        *(void**)((char*)obj + 0x3c) = lbl_51_data_6200;
        __ct__14snd3DGeneratorFv((snd3DGenerator*)((char*)obj + 0x1c4));
        float value = lbl_51_rodata_178;
        *(float*)((char*)obj + 0x198) = value;
        *(float*)((char*)obj + 0x19c) = value;
        *(float*)((char*)obj + 0x1a0) = value;
        *(float*)((char*)obj + 0x1a4) = value;
        memset((char*)obj + 0x1a8, 0, 0x1c);
        *(int*)((char*)obj + 0x194) = 0;
    }
    if (obj) {
        ((Ground*)obj)->fn_51_2830(a);
        ((Ground*)obj)->setTgtNode(b);
    }
    return obj;
}
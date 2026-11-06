#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
void fn_73_34A4(void* a, int b);
void __ct__14snd3DGeneratorFv(void* a);
extern char lbl_73_data_2DD0[];
extern float lbl_73_rodata_78;
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
    virtual void fn_73_33B4();
    virtual void slot37();
    virtual void slot38();
    virtual void fn_73_994();
    virtual void fn_73_33AC();
    virtual void fn_73_33A8();
    virtual void fn_73_2C5C(int a);
    virtual void fn_73_33A0();
    virtual void fn_73_3394();
    virtual void fn_73_3384();
    virtual void fn_73_3374();
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
    virtual void fn_73_336C();
    virtual void fn_73_3364();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_73_335C();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode(const char* name);
};

extern "C" void* fn_73_675C(int arg0, const char* arg1, void* arg2) {
    Ground* obj = (Ground*)__nw__FUlQ25Heaps8HeapType(0x2b0, 0xf);
    if (obj) {
        fn_73_34A4(obj, (int)arg2);
        *(void**)((char*)obj + 0x3c) = lbl_73_data_2DD0;
        __ct__14snd3DGeneratorFv((char*)obj + 0x2a8);
        *(int*)((char*)obj + 0x294) = 0;
        float f = lbl_73_rodata_78;
        *(char*)((char*)obj + 0x298) = 0;
        *(float*)((char*)obj + 0x29c) = f;
        *(float*)((char*)obj + 0x2a0) = f;
        *(float*)((char*)obj + 0x2a4) = f;
    }
    if (obj) {
        obj->fn_73_2C5C(arg0);
        obj->setTgtNode(arg1);
    }
    return obj;
}
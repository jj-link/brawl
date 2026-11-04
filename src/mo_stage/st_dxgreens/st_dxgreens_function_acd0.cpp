#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_79_1A64(void*, const char*);
extern unsigned char lbl_79_data_2E70[];
extern const float lbl_79_rodata_60;
}

struct Ground_base {
    char pad[0x3c];
};

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
    virtual void fn_79_ADB4();
    virtual void fn_79_AE0C();
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
    virtual void fn_79_1B64();
    virtual void startup();
    virtual void setNode();
    virtual void fn_79_624();
    virtual void fn_79_1B5C();
    virtual void fn_79_1B58();
    virtual void fn_79_1A5C(void*);
    virtual void fn_79_1B50();
    virtual void fn_79_1B44();
    virtual void fn_79_1B34();
    virtual void fn_79_1B24();
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
    virtual void fn_79_1B20();
    virtual void fn_79_1B1C();
    virtual void fn_79_1B14();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_79_1B0C();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode(const char*);

    char pad40[0x150 - 0x40];
    unsigned char field150;
    float field154;
    int field158;
    unsigned char field15C;
    float field160;
    float field164;
    unsigned char field168;
    int field16C;
    int field170;
};

extern "C" Ground* fn_79_ACD0(void* a, void* b, const char* name) {
    Ground* obj = (Ground*)__nw__FUlQ25Heaps8HeapType(0x174, 0xF);
    if (obj != 0) {
        fn_79_1A64(obj, name);
        *(unsigned char**)((char*)obj + 0x3C) = lbl_79_data_2E70;
        obj->field150 = 0;
        obj->field154 = lbl_79_rodata_60;
        obj->field158 = 0;
        obj->field15C = 11;
        obj->field160 = lbl_79_rodata_60;
        obj->field164 = lbl_79_rodata_60;
        obj->field168 = 0;
        obj->field16C = 0;
        obj->field170 = 0;
    }
    if (obj != 0) {
        obj->fn_79_1A5C(a);
        obj->setTgtNode((const char*)b);
    }
    return obj;
}

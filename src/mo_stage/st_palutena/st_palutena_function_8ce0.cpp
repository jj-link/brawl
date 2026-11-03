#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_67_223C(void*, void*);
extern "C" char lbl_67_data_1F20[];
extern "C" const float lbl_67_rodata_80[];

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void slot2();
    virtual void slot3();
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
    virtual void fn_67_2168();
    virtual void slot37();
    virtual void slot38();
    virtual void fn_67_880();
    virtual void fn_67_2160();
    virtual void fn_67_888();
    virtual void fn_67_2050(void*);
    virtual void fn_67_2158();
    virtual void fn_67_214C();
    virtual void fn_67_213C();
    virtual void fn_67_212C();
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
    virtual void slot60();
    virtual void slot61();
    virtual void fn_67_2128();
    virtual void fn_67_2124();
    virtual void fn_67_211C();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void slot72();
    virtual void fn_67_2114();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode(void*);
    char pad2[0xc0 - 0x40];
    int c0, c4;
    char pad3[0x1d1 - 0xc8];
    unsigned char d1, d2;
    char pad4;
    float d4, d8, dc, e0, e4, e8, ec, f0;
};

extern "C" void* fn_67_8CE0(void* a, void* b, void* c)
{
    Ground* obj = (Ground*)__nw__FUlQ25Heaps8HeapType(0x1f4, 0xf);
    if (obj) {
        fn_67_223C(obj, c);
        *(void**)((char*)obj + 0x3c) = lbl_67_data_1F20;
        obj->e8 = lbl_67_rodata_80[0];
        obj->ec = lbl_67_rodata_80[0];
        obj->f0 = lbl_67_rodata_80[0];
        obj->dc = lbl_67_rodata_80[0];
        obj->e0 = lbl_67_rodata_80[0];
        obj->e4 = lbl_67_rodata_80[0];
        obj->c0 = -1;
        obj->c4 = -1;
        obj->d1 = 0;
        obj->d2 = 0;
        obj->d4 = lbl_67_rodata_80[0];
        obj->d8 = lbl_67_rodata_80[0];
    }
    if (obj) {
        obj->fn_67_2050(a);
        obj->setTgtNode(b);
    }
    return obj;
}
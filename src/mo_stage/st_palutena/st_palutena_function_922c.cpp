#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_67_C978(void*, const char*);
extern "C" char lbl_67_data_2188[];
extern "C" const float lbl_67_rodata_B0;

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
    char pad2[0x15c - 0x40];
    int f15C;
    unsigned char f160;
    char pad3[3];
    float f164, f168;
    int f16C;
    unsigned char f170, f171;
    char pad4[2];
    float f174;
    unsigned char f178;
    char pad5[3];
};

extern "C" void* fn_67_922C(void* a, void* b, const char* c)
{
    Ground* obj = (Ground*)__nw__FUlQ25Heaps8HeapType(0x17c, 0xf);
    if (obj) {
        fn_67_C978(obj, c);
        *(void**)((char*)obj + 0x3c) = lbl_67_data_2188;
        obj->f15C = 0;
        obj->f160 = 0;
        obj->f164 = lbl_67_rodata_B0;
        obj->f168 = lbl_67_rodata_B0;
        obj->f16C = 0;
        obj->f170 = 0;
        obj->f171 = 1;
        obj->f174 = lbl_67_rodata_B0;
        obj->f178 = 0;
    }
    if (obj) {
        obj->fn_67_2050(a);
        obj->setTgtNode(b);
    }
    return obj;
}

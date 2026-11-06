#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
void fn_51_3BAC(void* a, void* b);
void __ct__14snd3DGeneratorFv(void* a);
extern char lbl_51_data_2C20[];
extern float lbl_51_rodata_A0;
}

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();  // offset 0x8
    virtual void processBegin();  // offset 0xc
    virtual void slot2();  // offset 0x10
    virtual void processUpdate();  // offset 0x14
    virtual void processPreMapCorrection();  // offset 0x18
    virtual void processMapCorrection();  // offset 0x1c
    virtual void processFixPosition();  // offset 0x20
    virtual void processPreCollision();  // offset 0x24
    virtual void processCollision();  // offset 0x28
    virtual void processCatch();  // offset 0x2c
    virtual void processHit();  // offset 0x30
    virtual void processCamera();  // offset 0x34
    virtual void processFixCamera();  // offset 0x38
    virtual void processEffect();  // offset 0x3c
    virtual void processGameProc();  // offset 0x40
    virtual void processEnd();  // offset 0x44
    virtual void renderPre();  // offset 0x48
    virtual void renderOpa();  // offset 0x4c
    virtual void renderXlu();  // offset 0x50
    virtual void processDebug();  // offset 0x54
    virtual void renderDebug();  // offset 0x58
    virtual void init();  // offset 0x5c
    virtual void slot22();  // offset 0x60
    virtual void slot23();  // offset 0x64
    virtual void loadGroundData();  // offset 0x68
    virtual void bindData();  // offset 0x6c
    virtual void setupMelee();  // offset 0x70
    virtual void setVisibility();  // offset 0x74
    virtual void setVisibilityByClipping();  // offset 0x78
    virtual void setVisibilityAttachedEffect();  // offset 0x7c
    virtual void receiveCollMsg();  // offset 0x80
    virtual void receiveCollMsg_Landing();  // offset 0x84
    virtual void receiveCollMsg_Heading();  // offset 0x88
    virtual void receiveCollMsg_Wall();  // offset 0x8c
    virtual void receiveCollMsg_Attack();  // offset 0x90
    virtual void unloadData();  // offset 0x94
    virtual void fn_51_33B4();  // offset 0x98
    virtual void slot37();  // offset 0x9c
    virtual void slot38();  // offset 0xa0
    virtual void fn_51_994();  // offset 0xa4
    virtual void fn_51_33AC();  // offset 0xa8
    virtual void fn_51_33A8();  // offset 0xac
    virtual void fn_51_2830(int a);  // offset 0xb0
    virtual void fn_51_33A0();  // offset 0xb4
    virtual void fn_51_3394();  // offset 0xb8
    virtual void fn_51_3384();  // offset 0xbc
    virtual void fn_51_3374();  // offset 0xc0
    virtual void getNodeIndex();  // offset 0xc4
    virtual void getNodePosition();  // offset 0xc8
    virtual void getNodePosition_2();  // offset 0xcc
    virtual void getNodeMatrix();  // offset 0xd0
    virtual void getNodeMatrix_2();  // offset 0xd4
    virtual void setNodeVisibility();  // offset 0xd8
    virtual void setNodeVisibility_2();  // offset 0xdc
    virtual void setNodeVisibilityAll();  // offset 0xe0
    virtual void isNodeVisible();  // offset 0xe4
    virtual void setNodeCollision();  // offset 0xe8
    virtual void setNodeCollision_2();  // offset 0xec
    virtual void getNodeScale();  // offset 0xf0
    virtual void getNodeScale_2();  // offset 0xf4
    virtual void setValid();  // offset 0xf8
    virtual void setValidAttachedEffect();  // offset 0xfc
    virtual void slot62();  // offset 0x100
    virtual void fn_51_336C();  // offset 0x104
    virtual void fn_51_3364();  // offset 0x108
    virtual void setMotionRatio();  // offset 0x10c
    virtual void setMotionFrame();  // offset 0x110
    virtual void getMotionFrame();  // offset 0x114
    virtual void setMotionLoop();  // offset 0x118
    virtual void setMatAlphaMul();  // offset 0x11c
    virtual void setMatAlpha();  // offset 0x120
    virtual void updateG3dProcCalcWorld();  // offset 0x124
    virtual void preExit();  // offset 0x128
    virtual void fn_51_335C();  // offset 0x12c
    virtual void invalidatedByCameraClipping();  // offset 0x130
    virtual void setTransparencyFlag();  // offset 0x134
    virtual void updateCallback();  // offset 0x138
    virtual void fixedPosition();  // offset 0x13c
    virtual void setTgtNode(const char* name);  // offset 0x140
};

extern "C" void* fn_51_B224(int arg0, const char* arg1, void* arg2) {
    Ground* obj = (Ground*)__nw__FUlQ25Heaps8HeapType(0x1b8, 0xf);
    if (obj) {
        fn_51_3BAC(obj, arg2);
        *(void**)((char*)obj + 0x3c) = lbl_51_data_2C20;
        __ct__14snd3DGeneratorFv((char*)obj + 0x1b0);
        *(int*)((char*)obj + 0x194) = 0;
        float f = lbl_51_rodata_A0;
        *(float*)((char*)obj + 0x198) = f;
        *(float*)((char*)obj + 0x19c) = f;
        *(float*)((char*)obj + 0x1a0) = f;
        *(float*)((char*)obj + 0x1a4) = f;
        *(int*)((char*)obj + 0x1a8) = 0;
        *(int*)((char*)obj + 0x1ac) = 0;
    }
    if (obj) {
        obj->fn_51_2830(arg0);
        obj->setTgtNode(arg1);
    }
    return obj;
}

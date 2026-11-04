#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_63_10C5C(void*, int);
extern "C" char lbl_63_data_4E30[];
extern "C" const float lbl_63_rodata_18C;
struct Inner { char pad0[4]; unsigned int flags; char pad8[0x7c]; unsigned int flags84; };
class Class_47D8 {
public:
virtual void fn_63_EF70();
virtual void fn_63_E390();
virtual void fn_63_E3A0();
virtual void fn_63_10B3C();
virtual void fn_63_AA10(int,int);
virtual void fn_63_10A54();
Inner* inner; int mode;
};
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
virtual void slot14();
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
virtual void fn_63_3378();
virtual void slot37();
virtual void slot38();
virtual void fn_63_59C();
virtual void fn_63_3370();
virtual void fn_63_336C();
virtual void fn_63_2B64(int);
virtual void fn_63_3364();
virtual void fn_63_3358();
virtual void fn_63_3348();
virtual void fn_63_3338();
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
virtual void fn_63_3330();
virtual void fn_63_3328();
virtual void setMotionRatio();
virtual void setMotionFrame();
virtual void getMotionFrame();
virtual void setMotionLoop();
virtual void setMatAlphaMul();
virtual void setMatAlpha();
virtual void updateG3dProcCalcWorld();
virtual void preExit();
virtual void fn_63_3320();
virtual void invalidatedByCameraClipping();
virtual void setTransparencyFlag();
virtual void updateCallback();
virtual void fixedPosition();
virtual void setTgtNode(int);
char pad40[0x90]; Class_47D8 component; char padDC[0xd0];
unsigned char a1ac; char pad1ad[3]; int a1b0; float a1b4;
};
inline Ground* setup(Ground* obj, Class_47D8*& p) {
    if (!p) return obj;
    p->fn_63_10A54();
    p->mode = 2;
    p->fn_63_AA10(0, 15);
    p->inner->flags |= 1;
    p->inner->flags |= 4;
    p->inner->flags84 |= 1;
    return obj;
}
extern "C" Ground* fn_63_13148(int a,int b,int c) {
    Ground* obj = (Ground*)__nw__FUlQ25Heaps8HeapType(0x1b8,15);
    if(obj) {
        fn_63_10C5C(obj,c);
        obj->a1ac = 0;
        obj->a1b0 = -1;
        *(void**)((char*)obj + 0x3c) = lbl_63_data_4E30;
        obj->a1b4 = lbl_63_rodata_18C;
        Class_47D8* p = &obj->component;
        obj = setup(obj,p);
    }
    if(obj) { obj->fn_63_2B64(a); obj->setTgtNode(b); }
    return obj;
}

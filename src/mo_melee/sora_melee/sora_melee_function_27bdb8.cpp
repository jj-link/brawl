#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_270838(void*, const char*);
void makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(void*, unsigned long, int);
void setCalcuCallbackRoot__9grGimmickFUl(void*, unsigned long);
extern char lbl_27_data_5A6F0[];
}

struct Ground_base {
    unsigned char pad[0x3C];
};

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
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void loadGroundData();
    virtual void slot25();
    virtual void setupMelee();
    virtual void slot27();
    virtual void setVisibilityByClipping();
    virtual void slot29();
    virtual void receiveCollMsg();
    virtual void slot31();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void getModelCount();
    virtual void slot37();
    virtual void slot38();
    virtual void setStageData();
    virtual void getStageData();
    virtual void initStageData();
    virtual void setMdlIndex(int);
};

extern "C" Ground* fn_27_27BDB8(int arg0, const char* arg1) {
    Ground* p = (Ground*)__nw__FUlQ25Heaps8HeapType(0x1F0, 15);
    if (p) {
        fn_27_270838(p, arg1);
        *(char**)((char*)p + 0x3C) = lbl_27_data_5A6F0;
        *(int*)((char*)p + 0x1E0) = 0;
        *(int*)((char*)p + 0x1E4) = 0;
        makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(p, 1, 15);
        setCalcuCallbackRoot__9grGimmickFUl(p, 3);
        *(unsigned char*)((char*)p + 0x1EC) = 0;
        *(unsigned char*)((char*)p + 0x1ED) = 0;
        *(unsigned char*)((char*)p + 0x1EE) = 0;
        *(unsigned char*)((char*)p + 0x1EF) = 0;
    }
    if (p) {
        p->setMdlIndex(arg0);
    }
    p->setupMelee();
    return p;
}

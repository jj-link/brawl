#pragma force_active on

typedef unsigned int u32;

namespace Heaps {
    enum HeapType { StageInstance = 15 };
}

extern void* operator new(unsigned long, Heaps::HeapType);
extern "C" void fn_54_2C48(void*, const char*);
extern char lbl_54_data_27E8[];
extern const float lbl_54_rodata_100;

struct Flags {
    u32 pad;
    u32 flags;
};

struct Part {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void clear(int, int);
    Flags* data;
    u32 state;
};

struct Obj {
    Obj(const char* name);

    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    char part[0xc];
    char paddc[0x80];
    u32 f15c;
    u32 f160;
    unsigned char f164;
    float f168;
};

inline Obj::Obj(const char* name) {
    fn_54_2C48(this, name);
    vtable = lbl_54_data_27E8;
    f15c = 0;
    f160 = 0;
    f164 = 2;
    f168 = lbl_54_rodata_100;
    Part* p = (Part*)part;
    if (!p)
        return;
    p->state = 1;
    p->clear(0, 15);
    p->data->flags |= 1;
}

struct Base {
    char pad[0x3c];
};

struct CallObj : Base {
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
    virtual void fn_54_338C();
    virtual void startup();
    virtual void slot38();
    virtual void fn_54_1310();
    virtual void fn_54_3150();
    virtual void fn_54_3388();
    virtual void fn_54_2C40(int);
    virtual void fn_54_3380();
    virtual void fn_54_3374();
    virtual void fn_54_3364();
    virtual void fn_54_3354();
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
    virtual void fn_54_3350();
    virtual void fn_54_334C();
    virtual void fn_54_3344();
    virtual void setMotionRatio();
    virtual void slot66();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_54_333C();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode(const char*);
};

extern "C" Obj* fn_54_C060(int arg0, const char* arg1, const char* arg2) {
    Obj* obj = new (Heaps::StageInstance) Obj(arg2);
    if (obj) {
        ((CallObj*)obj)->fn_54_2C40(arg0);
        ((CallObj*)obj)->setTgtNode(arg1);
    }
    return obj;
}

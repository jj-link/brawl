#pragma force_active on

typedef unsigned int u32;

struct Flags { u32 pad; u32 flags; };
class Class_1410 {
public:
    virtual void fn_79_9A10();
    virtual void fn_79_8E30();
    virtual void fn_79_8E40();
    virtual void fn_79_56EC();
    virtual void fn_79_5350(int, int);
    Flags* data;
    u32 state;
};
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault(); virtual void processBegin(); virtual void processAnim(); virtual void processUpdate();
    virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void processFixPosition(); virtual void processPreCollision();
    virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera();
    virtual void processFixCamera(); virtual void processEffect(); virtual void processGameProc(); virtual void processEnd();
    virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug();
    virtual void renderDebug(); virtual void init(); virtual void slot22(); virtual void slot23();
    virtual void loadGroundData(); virtual void bindData(); virtual void setupMelee(); virtual void setVisibility();
    virtual void setVisibilityByClipping(); virtual void setVisibilityAttachedEffect(); virtual void receiveCollMsg(); virtual void receiveCollMsg_Landing();
    virtual void slot32(); virtual void receiveCollMsg_Wall(); virtual void receiveCollMsg_Attack(); virtual void unloadData();
    virtual void fn_79_1B64(); virtual void startup(); virtual void slot38(); virtual void fn_79_624();
    virtual void fn_79_1B5C(); virtual void fn_79_1B58(); virtual void fn_79_1A5C(int); virtual void fn_79_1B50();
    virtual void fn_79_1B44(); virtual void fn_79_1B34(); virtual void fn_79_1B24(); virtual void getNodeIndex();
    virtual void getNodePosition(); virtual void getNodePosition_2(); virtual void getNodeMatrix(); virtual void getNodeMatrix_2();
    virtual void setNodeVisibility(); virtual void setNodeVisibility_2(); virtual void setNodeVisibilityAll(); virtual void isNodeVisible();
    virtual void setNodeCollision(); virtual void setNodeCollision_2(); virtual void getNodeScale(); virtual void getNodeScale_2();
    virtual void setValid(); virtual void setValidAttachedEffect(); virtual void fn_79_1B20(); virtual void fn_79_1B1C();
    virtual void fn_79_1B14(); virtual void setMotionRatio(); virtual void setMotionFrame(); virtual void getMotionFrame();
    virtual void setMotionLoop(); virtual void setMatAlphaMul(); virtual void setMatAlpha(); virtual void updateG3dProcCalcWorld();
    virtual void slot72(); virtual void fn_79_1B0C(); virtual void invalidatedByCameraClipping(); virtual void setTransparencyFlag();
    virtual void updateCallback(); virtual void fixedPosition(); virtual void setTgtNode(const char*);
};

struct Obj {
    Obj(const char* name);
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    char part[0xc];
    char paddc[0x74];
    unsigned char f150;
    float f154;
    float f158;
    u32 pad15c;
    u32 f160;
    unsigned char f164;
};

namespace Heaps { enum HeapType { StageInstance = 15 }; }

extern void* operator new(unsigned long, Heaps::HeapType);
extern "C" void fn_79_1A64(void*, const char*);
extern char lbl_79_data_2C08[];
extern const float lbl_79_rodata_50;

inline Obj::Obj(const char* name) {
    fn_79_1A64(this, name);
    vtable = lbl_79_data_2C08;
    f150 = 0;
    f154 = lbl_79_rodata_50;
    f158 = lbl_79_rodata_50;
    f160 = 0;
    f164 = 0;
    Class_1410* p = (Class_1410*)part;
    if (!p)
        return;
    p->state = 1;
    p->fn_79_5350(0, 15);
    p->data->flags |= 1;
}

extern "C" Obj* fn_79_A6B0(int arg0, const char* arg1, const char* arg2) {
    Obj* obj = new (Heaps::StageInstance) Obj(arg2);
    if (obj) {
        ((Ground*)obj)->fn_79_1A5C(arg0);
        ((Ground*)obj)->setTgtNode(arg1);
    }
    return obj;
}

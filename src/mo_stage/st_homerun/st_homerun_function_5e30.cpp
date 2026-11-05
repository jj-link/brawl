#pragma force_active on
typedef unsigned int u32;
struct Flags { u32 pad; u32 flags; };
class Part {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void clear(int, int);
    Flags* data;
    u32 state;
};
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault(); virtual void processBegin(); virtual void processAnim(); virtual void processUpdate();
    virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void slot6(); virtual void processPreCollision();
    virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera();
    virtual void processFixCamera(); virtual void processEffect(); virtual void processGameProc(); virtual void processEnd();
    virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug();
    virtual void renderDebug(); virtual void init(); virtual void slot22(); virtual void slot23();
    virtual void loadGroundData(); virtual void bindData(); virtual void setupMelee(); virtual void setVisibility();
    virtual void setVisibilityByClipping(); virtual void setVisibilityAttachedEffect(); virtual void receiveCollMsg(); virtual void slot31();
    virtual void receiveCollMsg_Heading(); virtual void slot33(); virtual void receiveCollMsg_Attack(); virtual void unloadData();
    virtual void fn_88_447C(); virtual void startup(); virtual void slot38(); virtual void fn_88_B1C();
    virtual void fn_88_4474(); virtual void fn_88_4470(); virtual void fn_88_4360(int); virtual void fn_88_4468();
    virtual void fn_88_445C(); virtual void fn_88_444C(); virtual void fn_88_443C(); virtual void getNodeIndex();
    virtual void getNodePosition(); virtual void getNodePosition_2(); virtual void getNodeMatrix(); virtual void getNodeMatrix_2();
    virtual void setNodeVisibility(); virtual void setNodeVisibility_2(); virtual void setNodeVisibilityAll(); virtual void isNodeVisible();
    virtual void setNodeCollision(); virtual void setNodeCollision_2(); virtual void getNodeScale(); virtual void getNodeScale_2();
    virtual void setValid(); virtual void setValidAttachedEffect(); virtual void fn_88_4438(); virtual void fn_88_4434();
    virtual void fn_88_442C(); virtual void setMotionRatio(); virtual void slot66(); virtual void getMotionFrame();
    virtual void setMotionLoop(); virtual void setMatAlphaMul(); virtual void setMatAlpha(); virtual void updateG3dProcCalcWorld();
    virtual void preExit(); virtual void fn_88_4424(); virtual void invalidatedByCameraClipping(); virtual void setTransparencyFlag();
    virtual void updateCallback(); virtual void fixedPosition(); virtual void setTgtNode(const char*);
};
struct Obj {
    Obj(const char*);
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    char part[0xc];
    char paddc[0xa4];
    float x, y, z;
};
namespace Heaps { enum HeapType { StageInstance = 15 }; }
extern void* operator new(unsigned long, Heaps::HeapType);
extern "C" Obj* fn_88_4CFC(Obj*, const char*);
extern char lbl_88_data_17D8[];
extern const float lbl_88_rodata_118;
inline Obj::Obj(const char* name) {
    fn_88_4CFC(this, name);
    vtable = lbl_88_data_17D8;
    float zero = lbl_88_rodata_118;
    x = zero;
    y = zero;
    z = zero;
    Part* p = (Part*)part;
    if (!p) return;
    p->state = 1;
    p->clear(0, 15);
    p->data->flags |= 1;
    p->data->flags |= 0x10;
}
extern "C" Obj* fn_88_5E30(int arg0, const char* arg1, const char* arg2) {
    Obj* obj = new (Heaps::StageInstance) Obj(arg2);
    if (obj) {
        ((Ground*)obj)->fn_88_4360(arg0);
        ((Ground*)obj)->setTgtNode(arg1);
    }
    return obj;
}

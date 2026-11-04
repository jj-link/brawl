#pragma force_active on
typedef unsigned int u32;
struct Flags { u32 pad; u32 flags; };
class Class_2110 {
public:
    virtual void fn_57_C674();
    virtual void fn_57_BA94();
    virtual void fn_57_BAA4();
    virtual void fn_57_ADD8();
    virtual void fn_57_AB4C(int, int);
    Flags* data;
    u32 state;
};
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault(); virtual void processBegin(); virtual void slot2(); virtual void processUpdate();
    virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void processFixPosition(); virtual void processPreCollision();
    virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera();
    virtual void processFixCamera(); virtual void processEffect(); virtual void processGameProc(); virtual void processEnd();
    virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug();
    virtual void renderDebug(); virtual void init(); virtual void slot22(); virtual void slot23();
    virtual void loadGroundData(); virtual void bindData(); virtual void setupMelee(); virtual void setVisibility();
    virtual void setVisibilityByClipping(); virtual void setVisibilityAttachedEffect(); virtual void receiveCollMsg(); virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading(); virtual void receiveCollMsg_Wall(); virtual void receiveCollMsg_Attack(); virtual void unloadData();
    virtual void fn_57_3A9C(); virtual void slot37(); virtual void setNode(); virtual void fn_57_638();
    virtual void fn_57_3A94(); virtual void fn_57_3A90(); virtual void fn_57_3978(int); virtual void fn_57_3A88();
    virtual void fn_57_3A7C(); virtual void fn_57_3A6C(); virtual void fn_57_3A5C(); virtual void getNodeIndex();
    virtual void getNodePosition(); virtual void getNodePosition_2(); virtual void getNodeMatrix(); virtual void getNodeMatrix_2();
    virtual void setNodeVisibility(); virtual void setNodeVisibility_2(); virtual void setNodeVisibilityAll(); virtual void isNodeVisible();
    virtual void setNodeCollision(); virtual void setNodeCollision_2(); virtual void getNodeScale(); virtual void getNodeScale_2();
    virtual void setValid(); virtual void setValidAttachedEffect(); virtual void fn_57_3A58(); virtual void fn_57_3A54();
    virtual void fn_57_3A4C(); virtual void setMotionRatio(); virtual void slot66(); virtual void slot67();
    virtual void setMotionLoop(); virtual void setMatAlphaMul(); virtual void setMatAlpha(); virtual void updateG3dProcCalcWorld();
    virtual void preExit(); virtual void fn_57_3A44(); virtual void invalidatedByCameraClipping(); virtual void setTransparencyFlag();
    virtual void updateCallback(); virtual void fixedPosition(); virtual void setTgtNode(const char*);
};
struct Obj {
    Obj(const char*);
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    char part[0xc];
    char paddc[0x84];
    u32 f160;
    unsigned char f164, f165;
    float f168;
};
namespace Heaps { enum HeapType { StageInstance = 15 }; }
extern void* operator new(unsigned long, Heaps::HeapType);
extern "C" Obj* fn_57_3980(Obj*, const char*);
extern char lbl_57_data_C30[];
extern const float lbl_57_rodata_188;
inline Obj::Obj(const char* name) {
    fn_57_3980(this, name);
    vtable = lbl_57_data_C30;
    f160 = 0;
    f164 = 0;
    f165 = 2;
    f168 = lbl_57_rodata_188;
    Class_2110* p = (Class_2110*)part;
    if (!p) return;
    p->state = 1;
    p->fn_57_AB4C(0, 15);
    p->data->flags |= 8;
}
extern "C" Obj* fn_57_4D68(int arg0, const char* arg1, const char* arg2) {
    Obj* obj = new (Heaps::StageInstance) Obj(arg2);
    if (obj) {
        ((Ground*)obj)->fn_57_3978(arg0);
        ((Ground*)obj)->setTgtNode(arg1);
    }
    return obj;
}
#pragma force_active on
typedef unsigned int u32;
struct Flags { u32 pad; u32 flags; };
class Class_1700 {
public:
    virtual void fn_49_9368();
    virtual void fn_49_8830();
    virtual void fn_49_8840();
    virtual void fn_49_6D28();
    virtual void fn_49_6970(int, int);
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
    virtual void receiveCollMsg_Heading(); virtual void receiveCollMsg_Wall(); virtual void receiveCollMsg_Attack(); virtual void unloadData();
    virtual void fn_49_1900(); virtual void startup(); virtual void setNode(); virtual void fn_49_4AC();
    virtual void fn_49_18F8(); virtual void fn_49_18F4(); virtual void fn_49_13A8(int); virtual void fn_49_18EC();
    virtual void fn_49_18E0(); virtual void fn_49_18D0(); virtual void fn_49_18C0(); virtual void getNodeIndex();
    virtual void getNodePosition(); virtual void getNodePosition_2(); virtual void getNodeMatrix(); virtual void getNodeMatrix_2();
    virtual void setNodeVisibility(); virtual void setNodeVisibility_2(); virtual void setNodeVisibilityAll(); virtual void isNodeVisible();
    virtual void setNodeCollision(); virtual void setNodeCollision_2(); virtual void getNodeScale(); virtual void getNodeScale_2();
    virtual void setValid(); virtual void setValidAttachedEffect(); virtual void fn_49_18BC(); virtual void fn_49_18B8();
    virtual void fn_49_18B0(); virtual void setMotionRatio(); virtual void setMotionFrame(); virtual void getMotionFrame();
    virtual void setMotionLoop(); virtual void setMatAlphaMul(); virtual void setMatAlpha(); virtual void updateG3dProcCalcWorld();
    virtual void preExit(); virtual void fn_49_18A8(); virtual void invalidatedByCameraClipping(); virtual void setTransparencyFlag();
    virtual void updateCallback(); virtual void fixedPosition(); virtual void setTgtNode(const char*);
};
struct Obj;
struct VTable { char pad[0x1e0]; };
struct Obj {
    Obj(const char*);
    char pad0[0x3c];
    VTable* vtable;
    char pad40[0x90];
    char part[0xc];
    char paddc[0x7c];
    float x, y, z;
    u32 a164, a168;
};
namespace Heaps { enum HeapType { StageInstance = 15 }; }
extern void* operator new(unsigned long, Heaps::HeapType);
extern "C" Obj* fn_49_13B0(Obj*, const char*);
extern VTable lbl_49_data_2360;
extern const float lbl_49_rodata_120;
inline Obj::Obj(const char* name) {
    Obj* self = this;
    fn_49_13B0(self, name);
    self->vtable = &lbl_49_data_2360;
    float zero = lbl_49_rodata_120;
    self->x = zero;
    self->y = zero;
    self->z = zero;
    self->a164 = 0;
    self->a168 = 0;
    Class_1700* p = (Class_1700*)self->part;
    if (!p) return;
    p->state = 1;
    p->fn_49_6970(0, 15);
    p->data->flags |= 1;
}
extern "C" Obj* fn_49_B974(int mdlIndex, const char* node, const char* name) {
    Obj* obj = new (Heaps::StageInstance) Obj(name);
    if (obj) {
        ((Ground*)obj)->fn_49_13A8(mdlIndex);
        ((Ground*)obj)->setTgtNode(node);
    }
    return obj;
}
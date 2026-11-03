class Vec3f;
#include <snd/snd_3d_generator.h>
#pragma force_active on

namespace Heaps { enum HeapType { StageInstance = 15 }; }
extern void* operator new(unsigned long, Heaps::HeapType);
extern void* operator new(unsigned long, void*);
extern "C" void fn_57_3980(void*, const char*);
extern "C" char lbl_57_data_27D8[];
extern "C" const float lbl_57_rodata_2A8;

struct Flags { unsigned int pad, flags; };
class Class_2110 {
public:
    virtual void fn_57_C674();
    virtual void fn_57_BA94();
    virtual void fn_57_BAA4();
    virtual void fn_57_ADD8();
    virtual void fn_57_AB4C(int, int);
    Flags* data;
    unsigned int state;
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
    virtual void fn_57_3A9C();
    virtual void slot37();
    virtual void setNode();
    virtual void fn_57_638();
    virtual void fn_57_3A94();
    virtual void fn_57_3A90();
    virtual void fn_57_3978(int);
    virtual void fn_57_3A88();
    virtual void fn_57_3A7C();
    virtual void fn_57_3A6C();
    virtual void fn_57_3A5C();
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
    virtual void fn_57_3A58();
    virtual void fn_57_3A54();
    virtual void fn_57_3A4C();
    virtual void setMotionRatio();
    virtual void slot66();
    virtual void slot67();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_57_3A44();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode(const char*);
};

struct Obj;
struct ObjBase {
    ObjBase(const char*);
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    char part[0xc];
    char paddc[0x84];
    int field160;
    char field164;
    char pad165[3];
    float field168;
};
struct Obj : ObjBase {
    Obj(const char*);
    snd3DGenerator generator;
    int field174, field178;
};
inline ObjBase::ObjBase(const char* name) {
    fn_57_3980(this, name);
    vtable = lbl_57_data_27D8;
}
inline Obj::Obj(const char* name) : ObjBase(name) {
    Obj* self = this;
    self->field160 = 0;
    self->field164 = 4;
    self->field168 = lbl_57_rodata_2A8;
    Class_2110* p = (Class_2110*)self->part;
    if (!p) return;
    p->state = 1;
    p->fn_57_AB4C(0, 15);
    p->data->flags |= 1;
    self->field174 = -1;
    self->field178 = -1;
}
extern "C" Obj* fn_57_D16C(int index, const char* target, const char* name) {
    Obj* obj = new (Heaps::StageInstance) Obj(name);
    if (obj) {
        ((Ground*)obj)->fn_57_3978(index);
        ((Ground*)obj)->setTgtNode(target);
    }
    return obj;
}
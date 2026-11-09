#pragma force_active on
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_anmchr.h>

class Manager {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34(int, int);
    virtual void v38();
    virtual void v3C(void*);
};

class AnmChrSlots {
public:
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void setFrame(float);
};

extern Manager* lbl_805A02E0;
extern float lbl_805A23B0;
extern float lbl_805A23C0;

extern "C" void fn_800B6838(MuObject*, Vec3f*);
extern "C" void fn_801B4CB0(Manager*, void*, int);

extern "C" void fn_800E418C(int idx, char* self) {
    MuObject** slot = (MuObject**)(self + (idx + 0x19) * 4);
    MuObject* obj = slot[10];
    lbl_805A02E0->v3C(obj->m_sceneModel);
    Manager* owner = *(Manager**)(self + 0xF0);
    owner->v3C(obj->m_sceneModel);
    Vec3f pos;
    pos.m_x = lbl_805A23B0;
    pos.m_y = lbl_805A23B0;
    pos.m_z = lbl_805A23B0;
    fn_800B6838(obj, &pos);
    fn_801B4CB0(owner, obj->m_sceneModel, *(int*)(self + (idx + 2) * 4 + 0x5A8));
    MuObject* sf = slot[10];
    sf->setFrameNode(lbl_805A23B0);
    ((AnmChrSlots*)sf->m_modelAnim->m_anmObjChrRes)->setFrame(lbl_805A23C0);
}

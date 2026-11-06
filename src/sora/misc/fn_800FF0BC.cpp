#include <mu/mu_object.h>
#pragma force_active on

class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
    virtual void fn_801B26E4();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AB290();
    virtual void fn_801B2EEC(void*, void*);
    virtual void fn_801B3050();
    virtual void fn_801B3248(void*);
    char pad[0xE0];
    void* fieldE4;
};

struct Self {
    Class_8042B6D0* obj;
    char pad4[0x64];
    MuObject* muObj;
    char pad6c[0x115 - 0x6c];
    u8 f115;
};

extern float lbl_805A2748;
extern float lbl_805A274C;

extern "C" void fn_800FF0BC(Self* self, s32 arg1, s32 arg2) {
    MuObject* m = self->muObj;
    self->obj->fn_801B3248(m->m_sceneModel);
    self->obj->fn_801B2EEC(self->obj->fieldE4, m->m_sceneModel);
    m->setFrameVisible((float)(arg1 + (arg2 - 1) * 2));
    m->m_modelAnim->m_anmObjVisRes->SetUpdateRate(lbl_805A2748);
    m->setFrameNode(lbl_805A2748);
    m->m_modelAnim->m_anmObjChrRes->SetUpdateRate(lbl_805A274C);
    m->setFrameMatCol(lbl_805A2748);
    m->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(lbl_805A274C);
    self->f115 = 1;
}

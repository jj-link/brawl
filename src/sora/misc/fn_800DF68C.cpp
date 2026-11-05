#include <gf/gf_pad_system.h>
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
    char pad[0xe0];
    void* fieldE4;
};
struct Context {
    char pad[8];
    Class_8042B6D0* scene;
    char pad2[0x144];
    MuObject* object;
};
extern const unsigned char lbl_805A23A0[8];
extern const float lbl_805A2374;
extern const float lbl_805A2380;

extern "C" void fn_800DF68C(Context* self, int active, int port, int flag, int other) {
    MuObject* obj = self->object;
    self->scene->fn_801B3248(obj->m_sceneModel);
    if (active) {
        gfPadStatus status;
        g_gfPadSystem->getSysPadStatus(port, &status);
        float frame;
        if (status.m_error == 0) {
            frame = (float)lbl_805A23A0[status.m_controllerType];
        } else if (port < 4) {
            frame = lbl_805A2374;
        } else {
            frame = lbl_805A2380;
        }
        obj->setFrameTex(frame);
        obj->m_modelAnim->m_anmObjTexPatRes->SetUpdateRate(lbl_805A2374);
        int visible = flag == 0;
        if (other) visible += 2;
        obj->setFrameVisible((float)visible);
        obj->m_modelAnim->m_anmObjVisRes->SetUpdateRate(lbl_805A2374);
        self->scene->fn_801B2EEC(self->scene->fieldE4, obj->m_sceneModel);
    }
}
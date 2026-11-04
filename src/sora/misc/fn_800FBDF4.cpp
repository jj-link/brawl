#include <mu/mu_msg.h>
#include <gf/gf_pad_system.h>
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
    char pad[0xe0];
    void* fieldE4;
};
struct State {
    Class_8042B6D0* scene;
    MuObject* object;
    MuMsg* msg;
    int count;
    int unk10;
    int unk14;
    int port;
    bool enabled;
    char pad1d[3];
    int timer;
    char data[1];
};
extern "C" void fn_800B5854(void*, int, int, int, int);
extern "C" void fn_800B96E8(void*, unsigned char);
extern "C" char lbl_8059E4CC[4];
extern "C" const unsigned char lbl_805A2700[8];

extern "C" void fn_800FBDF4(State* self, int port, int arg) {
    MuObject* obj = self->object;
    float frame = obj->m_modelAnim->m_anmObjVisRes->GetFrame();
    fn_800B5854(obj, arg != 0, 2, 0, 0);
    obj->setFrameVisible(frame);
    self->count = (arg != 0) + 1;
    self->msg->printIndex(0, 0x1d, 0);
    if (arg) {
        self->msg->printIndex(1, 0x1e, 0);
    } else {
        self->msg->printf(1, lbl_8059E4CC);
    }
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(port, &status);
    self->object->setFrameVisible((float)lbl_805A2700[status.m_controllerType]);
    self->unk14 = 0;
    fn_800B5854(self->object, 0, 0x10, 1, 0);
    self->scene->fn_801B2EEC(self->scene->fieldE4, self->object->m_sceneModel);
    self->port = port;
    self->enabled = true;
    self->timer = 15;
    fn_800B96E8(self->data, (unsigned char)port);
}
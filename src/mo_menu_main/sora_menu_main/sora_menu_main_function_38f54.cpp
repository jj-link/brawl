#include <mu/mu_object.h>
#include <mu/mu_msg.h>
#include <snd/snd_system.h>
#pragma force_active on
extern "C" {
void fn_800B5854(void*, int, int, int, int);
void fn_800B753C(void*, float);
extern const float lbl_2_rodata_1750;
extern const float lbl_2_rodata_1760;
extern char lbl_2_data_4BEC[];
}
struct Callback {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10();
    virtual void call(int, int);
    char pad[0xe0];
    int value;
};
struct State {
    char pad[0x40];
    int mode;
    MuObject* object;
    MuObject* other;
    char pad2[0x20];
    int arg;
    Callback* callback;
    MuMsg* msg;
    char pad3[0xac];
    unsigned char selected;
};
extern "C" void fn_2_38F54(State* self) {
    int mode = self->mode;
    bool flag = mode != 0;
    int index = 4;
    if (mode == 0) index = 0;
    MuObject* obj = self->other;
    fn_800B5854(obj, index, 0x18, 0, 0);
    fn_800B753C(obj, lbl_2_rodata_1750);
    obj->m_modelAnim->setUpdateRate(lbl_2_rodata_1760);
    obj = self->object;
    obj->setFrameVisible(lbl_2_rodata_1760);
    self->msg->printIndex(2, 0x11, 0);
    self->msg->printIndex(3, 0x12, 0);
    self->msg->printIndex(1, flag, 0);
    float frame = lbl_2_rodata_1760;
    self->object->setFrameMatCol(frame);
    self->selected = 0;
    obj->changeNodeAnimN(lbl_2_data_4BEC);
    obj->setFrameNode(lbl_2_rodata_1750);
    obj->m_modelAnim->m_anmObjChrRes->SetUpdateRate(lbl_2_rodata_1760);
    self->callback->call(self->callback->value, self->arg);
    g_sndSystem->playSE((SndID)5, -1, 0, 0, -1);
}
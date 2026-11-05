#include <types.h>
#include <so/anim/so_anim_cmd_event_presenter.h>

#pragma force_active on

extern "C" u8 lbl_27_data_AC28[];
extern "C" u8 lbl_27_data_1550C[];
extern "C" u8 __vt__22soAnimCmdEventObserver[];

struct Module {
    u8 pad[0x80];
    void* object;
};

struct Owner {
    u8 pad[0xD8];
    Module* module;
};

struct Getter {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual s16 target(Owner*, s32, void*);
};

struct Self {
    void* vtable;
    u8 flag;
    u8 pad05[3];
    s32 f8;
    s32 fC;
    soAnimCmdEventObserver observer;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 field_28;
    s32 f2C;
};

extern "C" Self* fn_27_A1DA4(Self* self, Owner* owner, s32 arg2) {
    self->flag = 0;
    self->f8 = 0;
    self->fC = 0;
    self->vtable = &lbl_27_data_AC28;

    s16 id = ((Getter*)((u8*)owner->module->object + 8))->target(owner, arg2, &lbl_27_data_AC28);

    self->observer.m_manageID = -1;
    self->observer.m_unitID = 5;
    self->observer.m_sendID = -1;
    *(void**)&self->observer = __vt__22soAnimCmdEventObserver;
    self->observer.addObserver((short)id, -1);

    self->field_28 = arg2;
    self->vtable = &lbl_27_data_1550C;
    *(void**)&self->observer = lbl_27_data_1550C + 0x68;
    self->f2C = 0;
    self->f1C = 0;
    self->f20 = 0;
    self->f24 = 0;
    return self;
}
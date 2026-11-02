#include <so/anim/so_anim_cmd_event_presenter.h>
#include <types.h>
#pragma force_active on

struct Class_90D8_base { char pad[0x8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual int getId();
};

struct Class_6D008_base { char pad[0x8]; };
class Class_6D008 : public Class_6D008_base {
public:
    virtual void fn_27_2A0C2C();
};

struct Getter {
    virtual void fn_27_7B274();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual int getId();
};

struct Module {
    char pad[0x80];
    Class_90D8* object;
};

struct Owner {
    char pad[0xD8];
    Module* module;
};

struct Object {
    void* vtable;
    u8 flag;
    u8 pad[3];
    soAnimCmdEventObserver observer;
    int value;
    int state;
    Owner* owner;
};

extern "C" u8 lbl_27_data_CD30[];
extern "C" u8 lbl_27_data_132B0[];
extern "C" u8 __vt__22soAnimCmdEventObserver[];

extern "C" Object* fn_27_87084(Object* self, Owner* owner, int value) {
    self->flag = 0;
    self->vtable = lbl_27_data_CD30;

    int id = ((Getter*)((u8*)owner->module->object + 8))->getId();

    self->observer.m_manageID = -1;
    self->observer.m_unitID = 5;
    self->observer.m_sendID = -1;
    *(void**)&self->observer = __vt__22soAnimCmdEventObserver;
    self->observer.addObserver((short)id, -1);

    self->value = value;
    self->vtable = lbl_27_data_132B0;
    *(void**)&self->observer = lbl_27_data_132B0 + 0x6C;
    self->state = -1;
    self->owner = owner;
    return self;
}

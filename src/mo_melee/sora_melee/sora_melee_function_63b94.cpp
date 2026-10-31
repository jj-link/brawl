#include <types.h>
#pragma force_active on

extern "C" u8 lbl_27_data_71A0[];
extern "C" u8 lbl_27_data_7270[];
extern "C" u8 lbl_27_data_7284[];
extern "C" u8 lbl_27_data_7298[];
extern "C" const f32 lbl_27_rodata_8F0;
extern "C" const f32 lbl_27_rodata_8F4;

struct OwnerModule {
    u8 pad[0x80];
    void* object;
};

struct Owner {
    u8 pad[0xD8];
    OwnerModule* module;
};

struct VirtualObject {
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual void fn3();
    virtual void fn4();
    virtual void fn5();
    virtual void fn6();
    virtual s32 getID();
};

struct Observer {
    virtual void attach(s16, s32);
    s16 id;
    s16 type;
    s16 link;
};

struct MainObject {
    void* field0;
    u8 field4;
    u8 pad5[3];
    void* field8;
    Observer observer;
    Observer observer2;
    s32 field24;
    s32 field28;
    f32 field2C;
    f32 field30;
    f32 field34;
    u8 pad38[5];
    u8 field3D;
};

extern "C" MainObject* fn_27_63B94(
    MainObject* self, Owner* obj, s32 flag
) {
    self->field4 = 0;
    self->field8 = lbl_27_data_7298;
    self->field0 = lbl_27_data_7298 + 8;

    s32 id = ((VirtualObject*)((u8*)obj->module->object + 8))->getID();

    s32 secondID = -1;

    self->observer.id = -1;
    self->observer.type = 1;
    self->observer.link = -1;
    *(void**)&self->observer = lbl_27_data_7284;
    self->observer.attach(id, -1);

    if (flag != 0) {
        secondID = ((VirtualObject*)((u8*)obj->module->object + 8))->getID();
    }

    Observer* obs2 = &self->observer2;
    obs2->id = -1;
    obs2->type = 0x11;
    obs2->link = -1;
    *(void**)obs2 = lbl_27_data_7270;
    obs2->attach(secondID, -1);

    self->field8 = lbl_27_data_71A0;
    self->field0 = lbl_27_data_71A0 + 8;
    *(void**)&self->observer = lbl_27_data_71A0 + 0x4C;
    *(void**)&self->observer2 = lbl_27_data_71A0 + 0x60;
    self->field24 = -1;
    self->field28 = -1;
    self->field2C = lbl_27_rodata_8F0;
    self->field30 = lbl_27_rodata_8F0;
    self->field34 = lbl_27_rodata_8F4;
    self->field3D = 0;

    return self;
}

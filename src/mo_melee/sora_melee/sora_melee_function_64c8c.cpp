#include <types.h>
#pragma force_active on

extern "C" u8 lbl_27_data_7440[];
extern "C" u8 lbl_27_data_74D8[];
extern "C" u8 lbl_27_data_7558[];

struct Module {
    u8 pad[0x80];
    void* object;
};

struct Owner {
    u8 pad[0xD8];
    Module* module;
};

struct VirtualObj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual s16 method(Owner*, s32, void*);
};

struct Observer {
    virtual void attach(s16, s32, void*);
    s16 id;
    s16 type;
    s16 link;
};

struct MainObj {
    void* vtable;
    Observer observer;
    void* field_10;
    u8 pad_14[0xC];
    s32 field_20;
    u8 pad_24[0x2C];
    void* field_50;
    u8 pad_54[0xD];
    u8 field_61;
};

extern "C" MainObj* fn_27_64C8C(MainObj* self, Owner* owner, s32 arg2) {
    self->vtable = lbl_27_data_7558;

    VirtualObj* obj = (VirtualObj*)((u8*)owner->module->object + 8);
    s16 result = obj->method(owner, arg2, lbl_27_data_7558);

    self->observer.id = -1;
    self->observer.type = 2;
    self->observer.link = -1;
    *(void**)&self->observer = lbl_27_data_74D8;
    self->observer.attach(result, -1, lbl_27_data_74D8);

    self->field_10 = owner;
    self->vtable = lbl_27_data_7440;
    *(void**)&self->observer = lbl_27_data_7440 + 0x48;
    self->field_20 = arg2;
    self->field_50 = self;
    self->field_61 = 0;

    return self;
}

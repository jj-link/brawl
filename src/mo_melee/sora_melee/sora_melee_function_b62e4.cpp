#include <types.h>
#pragma force_active on

extern "C" u8 lbl_27_data_A360[];
extern "C" u8 lbl_27_data_171D8[];
extern "C" u8 lbl_27_data_14F8[];
extern "C" void* __vt__21soStatusEventObserver[];
extern "C" void* __vt__22soAnimCmdEventObserver[];
extern "C" const float lbl_27_rodata_E00[];

struct Getter {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual s16 getId();
};

struct Holder {
    char pad[8];
    Getter getter;
};

struct Module {
    char pad[0x80];
    Holder* holder;
};

struct Owner {
    char pad[0xd8];
    Module* module;
};

struct Observer {
    virtual void attach(s16, s32);
    s16 id;
    s16 type;
    s16 link;
};

struct Obj {
    void* vt;        // 0x00
    Observer obs1;   // 0x04
    Observer obs2;   // 0x10
    Observer obs3;   // 0x1c
    Owner* owner;    // 0x28
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    s32 f40;
    u8 flag;         // 0x44
};

extern "C" Obj* fn_27_B62E4(Obj* self, Owner* owner, s32 arg2, float farg0) {
    *(void**)self = lbl_27_data_A360;

    s16 id = owner->module->holder->getter.getId();
    self->obs1.id = -1;
    self->obs1.type = 4;
    self->obs1.link = -1;
    *(void**)&self->obs1 = __vt__21soStatusEventObserver;
    self->obs1.attach(id, -1);

    id = owner->module->holder->getter.getId();
    Observer* o2 = &self->obs2;
    o2->id = -1;
    o2->type = 5;
    o2->link = -1;
    *(void**)o2 = __vt__22soAnimCmdEventObserver;
    o2->attach(id, -1);

    id = owner->module->holder->getter.getId();
    Observer* o3 = &self->obs3;
    o3->id = -1;
    o3->type = 9;
    o3->link = -1;
    *(void**)o3 = lbl_27_data_14F8;
    o3->attach(id, -1);

    *(void**)self = lbl_27_data_171D8;
    *(void**)&self->obs1 = lbl_27_data_171D8 + 0x48;
    *(void**)&self->obs2 = lbl_27_data_171D8 + 0x58;
    *(void**)&self->obs3 = lbl_27_data_171D8 + 0x6C;
    self->owner = owner;
    self->f2c = farg0;
    self->f30 = 4.0f;
    self->f34 = 100.0f;
    self->f38 = 0.0f;
    self->f3c = 1.5f;
    self->f40 = arg2;
    self->flag = (u8)((((self->flag | 0x80) & 0xFFFFFF8F) | 0xC) & 0xFFFFFFFD);
    return self;
}

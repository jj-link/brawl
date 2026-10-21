#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct Observer {
    virtual void attach(short, int);
    short id;
    short type;
    short link;
};

struct Getter {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual int get();
};

struct Module {
    u8 pad[0x80];
    void* object;
};

struct Owner {
    u8 pad[0xD8];
    Module* module;
};

struct Object {
    void* vtable;
    u8 flag;
    u8 pad05[3];
    void* vtable08;
    Observer observer;
    Owner* owner;
    u8 data[0x28];
    short value;
    signed char flag46;
    u8 flag47;
    u8 flag48;
    u8 flag49;
    u8 flag4A;
    u8 flag4B;
};

extern "C" u8 lbl_27_data_98D0[];
extern "C" u8 lbl_27_data_17AA8[];
extern "C" void* __vt__21soStatusEventObserver[];
extern "C" void fn_27_C1A30(void*, u8, u32);

extern "C" Object* fn_27_C20D8(
    Object* self, Owner* owner, short value, u8 a, u32 b
) {
    self->flag = 0;
    self->vtable08 = lbl_27_data_98D0;
    self->vtable = lbl_27_data_98D0 + 8;

    void* sub = (u8*)owner->module->object + 8;
    int id = ((Getter*)sub)->get();

    self->observer.id = -1;
    self->observer.type = 4;
    self->observer.link = -1;
    *(void***)&self->observer = __vt__21soStatusEventObserver;
    self->observer.attach((short)id, -1);

    self->owner = owner;
    self->vtable08 = lbl_27_data_17AA8;
    self->vtable = lbl_27_data_17AA8 + 8;
    *(void***)&self->observer = (void**)(lbl_27_data_17AA8 + 0x50);

    fn_27_C1A30(self->data, a, b);

    self->value = value;
    self->flag46 = -1;
    self->flag47 = 0;
    self->flag48 = 0;
    self->flag49 = 0;
    self->flag4A = 0;
    self->flag4B = 0;
    return self;
}

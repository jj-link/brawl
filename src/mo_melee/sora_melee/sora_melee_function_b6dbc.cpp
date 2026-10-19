#pragma force_active on
typedef unsigned char u8;

struct Observer {
    virtual void attach(short, int);
    short id;
    short type;
    short link;
};

struct Object {
    void* vtable;
    u8 pad04[4];
    void* vtable08;
    u8 pad0C[0x14];
    Observer observer;
    void* value;
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

extern "C" void fn_27_87084(Object*, Owner*, int, void*);
extern "C" void* __vt__21soStatusEventObserver[];
extern "C" u8 lbl_27_data_172C0[];

extern "C" Object* fn_27_B6DBC(Object* self, Owner* owner, int arg, void* value) {
    fn_27_87084(self, owner, arg, value);

    void* sub = (u8*)owner->module->object + 8;
    int id = ((Getter*)sub)->get();

    self->observer.id = -1;
    self->observer.type = 4;
    self->observer.link = -1;
    *(void***)&self->observer = __vt__21soStatusEventObserver;
    self->observer.attach((short)id, -1);

    self->value = value;
    self->vtable = lbl_27_data_172C0;
    self->vtable08 = lbl_27_data_172C0 + 0x6C;
    *(void***)&self->observer = (void**)(lbl_27_data_172C0 + 0x88);

    return self;
}

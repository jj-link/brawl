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

struct Elem {
    u8 pad[0x30];
    u32 padBits : 24;
    u32 bits : 7;
    u32 lowBit : 1;
};

struct Container {
    virtual void v0();
    virtual Elem* at(int);
    virtual void v2();
    virtual int size();
};

struct Object {
    void* vtable;
    u8 flag;
    u8 pad[3];
    Observer observer;
    int f_14;
    int f_18;
    int f_1C;
    int f_20;
    int f_24;
    int f_28;
    int f_2C;
    int f_30;
    Object* self_ptr;
    int f_38;
    short f_3C;
    u8 f_3E;
    u8 pad_3F;
    int f_40;
    Owner* owner;
    Container* cont;
    int f_4C;
    int f_50;
};

extern "C" void* __vt__22soAnimCmdEventObserver[];
extern "C" u8 lbl_27_data_7E08[];
extern "C" u8 lbl_27_data_7BE0[];
extern "C" void fn_27_6F314(Elem*);

extern "C" Object* fn_27_6A244(Object* self, Owner* owner, Container* cont) {
    int i;
    int zero = 0;
    self->flag = zero;
    self->vtable = lbl_27_data_7E08;

    int id = ((Getter*)((u8*)owner->module->object + 8))->get();

    self->observer.id = -1;
    self->observer.type = 5;
    self->observer.link = -1;
    *(void***)&self->observer = __vt__22soAnimCmdEventObserver;
    self->observer.attach((short)id, -1);

    self->f_38 = -1;
    self->vtable = lbl_27_data_7BE0;
    *(void***)&self->observer = (void**)(lbl_27_data_7BE0 + 0x1C8);
    self->f_3C = zero;
    self->f_3E = zero;
    self->f_40 = -1;
    self->owner = owner;
    self->cont = cont;
    self->f_4C = -1;
    self->f_50 = -1;
    self->f_2C = zero;
    self->f_30 = zero;
    self->self_ptr = self;

    for (i = 0; i < self->cont->size(); i++) {
        Elem* elem = self->cont->at(i);
        elem->bits = i;
        fn_27_6F314(elem);
    }

    self->f_18 = 0;
    self->f_14 = 0;
    self->f_1C = 0;
    self->f_24 = 0;
    self->f_20 = 0;
    self->f_28 = 0;
    return self;
}

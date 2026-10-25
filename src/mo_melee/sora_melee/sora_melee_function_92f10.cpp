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
    u8 pad[0xC];
    Owner* owner;
};

struct Container {
    virtual void v0();
    virtual Elem* at(int);
    virtual void v2();
    virtual int size();
};

struct Buildable {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void build(void*, void*, void*);
};

struct Object {
    void* f0;
    Observer obs1;
    Observer obs2;
    Observer obs3;
    Owner* owner;
    Buildable* buildable;
    int arg3;
    Container* cont;
    int count;
};

extern "C" void* __vt__21soStatusEventObserver[];
extern "C" void* __vt__22soAnimCmdEventObserver[];
extern "C" u8 lbl_27_data_AF78[];
extern "C" u8 lbl_27_data_250[];
extern "C" u8 lbl_27_data_14368[];

extern "C" Object* fn_27_92F10(Object* self, Owner* owner, Buildable* buildable, int arg3, Container* cont) {
    self->f0 = lbl_27_data_AF78;

    int id = ((Getter*)((u8*)owner->module->object + 8))->get();

    self->obs1.id = -1;
    self->obs1.type = 4;
    self->obs1.link = -1;
    *(void***)&self->obs1 = __vt__21soStatusEventObserver;
    self->obs1.attach((short)id, -1);

    id = ((Getter*)((u8*)owner->module->object + 8))->get();

    Observer* o2 = &self->obs2;
    self->obs2.id = -1;
    self->obs2.type = 5;
    self->obs2.link = -1;
    *(void***)o2 = __vt__22soAnimCmdEventObserver;
    o2->attach((short)id, -1);

    id = ((Getter*)((u8*)owner->module->object + 8))->get();

    Observer* o3 = &self->obs3;
    self->obs3.id = -1;
    self->obs3.type = 7;
    self->obs3.link = -1;
    *(void**)o3 = (void*)lbl_27_data_250;
    o3->attach((short)id, -1);

    self->owner = owner;
    self->f0 = (void*)lbl_27_data_14368;
    *(void**)&self->obs1 = (void*)(lbl_27_data_14368 + 0x7C);
    *(void**)&self->obs2 = (void*)(lbl_27_data_14368 + 0x8C);
    *(void**)&self->obs3 = (void*)(lbl_27_data_14368 + 0xA0);
    self->buildable = buildable;
    self->arg3 = arg3;
    self->cont = cont;
    self->count = 0;

    buildable->build((void*)(lbl_27_data_14368 + 0xA0), (void*)(lbl_27_data_14368 + 0x8C), (void*)(lbl_27_data_14368 + 0x7C));

    int n = self->cont->size();
    for (int i = 0; i < n; i++) {
        self->cont->at(i)->owner = owner;
    }

    return self;
}

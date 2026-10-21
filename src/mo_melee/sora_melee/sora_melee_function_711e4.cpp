#pragma force_active on

typedef unsigned char u8;

struct Observer {
    virtual void attach(int, int);
    short id;
    short type;
    short link;
};

struct Object {
    void* vtable;
    u8 flag;
    u8 pad[3];
    Observer status;
    Observer anim;
    void* value;
};

extern "C" u8 lbl_27_data_8310[];
extern "C" u8 lbl_27_data_8238[];
extern "C" void* __vt__21soStatusEventObserver[];
extern "C" void* __vt__22soAnimCmdEventObserver[];

extern "C" Object* fn_27_711E4(Object* self, int arg, void* value) {
    self->flag = 0;
    self->vtable = lbl_27_data_8310;

    Observer* status = &self->status;
    status->id = -1;
    status->type = 4;
    status->link = -1;
    *(void***)status = __vt__21soStatusEventObserver;
    status->attach(arg, -1);

    self->anim.id = -1;
    self->anim.type = 5;
    self->anim.link = -1;
    *(void***)&self->anim = __vt__22soAnimCmdEventObserver;
    self->anim.attach(arg, -1);

    self->value = value;
    self->vtable = lbl_27_data_8238;
    *(void**)&self->status = lbl_27_data_8238 + 0x58;
    *(void**)&self->anim = lbl_27_data_8238 + 0x68;
    return self;
}

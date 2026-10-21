#pragma force_active on

typedef unsigned char u8;

struct Observer {
    virtual void attach(int, int);
    short id;
    short type;
    short link;
};

struct Object {
    u8 pad[0x3C];
    void* vtable;
    void* vtable40;
    u8 flag;
    u8 pad45[3];
    Observer anim;
    Observer other;
    int value;
};

extern "C" void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    void*, const char*, int, int, int, bool);

extern "C" u8 lbl_27_data_408[];
extern "C" u8 __vt__22soAnimCmdEventObserver[];
extern "C" u8 lbl_27_data_250[];
extern "C" u8 lbl_27_data_130[];

extern "C" Object* fn_27_3860(
    Object* self, const char* name, int category,
    int a, int b, bool c, int value)
{
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, name, category, a, b, c);

    {
        Observer* anim = &self->anim;
        self->vtable40 = lbl_27_data_408;
        self->flag = 0;
        anim->id = -1;
        anim->type = 5;
        anim->link = -1;
        *(void**)anim = __vt__22soAnimCmdEventObserver;
        anim->attach(-1, -1);
    }

    self->other.id = -1;
    self->other.type = 7;
    self->other.link = -1;
    *(void**)&self->other = lbl_27_data_250;
    self->other.attach(-1, -1);

    self->value = value;
    self->vtable = lbl_27_data_130;
    self->vtable40 = lbl_27_data_130 + 0x64;
    *(void**)&self->anim = lbl_27_data_130 + 0x70;
    *(void**)&self->other = lbl_27_data_130 + 0x84;
    return self;
}

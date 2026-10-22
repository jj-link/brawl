#pragma force_active on
typedef unsigned char u8;
struct Observer {
    virtual void attach(short, int);
    short id;
    short type;
    short link;
};
struct Getter {
    virtual void f0();virtual void f1();virtual void f2();virtual void f3();virtual void f4();virtual void f5();virtual void f6();
    virtual int get();
};
struct Module { u8 pad[0x80]; void* object; };
struct Owner { u8 pad[0xD8]; Module* module; };
struct Elem { u8 pad[0x34]; float v; };
struct Cont {
    virtual void a0();
    virtual Elem* at(int);
    virtual void a2();
    virtual int size();
};
struct Object {
    void* vtable;
    u8 flag;
    u8 pad05[3];
    void* vtable08;
    Observer obs;
    Observer obs2;
    Owner* owner;
    int f28, f2c, f30;
    Cont* cont;
    int count;
    int f3c;
    int f40;
    u8 a:2;
    u8 b1:1;
    u8 c:1;
    u8 d:1;
    u8 e:3;
};
extern "C" u8 lbl_27_data_1008[];
extern "C" u8 lbl_27_data_E14[];
extern "C" void* __vt__21soStatusEventObserver[];
extern "C" void* __vt__22soAnimCmdEventObserver[];
extern const float lbl_27_rodata_320;

extern "C" Object* fn_27_10158(Object* self, Owner* owner, int count, Cont* c, int b) {
    self->flag = 0;
    self->vtable08 = lbl_27_data_1008;
    self->vtable = lbl_27_data_1008 + 8;
    int id = ((Getter*)((u8*)owner->module->object + 8))->get();
    self->obs.id = -1;
    self->obs.type = 4;
    self->obs.link = -1;
    *(void***)&self->obs = __vt__21soStatusEventObserver;
    self->obs.attach((short)id, -1);
    id = ((Getter*)((u8*)owner->module->object + 8))->get();
    Observer* o2 = &self->obs2;
    self->obs2.id = -1;
    self->obs2.type = 5;
    self->obs2.link = -1;
    *(void***)o2 = __vt__22soAnimCmdEventObserver;
    o2->attach((short)id, -1);
    self->vtable08 = lbl_27_data_E14;
    self->vtable = lbl_27_data_E14 + 8;
    *(void**)&self->obs = lbl_27_data_E14 + 0x104;
    *(void**)&self->obs2 = lbl_27_data_E14 + 0x114;
    self->owner = owner;
    self->f28 = 0; self->f2c = 0; self->f30 = 0;
    self->cont = c;
    self->count = count;
    self->f3c = -1;
    self->f40 = 1;
    self->a = 0;
    self->b1 = 1;
    self->c = 0;
    self->d = b;
    int n = c->size();
    float z = lbl_27_rodata_320;
    for (int i = 0; i < n; i++) self->cont->at(i)->v = z;
    return self;
}

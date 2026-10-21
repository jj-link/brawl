#pragma force_active on
typedef int s32;

struct Vt {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void setParam(s32 a, s32 b, void* c);
};

struct Mid {
    char pad[0x6c];
    Vt* vt;
};

struct Stage {
    char pad[0xd8];
    Mid* mid;
};

struct Owner {
    char pad[0x6c];
    Stage* stage;
};

extern "C" {
void fn_41_31708(Owner* self) {
    Stage* st = self->stage;
    Vt* vt = st->mid->vt;
    vt->setParam(4, 0, st);
    vt->setParam(2, 0, self->stage);
    vt->setParam(3, 0, self->stage);
}
}

#pragma force_active on

class Manager {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void process(int, int, int);
};

struct Inner {
    char pad[0x90];
    Manager* manager;
};

struct Holder {
    char pad[0xD8];
    Inner* inner;
};

struct Owner {
    char pad0[0x14];
    Holder* holder;
    char pad1[0x3C - 0x18];
    int a;
    int b;
    int c;
    int d;
    int e;
};

extern "C" void fn_27_A81B8(Owner* self) {
    Manager* manager = self->holder->inner->manager;

    if (self->a != -1) manager->process(self->a, 0, -1);
    if (self->b != -1) manager->process(self->b, 0, -1);
    if (self->c != -1) manager->process(self->c, 0, -1);
    if (self->d != -1) manager->process(self->d, 0, -1);
    if (self->e != -1) manager->process(self->e, 0, -1);
}

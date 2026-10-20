#pragma force_active on
struct Work {
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
    virtual void setInt(int, unsigned int);
};

struct Modules {
    char pad[0x64];
    Work* work;
};

struct Base {
    char pad[0xD8];
    Modules* modules;
};

struct Params {
    char pad[0x40];
    float scale;
};

struct Object {
    char pad0[0x60];
    Base* base;
    char pad1[0x4870 - 0x64];
    Params* params;
};

extern "C" void fn_27_1DB0E8(void*);

extern "C" void fn_27_317F94(Object* self, float value) {
    fn_27_1DB0E8(self);
    self->base->modules->work->setInt(
        (int)(self->params->scale * value), 0x10000006);
}

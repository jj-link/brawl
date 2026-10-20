#pragma force_active on
struct Module {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual int getState();
};

struct Accessor {
    unsigned char pad[0x70];
    Module* module;
};

struct Owner {
    unsigned char pad[0xD8];
    Accessor* accessor;
};

struct Object {
    unsigned char pad[0x60];
    Owner* owner;
};

extern "C" int fn_27_1DAF80(Object*, void*);

extern "C" int fn_27_2F3C1C(Object* self, void* arg) {
    Module* module = self->owner->accessor->module;
    switch (module->getState()) {
    case 0:
    case 1:
        return 0;
    default:
        return fn_27_1DAF80(self, arg);
    }
}

#pragma force_active on
#define VIRTUAL_SLOTS_8(n) \
    virtual void slot##n##0(); \
    virtual void slot##n##1(); \
    virtual void slot##n##2(); \
    virtual void slot##n##3(); \
    virtual void slot##n##4(); \
    virtual void slot##n##5(); \
    virtual void slot##n##6(); \
    virtual void slot##n##7();

struct someStruct;
struct Context;

struct ObjectBase {
    char padding[0x3c];
};

struct Object : ObjectBase {
    VIRTUAL_SLOTS_8(0)
    VIRTUAL_SLOTS_8(1)
    VIRTUAL_SLOTS_8(2)
    VIRTUAL_SLOTS_8(3)
    VIRTUAL_SLOTS_8(4)
    VIRTUAL_SLOTS_8(5)
    VIRTUAL_SLOTS_8(6)
    VIRTUAL_SLOTS_8(7)
    VIRTUAL_SLOTS_8(8)
    VIRTUAL_SLOTS_8(9)
    VIRTUAL_SLOTS_8(10)
    VIRTUAL_SLOTS_8(11)
    VIRTUAL_SLOTS_8(12)
    VIRTUAL_SLOTS_8(13)
    VIRTUAL_SLOTS_8(14)
    VIRTUAL_SLOTS_8(15)
    VIRTUAL_SLOTS_8(16)
    VIRTUAL_SLOTS_8(17)
    VIRTUAL_SLOTS_8(18)
    VIRTUAL_SLOTS_8(19)
    VIRTUAL_SLOTS_8(20)
    VIRTUAL_SLOTS_8(21)
    VIRTUAL_SLOTS_8(22)
    virtual void extraSlot();
    virtual someStruct** getWork();

    char padding[0x20];
    Context* context;
};

struct Module {
    VIRTUAL_SLOTS_8(0)
    VIRTUAL_SLOTS_8(1)
    VIRTUAL_SLOTS_8(2)
    VIRTUAL_SLOTS_8(3)
    virtual void set(int, int);
};

#undef VIRTUAL_SLOTS_8

struct ModuleSet {
    char padding[0x60];
    Module* module;
};

struct Context {
    char padding[0xd8];
    ModuleSet* modules;
};

extern "C" int fn_27_1125B0(someStruct**);

extern "C" void fn_27_13C7D0(Object* self) {
    if (fn_27_1125B0(self->getWork()) == 0) {
        self->context->modules->module->set(5, -1);
    } else {
        self->context->modules->module->set(4, -1);
    }
}

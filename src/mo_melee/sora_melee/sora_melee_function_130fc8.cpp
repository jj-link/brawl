#pragma force_active on
#define VIRTUAL_TEN(prefix) \
    virtual void prefix##0(); \
    virtual void prefix##1(); \
    virtual void prefix##2(); \
    virtual void prefix##3(); \
    virtual void prefix##4(); \
    virtual void prefix##5(); \
    virtual void prefix##6(); \
    virtual void prefix##7(); \
    virtual void prefix##8(); \
    virtual void prefix##9();

struct Module {
    char padding[8];
    VIRTUAL_TEN(slotA)
    VIRTUAL_TEN(slotB)
    VIRTUAL_TEN(slotC)
    virtual void slotD0();
    virtual void slotD1();
    virtual void slotD2();
    virtual void slotD3();
    virtual void slotD4();
    virtual void slotD5();
    virtual void call(int);
};

struct Modules {
    char padding[0x38];
    Module* module;
};

struct Data {
    char padding[0xD8];
    Modules* modules;
};

struct ObjectBase {
    char padding[0x3C];
    VIRTUAL_TEN(slotA)
    VIRTUAL_TEN(slotB)
    VIRTUAL_TEN(slotC)
    VIRTUAL_TEN(slotD)
    VIRTUAL_TEN(slotE)
    VIRTUAL_TEN(slotF)
    VIRTUAL_TEN(slotG)
    VIRTUAL_TEN(slotH)
    VIRTUAL_TEN(slotI)
    VIRTUAL_TEN(slotJ)
    VIRTUAL_TEN(slotK)
    VIRTUAL_TEN(slotL)
    VIRTUAL_TEN(slotM)
    VIRTUAL_TEN(slotN)
    VIRTUAL_TEN(slotO)
    VIRTUAL_TEN(slotP)
    virtual void slotQ0();
    virtual void call();
};

#undef VIRTUAL_TEN

struct Object : ObjectBase {
    char padding1[0x20];
    Data* data;
};

extern "C" void fn_27_130FC8(Object* object, int value) {
    object->data->modules->module->call(value);
    object->call();
}

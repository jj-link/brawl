#pragma force_active on
struct Object {
    virtual int f00();
    virtual int f01();
    virtual int f02();
    virtual int f03();
    virtual int f04();
    virtual int f05();
    virtual int f06();
    virtual int f07();
    virtual int f08();
    virtual int f09();
    virtual int f10();
    virtual int f11();
    virtual int f12();
    virtual int f13();
    virtual int f14();
    virtual int call();
};

struct Module {
    char padding[0x40];
    Object* object;
};

struct Context {
    char padding[0xd8];
    Module* module;
};

extern "C" int fn_27_187690(void*, Context* context) {
    return context->module->object->call();
}

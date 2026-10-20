#pragma force_active on
class Object {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual unsigned int call();
};

struct Modules {
    char padding[0x40];
    Object* object;
};

struct Context {
    char padding[0xD8];
    Modules* modules;
};

extern "C" unsigned int fn_27_186F9C(void*, Context* context) {
    return context->modules->object->call();
}

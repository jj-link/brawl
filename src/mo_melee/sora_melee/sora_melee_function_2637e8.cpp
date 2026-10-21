#pragma force_active on
class Target {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void invoke();
};

struct Module {
    unsigned char padding[0x20];
    Target* target;
};

struct Object {
    unsigned char padding[0x180];
    Module* module;
};

extern "C" void fn_27_2637E8(Object* object) {
    object->module->target->invoke();
}

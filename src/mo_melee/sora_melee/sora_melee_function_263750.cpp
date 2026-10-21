#pragma force_active on
class Target {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void invoke();
};

struct Modules {
    unsigned char padding[0x1C];
    Target* target;
};

struct Object {
    unsigned char padding[0x180];
    Modules* modules;
};

extern "C" void fn_27_263750(Object* self) {
    self->modules->target->invoke();
}

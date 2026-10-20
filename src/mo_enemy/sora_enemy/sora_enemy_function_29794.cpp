#pragma force_active on
class Module {
public:
    virtual void f08();
    virtual void f0C();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1C();
    virtual void f20();
    virtual void reset();
    virtual void f28();
    virtual void set(int value);
    virtual void f30();
    virtual void f34();
    virtual void f38();
    virtual void f3C();
    virtual unsigned int query();
};

struct Accesser {
    Module* module;
};

extern "C" void fn_41_29794(Accesser* self, int value) {
    if (self->module->query() == 1) {
        self->module->reset();
    }
    self->module->set(value);
}

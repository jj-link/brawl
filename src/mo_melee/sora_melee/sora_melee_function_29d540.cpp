#pragma force_active on
struct Owner;

class Target {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void call(int, Owner*);
};

struct Module {
    char pad[0x70];
    Target* target;
};

struct Owner {
    char pad[0xD8];
    Module* module;
};

struct Context {
    char pad[0x60];
    Owner* owner;
};

extern "C" void fn_27_29D540(void*, Context* context) {
    Owner* owner = context->owner;
    owner->module->target->call(5, owner);
}

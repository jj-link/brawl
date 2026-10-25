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
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual int query();
};

struct Modules {
    char pad[0x54];
    Module* module;
};

struct Owner {
    char pad[0xd8];
    Modules* modules;
};

struct Context {
    char pad[0xe];
    unsigned char enabled;
    Owner* owner;
};

extern "C" {

int fn_27_5AF1C(const Context* self) {
    unsigned char en = self->enabled;
    int result = 0;
    if (en != 0) {
        if (self->owner->modules->module->query() != 0) {
            result = 1;
        }
    }
    return result;
}

}

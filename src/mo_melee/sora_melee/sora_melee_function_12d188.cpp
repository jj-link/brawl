#pragma force_active on
struct Owner;

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
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void call(int, Owner*);
};

struct Modules {
    unsigned char padding[0x70];
    Module* module;
};

struct Owner {
    unsigned char padding[0xD8];
    Modules* modules;
};

struct Object {
    unsigned char padding[0x60];
    Owner* owner;
};

extern "C" void fn_27_12D188(Object* self) {
    Module* module = self->owner->modules->module;
    module->call(0x10B, self->owner);
}

#pragma force_active on
typedef unsigned char u8;

struct Target {
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
    virtual void unused34();
    virtual void setEnabled(bool);
};

struct Modules {
    u8 pad[0x54];
    Target* target;
};

struct Owner {
    u8 pad[0xd8];
    Modules* modules;
};

struct State {
    u8 pad[0xe9];
    bool disabled;
};

struct Object {
    u8 pad0[0x24];
    Owner* owner;
    State* state;
    u8 pad1[0x18];
    u8 upper : 2;
    u8 enabled : 1;
    u8 locked : 1;
    u8 lower : 4;
};

extern "C" void fn_27_12984(Object* self, bool enabled) {
    if (self->state && !self->locked && self->enabled != enabled) {
        self->state->disabled = !enabled;
        Target* target = self->owner->modules->target;
        target->setEnabled(enabled);
        self->enabled = enabled;
    }
}

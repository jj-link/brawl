#pragma force_active on

struct Owner;

struct GroundModule {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
};

struct StatusModule {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int, Owner*);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
};

struct Modules {
    char pad0[0x14];
    GroundModule* ground;
    char pad1[0x58];
    StatusModule* status;
};

struct Owner {
    char pad[0xD8];
    Modules* modules;
};

struct Context {
    char pad[0x60];
    Owner* owner;
};

extern "C" void fn_27_383698(Context* self) {
    Owner* owner = self->owner;

    if (owner->modules->ground->slot3() == 5 || owner->modules->status->slot16() == 0x11B) {
        return;
    }
    owner->modules->status->slot3(0x127, owner);
}

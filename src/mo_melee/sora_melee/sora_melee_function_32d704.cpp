#pragma force_active on
struct Owner;

struct Target {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
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
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void call(int, Owner*);
};

struct Module {
    unsigned char padding[0x70];
    Target* target;
};

struct Owner {
    unsigned char padding[0xD8];
    Module* module;
};

struct Object {
    unsigned char padding[0x60];
    Owner* owner;
};

extern "C" void fn_27_32D704(Object* object) {
    Owner* owner = object->owner;
    owner->module->target->call(1, owner);
}

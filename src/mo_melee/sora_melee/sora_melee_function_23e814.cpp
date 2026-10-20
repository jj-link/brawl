#pragma force_active on
typedef unsigned char u8;

struct State {
    u8 kind;
    u8 mode;
};

struct Prefix {
    u8 padding[0x3C];
};

struct Object : Prefix {
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
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual State* getState();

    u8 padding40[4];
    u8 disabled;
    u8 padding45[2];
    u8 enabled;
};

extern "C" bool fn_27_23E814(Object* self) {
    if (self->disabled == 0) {
        State* state = self->getState();
        if (state->mode == 3 || state->kind == 0x3E) {
            return true;
        }
        if (self->enabled == 1) {
            return true;
        }
    }
    return false;
}

#pragma force_active on
typedef unsigned char u8;

class Target {
    u8 padding[0x3C];

public:
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
    virtual u8* getByte();
};

struct Object {
    u8 padding0[0x40];
    u8 state;
    u8 padding1[0xF];
    Target* target;
    u8 padding2[0x10];
    u8 value;
};

extern "C" void fn_27_2462A0(Object* self) {
    if ((u8)(self->state + 255) <= 1) {
        u8* result = self->target->getByte();
        *result = self->value;
    }
    self->state = 0;
}

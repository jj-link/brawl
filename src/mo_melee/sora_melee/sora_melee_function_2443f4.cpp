#pragma force_active on
class Target {
    unsigned char padding[0x3c];
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
    virtual void call();
};
struct State {
    unsigned char padding0[0x40];
    unsigned char state;
    unsigned char padding1[0x177];
    Target* target;
};
extern "C" void fn_27_2443F4(State* self) {
    Target* target = self->target;
    self->state = 6;
    if (target) {
        target->call();
    }
}

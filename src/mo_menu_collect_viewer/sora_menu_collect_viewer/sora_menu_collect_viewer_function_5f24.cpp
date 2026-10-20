#pragma force_active on
struct Result {
    unsigned char data[0x48];
};

struct Target {
    unsigned char padding[0x350];
    int status;
};

struct State {
    unsigned char padding0[0x1A0];
    int value;
    unsigned char padding1[0x1BFC - 0x1A4];
    int mode;
    unsigned char padding2[0x1CE4 - 0x1C00];
    Target* target;
};

struct ViewerBase {
    unsigned char padding[0x3C];

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
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual Result getResult();
};

struct Viewer : ViewerBase {
    unsigned char padding1[0x1AC - 0x40];
    State* state;
};

extern "C" void fn_800C6F40(Target*, int, const Result*);

extern "C" void fn_6_5F24(Viewer* self) {
    State* state = self->state;
    if (state->target->status == 0) {
        fn_800C6F40(state->target, state->value, &self->getResult());
        self->state->mode = 5;
    }
}
